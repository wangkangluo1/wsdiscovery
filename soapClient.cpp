/* soapClient.cpp
   Generated by gSOAP 2.8.1 from ns_ProbeOp.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.1 2011-05-20 07:01:44 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_send_d__Probe(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *d__Types, char *d__Scopes)
{	struct d__Probe soap_tmp_d__Probe;
	soap->encodingStyle = NULL;
	soap_tmp_d__Probe.d__Types = d__Types;
	soap_tmp_d__Probe.d__Scopes = d__Scopes;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_d__Probe(soap, &soap_tmp_d__Probe);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_d__Probe(soap, &soap_tmp_d__Probe, "d:Probe", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_d__Probe(soap, &soap_tmp_d__Probe, "d:Probe", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_d__Probe(struct soap *soap, struct d__Probe *_param_1)
{
	soap_default_d__Probe(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_d__Probe(soap, _param_1, "d:Probe", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_NO_METHOD;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send_d__ProbeMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct d__ProbeMatchType *d__ProbeMatch)
{	struct d__ProbeMatches soap_tmp_d__ProbeMatches;
	soap->encodingStyle = NULL;
	soap_tmp_d__ProbeMatches.d__ProbeMatch = d__ProbeMatch;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_d__ProbeMatches(soap, &soap_tmp_d__ProbeMatches);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_d__ProbeMatches(soap, &soap_tmp_d__ProbeMatches, "d:ProbeMatches", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_d__ProbeMatches(soap, &soap_tmp_d__ProbeMatches, "d:ProbeMatches", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_d__ProbeMatches(struct soap *soap, struct d__ProbeMatches *_param_2)
{
	soap_default_d__ProbeMatches(soap, _param_2);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_d__ProbeMatches(soap, _param_2, "d:ProbeMatches", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_NO_METHOD;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */
