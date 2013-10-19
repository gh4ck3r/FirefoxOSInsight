/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_BlobBinding_h__
#define mozilla_dom_BlobBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {


MOZ_BEGIN_ENUM_CLASS(EndingTypes, uint32_t)
  Transparent,
  Native
MOZ_END_ENUM_CLASS(EndingTypes)

namespace EndingTypesValues {
extern const EnumEntry strings[3];
} // namespace EndingTypesValues


struct BlobPropertyBagWorkers : public DictionaryBase {
  BlobPropertyBagWorkers() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  EndingTypes mEndings;
  nsString mType;
private:
  // Disallow copy-construction
  BlobPropertyBagWorkers(const BlobPropertyBagWorkers&) MOZ_DELETE;
  static jsid endings_id;
  static jsid type_id;
};
struct BlobPropertyBagWorkersInitializer : public BlobPropertyBagWorkers {
  BlobPropertyBagWorkersInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

struct BlobPropertyBag : public MainThreadDictionaryBase {
  BlobPropertyBag() {}
  bool Init(JSContext* cx, JS::Handle<JS::Value> val);
  bool Init(const nsAString& aJSON);
  bool ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::Value *vp) const;
  void TraceDictionary(JSTracer* trc);

  EndingTypes mEndings;
  nsString mType;
private:
  // Disallow copy-construction
  BlobPropertyBag(const BlobPropertyBag&) MOZ_DELETE;
  static bool InitIds(JSContext* cx);
  static bool initedIds;
  static jsid endings_id;
  static jsid type_id;
};
struct BlobPropertyBagInitializer : public BlobPropertyBag {
  BlobPropertyBagInitializer() {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_BlobBinding_h__
