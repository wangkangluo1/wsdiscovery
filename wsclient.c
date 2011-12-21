#include <stdio.h>
#include <stdlib.h>

//#include "/home/hunda/gsoap-2.8/gsoap/import/wsa.h"
#include "soapStub.h"
#include "wsa.nsmap"
#include "../uuid/uuid.h"

int main(int argc, char **argv)
{
int result = -1;
int id_count = 1;

struct Namespace namespaces[] =
{   // {"ns-prefix", "ns-name"}
   {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope"}, // MUST be first
   {"d", "http://schemas.xmlsoap.org/ws/2005/04/discovery"}, 
   {"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing"}, 
   {"dn", "http://www.onvif.org/ver10/network/wsdl"}, // given by the service description
   {NULL, NULL} // end of table
}; 
	 
	 // Get UUID
	 uuid_t uuid;
	 char szUuid[36] = {0};
	 char szMsgID[50] = {0};
	 
	 uuid_generate_time(uuid);
	 
	 uuid_unparse(uuid, szUuid);
	 
	 snprintf(szMsgID, sizeof(szMsgID), "uuid:%s", szUuid);
	 
struct soap soap;
struct SOAP_ENV__Header header; // the SOAP Header

soap_init(&soap);
soap.send_timeout = 1; // 1s timeout
soap.recv_timeout = 1; // 1s timeout

soap_set_namespaces(&soap, namespaces);

soap_default_SOAP_ENV__Header(&soap, &header); // init SOAP Header
header.wsa__MessageID = szMsgID;
header.wsa__To = "urn:schemas-xmlsoap-org:ws:2005:04:discovery";
header.wsa__Action = "http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe";

soap.header = &header;

struct d__ProbeMatchType r;
// Send and receive messages over UDP:
if (soap_send_d__Probe(&soap, "soap.udp://239.255.255.250:3702", NULL, "", ""))
{
      soap_print_fault(&soap, stderr);
}

// Send and receive messages over UDP:
if (soap_send_d__ProbeMatches(&soap, "soap.udp://239.255.255.250:3702", NULL, NULL))
{
      soap_print_fault(&soap, stderr);
}

soap_destroy(&soap); // cleanup
soap_end(&soap); // cleanup
soap_done(&soap); // close connection (should not use soap struct after this) 

return 0;
}
