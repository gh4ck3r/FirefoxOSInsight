/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_EventBinding_h__
#define mozilla_dom_EventBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

class nsDOMEvent;

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::Event>
{
  enum
  {
    Depth = 0
  };
  typedef nsDOMEvent NativeType;
};
template <>
struct PrototypeIDMap<nsDOMEvent>
{
  enum
  {
    PrototypeID = prototypes::id::Event
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct EventInit : public MainThreadDictionaryBase {
  EventInit() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  bool mBubbles;
  bool mCancelable;
private:
  // Disallow copy-construction
  EventInit(const EventInit&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid bubbles_id;
  static jsid cancelable_id;
};
struct EventInitInitializer : public EventInit {
  EventInitInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

namespace EventBinding {

  extern const NativePropertyHooks sNativePropertyHooks;

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JSObject** protoAndIfaceArray);

  inline JS::Handle<JSObject*> GetProtoObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface prototype object for this class.  This will create the
       object as needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JSObject** protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[prototypes::id::Event]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::Event]);
  }

  inline JS::Handle<JSObject*> GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface object for this class.  This will create the object as
       needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JSObject** protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[constructors::id::Event]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::Event]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, nsDOMEvent* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace EventBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_EventBinding_h__
