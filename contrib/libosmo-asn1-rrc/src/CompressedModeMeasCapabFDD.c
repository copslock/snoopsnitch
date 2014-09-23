/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#include "CompressedModeMeasCapabFDD.h"

static asn_TYPE_member_t asn_MBR_CompressedModeMeasCapabFDD_1[] = {
	{ ATF_POINTER, 1, offsetof(struct CompressedModeMeasCapabFDD, radioFrequencyBandFDD),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RadioFrequencyBandFDD,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"radioFrequencyBandFDD"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CompressedModeMeasCapabFDD, dl_MeasurementsFDD),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dl-MeasurementsFDD"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CompressedModeMeasCapabFDD, ul_MeasurementsFDD),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ul-MeasurementsFDD"
		},
};
static int asn_MAP_CompressedModeMeasCapabFDD_oms_1[] = { 0 };
static ber_tlv_tag_t asn_DEF_CompressedModeMeasCapabFDD_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CompressedModeMeasCapabFDD_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* radioFrequencyBandFDD at 929 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* dl-MeasurementsFDD at 930 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ul-MeasurementsFDD at 931 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CompressedModeMeasCapabFDD_specs_1 = {
	sizeof(struct CompressedModeMeasCapabFDD),
	offsetof(struct CompressedModeMeasCapabFDD, _asn_ctx),
	asn_MAP_CompressedModeMeasCapabFDD_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_CompressedModeMeasCapabFDD_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CompressedModeMeasCapabFDD = {
	"CompressedModeMeasCapabFDD",
	"CompressedModeMeasCapabFDD",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_CompressedModeMeasCapabFDD_tags_1,
	sizeof(asn_DEF_CompressedModeMeasCapabFDD_tags_1)
		/sizeof(asn_DEF_CompressedModeMeasCapabFDD_tags_1[0]), /* 1 */
	asn_DEF_CompressedModeMeasCapabFDD_tags_1,	/* Same as above */
	sizeof(asn_DEF_CompressedModeMeasCapabFDD_tags_1)
		/sizeof(asn_DEF_CompressedModeMeasCapabFDD_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CompressedModeMeasCapabFDD_1,
	3,	/* Elements count */
	&asn_SPC_CompressedModeMeasCapabFDD_specs_1	/* Additional specs */
};
