////////////////////////////////////////////////////////////////////////////////
//
//	Import WS-Addressing
//
////////////////////////////////////////////////////////////////////////////////

//gsoap wsa schema import: http://schemas.xmlsoap.org/ws/2004/08/addressing

#import "wsa.h"		// wsa.h is in the import directory

////////////////////////////////////////////////////////////////////////////////
//
//	SOAP-over-UDP SOAP Headers with WS-Addressing
//
////////////////////////////////////////////////////////////////////////////////


struct SOAP_ENV__Header
{
  mustUnderstand _wsa__MessageID      wsa__MessageID 0; ///< WS-Addressing
  mustUnderstand _wsa__RelatesTo     *wsa__RelatesTo 0; ///< WS-Addressing
  mustUnderstand _wsa__From          *wsa__From      0; ///< WS-Addressing
  mustUnderstand _wsa__ReplyTo       *wsa__ReplyTo   0; ///< WS-Addressing
  mustUnderstand _wsa__FaultTo       *wsa__FaultTo   0; ///< WS-Addressing
  mustUnderstand _wsa__To             wsa__To        0; ///< WS-Addressing
  mustUnderstand _wsa__Action         wsa__Action    0; ///< WS-Addressing
};

struct d__EndpointReferenceType {
	char *wsa__Address;
}

struct d__HelloType
{
	/// Element reference "http://schemas.xmlsoap.org/ws/2004/08/addressing":EndpointReference.
    struct d__EndpointReferenceType*   wsa__EndpointReference;	///< Required element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":Types.
    char                   							 *d__Types;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":Scopes.
    char											           *d__Scopes;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":XAddrs.
    char                   							 *d__XAddrs;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":MetadataVersion.
    unsigned int                         d__MetadataVersion;	///< Required element.
};

struct d__ProbeMatchType {
	/// Element reference "http://schemas.xmlsoap.org/ws/2004/08/addressing":EndpointReference.
    struct d__EndpointReferenceType*   wsa__EndpointReference;	///< Required element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":Types.
    char                   							 *d__Types;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":Scopes.
    char											           *d__Scopes;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":XAddrs.
    char                   							 *d__XAddrs;	///< Optional element.
/// Element reference "http://schemas.xmlsoap.org/ws/2005/04/discovery":MetadataVersion.
    unsigned int                         d__MetadataVersion;	///< Required element.
};

//gsoap ns service name: Probe
//gsoap ns service namespace: http://localhost/ProbeMatches.wsdl
//gsoap ns service location: http://localhost
//gsoap ns service executable: ProbeMatches.cgi
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:d

//gsoap ns service method-header-part: Probe wsa__MessageID
//gsoap ns service method-header-part: Probe wsa__To
//gsoap ns service method-header-part: Probe wsa__Action
//gsoap ns service method-header-part: Probe wsa__RelatesTo
int d__Hello(struct d__EndpointReferenceType*   wsa__EndpointReference, char *d__Types, char *d__Scopes, char *d__XAddrs, int d__MetadataVersion, void *);

//gsoap ns service method-header-part: Probe wsa__MessageID
//gsoap ns service method-header-part: Probe wsa__To
//gsoap ns service method-header-part: Probe wsa__Action
//gsoap ns service method-header-part: Probe wsa__RelatesTo
int d__Probe(char *d__Types, char *d__Scopes, void *);



//gsoap ns service method-header-part: ProbeMatches wsa__MessageID
//gsoap ns service method-header-part: ProbeMatches wsa__To
//gsoap ns service method-header-part: ProbeMatches wsa__Action
//gsoap ns service method-header-part: ProbeMatches wsa__RelatesTo
int d__ProbeMatches(struct d__ProbeMatchType *d__ProbeMatch, void *);
