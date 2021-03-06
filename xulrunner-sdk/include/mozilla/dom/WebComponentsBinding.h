/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_WebComponentsBinding_h__
#define mozilla_dom_WebComponentsBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {

class LifecycleCreatedCallback;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct LifecycleCallbacks : public MainThreadDictionaryBase {
  LifecycleCallbacks() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  nsRefPtr<LifecycleCreatedCallback> mCreated;
private:
  // Disallow copy-construction
  LifecycleCallbacks(const LifecycleCallbacks&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid created_id;
};
struct LifecycleCallbacksInitializer : public LifecycleCallbacks {
  LifecycleCallbacksInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

struct ElementRegistrationOptions : public MainThreadDictionaryBase {
  ElementRegistrationOptions() :
    mPrototype(nullptr)
  {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  LifecycleCallbacks mLifecycle;
  JSObject* mPrototype;
private:
  // Disallow copy-construction
  ElementRegistrationOptions(const ElementRegistrationOptions&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid lifecycle_id;
  static jsid prototype_id;
};
struct ElementRegistrationOptionsInitializer : public ElementRegistrationOptions {
  ElementRegistrationOptionsInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

class LifecycleCreatedCallback : public CallbackFunction
{
public:
  explicit inline LifecycleCreatedCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline LifecycleCreatedCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, aRv);
  }

  inline void
  Call(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, ErrorResult& aRv);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_WebComponentsBinding_h__
