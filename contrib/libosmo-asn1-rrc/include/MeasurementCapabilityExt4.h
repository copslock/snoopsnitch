/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_MeasurementCapabilityExt4_H_
#define	_MeasurementCapabilityExt4_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CompressedModeMeasCapabFDDList2;
struct CompressedModeMeasCapabFDDList3;
struct CompressedModeMeasCapabTDDList;
struct CompressedModeMeasCapabGSMList;
struct CompressedModeMeasCapabMC;
struct CompressedModeMeasCapabEUTRAList;

/* MeasurementCapabilityExt4 */
typedef struct MeasurementCapabilityExt4 {
	struct CompressedModeMeasCapabFDDList2	*compressedModeMeasCapabFDDList2	/* OPTIONAL */;
	struct CompressedModeMeasCapabFDDList3	*compressedModeMeasCapabFDDList3	/* OPTIONAL */;
	struct CompressedModeMeasCapabTDDList	*compressedModeMeasCapabTDDList	/* OPTIONAL */;
	struct CompressedModeMeasCapabGSMList	*compressedModeMeasCapabGSMList	/* OPTIONAL */;
	struct CompressedModeMeasCapabMC	*compressedModeMeasCapabMC	/* OPTIONAL */;
	struct CompressedModeMeasCapabEUTRAList	*compressedModeMeasCapabEUTRAList	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasurementCapabilityExt4_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasurementCapabilityExt4;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CompressedModeMeasCapabFDDList2.h"
#include "CompressedModeMeasCapabFDDList3.h"
#include "CompressedModeMeasCapabTDDList.h"
#include "CompressedModeMeasCapabGSMList.h"
#include "CompressedModeMeasCapabMC.h"
#include "CompressedModeMeasCapabEUTRAList.h"

#endif	/* _MeasurementCapabilityExt4_H_ */
#include <asn_internal.h>