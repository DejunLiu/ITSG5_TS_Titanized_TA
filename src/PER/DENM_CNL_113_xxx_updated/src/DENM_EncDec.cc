/*
///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2015 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
//
//  File:               DENM_EncDec.cc
//  Rev:                
//  Prodnr:             
//  Updated:            2015-09-08
//  Contact:            http://ttcn.ericsson.se
//  Reference:          

*/ 

#include "DENM_Types.hh"
#include "DENM.h"
#include <asn_application.h>
#include <asn_internal.h>	/* for _ASN_DEFAULT_STACK_MAX */
#include <string.h>
#include <stdarg.h>

//unsigned char* res = NULL;
//size_t res_size = 0;

namespace DENM__Types {

unsigned char* res = NULL;
size_t res_size = 0;

TTCN_Module DENM__EncDec("DENM_EncDec", __DATE__, __TIME__);

// This function is called multiple times while ber and per decoding
static int write_out(const void *buffer, size_t size, void *key) {
  unsigned char * temp = (unsigned char*)realloc(res, (res_size + size) * sizeof(unsigned char));
  unsigned char *tempbuf = temp + res_size;
  res = temp;
  memcpy(tempbuf, buffer, size);
  res_size += size;
  return 0;      
}

//////////////////////////////////
// Encoding function for DENM
//////////////////////////////////

OCTETSTRING enc__DENM__PDU(const DENM__PDU__Descriptions::DENM& pdu)
{
  boolean Debugging;
  if (TTCN_Logger::log_this_event(TTCN_DEBUG)) Debugging = TRUE;
  else Debugging = FALSE;


  // PDU_DENM is a union the union element will show us which BER encoding
  // function shall be chosen

  DENM_t *denm = 0; /* Type to encode */
  denm = (DENM_t*)calloc(1, sizeof(DENM_t));
  asn_enc_rval_t erv; /* Encoder return value */
  asn_dec_rval_t rval; /* Decoder return value */

  //set error behavior
  TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_ALL,TTCN_EncDec::EB_WARNING);


  TTCN_Buffer TTCN_buf;
  TTCN_buf.clear();

  pdu.encode(DENM__PDU__Descriptions::DENM_descr_,TTCN_buf,TTCN_EncDec::CT_BER,BER_ENCODE_DER);


  // After BER encoding, we are calling the BER decoder function of asn1c tool
  //TTCN_buf.get_len() returns the length of encoded data
  //TTCN_buf.get_data() returns the pointer of recorded data

  size_t length = TTCN_buf.get_len();
  unsigned char *tempbuf = new unsigned char [length];
  unsigned char *value = tempbuf;
  memcpy(value, TTCN_buf.get_data(), length);

  TTCN_buf.cut();

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Encoded DENM PDU in BER: ");
    OCTETSTRING(length,value).log();
    TTCN_Logger::end_event();
  }

  //Decode the BER values from the value buffer into the denm variable
  rval = ber_decode(0, &asn_DEF_DENM, (void **)&denm, value, length);

  if(rval.code != RC_OK) {
    /* Free partially decoded rect */
    asn_DEF_DENM.free_struct(&asn_DEF_DENM, denm, 0);
    TTCN_error("ASN1C BER decoding failed");
  }else {
     TTCN_Logger::log(TTCN_DEBUG, "BER2PER: DENM BER decoding successful.");
  }


  // Free and reset the buffers for the write_out function
  free(res);
  res = NULL;
  res_size = 0;

  // Unaligned PER encoding
  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Starting ASN1C PER encoding: ");
    TTCN_Logger::end_event();
  }
  erv = uper_encode(&asn_DEF_DENM, denm, write_out, NULL);


  if(erv.encoded < 0){
    TTCN_error("ASN1C PER encoding failed.");
  }else {
    TTCN_Logger::log(TTCN_DEBUG, "DENM PER decoding successful.");
  }

  OCTETSTRING ret_val(res_size, res);

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Encoded PDU in PER: ");
    ret_val.log();
    TTCN_Logger::end_event();
  }

  free(denm);
  free(res);
  res = NULL;
  res_size = 0;

  // Return the PER encoded data as an OCTETSTRING
  return ret_val;
}

//////////////////////////////////
// Decoding function for DENM
//////////////////////////////////

DENM__PDU__Descriptions::DENM dec__DENM__PDU(const OCTETSTRING& stream)
{
  boolean Debugging;
  if (TTCN_Logger::log_this_event(TTCN_DEBUG)) Debugging = TRUE;
  else Debugging = FALSE;

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("dec_DENM_PDU was called with: ");
    stream.log();
    TTCN_Logger::end_event();
  }

  DENM *denm = 0; /* Type to encode */
  denm = (DENM_t*)calloc(1, sizeof(DENM_t));
  asn_enc_rval_t erv; /* Encoder return value */
  asn_dec_rval_t rval; /* Decoder return value */

  res_size = stream.lengthof();
  unsigned char *tempbuf = new unsigned char [res_size];
  res = tempbuf;
  memcpy(tempbuf, (const unsigned char*)stream, res_size);

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Starting ASN1C PER decoding: ");
    TTCN_Logger::end_event();
  }

  // Decode the Unaligned PER into the denm variable
  rval = uper_decode_complete(NULL,&asn_DEF_DENM,(void **)&denm, res, res_size);

  if(rval.code != RC_OK) {
    /* Free partially decoded rect */
    asn_DEF_DENM.free_struct(&asn_DEF_DENM, denm, 0);
    TTCN_error("ASN1C PER decoding failed");
  }else {
     TTCN_Logger::log(TTCN_DEBUG, "BER2PER: DENM PER decoding successful.");
  }

  // Free and reset the buffers for the write_out function
  free(res);
  res = NULL;
  res_size = 0;

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Starting ASN1C BER encoding: ");
    TTCN_Logger::end_event();
  }
  // Encode the denm variable into BER
  erv = der_encode(&asn_DEF_DENM, denm, write_out, NULL);

  if(erv.encoded < 0){
    TTCN_error("ASN1C BER encoding failed.");
  }else {
    TTCN_Logger::log(TTCN_DEBUG, "DENM BER decoding successful.");
  }

  if (Debugging) {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Encoded PDU in BER: ");
    OCTETSTRING(res_size, res).log();
    TTCN_Logger::end_event();
  }

  TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_ALL,TTCN_EncDec::EB_WARNING);
  DENM__PDU__Descriptions::DENM ret_denm;
  TTCN_Buffer TTCN_buf;
  TTCN_buf.clear();
  TTCN_buf.put_s(res_size, res);

  ret_denm.decode(DENM__PDU__Descriptions::DENM_descr_,TTCN_buf,TTCN_EncDec::CT_BER,BER_ACCEPT_ALL);

  free(denm);
  free(res);
  res = NULL;
  res_size = 0;

  return ret_denm;
}

void DENM__EncDec_init(){}

}//namespace
