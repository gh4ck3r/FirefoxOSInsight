/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_MouseEventBinding_h__
#define mozilla_dom_MouseEventBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "mozilla/dom/EventTarget.h"
#include "mozilla/dom/workers/bindings/EventTarget.h"
#include "nsIDOMWindow.h"

class nsDOMMouseEvent;

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::MouseEvent>
{
  enum
  {
    Depth = 2
  };
  typedef nsDOMMouseEvent NativeType;
};
template <>
struct PrototypeIDMap<nsDOMMouseEvent>
{
  enum
  {
    PrototypeID = prototypes::id::MouseEvent
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct MouseEventInit : public MainThreadDictionaryBase {
  MouseEventInit() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  bool mAltKey;
  bool mBubbles;
  uint16_t mButton;
  uint16_t mButtons;
  bool mCancelable;
  int32_t mClientX;
  int32_t mClientY;
  bool mCtrlKey;
  int32_t mDetail;
  bool mMetaKey;
  nsRefPtr<mozilla::dom::EventTarget> mRelatedTarget;
  int32_t mScreenX;
  int32_t mScreenY;
  bool mShiftKey;
  nsRefPtr<nsIDOMWindow> mView;
private:
  // Disallow copy-construction
  MouseEventInit(const MouseEventInit&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid altKey_id;
  static jsid bubbles_id;
  static jsid button_id;
  static jsid buttons_id;
  static jsid cancelable_id;
  static jsid clientX_id;
  static jsid clientY_id;
  static jsid ctrlKey_id;
  static jsid detail_id;
  static jsid metaKey_id;
  static jsid relatedTarget_id;
  static jsid screenX_id;
  static jsid screenY_id;
  static jsid shiftKey_id;
  static jsid view_id;
};
struct MouseEventInitInitializer : public MouseEventInit {
  MouseEventInitInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

namespace MouseEventBinding {

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
    if (!protoAndIfaceArray[prototypes::id::MouseEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::MouseEvent]);
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
    if (!protoAndIfaceArray[constructors::id::MouseEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::MouseEvent]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, nsDOMMouseEvent* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace MouseEventBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_MouseEventBinding_h__