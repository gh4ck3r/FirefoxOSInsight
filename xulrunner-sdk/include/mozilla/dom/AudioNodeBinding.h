/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_AudioNodeBinding_h__
#define mozilla_dom_AudioNodeBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {

class AudioNode;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::AudioNode>
{
  enum
  {
    Depth = 1
  };
  typedef mozilla::dom::AudioNode NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::AudioNode>
{
  enum
  {
    PrototypeID = prototypes::id::AudioNode
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {


MOZ_BEGIN_ENUM_CLASS(ChannelCountMode, uint32_t)
  Max,
  Clamped_max,
  Explicit
MOZ_END_ENUM_CLASS(ChannelCountMode)

namespace ChannelCountModeValues {
extern const EnumEntry strings[4];
} // namespace ChannelCountModeValues



MOZ_BEGIN_ENUM_CLASS(ChannelInterpretation, uint32_t)
  Speakers,
  Discrete
MOZ_END_ENUM_CLASS(ChannelInterpretation)

namespace ChannelInterpretationValues {
extern const EnumEntry strings[3];
} // namespace ChannelInterpretationValues


namespace AudioNodeBinding {

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
    if (!protoAndIfaceArray[prototypes::id::AudioNode]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[prototypes::id::AudioNode]);
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
    if (!protoAndIfaceArray[constructors::id::AudioNode]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /* The object might _still_ be null, but that's OK */
    return JS::Handle<JSObject*>::fromMarkedLocation(&protoAndIfaceArray[constructors::id::AudioNode]);
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  bool
  PrefEnabled();

} // namespace AudioNodeBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_AudioNodeBinding_h__
