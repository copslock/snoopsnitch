/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_RB_MappingInfo_H_
#define	_RB_MappingInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RB_MappingOption;

/* RB-MappingInfo */
typedef struct RB_MappingInfo {
	A_SEQUENCE_OF(struct RB_MappingOption) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RB_MappingInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RB_MappingInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RB-MappingOption.h"

#endif	/* _RB_MappingInfo_H_ */
#include <asn_internal.h>
