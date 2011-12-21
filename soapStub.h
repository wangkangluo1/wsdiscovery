/* soapStub.h
   Generated by gSOAP 2.8.1 from ns_ProbeOp.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#define SOAP_WSA_200408
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_wsa__RelationshipTypeValues
#define SOAP_TYPE_wsa__RelationshipTypeValues (12)
/* wsa:RelationshipTypeValues */
enum wsa__RelationshipTypeValues {wsa__Reply = 0};
typedef enum wsa__RelationshipTypeValues wsa__RelationshipTypeValues;
#endif

#ifndef SOAP_TYPE_wsa__FaultSubcodeValues
#define SOAP_TYPE_wsa__FaultSubcodeValues (13)
/* wsa:FaultSubcodeValues */
enum wsa__FaultSubcodeValues {wsa__InvalidMessageInformationHeader = 0, wsa__MessageInformationHeaderRequired = 1, wsa__DestinationUnreachable = 2, wsa__ActionNotSupported = 3, wsa__EndpointUnavailable = 4};
typedef enum wsa__FaultSubcodeValues wsa__FaultSubcodeValues;
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_wsa__EndpointReferenceType
#define SOAP_TYPE_wsa__EndpointReferenceType (7)
/* wsa:EndpointReferenceType */
struct wsa__EndpointReferenceType
{
public:
	char *Address;	/* required element of type xsd:string */
	struct wsa__ReferencePropertiesType *ReferenceProperties;	/* optional element of type wsa:ReferencePropertiesType */
	struct wsa__ReferenceParametersType *ReferenceParameters;	/* optional element of type wsa:ReferenceParametersType */
	char **PortType;	/* optional element of type xsd:QName */
	struct wsa__ServiceNameType *ServiceName;	/* optional element of type wsa:ServiceNameType */
	int __size;	/* sequence of elements <-any> */
	char **__any;
	char *__anyAttribute;	/* optional attribute of type xsd:anyType */
};
typedef struct wsa__EndpointReferenceType wsa__EndpointReferenceType;
#endif

#ifndef SOAP_TYPE_wsa__ReferencePropertiesType
#define SOAP_TYPE_wsa__ReferencePropertiesType (8)
/* wsa:ReferencePropertiesType */
struct wsa__ReferencePropertiesType
{
public:
	int __size;	/* sequence of elements <-any> */
	char **__any;
};
typedef struct wsa__ReferencePropertiesType wsa__ReferencePropertiesType;
#endif

#ifndef SOAP_TYPE_wsa__ReferenceParametersType
#define SOAP_TYPE_wsa__ReferenceParametersType (9)
/* wsa:ReferenceParametersType */
struct wsa__ReferenceParametersType
{
public:
	int __size;	/* sequence of elements <-any> */
	char **__any;
};
typedef struct wsa__ReferenceParametersType wsa__ReferenceParametersType;
#endif

#ifndef SOAP_TYPE_wsa__ServiceNameType
#define SOAP_TYPE_wsa__ServiceNameType (10)
/* Primitive wsa:ServiceNameType schema type: */
struct wsa__ServiceNameType
{
public:
	char *__item;
	char *PortName;	/* optional attribute of type xsd:string */
	char *__anyAttribute;	/* optional attribute of type xsd:anyType */
};
typedef struct wsa__ServiceNameType wsa__ServiceNameType;
#endif

#ifndef SOAP_TYPE_wsa__Relationship
#define SOAP_TYPE_wsa__Relationship (11)
/* Primitive wsa:Relationship schema type: */
struct wsa__Relationship
{
public:
	char *__item;
	char *RelationshipType;	/* optional attribute of type xsd:QName */
	char *__anyAttribute;	/* optional attribute of type xsd:anyType */
};
typedef struct wsa__Relationship wsa__Relationship;
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (29)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	char *wsa__MessageID;	/* optional element of type wsa:MessageID */
	struct wsa__Relationship *wsa__RelatesTo;	/* optional element of type wsa:RelatesTo */
	struct wsa__EndpointReferenceType *wsa__From;	/* optional element of type wsa:From */
	struct wsa__EndpointReferenceType *wsa__ReplyTo;	/* mustUnderstand */
	struct wsa__EndpointReferenceType *wsa__FaultTo;	/* mustUnderstand */
	char *wsa__To;	/* mustUnderstand */
	char *wsa__Action;	/* mustUnderstand */
};
#endif

#endif

#ifndef SOAP_TYPE_d__EndpointReferenceType
#define SOAP_TYPE_d__EndpointReferenceType (34)
/* d:EndpointReferenceType */
struct d__EndpointReferenceType
{
public:
	char *wsa__Address;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_d__ProbeMatchType
#define SOAP_TYPE_d__ProbeMatchType (35)
/* d:ProbeMatchType */
struct d__ProbeMatchType
{
public:
	struct d__EndpointReferenceType *wsa__EndpointReference;	/* optional element of type d:EndpointReferenceType */
	char *d__Types;	/* optional element of type xsd:string */
	char *d__Scopes;	/* optional element of type xsd:string */
	char *d__XAddrs;	/* optional element of type xsd:string */
	unsigned int d__MetadataVersion;	/* required element of type xsd:unsignedInt */
};
#endif

#ifndef SOAP_TYPE_d__Probe
#define SOAP_TYPE_d__Probe (40)
/* d:Probe */
struct d__Probe
{
public:
	char *d__Types;	/* optional element of type xsd:string */
	char *d__Scopes;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_d__ProbeMatches
#define SOAP_TYPE_d__ProbeMatches (43)
/* d:ProbeMatches */
struct d__ProbeMatches
{
public:
	struct d__ProbeMatchType *d__ProbeMatch;	/* optional element of type d:ProbeMatchType */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (44)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (46)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (47)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (48)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__wsa__EndpointReference
#define SOAP_TYPE__wsa__EndpointReference (19)
typedef struct wsa__EndpointReferenceType _wsa__EndpointReference;
#endif

#ifndef SOAP_TYPE__wsa__MessageID
#define SOAP_TYPE__wsa__MessageID (20)
typedef char *_wsa__MessageID;
#endif

#ifndef SOAP_TYPE__wsa__RelatesTo
#define SOAP_TYPE__wsa__RelatesTo (21)
typedef struct wsa__Relationship _wsa__RelatesTo;
#endif

#ifndef SOAP_TYPE__wsa__To
#define SOAP_TYPE__wsa__To (22)
typedef char *_wsa__To;
#endif

#ifndef SOAP_TYPE__wsa__Action
#define SOAP_TYPE__wsa__Action (23)
typedef char *_wsa__Action;
#endif

#ifndef SOAP_TYPE__wsa__From
#define SOAP_TYPE__wsa__From (24)
typedef struct wsa__EndpointReferenceType _wsa__From;
#endif

#ifndef SOAP_TYPE__wsa__ReplyTo
#define SOAP_TYPE__wsa__ReplyTo (25)
typedef struct wsa__EndpointReferenceType _wsa__ReplyTo;
#endif

#ifndef SOAP_TYPE__wsa__FaultTo
#define SOAP_TYPE__wsa__FaultTo (26)
typedef struct wsa__EndpointReferenceType _wsa__FaultTo;
#endif

#ifndef SOAP_TYPE__wsa__ReplyAfter
#define SOAP_TYPE__wsa__ReplyAfter (28)
typedef unsigned int _wsa__ReplyAfter;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 d__Probe(struct soap*, char *d__Types, char *d__Scopes);

SOAP_FMAC5 int SOAP_FMAC6 d__ProbeMatches(struct soap*, struct d__ProbeMatchType *d__ProbeMatch);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_d__Probe(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_d__ProbeMatches(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_send_d__Probe(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *d__Types, char *d__Scopes);

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_d__Probe(struct soap *soap, struct d__Probe *_param_1);


SOAP_FMAC5 int SOAP_FMAC6 soap_send_d__ProbeMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct d__ProbeMatchType *d__ProbeMatch);

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_d__ProbeMatches(struct soap *soap, struct d__ProbeMatches *_param_2);


#endif

/* End of soapStub.h */