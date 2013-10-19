/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_lx_bld-0000000000/build/dom/network/interfaces/nsITCPSocketChild.idl
 */

#ifndef __gen_nsITCPSocketChild_h__
#define __gen_nsITCPSocketChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITCPSocketInternal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsITCPSocketChild */
#define NS_ITCPSOCKETCHILD_IID_STR "bdc91763-e9a1-4122-9c2f-8f17505c8c7a"

#define NS_ITCPSOCKETCHILD_IID \
  {0xbdc91763, 0xe9a1, 0x4122, \
    { 0x9c, 0x2f, 0x8f, 0x17, 0x50, 0x5c, 0x8c, 0x7a }}

class NS_NO_VTABLE nsITCPSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETCHILD_IID)

  /* [implicit_jscontext] void open (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval socketVal); */
  NS_IMETHOD Open(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, const JS::Value & socketVal, JSContext* cx) = 0;

  /* [implicit_jscontext] void send (in jsval data, in unsigned long byteOffset, in unsigned long byteLength); */
  NS_IMETHOD Send(const JS::Value & data, uint32_t byteOffset, uint32_t byteLength, JSContext* cx) = 0;

  /* void resume (); */
  NS_IMETHOD Resume(void) = 0;

  /* void suspend (); */
  NS_IMETHOD Suspend(void) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketChild, NS_ITCPSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETCHILD \
  NS_IMETHOD Open(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, const JS::Value & socketVal, JSContext* cx); \
  NS_IMETHOD Send(const JS::Value & data, uint32_t byteOffset, uint32_t byteLength, JSContext* cx); \
  NS_IMETHOD Resume(void); \
  NS_IMETHOD Suspend(void); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD Open(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, const JS::Value & socketVal, JSContext* cx) { return _to Open(socket, host, port, ssl, binaryType, window, socketVal, cx); } \
  NS_IMETHOD Send(const JS::Value & data, uint32_t byteOffset, uint32_t byteLength, JSContext* cx) { return _to Send(data, byteOffset, byteLength, cx); } \
  NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_IMETHOD Suspend(void) { return _to Suspend(); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD Open(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, const JS::Value & socketVal, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(socket, host, port, ssl, binaryType, window, socketVal, cx); } \
  NS_IMETHOD Send(const JS::Value & data, uint32_t byteOffset, uint32_t byteLength, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(data, byteOffset, byteLength, cx); } \
  NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_IMETHOD Suspend(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suspend(); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketChild : public nsITCPSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETCHILD

  nsTCPSocketChild();

private:
  ~nsTCPSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketChild, nsITCPSocketChild)

nsTCPSocketChild::nsTCPSocketChild()
{
  /* member initializers and constructor code */
}

nsTCPSocketChild::~nsTCPSocketChild()
{
  /* destructor code */
}

/* [implicit_jscontext] void open (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval socketVal); */
NS_IMETHODIMP nsTCPSocketChild::Open(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, const JS::Value & socketVal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void send (in jsval data, in unsigned long byteOffset, in unsigned long byteLength); */
NS_IMETHODIMP nsTCPSocketChild::Send(const JS::Value & data, uint32_t byteOffset, uint32_t byteLength, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsTCPSocketChild::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspend (); */
NS_IMETHODIMP nsTCPSocketChild::Suspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsTCPSocketChild::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketChild_h__ */
