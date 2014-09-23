/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_MBSFN_TDM_Info_H_
#define	_MBSFN_TDM_Info_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MBMS-ShortTransmissionID.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MBSFN-TDM-Info */
typedef struct MBSFN_TDM_Info {
	MBMS_ShortTransmissionID_t	 shortTransmissionID;
	long	 tDMPeriod;
	long	 tDMOffset;
	long	 tDMLength;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBSFN_TDM_Info_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBSFN_TDM_Info;

#ifdef __cplusplus
}
#endif

#endif	/* _MBSFN_TDM_Info_H_ */
#include <asn_internal.h>