/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_REG_D.asn"
 * 	`asn1c -gen-PER`
 */

#include "SPAT.h"

static asn_TYPE_member_t asn_MBR_SPAT_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SPAT, msgID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DSRCmsgID2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"msgID"
		},
	{ ATF_POINTER, 2, offsetof(struct SPAT, msgSubID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DSRCmsgSubID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"msgSubID"
		},
	{ ATF_POINTER, 1, offsetof(struct SPAT, name),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DescriptiveName,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"name"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SPAT, intersections),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionStateList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"intersections"
		},
	{ ATF_POINTER, 1, offsetof(struct SPAT, regional),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RegionalSPAT,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"regional"
		},
};
static int asn_MAP_SPAT_oms_1[] = { 1, 2, 4 };
static ber_tlv_tag_t asn_DEF_SPAT_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SPAT_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* msgID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* msgSubID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* name */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* intersections */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* regional */
};
static asn_SEQUENCE_specifics_t asn_SPC_SPAT_specs_1 = {
	sizeof(struct SPAT),
	offsetof(struct SPAT, _asn_ctx),
	asn_MAP_SPAT_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_SPAT_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	4,	/* Start extensions */
	6	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SPAT = {
	"SPAT",
	"SPAT",
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
	asn_DEF_SPAT_tags_1,
	sizeof(asn_DEF_SPAT_tags_1)
		/sizeof(asn_DEF_SPAT_tags_1[0]), /* 1 */
	asn_DEF_SPAT_tags_1,	/* Same as above */
	sizeof(asn_DEF_SPAT_tags_1)
		/sizeof(asn_DEF_SPAT_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SPAT_1,
	5,	/* Elements count */
	&asn_SPC_SPAT_specs_1	/* Additional specs */
};
