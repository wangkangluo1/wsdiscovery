#include <stdio.h>
#include <stdlib.h>
#include <net/if.h>
#include <sys/ioctl.h>

#include "soapStub.h"
#include "wsa.nsmap"
#include "uuid.h"

#define DEV_LOCAL_IP		"192.168.1.248"

char *GetLocalHostIP()
{  
    char *ip=NULL;
    int fd;
    struct ifreq ifr; ///if.h
    struct sockaddr_in *addr = NULL;

    if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0) //socket.h
    {
    	memset(&ifr, 0, sizeof(ifr));
    	
    	strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);
    	
    	if(ioctl(fd, SIOCGIFADDR, &ifr) == -1) {
    		perror("ioctl error");
    	}
    	
    	addr = (struct sockaddr_in *)&(ifr.ifr_addr);
    	ip = inet_ntoa(addr->sin_addr);
      
      close (fd);
    }
    
    return ip;
}

int SetLocalHostIP(const char *pszIP)
{  
    char *ip=NULL;
    int fd;
    struct ifreq ifr; ///if.h
    struct sockaddr_in sin;

    if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0) //socket.h
    {
    	memset(&ifr, 0, sizeof(ifr));
    	
    	strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);
    	
    	memset(&sin, 0, sizeof(sin));
    	sin.sin_family = AF_INET;
    	sin.sin_addr.s_addr = inet_addr(pszIP);
    	
    	memcpy(&ifr.ifr_addr, &sin, sizeof(sin));
    	
    	if(ioctl(fd, SIOCSIFADDR, &ifr) < 0) {
    		perror("ioctl error");
    	}
      
      close (fd);
    }
    
    return 0;
}

int SetIPConf(const char *pszIP, const char *pszMask, const char *pszGateway)
{
	int fd = 0;
	
	fd = open("/etc/network/interfaces", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP);
	if(fd < 0){
		perror("open file:");
		return -1;
	}
	
	char szBuf[1024] = {0};
	
	snprintf(szBuf, sizeof(szBuf), "# Configure Loopback\nauto lo\niface lo inet loopback\n\n\nauto eth0\niface eth0 inet static\naddress %s\nnetmask %s\ngateway %s\n",
						pszIP, pszMask, pszGateway);
						
	int nBufLen = 0;
	int nRet = 0;
	
	nBufLen = strlen(szBuf);
	
	nRet = write(fd, szBuf, nBufLen);
	if (nBufLen != nRet) {
		perror("write ip interfaces failed:");
		return -2;
	}
	
	close(fd);
	
	return 0;
}

int NotifyHello()
{
	
	return 0;
}

int main(int argc, char **argv)
{
   struct soap soap;
   struct ip_mreq mcast;

   soap_init1(&soap, SOAP_IO_UDP);    
   if (!soap_valid_socket(soap_bind(&soap, NULL, 3702, 100))) {
      soap_print_fault(&soap, stderr);
      exit(1);
   }
   mcast.imr_multiaddr.s_addr = inet_addr("239.255.255.250");
   mcast.imr_interface.s_addr = htonl(INADDR_ANY);
   if (setsockopt(soap.master, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mcast, sizeof(mcast))<0) {
  	printf("Setsockopt failed.\n");
  }

  struct Namespace namespaces[] =
	{   // {"ns-prefix", "ns-name"}
   {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope"}, // MUST be first
   {"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding"},
   {"xsi", "http://www.w3.org/2001/XMLSchema-instance"},
   {"xsd", "http://www.w3.org/2001/XMLSchema"},
   {"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing"},
   {"d", "http://schemas.xmlsoap.org/ws/2005/04/discovery"},
   {"d3", "http://www.onvif.org/ver10/network/wsdl/RemoteDiscoveryBinding"}, 
   {"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing"}, 
   {"d4", "http://www.onvif.org/ver10/network/wsdl/DiscoveryLookupBinding"},
   {"dn", "http://www.onvif.org/ver10/network/wsdl"}, // given by the service description
   {NULL, NULL} // end of table
	}; 

  soap_set_namespaces(&soap, namespaces);
  
   for (;;)
   {
      if (soap_serve(&soap))
         soap_print_fault(&soap, stderr); // report the problem
      soap_destroy(&soap);
      soap_end(&soap);
   }
   
   soap_done(&soap); // close connection
   
   return 0;
}

int d__Probe(struct soap *soap, char *d__Types, char *d__Scopes)
{
  struct Namespace namespaces[] =
	{   // {"ns-prefix", "ns-name"}
   {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope"}, // MUST be first
   {"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing"},
   {"d", "http://schemas.xmlsoap.org/ws/2005/04/discovery"},
   {"dn", "http://www.onvif.org/ver10/network/wsdl"}, // given by the service description
   {NULL, NULL} // end of table
	}; 
	 
	 // Get UUID
	 uuid_t uuid;
	 char szUuid[36] = {0};
	
	 uuid_generate_time(uuid);
	 
	 uuid_unparse(uuid, szUuid);
	 
	 
	 
	struct soap RetSoap;
	struct SOAP_ENV__Header header; // the SOAP Header

	soap_init(&RetSoap);
	RetSoap.send_timeout = 1; // 1s timeout
	RetSoap.recv_timeout = 1; // 1s timeout

	soap_set_namespaces(&RetSoap, namespaces);
	
	char *pszMsgID = (char *)soap_malloc(&RetSoap, 50);
	snprintf(pszMsgID, 50, "uuid:%s", szUuid);
	
	soap_default_SOAP_ENV__Header(&RetSoap, &header); // init SOAP Header
  header.wsa__To        = "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous";
  header.wsa__MessageID = pszMsgID ;
  header.wsa__Action    = "http://schemas.xmlsoap.org/ws/2005/04/discovery/ProbeMatches";
  header.wsa__RelatesTo = (struct wsa__Relationship*)soap_malloc(&RetSoap, sizeof(struct wsa__Relationship));
  header.wsa__RelatesTo->__item = soap->header->wsa__MessageID;
  
  RetSoap.header = &header;
	 	
	struct d__ProbeMatchType r;
	struct d__EndpointReferenceType ed;
	char szID[100] = {0};
	
	memset(&ed, sizeof(ed), 0);
	
	uuid_generate_time(uuid);
	uuid_unparse(uuid, szUuid);
	 
	 snprintf(szID, sizeof(szID), "urn:uuid:%s", szUuid);
	 
	 char szIP[16] = {0};
	 char *pszTmp = NULL;
	 
	 pszTmp = GetLocalHostIP();
	 
	 snprintf(szIP, sizeof(szIP), "%s", pszTmp);
	 
	 char szAddr[50] = {0};
	 snprintf(szAddr, sizeof(szAddr), "http://%s:8800", szIP);
	 
		ed.wsa__Address = szID;
		r.wsa__EndpointReference = &ed;
		r.d__Types = "dn:NetworkVideoTransmitter";
		r.d__Scopes = "onvif://www.onvif.org/type/video_encoder onvif://www.onvif.org/hardware/HUNDAIPC-100 onvif://www.onvif.org/name/hunda onvif://www.onvif.org/location/country/china onvif://www.onvif.org/location/city/shanghai";
		r.d__XAddrs = szAddr;
		r.d__MetadataVersion = 75965;
		
		char szEndpoint[100] = {0};
		
		snprintf(szEndpoint, sizeof(szEndpoint), "soap.udp://%s:%d", inet_ntoa(soap->peer.sin_addr), ntohs(soap->peer.sin_port));
		
		usleep(200);
		
	// Send and receive messages over UDP:
	if (soap_send_d__ProbeMatches(&RetSoap, szEndpoint, NULL, &r))
	{
	      soap_print_fault(&RetSoap, stderr);
	}

	soap_destroy(&RetSoap); // cleanup
	soap_end(&RetSoap); // cleanup
	soap_done(&RetSoap); // close connection (should not use soap struct after this) 
	
	return SOAP_OK;
}

int d__ProbeMatches(struct soap *soap, struct d__ProbeMatchType *d__ProbeMatch)
{
	
	return SOAP_OK;
}

