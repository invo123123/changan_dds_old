// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Basic_ConvoyFun.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Basic_5fConvoyFun_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Basic_5fConvoyFun_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Basic_5fConvoyFun_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Basic_5fConvoyFun_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Basic_5fConvoyFun_2eproto;
namespace Soa {
class PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg;
struct PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_MsgDefaultTypeInternal;
extern PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_MsgDefaultTypeInternal _PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg_default_instance_;
}  // namespace Soa
PROTOBUF_NAMESPACE_OPEN
template<> ::Soa::PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* Arena::CreateMaybeMessage<::Soa::PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Soa {

// ===================================================================

class PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg) */ {
 public:
  inline PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg() : PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg(nullptr) {}
  ~PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg() override;
  explicit constexpr PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg(const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& from);
  PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg&& from) noexcept
    : PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg() {
    *this = ::std::move(from);
  }

  inline PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& operator=(const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& from) {
    CopyFrom(from);
    return *this;
  }
  inline PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& operator=(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& default_instance() {
    return *internal_default_instance();
  }
  static inline const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* internal_default_instance() {
    return reinterpret_cast<const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg*>(
               &_PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& a, PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& b) {
    a.Swap(&b);
  }
  inline void Swap(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg";
  }
  protected:
  explicit PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 3,
    kCrcFieldNumber = 1,
    kCounterFieldNumber = 2,
  };
  // .Soa.PB_DDSData_Msg message = 3;
  bool has_message() const;
  private:
  bool _internal_has_message() const;
  public:
  void clear_message();
  const ::Soa::PB_DDSData_Msg& message() const;
  PROTOBUF_NODISCARD ::Soa::PB_DDSData_Msg* release_message();
  ::Soa::PB_DDSData_Msg* mutable_message();
  void set_allocated_message(::Soa::PB_DDSData_Msg* message);
  private:
  const ::Soa::PB_DDSData_Msg& _internal_message() const;
  ::Soa::PB_DDSData_Msg* _internal_mutable_message();
  public:
  void unsafe_arena_set_allocated_message(
      ::Soa::PB_DDSData_Msg* message);
  ::Soa::PB_DDSData_Msg* unsafe_arena_release_message();

  // uint32 crc = 1;
  void clear_crc();
  uint32_t crc() const;
  void set_crc(uint32_t value);
  private:
  uint32_t _internal_crc() const;
  void _internal_set_crc(uint32_t value);
  public:

  // uint32 counter = 2;
  void clear_counter();
  uint32_t counter() const;
  void set_counter(uint32_t value);
  private:
  uint32_t _internal_counter() const;
  void _internal_set_counter(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::Soa::PB_DDSData_Msg* message_;
  uint32_t crc_;
  uint32_t counter_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Basic_5fConvoyFun_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg

// uint32 crc = 1;
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::clear_crc() {
  crc_ = 0u;
}
inline uint32_t PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_crc() const {
  return crc_;
}
inline uint32_t PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::crc() const {
  // @@protoc_insertion_point(field_get:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.crc)
  return _internal_crc();
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_set_crc(uint32_t value) {
  
  crc_ = value;
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::set_crc(uint32_t value) {
  _internal_set_crc(value);
  // @@protoc_insertion_point(field_set:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.crc)
}

// uint32 counter = 2;
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::clear_counter() {
  counter_ = 0u;
}
inline uint32_t PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_counter() const {
  return counter_;
}
inline uint32_t PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::counter() const {
  // @@protoc_insertion_point(field_get:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.counter)
  return _internal_counter();
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_set_counter(uint32_t value) {
  
  counter_ = value;
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::set_counter(uint32_t value) {
  _internal_set_counter(value);
  // @@protoc_insertion_point(field_set:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.counter)
}

// .Soa.PB_DDSData_Msg message = 3;
inline bool PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_has_message() const {
  return this != internal_default_instance() && message_ != nullptr;
}
inline bool PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::has_message() const {
  return _internal_has_message();
}
inline const ::Soa::PB_DDSData_Msg& PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_message() const {
  const ::Soa::PB_DDSData_Msg* p = message_;
  return p != nullptr ? *p : reinterpret_cast<const ::Soa::PB_DDSData_Msg&>(
      ::Soa::_PB_DDSData_Msg_default_instance_);
}
inline const ::Soa::PB_DDSData_Msg& PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::message() const {
  // @@protoc_insertion_point(field_get:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.message)
  return _internal_message();
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::unsafe_arena_set_allocated_message(
    ::Soa::PB_DDSData_Msg* message) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(message_);
  }
  message_ = message;
  if (message) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.message)
}
inline ::Soa::PB_DDSData_Msg* PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::release_message() {
  
  ::Soa::PB_DDSData_Msg* temp = message_;
  message_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Soa::PB_DDSData_Msg* PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::unsafe_arena_release_message() {
  // @@protoc_insertion_point(field_release:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.message)
  
  ::Soa::PB_DDSData_Msg* temp = message_;
  message_ = nullptr;
  return temp;
}
inline ::Soa::PB_DDSData_Msg* PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::_internal_mutable_message() {
  
  if (message_ == nullptr) {
    auto* p = CreateMaybeMessage<::Soa::PB_DDSData_Msg>(GetArenaForAllocation());
    message_ = p;
  }
  return message_;
}
inline ::Soa::PB_DDSData_Msg* PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::mutable_message() {
  ::Soa::PB_DDSData_Msg* _msg = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.message)
  return _msg;
}
inline void PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg::set_allocated_message(::Soa::PB_DDSData_Msg* message) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(message_);
  }
  if (message) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(message));
    if (message_arena != submessage_arena) {
      message = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, message, submessage_arena);
    }
    
  } else {
    
  }
  message_ = message;
  // @@protoc_insertion_point(field_set_allocated:Soa.PB_carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg.message)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Soa

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Basic_5fConvoyFun_2eproto