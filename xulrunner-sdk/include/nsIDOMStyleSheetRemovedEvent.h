/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_lx_bld-0000000000/build/dom/interfaces/events/nsIDOMStyleSheetRemovedEvent.idl
 */

#ifndef __gen_nsIDOMStyleSheetRemovedEvent_h__
#define __gen_nsIDOMStyleSheetRemovedEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    nsIDOMStyleSheetRemovedEvent */
#define NS_IDOMSTYLESHEETREMOVEDEVENT_IID_STR "76a7afe1-5b7b-48ee-aef0-7e89b5b0b8e6"

#define NS_IDOMSTYLESHEETREMOVEDEVENT_IID \
  {0x76a7afe1, 0x5b7b, 0x48ee, \
    { 0xae, 0xf0, 0x7e, 0x89, 0xb5, 0xb0, 0xb8, 0xe6 }}

class NS_NO_VTABLE nsIDOMStyleSheetRemovedEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLESHEETREMOVEDEVENT_IID)

  /* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) = 0;

  /* readonly attribute boolean documentSheet; */
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) = 0;

  /* [noscript] void initStyleSheetRemovedEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
  NS_IMETHOD InitStyleSheetRemovedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleSheetRemovedEvent, NS_IDOMSTYLESHEETREMOVEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLESHEETREMOVEDEVENT \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet); \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet); \
  NS_IMETHOD InitStyleSheetRemovedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLESHEETREMOVEDEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return _to GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetRemovedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return _to InitStyleSheetRemovedEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLESHEETREMOVEDEVENT(_to) \
  NS_IMETHOD GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD GetDocumentSheet(bool *aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentSheet(aDocumentSheet); } \
  NS_IMETHOD InitStyleSheetRemovedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStyleSheetRemovedEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aStyleSheet, aDocumentSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleSheetRemovedEvent : public nsIDOMStyleSheetRemovedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLESHEETREMOVEDEVENT

  nsDOMStyleSheetRemovedEvent();

private:
  ~nsDOMStyleSheetRemovedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStyleSheetRemovedEvent, nsIDOMStyleSheetRemovedEvent)

nsDOMStyleSheetRemovedEvent::nsDOMStyleSheetRemovedEvent()
{
  /* member initializers and constructor code */
}

nsDOMStyleSheetRemovedEvent::~nsDOMStyleSheetRemovedEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleSheet stylesheet; */
NS_IMETHODIMP nsDOMStyleSheetRemovedEvent::GetStylesheet(nsIDOMCSSStyleSheet * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentSheet; */
NS_IMETHODIMP nsDOMStyleSheetRemovedEvent::GetDocumentSheet(bool *aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initStyleSheetRemovedEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in nsIDOMCSSStyleSheet aStyleSheet, in boolean aDocumentSheet); */
NS_IMETHODIMP nsDOMStyleSheetRemovedEvent::InitStyleSheetRemovedEvent(const nsAString & aTypeArg, bool aCanBubbleArg, bool aCancelableArg, nsIDOMCSSStyleSheet *aStyleSheet, bool aDocumentSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleSheetRemovedEvent_h__ */
