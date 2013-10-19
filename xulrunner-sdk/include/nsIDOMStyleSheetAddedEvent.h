/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_lx_bld-0000000000/build/dom/interfaces/events/nsIDOMStyleSheetAddedEvent.idl
 */

#ifndef __gen_nsIDOMStyleSheetAddedEvent_h__
#define __gen_nsIDOMStyleSheetAddedEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    nsIDOMStyleSheetAddedEvent */
#define NS_IDOMSTYLESHEETADDEDEVENT_IID_STR "05a78874-43d7-459d-be32-ba9271527153"

#define NS_IDOMSTYLESHEETADDEDEVENT_IID \
  {0x05a78874, 0x43d7, 0x459d, \
    { 0xbe, 0x32, 0xba, 0x92, 0x71, 0x52, 0x71, 0x53 }}

class NS_NO_VTABLE nsIDOMStyleSheetAddedEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLESHEETADDEDEVENT_IID)

  /* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) = 0;

  /* readonly attribute boolean documentSheet; */
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) = 0;

  /* [noscript] void initStyleSheetAddedEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
  NS_IMETHOD InitStyleSheetAddedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleSheetAddedEvent, NS_IDOMSTYLESHEETADDEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLESHEETADDEDEVENT \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet); \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet); \
  NS_IMETHOD InitStyleSheetAddedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLESHEETADDEDEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return _to GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetAddedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return _to InitStyleSheetAddedEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLESHEETADDEDEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetAddedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStyleSheetAddedEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleSheetAddedEvent : public nsIDOMStyleSheetAddedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLESHEETADDEDEVENT

  nsDOMStyleSheetAddedEvent();

private:
  ~nsDOMStyleSheetAddedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStyleSheetAddedEvent, nsIDOMStyleSheetAddedEvent)

nsDOMStyleSheetAddedEvent::nsDOMStyleSheetAddedEvent()
{
  /* member initializers and constructor code */
}

nsDOMStyleSheetAddedEvent::~nsDOMStyleSheetAddedEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
NS_IMETHODIMP nsDOMStyleSheetAddedEvent::GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentSheet; */
NS_IMETHODIMP nsDOMStyleSheetAddedEvent::GetDocumentSheet(bool *aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initStyleSheetAddedEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
NS_IMETHODIMP nsDOMStyleSheetAddedEvent::InitStyleSheetAddedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleSheetAddedEvent_h__ */
