package de.srlabs.snoopsnitch.util;

import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.security.KeyManagementException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.cert.CertificateException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManagerFactory;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnCancelListener;
import android.content.DialogInterface.OnClickListener;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Build;
import android.telephony.TelephonyManager;
import de.srlabs.snoopsnitch.EncryptedFileWriterError;
import de.srlabs.snoopsnitch.R;
import de.srlabs.snoopsnitch.analysis.ImsiCatcher;
import de.srlabs.snoopsnitch.qdmon.EncryptedFileWriter;
import de.srlabs.snoopsnitch.qdmon.MsdSQLiteOpenHelper;
import de.srlabs.snoopsnitch.upload.DumpFile;


public class Utils {
	public static HttpsURLConnection openUrlWithPinning(Context context, String strUrl) throws IOException, KeyStoreException, NoSuchAlgorithmException, CertificateException, KeyManagementException{
		URL url = new URL(strUrl);
		HttpsURLConnection connection = (HttpsURLConnection) url.openConnection();
		final InputStream keystoreInputStream = context.getAssets().open("keystore.bks");

		final KeyStore keystore = KeyStore.getInstance("BKS");
		keystore.load(keystoreInputStream, "password".toCharArray());
		keystoreInputStream.close();

		final TrustManagerFactory tmf = TrustManagerFactory.getInstance("X509");
		tmf.init(keystore);

		final SSLContext sslContext = SSLContext.getInstance("TLSv1.2");
		sslContext.init(null, tmf.getTrustManagers(), null);

		// TODO: Handle pinning errors with an appropriate error message/Notification
		connection.setSSLSocketFactory(sslContext.getSocketFactory());
		return connection;
	}

	/**
	 * Generates a new random app ID. Currently the App id consists of 8
	 * hexadecimal digits generated based on the Android SecureRandom class.
	 * 
	 * @return
	 */
	@SuppressLint("TrulyRandom")
	public static String generateAppId(){
		SecureRandom sr = new SecureRandom();
		byte[] random = new byte[4];
		sr.nextBytes(random);
		return String.format("%02x%02x%02x%02x", random[0],random[1],random[2],random[3]);
	}
	public static String formatTimestamp(long millis){
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.getDefault());
		Date date = new Date(millis);
		return dateFormat.format(date);
	}
	/**
	 * Determines the network generation based on the networkType retrieved via telephonyManager.getNetworkType()
	 * @param networkType
	 * @return
	 * 0: Invalid value
	 * 2: GSM
	 * 3: 3G
	 * 4: LTE
	 */
	public static int networkTypeToNetworkGeneration(int networkType) {
		if (networkType == 0)
			return 0;
		else if (networkType == TelephonyManager.NETWORK_TYPE_UMTS || networkType == TelephonyManager.NETWORK_TYPE_HSDPA
				|| networkType == TelephonyManager.NETWORK_TYPE_HSPA
				|| networkType == TelephonyManager.NETWORK_TYPE_HSPAP
				|| networkType == TelephonyManager.NETWORK_TYPE_HSUPA)
			return 3;
		else if (networkType == TelephonyManager.NETWORK_TYPE_GPRS || networkType == TelephonyManager.NETWORK_TYPE_EDGE
				|| networkType == TelephonyManager.NETWORK_TYPE_CDMA)
			return 2;
		else if(networkType == TelephonyManager.NETWORK_TYPE_LTE){
			return 4;
		} else{
			return 0;
		}
	}

	public static String readFromAssets(Context context, String fileName) throws IOException {

		InputStream inputStream = context.getAssets().open(fileName);
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		int i;
		try {
			i = inputStream.read();
			while (i != -1)
			{
				byteArrayOutputStream.write(i);
				i = inputStream.read();
			}
			inputStream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return byteArrayOutputStream.toString();
	}
	public static String readFromFileInput(Context context, String fileName) throws IOException {

		InputStream inputStream = context.openFileInput(fileName);
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		int i;
		try {
			i = inputStream.read();
			while (i != -1)
			{
				byteArrayOutputStream.write(i);
				i = inputStream.read();
			}
			inputStream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return byteArrayOutputStream.toString();
	}

	public static String readFromFileOrAssets(Context context, String fileName) throws IOException {
		String jsonData;
		//  FIXME: Check for file existence - do not use exception for control flow
		try{
			jsonData = readFromFileInput(context, fileName);
		} catch(FileNotFoundException e){
			jsonData = readFromAssets(context, fileName);
		}
		return jsonData;
	}
	public static void showDeviceIncompatibleDialog(Activity activity, String incompatibilityReason, final Runnable callback){
		String dialogMessage =
				activity.getResources().getString(R.string.alert_deviceCompatibility_header) + " " +
						incompatibilityReason + " " +
						activity.getResources().getString(R.string.alert_deviceCompatibility_message);

		MsdDialog.makeFatalConditionDialog(activity, dialogMessage, new OnClickListener()
		{
			@Override
			public void onClick(DialogInterface dialog, int which)
			{
				callback.run();
			}
		}, null,
		new OnCancelListener() {
			@Override
			public void onCancel(DialogInterface dialog) {
				callback.run();
			}
		}, false
				).show();
	}

	private static String dumpRow (Cursor c)
	{
		String result = "VALUES(";

		for (int pos = 0; pos < c.getColumnCount(); pos++)
		{
			switch (c.getType(pos))
			{
			case Cursor.FIELD_TYPE_NULL:
				result += "null";
				break;
			case Cursor.FIELD_TYPE_INTEGER:
				result += Integer.toString(c.getInt(pos));
				break;
			case Cursor.FIELD_TYPE_FLOAT:
				result += Float.toString(c.getFloat(pos));
				break;
			case Cursor.FIELD_TYPE_STRING:
				result += DatabaseUtils.sqlEscapeString(c.getString(pos));
				break;
			case Cursor.FIELD_TYPE_BLOB:
				result += "<<Blobs unsupported>>";
				break;
			default:
				return "Invalid field type " + c.getType(pos) + " at position " + pos;
			}

			if (pos < c.getColumnCount() - 1)
			{
				result += ", ";
			}
		}
		return result + ")";
	}

	private static void dumpRows (SQLiteDatabase db, String table, EncryptedFileWriter outputFile, String query) throws EncryptedFileWriterError
	{
		Cursor c = db.rawQuery (query, null);
		while (c.moveToNext())
		{
			outputFile.write("INSERT INTO '" + table + "' " + dumpRow(c) + ";\n");
		}
		c.close();
	}
	/**
	 * Dump data related to an event to file
	 * @param id ID of an event
	 * @param outputFile Target file
	 * @throws EncryptedFileWriterError
	 */
	public static void dumpDatabase(Context context, SQLiteDatabase db, ImsiCatcher imsiCatcher, long startTime, long endTime, EncryptedFileWriter outputFile)
			throws EncryptedFileWriterError {

		// Create view with recent session_info IDs (last day)
		db.execSQL("DROP VIEW IF EXISTS si_dump");
		db.execSQL(
				"CREATE VIEW si_dump AS " +
						"SELECT id FROM session_info WHERE " +
						"(mcc > 0 AND lac > 0) AND " +				 
						"timestamp > datetime(" + Long.toString(startTime/1000) + ", 'unixepoch', '-1 day')");

		// session_info, sid_appid, paging_info
		dumpRows(db, "session_info", outputFile, "SELECT si.* FROM session_info as si, si_dump ON si_dump.id = si.id");
		dumpRows(db, "sid_appid", outputFile,    "SELECT sa.* FROM sid_appid as sa, si_dump    ON si_dump.id = sa.sid");
		dumpRows(db, "paging_info", outputFile,  "SELECT pi.* FROM paging_info as pi, si_dump  ON si_dump.id = pi.sid");

		if(imsiCatcher != null){
			// sms_meta and catcher entries (only for this event)
			dumpRows(db, "sms_meta", outputFile, "SELECT * FROM sms_meta WHERE id = " + Long.toString(imsiCatcher.getId()) + ";");
			dumpRows(db, "catcher", outputFile,  "SELECT * FROM catcher  WHERE id = " + Long.toString(imsiCatcher.getId()) + ";");
		}
		// create view with all relevant cell_info IDs
		db.execSQL("DROP VIEW IF EXISTS ci_dump");
		String sql = "CREATE VIEW ci_dump AS " +
				"SELECT cell_info.* FROM cell_info, config WHERE ";
		if(imsiCatcher != null)
			sql += "(mcc = " + imsiCatcher.getMcc() + " AND mnc = " + imsiCatcher.getMnc() + " AND lac = " + imsiCatcher.getLac() + " AND cid = " + imsiCatcher.getCid() + ") OR ";
		sql += "(abs(strftime('%s', first_seen) - " + Long.toString(startTime/1000) +
			") < (cell_info_max_delta + (max(delta_arfcn, neig_max_delta))))";
		db.execSQL(sql);

		// cell_info, arfcn_list
		dumpRows(db, "cell_info", outputFile,  "SELECT ci.* FROM cell_info  as ci, ci_dump ON ci.id = ci_dump.id");
		dumpRows(db, "arfcn_list", outputFile, "SELECT al.* FROM arfcn_list as al, ci_dump ON al.id = ci_dump.id");

		// config
		dumpRows(db, "config", outputFile, "SELECT * FROM config;");

		// location_info (10 minutes before and after the event)
		dumpRows(db, "location_info", outputFile,
				"SELECT * FROM location_info WHERE abs(strftime('%s', timestamp) - " + 
						Long.toString(startTime/1000) + ") < 600");

		// info table
		String info =
				"INSERT INTO 'info' VALUES (\n" +
						"'" + MsdConfig.getAppId(context) + "', -- App ID\n" +
						"'" + context.getResources().getString(R.string.app_version) + "', -- App version\n" +
						"'" + Build.VERSION.RELEASE +   "', -- Android version\n" +
						"'" + Build.MANUFACTURER +      "', -- Phone manufacturer\n" +
						"'" + Build.BOARD +             "', -- Phone board\n" +
						"'" + Build.BRAND +             "', -- Phone brand\n" +
						"'" + Build.PRODUCT +           "', -- Phone product\n" +
						"'" + Build.MODEL +             "', -- Phone model\n" +
						"'" + Build.getRadioVersion() + "', -- Baseband\n" +
						"'" + MsdLog.getTime() +        "', -- Time of export\n" +
						(imsiCatcher == null ? "0" : Long.toString(imsiCatcher.getId())) + "   -- Offending ID\n" +
						");";

		outputFile.write(info);
	}

	/**
	 * @param context
	 * @param db
	 * @param imsiCatcher Can be null for uploading suspicious activity
	 * @param startTime
	 * @param endTime
	 * @throws EncryptedFileWriterError
	 * @throws SQLException
	 * @throws IOException
	 */
	public static void uploadMetadata(Context context, SQLiteDatabase db, ImsiCatcher imsiCatcher, long startTime, long endTime)  throws EncryptedFileWriterError, SQLException, IOException {
		final boolean encryptedDump = true;
		final boolean plainDump = MsdConfig.dumpUnencryptedEvents(context);
		
		// Anonymize database before dumping
		MsdSQLiteOpenHelper.readSQLAsset(context, db, "anonymize.sql", false);
		
		String fileName = "meta-" + (imsiCatcher == null ? ("suspicious-" + System.currentTimeMillis()) : Long.toString(imsiCatcher.getId())) + ".gz";
		EncryptedFileWriter outputFile =
				new EncryptedFileWriter(context, fileName + ".smime", encryptedDump, fileName, plainDump);
		
		Utils.dumpDatabase(context, db, imsiCatcher, startTime, endTime, outputFile);
		outputFile.close();
		
		DumpFile meta = new DumpFile(outputFile.getEncryptedFilename(), DumpFile.TYPE_METADATA, startTime, endTime);
		meta.setImsi_catcher(true);
		meta.recordingStopped();
		meta.insert(db);
		meta.markForUpload(db);
	}
}
