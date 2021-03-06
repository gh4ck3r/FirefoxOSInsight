/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_USSDReceivedEventBinding_h__
#define mozilla_dom_USSDReceivedEventBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {

struct USSDReceivedEventDict : public MainThreadDictionaryBase {
  USSDReceivedEventDict() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  nsString mMessage;
  bool mSessionEnded;
private:
  // Disallow copy-construction
  USSDReceivedEventDict(const USSDReceivedEventDict&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid message_id;
  static jsid sessionEnded_id;
};
struct USSDReceivedEventDictInitializer : public USSDReceivedEventDict {
  USSDReceivedEventDictInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_USSDReceivedEventBinding_h__
