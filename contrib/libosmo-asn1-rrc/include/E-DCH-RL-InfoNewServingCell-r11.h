/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_E_DCH_RL_InfoNewServingCell_r11_H_
#define	_E_DCH_RL_InfoNewServingCell_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PrimaryCPICH-Info.h"
#include "E-AGCH-Information.h"
#include "E-DPCCH-DPCCH-PowerOffset.h"
#include <NativeInteger.h>
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>
#include "E-RGCH-Information.h"
#include <NULL.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E_DCH_RL_InfoNewServingCell_r11__servingGrant__primary_Secondary_GrantSelector {
	E_DCH_RL_InfoNewServingCell_r11__servingGrant__primary_Secondary_GrantSelector_primary	= 0,
	E_DCH_RL_InfoNewServingCell_r11__servingGrant__primary_Secondary_GrantSelector_secondary	= 1
} e_E_DCH_RL_InfoNewServingCell_r11__servingGrant__primary_Secondary_GrantSelector;
typedef enum E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR {
	E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR_NOTHING,	/* No components present */
	E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR_e_RGCH_Information,
	E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR_releaseIndicator
} E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR;

/* Forward declarations */
struct E_ROCH_Information;
struct E_DPDCH_Reference_E_TFCIList_r7;
struct E_HICH_Information_r11;

/* E-DCH-RL-InfoNewServingCell-r11 */
typedef struct E_DCH_RL_InfoNewServingCell_r11 {
	PrimaryCPICH_Info_t	 primaryCPICH_Info;
	E_AGCH_Information_t	 e_AGCH_Information;
	struct E_ROCH_Information	*e_ROCH_Information	/* OPTIONAL */;
	struct E_DCH_RL_InfoNewServingCell_r11__servingGrant {
		long	*value	/* OPTIONAL */;
		long	 primary_Secondary_GrantSelector;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *servingGrant;
	E_DPCCH_DPCCH_PowerOffset_t	*e_DPCCH_DPCCH_PowerOffset	/* OPTIONAL */;
	struct E_DPDCH_Reference_E_TFCIList_r7	*reference_E_TFCIs	/* OPTIONAL */;
	long	*powerOffsetForSchedInfo	/* OPTIONAL */;
	long	*threeIndexStepThreshold	/* OPTIONAL */;
	long	*twoIndexStepThreshold	/* OPTIONAL */;
	struct E_HICH_Information_r11	*e_HICH_Information	/* OPTIONAL */;
	struct E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info {
		E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_PR present;
		union E_DCH_RL_InfoNewServingCell_r11__e_RGCH_Info_u {
			E_RGCH_Information_t	 e_RGCH_Information;
			NULL_t	 releaseIndicator;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *e_RGCH_Info;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E_DCH_RL_InfoNewServingCell_r11_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_primary_Secondary_GrantSelector_7;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_E_DCH_RL_InfoNewServingCell_r11;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "E-ROCH-Information.h"
#include "E-DPDCH-Reference-E-TFCIList-r7.h"
#include "E-HICH-Information-r11.h"

#endif	/* _E_DCH_RL_InfoNewServingCell_r11_H_ */
#include <asn_internal.h>