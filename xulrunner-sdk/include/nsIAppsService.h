/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_lx_bld-0000000000/build/dom/interfaces/apps/nsIAppsService.idl
 */

#ifndef __gen_nsIAppsService_h__
#define __gen_nsIAppsService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIDOMApplication; /* forward declaration */

class mozIApplication; /* forward declaration */

#define APPS_SERVICE_CID { 0x05072afa, 0x92fe, 0x45bf, { 0xae, 0x22, 0x39, 0xb6, 0x9c, 0x11, 0x70, 0x58 } }
#define APPS_SERVICE_CONTRACTID "@mozilla.org/AppsService;1"

/* starting interface:    nsIAppsService */
#define NS_IAPPSSERVICE_IID_STR "1113c6e3-28a2-4315-be10-8b3230eecc0f"

#define NS_IAPPSSERVICE_IID \
  {0x1113c6e3, 0x28a2, 0x4315, \
    { 0xbe, 0x10, 0x8b, 0x32, 0x30, 0xee, 0xcc, 0x0f }}

class NS_NO_VTABLE nsIAppsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSSERVICE_IID)

  /* mozIDOMApplication getAppByManifestURL (in DOMString manifestURL); */
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIDOMApplication * *_retval) = 0;

  /* unsigned long getAppLocalIdByManifestURL (in DOMString manifestURL); */
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) = 0;

  /* mozIDOMApplication getAppByLocalId (in unsigned long localId); */
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIDOMApplication * *_retval) = 0;

  /* DOMString getManifestURLByLocalId (in unsigned long localId); */
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) = 0;

  /* mozIApplication getAppFromObserverMessage (in DOMString message); */
  NS_IMETHOD GetAppFromObserverMessage(const nsAString & message, mozIApplication * *_retval) = 0;

  /* DOMString getCSPByLocalId (in unsigned long localId); */
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) = 0;

  /* DOMString getCoreAppsBasePath (); */
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) = 0;

  /* DOMString getWebAppsBasePath (); */
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) = 0;

  /* jsval getAppInfo (in DOMString appId); */
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::Value *_retval) = 0;

  /* DOMString getAppLocalIdByStoreId (in DOMString storeID); */
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppsService, NS_IAPPSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSSERVICE \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIDOMApplication * *_retval); \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval); \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIDOMApplication * *_retval); \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval); \
  NS_IMETHOD GetAppFromObserverMessage(const nsAString & message, mozIApplication * *_retval); \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval); \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval); \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval); \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::Value *_retval); \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSSERVICE(_to) \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIDOMApplication * *_retval) { return _to GetAppByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) { return _to GetAppLocalIdByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIDOMApplication * *_retval) { return _to GetAppByLocalId(localId, _retval); } \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) { return _to GetManifestURLByLocalId(localId, _retval); } \
  NS_IMETHOD GetAppFromObserverMessage(const nsAString & message, mozIApplication * *_retval) { return _to GetAppFromObserverMessage(message, _retval); } \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) { return _to GetCSPByLocalId(localId, _retval); } \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) { return _to GetCoreAppsBasePath(_retval); } \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) { return _to GetWebAppsBasePath(_retval); } \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::Value *_retval) { return _to GetAppInfo(appId, _retval); } \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) { return _to GetAppLocalIdByStoreId(storeID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSSERVICE(_to) \
  NS_IMETHOD GetAppByManifestURL(const nsAString & manifestURL, mozIDOMApplication * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppLocalIdByManifestURL(manifestURL, _retval); } \
  NS_IMETHOD GetAppByLocalId(uint32_t localId, mozIDOMApplication * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppByLocalId(localId, _retval); } \
  NS_IMETHOD GetManifestURLByLocalId(uint32_t localId, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURLByLocalId(localId, _retval); } \
  NS_IMETHOD GetAppFromObserverMessage(const nsAString & message, mozIApplication * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppFromObserverMessage(message, _retval); } \
  NS_IMETHOD GetCSPByLocalId(uint32_t localId, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSPByLocalId(localId, _retval); } \
  NS_IMETHOD GetCoreAppsBasePath(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoreAppsBasePath(_retval); } \
  NS_IMETHOD GetWebAppsBasePath(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebAppsBasePath(_retval); } \
  NS_IMETHOD GetAppInfo(const nsAString & appId, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppInfo(appId, _retval); } \
  NS_IMETHOD GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppLocalIdByStoreId(storeID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppsService : public nsIAppsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSSERVICE

  nsAppsService();

private:
  ~nsAppsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppsService, nsIAppsService)

nsAppsService::nsAppsService()
{
  /* member initializers and constructor code */
}

nsAppsService::~nsAppsService()
{
  /* destructor code */
}

/* mozIDOMApplication getAppByManifestURL (in DOMString manifestURL); */
NS_IMETHODIMP nsAppsService::GetAppByManifestURL(const nsAString & manifestURL, mozIDOMApplication * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAppLocalIdByManifestURL (in DOMString manifestURL); */
NS_IMETHODIMP nsAppsService::GetAppLocalIdByManifestURL(const nsAString & manifestURL, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIDOMApplication getAppByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetAppByLocalId(uint32_t localId, mozIDOMApplication * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getManifestURLByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetManifestURLByLocalId(uint32_t localId, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIApplication getAppFromObserverMessage (in DOMString message); */
NS_IMETHODIMP nsAppsService::GetAppFromObserverMessage(const nsAString & message, mozIApplication * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getCSPByLocalId (in unsigned long localId); */
NS_IMETHODIMP nsAppsService::GetCSPByLocalId(uint32_t localId, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getCoreAppsBasePath (); */
NS_IMETHODIMP nsAppsService::GetCoreAppsBasePath(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWebAppsBasePath (); */
NS_IMETHODIMP nsAppsService::GetWebAppsBasePath(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getAppInfo (in DOMString appId); */
NS_IMETHODIMP nsAppsService::GetAppInfo(const nsAString & appId, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAppLocalIdByStoreId (in DOMString storeID); */
NS_IMETHODIMP nsAppsService::GetAppLocalIdByStoreId(const nsAString & storeID, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppsService_h__ */
