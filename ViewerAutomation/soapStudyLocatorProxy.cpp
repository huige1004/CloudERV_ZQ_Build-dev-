/* soapStudyLocatorProxy.cpp
   Generated by gSOAP 2.8.17r from ImageViewerAutomation.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapStudyLocatorProxy.h"

StudyLocatorProxy::StudyLocatorProxy()
{	StudyLocatorProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

StudyLocatorProxy::StudyLocatorProxy(const struct soap &_soap) : soap(_soap)
{ }

StudyLocatorProxy::StudyLocatorProxy(const char *url)
{	StudyLocatorProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

StudyLocatorProxy::StudyLocatorProxy(soap_mode iomode)
{	StudyLocatorProxy_init(iomode, iomode);
}

StudyLocatorProxy::StudyLocatorProxy(const char *url, soap_mode iomode)
{	StudyLocatorProxy_init(iomode, iomode);
	soap_endpoint = url;
}

StudyLocatorProxy::StudyLocatorProxy(soap_mode imode, soap_mode omode)
{	StudyLocatorProxy_init(imode, omode);
}

StudyLocatorProxy::~StudyLocatorProxy()
{ }

void StudyLocatorProxy::StudyLocatorProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns3", "http://schemas.microsoft.com/2003/10/Serialization/", NULL, NULL},
	{"ns4", "http://schemas.microsoft.com/2003/10/Serialization/Arrays", NULL, NULL},
	{"ns6", "http://www.Zhoban.com/dicom", NULL, NULL},
	{"ns2", "http://www.Zhoban.com/imageViewer/automation", NULL, NULL},
	{"ns5", "http://www.Zhoban.com/dicom/query", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void StudyLocatorProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void StudyLocatorProxy::reset()
{	destroy();
	soap_done(this);
	soap_initialize(this);
	StudyLocatorProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void StudyLocatorProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *StudyLocatorProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *StudyLocatorProxy::soap_fault()
{	return this->fault;
}

const char *StudyLocatorProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *StudyLocatorProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int StudyLocatorProxy::soap_close_socket()
{	return soap_closesock(this);
}

int StudyLocatorProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void StudyLocatorProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void StudyLocatorProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *StudyLocatorProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int StudyLocatorProxy::StudyQuery(const char *endpoint, const char *soap_action, _ns5__StudyQuery *ns5__StudyQuery, _ns5__StudyQueryResponse *ns5__StudyQueryResponse)
{	struct soap *soap = this;
	struct __ns5__StudyQuery soap_tmp___ns5__StudyQuery;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/StudyQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__StudyQuery.ns5__StudyQuery = ns5__StudyQuery;
	soap_serializeheader(soap);
	soap_serialize___ns5__StudyQuery(soap, &soap_tmp___ns5__StudyQuery);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns5__StudyQuery(soap, &soap_tmp___ns5__StudyQuery, "-ns5:StudyQuery", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns5__StudyQuery(soap, &soap_tmp___ns5__StudyQuery, "-ns5:StudyQuery", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__StudyQueryResponse)
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_get(soap, "ns5:StudyQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::SeriesQuery(const char *endpoint, const char *soap_action, _ns5__SeriesQuery *ns5__SeriesQuery, _ns5__SeriesQueryResponse *ns5__SeriesQueryResponse)
{	struct soap *soap = this;
	struct __ns5__SeriesQuery soap_tmp___ns5__SeriesQuery;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/SeriesQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__SeriesQuery.ns5__SeriesQuery = ns5__SeriesQuery;
	soap_serializeheader(soap);
	soap_serialize___ns5__SeriesQuery(soap, &soap_tmp___ns5__SeriesQuery);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns5__SeriesQuery(soap, &soap_tmp___ns5__SeriesQuery, "-ns5:SeriesQuery", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns5__SeriesQuery(soap, &soap_tmp___ns5__SeriesQuery, "-ns5:SeriesQuery", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__SeriesQueryResponse)
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_get(soap, "ns5:SeriesQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::ImageQuery(const char *endpoint, const char *soap_action, _ns5__ImageQuery *ns5__ImageQuery, _ns5__ImageQueryResponse *ns5__ImageQueryResponse)
{	struct soap *soap = this;
	struct __ns5__ImageQuery soap_tmp___ns5__ImageQuery;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/ImageQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__ImageQuery.ns5__ImageQuery = ns5__ImageQuery;
	soap_serializeheader(soap);
	soap_serialize___ns5__ImageQuery(soap, &soap_tmp___ns5__ImageQuery);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns5__ImageQuery(soap, &soap_tmp___ns5__ImageQuery, "-ns5:ImageQuery", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns5__ImageQuery(soap, &soap_tmp___ns5__ImageQuery, "-ns5:ImageQuery", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__ImageQueryResponse)
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_get(soap, "ns5:ImageQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::StudyQuery_(const char *endpoint, const char *soap_action, _ns5__StudyQuery *ns5__StudyQuery, _ns5__StudyQueryResponse *ns5__StudyQueryResponse)
{	struct soap *soap = this;
	struct __ns5__StudyQuery_ soap_tmp___ns5__StudyQuery_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/StudyQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__StudyQuery_.ns5__StudyQuery = ns5__StudyQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__StudyQuery_(soap, &soap_tmp___ns5__StudyQuery_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__StudyQuery_(soap, &soap_tmp___ns5__StudyQuery_, "-ns5:StudyQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__StudyQuery_(soap, &soap_tmp___ns5__StudyQuery_, "-ns5:StudyQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__StudyQueryResponse)
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_get(soap, "ns5:StudyQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::SeriesQuery_(const char *endpoint, const char *soap_action, _ns5__SeriesQuery *ns5__SeriesQuery, _ns5__SeriesQueryResponse *ns5__SeriesQueryResponse)
{	struct soap *soap = this;
	struct __ns5__SeriesQuery_ soap_tmp___ns5__SeriesQuery_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/SeriesQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__SeriesQuery_.ns5__SeriesQuery = ns5__SeriesQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__SeriesQuery_(soap, &soap_tmp___ns5__SeriesQuery_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__SeriesQuery_(soap, &soap_tmp___ns5__SeriesQuery_, "-ns5:SeriesQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__SeriesQuery_(soap, &soap_tmp___ns5__SeriesQuery_, "-ns5:SeriesQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__SeriesQueryResponse)
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_get(soap, "ns5:SeriesQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::ImageQuery_(const char *endpoint, const char *soap_action, _ns5__ImageQuery *ns5__ImageQuery, _ns5__ImageQueryResponse *ns5__ImageQueryResponse)
{	struct soap *soap = this;
	struct __ns5__ImageQuery_ soap_tmp___ns5__ImageQuery_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/ImageQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__ImageQuery_.ns5__ImageQuery = ns5__ImageQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__ImageQuery_(soap, &soap_tmp___ns5__ImageQuery_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__ImageQuery_(soap, &soap_tmp___ns5__ImageQuery_, "-ns5:ImageQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__ImageQuery_(soap, &soap_tmp___ns5__ImageQuery_, "-ns5:ImageQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__ImageQueryResponse)
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_get(soap, "ns5:ImageQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::StudyQuery__(const char *endpoint, const char *soap_action, _ns5__StudyQuery *ns5__StudyQuery, _ns5__StudyQueryResponse *ns5__StudyQueryResponse)
{	struct soap *soap = this;
	struct __ns5__StudyQuery__ soap_tmp___ns5__StudyQuery__;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/StudyQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__StudyQuery__.ns5__StudyQuery = ns5__StudyQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__StudyQuery__(soap, &soap_tmp___ns5__StudyQuery__);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__StudyQuery__(soap, &soap_tmp___ns5__StudyQuery__, "-ns5:StudyQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__StudyQuery__(soap, &soap_tmp___ns5__StudyQuery__, "-ns5:StudyQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__StudyQueryResponse)
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__StudyQueryResponse->soap_get(soap, "ns5:StudyQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::SeriesQuery__(const char *endpoint, const char *soap_action, _ns5__SeriesQuery *ns5__SeriesQuery, _ns5__SeriesQueryResponse *ns5__SeriesQueryResponse)
{	struct soap *soap = this;
	struct __ns5__SeriesQuery__ soap_tmp___ns5__SeriesQuery__;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/SeriesQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__SeriesQuery__.ns5__SeriesQuery = ns5__SeriesQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__SeriesQuery__(soap, &soap_tmp___ns5__SeriesQuery__);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__SeriesQuery__(soap, &soap_tmp___ns5__SeriesQuery__, "-ns5:SeriesQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__SeriesQuery__(soap, &soap_tmp___ns5__SeriesQuery__, "-ns5:SeriesQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__SeriesQueryResponse)
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__SeriesQueryResponse->soap_get(soap, "ns5:SeriesQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int StudyLocatorProxy::ImageQuery__(const char *endpoint, const char *soap_action, _ns5__ImageQuery *ns5__ImageQuery, _ns5__ImageQueryResponse *ns5__ImageQueryResponse)
{	struct soap *soap = this;
	struct __ns5__ImageQuery__ soap_tmp___ns5__ImageQuery__;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:51124/CloudPACS/ImageViewer/StudyLocator net.pipe://localhost/CloudPACS/ImageViewer/StudyLocator net.tcp://localhost:51125/CloudPACS/ImageViewer/StudyLocator";
	if (soap_action == NULL)
		soap_action = "http://www.Zhoban.com/dicom/query/IStudyRootQuery/ImageQuery";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns5__ImageQuery__.ns5__ImageQuery = ns5__ImageQuery;
	soap_set_version(soap, 0); /* no SOAP */
	soap_serialize___ns5__ImageQuery__(soap, &soap_tmp___ns5__ImageQuery__);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_put___ns5__ImageQuery__(soap, &soap_tmp___ns5__ImageQuery__, "-ns5:ImageQuery", NULL)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	soap->http_content = "text/xml";
	if (soap_connect_command(soap, SOAP_POST_FILE, soap_url(soap, soap_endpoint, soap_action), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_put___ns5__ImageQuery__(soap, &soap_tmp___ns5__ImageQuery__, "-ns5:ImageQuery", NULL)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns5__ImageQueryResponse)
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns5__ImageQueryResponse->soap_get(soap, "ns5:ImageQueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */