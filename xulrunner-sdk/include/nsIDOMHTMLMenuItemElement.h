/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/rel-m-rel-xr_lx_bld-0000000000/build/dom/interfaces/html/nsIDOMHTMLMenuItemElement.idl
 */

#ifndef __gen_nsIDOMHTMLMenuItemElement_h__
#define __gen_nsIDOMHTMLMenuItemElement_h__


#ifndef __gen_nsIDOMHTMLCommandElement_h__
#include "nsIDOMHTMLCommandElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMenuItemElement */
#define NS_IDOMHTMLMENUITEMELEMENT_IID_STR "7f449325-b250-478a-bd2c-d0986256763e"

#define NS_IDOMHTMLMENUITEMELEMENT_IID \
  {0x7f449325, 0xb250, 0x478a, \
    { 0xbd, 0x2c, 0xd0, 0x98, 0x62, 0x56, 0x76, 0x3e }}

class NS_NO_VTABLE nsIDOMHTMLMenuItemElement : public nsIDOMHTMLCommandElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMENUITEMELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMenuItemElement, NS_IDOMHTMLMENUITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMENUITEMELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMENUITEMELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMENUITEMELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMenuItemElement : public nsIDOMHTMLMenuItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMENUITEMELEMENT

  nsDOMHTMLMenuItemElement();

private:
  ~nsDOMHTMLMenuItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMenuItemElement, nsIDOMHTMLMenuItemElement)

nsDOMHTMLMenuItemElement::nsDOMHTMLMenuItemElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMenuItemElement::~nsDOMHTMLMenuItemElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMenuItemElement_h__ */
