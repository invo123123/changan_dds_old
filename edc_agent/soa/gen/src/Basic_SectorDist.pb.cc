// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Basic_SectorDist.proto

#include "Basic_SectorDist.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Soa {
constexpr PB_Basic_SectorDist_Get_SectorDist_In::PB_Basic_SectorDist_Get_SectorDist_In(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct PB_Basic_SectorDist_Get_SectorDist_InDefaultTypeInternal {
  constexpr PB_Basic_SectorDist_Get_SectorDist_InDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PB_Basic_SectorDist_Get_SectorDist_InDefaultTypeInternal() {}
  union {
    PB_Basic_SectorDist_Get_SectorDist_In _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PB_Basic_SectorDist_Get_SectorDist_InDefaultTypeInternal _PB_Basic_SectorDist_Get_SectorDist_In_default_instance_;
constexpr PB_Basic_SectorDist_Get_SectorDist_Out::PB_Basic_SectorDist_Get_SectorDist_Out(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : return__(nullptr){}
struct PB_Basic_SectorDist_Get_SectorDist_OutDefaultTypeInternal {
  constexpr PB_Basic_SectorDist_Get_SectorDist_OutDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PB_Basic_SectorDist_Get_SectorDist_OutDefaultTypeInternal() {}
  union {
    PB_Basic_SectorDist_Get_SectorDist_Out _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PB_Basic_SectorDist_Get_SectorDist_OutDefaultTypeInternal _PB_Basic_SectorDist_Get_SectorDist_Out_default_instance_;
}  // namespace Soa
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Basic_5fSectorDist_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Basic_5fSectorDist_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Basic_5fSectorDist_2eproto = nullptr;

const uint32_t TableStruct_Basic_5fSectorDist_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Soa::PB_Basic_SectorDist_Get_SectorDist_In, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Soa::PB_Basic_SectorDist_Get_SectorDist_Out, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Soa::PB_Basic_SectorDist_Get_SectorDist_Out, return__),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Soa::PB_Basic_SectorDist_Get_SectorDist_In)},
  { 6, -1, -1, sizeof(::Soa::PB_Basic_SectorDist_Get_SectorDist_Out)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Soa::_PB_Basic_SectorDist_Get_SectorDist_In_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Soa::_PB_Basic_SectorDist_Get_SectorDist_Out_default_instance_),
};

const char descriptor_table_protodef_Basic_5fSectorDist_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026Basic_SectorDist.proto\022\003Soa\032\014Common.pr"
  "oto\"\'\n%PB_Basic_SectorDist_Get_SectorDis"
  "t_In\"N\n&PB_Basic_SectorDist_Get_SectorDi"
  "st_Out\022$\n\007return_\030\001 \001(\0132\023.Soa.PB_DDSData"
  "_Msgb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Basic_5fSectorDist_2eproto_deps[1] = {
  &::descriptor_table_Common_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Basic_5fSectorDist_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Basic_5fSectorDist_2eproto = {
  false, false, 172, descriptor_table_protodef_Basic_5fSectorDist_2eproto, "Basic_SectorDist.proto", 
  &descriptor_table_Basic_5fSectorDist_2eproto_once, descriptor_table_Basic_5fSectorDist_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_Basic_5fSectorDist_2eproto::offsets,
  file_level_metadata_Basic_5fSectorDist_2eproto, file_level_enum_descriptors_Basic_5fSectorDist_2eproto, file_level_service_descriptors_Basic_5fSectorDist_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Basic_5fSectorDist_2eproto_getter() {
  return &descriptor_table_Basic_5fSectorDist_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Basic_5fSectorDist_2eproto(&descriptor_table_Basic_5fSectorDist_2eproto);
namespace Soa {

// ===================================================================

class PB_Basic_SectorDist_Get_SectorDist_In::_Internal {
 public:
};

PB_Basic_SectorDist_Get_SectorDist_In::PB_Basic_SectorDist_Get_SectorDist_In(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:Soa.PB_Basic_SectorDist_Get_SectorDist_In)
}
PB_Basic_SectorDist_Get_SectorDist_In::PB_Basic_SectorDist_Get_SectorDist_In(const PB_Basic_SectorDist_Get_SectorDist_In& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Soa.PB_Basic_SectorDist_Get_SectorDist_In)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PB_Basic_SectorDist_Get_SectorDist_In::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PB_Basic_SectorDist_Get_SectorDist_In::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata PB_Basic_SectorDist_Get_SectorDist_In::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Basic_5fSectorDist_2eproto_getter, &descriptor_table_Basic_5fSectorDist_2eproto_once,
      file_level_metadata_Basic_5fSectorDist_2eproto[0]);
}

// ===================================================================

class PB_Basic_SectorDist_Get_SectorDist_Out::_Internal {
 public:
  static const ::Soa::PB_DDSData_Msg& return_(const PB_Basic_SectorDist_Get_SectorDist_Out* msg);
};

const ::Soa::PB_DDSData_Msg&
PB_Basic_SectorDist_Get_SectorDist_Out::_Internal::return_(const PB_Basic_SectorDist_Get_SectorDist_Out* msg) {
  return *msg->return__;
}
void PB_Basic_SectorDist_Get_SectorDist_Out::clear_return_() {
  if (GetArenaForAllocation() == nullptr && return__ != nullptr) {
    delete return__;
  }
  return__ = nullptr;
}
PB_Basic_SectorDist_Get_SectorDist_Out::PB_Basic_SectorDist_Get_SectorDist_Out(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
}
PB_Basic_SectorDist_Get_SectorDist_Out::PB_Basic_SectorDist_Get_SectorDist_Out(const PB_Basic_SectorDist_Get_SectorDist_Out& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_return_()) {
    return__ = new ::Soa::PB_DDSData_Msg(*from.return__);
  } else {
    return__ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
}

inline void PB_Basic_SectorDist_Get_SectorDist_Out::SharedCtor() {
return__ = nullptr;
}

PB_Basic_SectorDist_Get_SectorDist_Out::~PB_Basic_SectorDist_Get_SectorDist_Out() {
  // @@protoc_insertion_point(destructor:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void PB_Basic_SectorDist_Get_SectorDist_Out::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete return__;
}

void PB_Basic_SectorDist_Get_SectorDist_Out::ArenaDtor(void* object) {
  PB_Basic_SectorDist_Get_SectorDist_Out* _this = reinterpret_cast< PB_Basic_SectorDist_Get_SectorDist_Out* >(object);
  (void)_this;
}
void PB_Basic_SectorDist_Get_SectorDist_Out::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PB_Basic_SectorDist_Get_SectorDist_Out::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void PB_Basic_SectorDist_Get_SectorDist_Out::Clear() {
// @@protoc_insertion_point(message_clear_start:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && return__ != nullptr) {
    delete return__;
  }
  return__ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PB_Basic_SectorDist_Get_SectorDist_Out::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Soa.PB_DDSData_Msg return_ = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_return_(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PB_Basic_SectorDist_Get_SectorDist_Out::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Soa.PB_DDSData_Msg return_ = 1;
  if (this->_internal_has_return_()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::return_(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  return target;
}

size_t PB_Basic_SectorDist_Get_SectorDist_Out::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Soa.PB_DDSData_Msg return_ = 1;
  if (this->_internal_has_return_()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *return__);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PB_Basic_SectorDist_Get_SectorDist_Out::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    PB_Basic_SectorDist_Get_SectorDist_Out::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PB_Basic_SectorDist_Get_SectorDist_Out::GetClassData() const { return &_class_data_; }

void PB_Basic_SectorDist_Get_SectorDist_Out::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<PB_Basic_SectorDist_Get_SectorDist_Out *>(to)->MergeFrom(
      static_cast<const PB_Basic_SectorDist_Get_SectorDist_Out &>(from));
}


void PB_Basic_SectorDist_Get_SectorDist_Out::MergeFrom(const PB_Basic_SectorDist_Get_SectorDist_Out& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_return_()) {
    _internal_mutable_return_()->::Soa::PB_DDSData_Msg::MergeFrom(from._internal_return_());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PB_Basic_SectorDist_Get_SectorDist_Out::CopyFrom(const PB_Basic_SectorDist_Get_SectorDist_Out& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Soa.PB_Basic_SectorDist_Get_SectorDist_Out)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PB_Basic_SectorDist_Get_SectorDist_Out::IsInitialized() const {
  return true;
}

void PB_Basic_SectorDist_Get_SectorDist_Out::InternalSwap(PB_Basic_SectorDist_Get_SectorDist_Out* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(return__, other->return__);
}

::PROTOBUF_NAMESPACE_ID::Metadata PB_Basic_SectorDist_Get_SectorDist_Out::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Basic_5fSectorDist_2eproto_getter, &descriptor_table_Basic_5fSectorDist_2eproto_once,
      file_level_metadata_Basic_5fSectorDist_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Soa
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Soa::PB_Basic_SectorDist_Get_SectorDist_In* Arena::CreateMaybeMessage< ::Soa::PB_Basic_SectorDist_Get_SectorDist_In >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Soa::PB_Basic_SectorDist_Get_SectorDist_In >(arena);
}
template<> PROTOBUF_NOINLINE ::Soa::PB_Basic_SectorDist_Get_SectorDist_Out* Arena::CreateMaybeMessage< ::Soa::PB_Basic_SectorDist_Get_SectorDist_Out >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Soa::PB_Basic_SectorDist_Get_SectorDist_Out >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>