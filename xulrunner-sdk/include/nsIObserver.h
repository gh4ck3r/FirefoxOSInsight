/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_l64_bld-000000000/build/xpcom/ds/nsIObserver.idl
 */

#ifndef __gen_nsIObserver_h__
#define __gen_nsIObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIObserver */
#define NS_IOBSERVER_IID_STR "db242e01-e4d9-11d2-9dde-000064657374"

#define NS_IOBSERVER_IID \
  {0xdb242e01, 0xe4d9, 0x11d2, \
    { 0x9d, 0xde, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE nsIObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBSERVER_IID)

  /* void observe (in nsISupports aSubject, in string aTopic, in wstring aData); */
  NS_IMETHOD Observe(nsISupports *aSubject, const char * aTopic, const PRUnichar * aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObserver, NS_IOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBSERVER \
  NS_IMETHOD Observe(nsISupports *aSubject, const char * aTopic, const PRUnichar * aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBSERVER(_to) \
  NS_IMETHOD Observe(nsISupports *aSubject, const char * aTopic, const PRUnichar * aData) { return _to Observe(aSubject, aTopic, aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBSERVER(_to) \
  NS_IMETHOD Observe(nsISupports *aSubject, const char * aTopic, const PRUnichar * aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->Observe(aSubject, aTopic, aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObserver : public nsIObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBSERVER

  nsObserver();

private:
  ~nsObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObserver, nsIObserver)

nsObserver::nsObserver()
{
  /* member initializers and constructor code */
}

nsObserver::~nsObserver()
{
  /* destructor code */
}

/* void observe (in nsISupports aSubject, in string aTopic, in wstring aData); */
NS_IMETHODIMP nsObserver::Observe(nsISupports *aSubject, const char * aTopic, const PRUnichar * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIObserver_h__ */
