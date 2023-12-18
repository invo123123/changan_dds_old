// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: hmi_basic_trafficsign.proto

#include "hmi_basic_trafficsign.pb.h"

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
namespace HmiInterface {
constexpr LaneArrowArray::LaneArrowArray(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : lane1garrowtype_(0u){}
struct LaneArrowArrayDefaultTypeInternal {
  constexpr LaneArrowArrayDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LaneArrowArrayDefaultTypeInternal() {}
  union {
    LaneArrowArray _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LaneArrowArrayDefaultTypeInternal _LaneArrowArray_default_instance_;
constexpr TrafficSign::TrafficSign(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : lanearrowdata_()
  , warningsign_(0u)
  , prohibitionsign_(0u)
  , mandatorysign_(0u){}
struct TrafficSignDefaultTypeInternal {
  constexpr TrafficSignDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TrafficSignDefaultTypeInternal() {}
  union {
    TrafficSign _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TrafficSignDefaultTypeInternal _TrafficSign_default_instance_;
constexpr BasicTrafficSign::BasicTrafficSign(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : trafficsign_(nullptr){}
struct BasicTrafficSignDefaultTypeInternal {
  constexpr BasicTrafficSignDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BasicTrafficSignDefaultTypeInternal() {}
  union {
    BasicTrafficSign _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BasicTrafficSignDefaultTypeInternal _BasicTrafficSign_default_instance_;
}  // namespace HmiInterface
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_hmi_5fbasic_5ftrafficsign_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_hmi_5fbasic_5ftrafficsign_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_hmi_5fbasic_5ftrafficsign_2eproto = nullptr;

const uint32_t TableStruct_hmi_5fbasic_5ftrafficsign_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::LaneArrowArray, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::LaneArrowArray, lane1garrowtype_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::TrafficSign, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::TrafficSign, warningsign_),
  PROTOBUF_FIELD_OFFSET(::HmiInterface::TrafficSign, prohibitionsign_),
  PROTOBUF_FIELD_OFFSET(::HmiInterface::TrafficSign, mandatorysign_),
  PROTOBUF_FIELD_OFFSET(::HmiInterface::TrafficSign, lanearrowdata_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::BasicTrafficSign, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::HmiInterface::BasicTrafficSign, trafficsign_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::HmiInterface::LaneArrowArray)},
  { 7, -1, -1, sizeof(::HmiInterface::TrafficSign)},
  { 17, -1, -1, sizeof(::HmiInterface::BasicTrafficSign)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::HmiInterface::_LaneArrowArray_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::HmiInterface::_TrafficSign_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::HmiInterface::_BasicTrafficSign_default_instance_),
};

const char descriptor_table_protodef_hmi_5fbasic_5ftrafficsign_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\033hmi_basic_trafficsign.proto\022\014HmiInterf"
  "ace\")\n\016LaneArrowArray\022\027\n\017lane1garrowtype"
  "\030\001 \001(\r\"\207\001\n\013TrafficSign\022\023\n\013warningsign\030\001 "
  "\001(\r\022\027\n\017prohibitionsign\030\002 \001(\r\022\025\n\rmandator"
  "ysign\030\003 \001(\r\0223\n\rlanearrowdata\030\004 \003(\0132\034.Hmi"
  "Interface.LaneArrowArray\"B\n\020BasicTraffic"
  "Sign\022.\n\013trafficsign\030\001 \001(\0132\031.HmiInterface"
  ".TrafficSignb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto = {
  false, false, 300, descriptor_table_protodef_hmi_5fbasic_5ftrafficsign_2eproto, "hmi_basic_trafficsign.proto", 
  &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_hmi_5fbasic_5ftrafficsign_2eproto::offsets,
  file_level_metadata_hmi_5fbasic_5ftrafficsign_2eproto, file_level_enum_descriptors_hmi_5fbasic_5ftrafficsign_2eproto, file_level_service_descriptors_hmi_5fbasic_5ftrafficsign_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_getter() {
  return &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_hmi_5fbasic_5ftrafficsign_2eproto(&descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto);
namespace HmiInterface {

// ===================================================================

class LaneArrowArray::_Internal {
 public:
};

LaneArrowArray::LaneArrowArray(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:HmiInterface.LaneArrowArray)
}
LaneArrowArray::LaneArrowArray(const LaneArrowArray& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  lane1garrowtype_ = from.lane1garrowtype_;
  // @@protoc_insertion_point(copy_constructor:HmiInterface.LaneArrowArray)
}

inline void LaneArrowArray::SharedCtor() {
lane1garrowtype_ = 0u;
}

LaneArrowArray::~LaneArrowArray() {
  // @@protoc_insertion_point(destructor:HmiInterface.LaneArrowArray)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void LaneArrowArray::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void LaneArrowArray::ArenaDtor(void* object) {
  LaneArrowArray* _this = reinterpret_cast< LaneArrowArray* >(object);
  (void)_this;
}
void LaneArrowArray::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LaneArrowArray::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LaneArrowArray::Clear() {
// @@protoc_insertion_point(message_clear_start:HmiInterface.LaneArrowArray)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  lane1garrowtype_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LaneArrowArray::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 lane1garrowtype = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          lane1garrowtype_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

uint8_t* LaneArrowArray::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:HmiInterface.LaneArrowArray)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 lane1garrowtype = 1;
  if (this->_internal_lane1garrowtype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_lane1garrowtype(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:HmiInterface.LaneArrowArray)
  return target;
}

size_t LaneArrowArray::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:HmiInterface.LaneArrowArray)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 lane1garrowtype = 1;
  if (this->_internal_lane1garrowtype() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_lane1garrowtype());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LaneArrowArray::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LaneArrowArray::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LaneArrowArray::GetClassData() const { return &_class_data_; }

void LaneArrowArray::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LaneArrowArray *>(to)->MergeFrom(
      static_cast<const LaneArrowArray &>(from));
}


void LaneArrowArray::MergeFrom(const LaneArrowArray& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:HmiInterface.LaneArrowArray)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_lane1garrowtype() != 0) {
    _internal_set_lane1garrowtype(from._internal_lane1garrowtype());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LaneArrowArray::CopyFrom(const LaneArrowArray& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HmiInterface.LaneArrowArray)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LaneArrowArray::IsInitialized() const {
  return true;
}

void LaneArrowArray::InternalSwap(LaneArrowArray* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(lane1garrowtype_, other->lane1garrowtype_);
}

::PROTOBUF_NAMESPACE_ID::Metadata LaneArrowArray::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_getter, &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_once,
      file_level_metadata_hmi_5fbasic_5ftrafficsign_2eproto[0]);
}

// ===================================================================

class TrafficSign::_Internal {
 public:
};

TrafficSign::TrafficSign(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  lanearrowdata_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:HmiInterface.TrafficSign)
}
TrafficSign::TrafficSign(const TrafficSign& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      lanearrowdata_(from.lanearrowdata_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&warningsign_, &from.warningsign_,
    static_cast<size_t>(reinterpret_cast<char*>(&mandatorysign_) -
    reinterpret_cast<char*>(&warningsign_)) + sizeof(mandatorysign_));
  // @@protoc_insertion_point(copy_constructor:HmiInterface.TrafficSign)
}

inline void TrafficSign::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&warningsign_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&mandatorysign_) -
    reinterpret_cast<char*>(&warningsign_)) + sizeof(mandatorysign_));
}

TrafficSign::~TrafficSign() {
  // @@protoc_insertion_point(destructor:HmiInterface.TrafficSign)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void TrafficSign::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void TrafficSign::ArenaDtor(void* object) {
  TrafficSign* _this = reinterpret_cast< TrafficSign* >(object);
  (void)_this;
}
void TrafficSign::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TrafficSign::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void TrafficSign::Clear() {
// @@protoc_insertion_point(message_clear_start:HmiInterface.TrafficSign)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  lanearrowdata_.Clear();
  ::memset(&warningsign_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&mandatorysign_) -
      reinterpret_cast<char*>(&warningsign_)) + sizeof(mandatorysign_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TrafficSign::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 warningsign = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          warningsign_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 prohibitionsign = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          prohibitionsign_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 mandatorysign = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          mandatorysign_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .HmiInterface.LaneArrowArray lanearrowdata = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_lanearrowdata(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
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

uint8_t* TrafficSign::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:HmiInterface.TrafficSign)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 warningsign = 1;
  if (this->_internal_warningsign() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_warningsign(), target);
  }

  // uint32 prohibitionsign = 2;
  if (this->_internal_prohibitionsign() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_prohibitionsign(), target);
  }

  // uint32 mandatorysign = 3;
  if (this->_internal_mandatorysign() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_mandatorysign(), target);
  }

  // repeated .HmiInterface.LaneArrowArray lanearrowdata = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_lanearrowdata_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_lanearrowdata(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:HmiInterface.TrafficSign)
  return target;
}

size_t TrafficSign::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:HmiInterface.TrafficSign)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .HmiInterface.LaneArrowArray lanearrowdata = 4;
  total_size += 1UL * this->_internal_lanearrowdata_size();
  for (const auto& msg : this->lanearrowdata_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint32 warningsign = 1;
  if (this->_internal_warningsign() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_warningsign());
  }

  // uint32 prohibitionsign = 2;
  if (this->_internal_prohibitionsign() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_prohibitionsign());
  }

  // uint32 mandatorysign = 3;
  if (this->_internal_mandatorysign() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_mandatorysign());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData TrafficSign::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    TrafficSign::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*TrafficSign::GetClassData() const { return &_class_data_; }

void TrafficSign::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<TrafficSign *>(to)->MergeFrom(
      static_cast<const TrafficSign &>(from));
}


void TrafficSign::MergeFrom(const TrafficSign& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:HmiInterface.TrafficSign)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  lanearrowdata_.MergeFrom(from.lanearrowdata_);
  if (from._internal_warningsign() != 0) {
    _internal_set_warningsign(from._internal_warningsign());
  }
  if (from._internal_prohibitionsign() != 0) {
    _internal_set_prohibitionsign(from._internal_prohibitionsign());
  }
  if (from._internal_mandatorysign() != 0) {
    _internal_set_mandatorysign(from._internal_mandatorysign());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void TrafficSign::CopyFrom(const TrafficSign& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HmiInterface.TrafficSign)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TrafficSign::IsInitialized() const {
  return true;
}

void TrafficSign::InternalSwap(TrafficSign* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  lanearrowdata_.InternalSwap(&other->lanearrowdata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TrafficSign, mandatorysign_)
      + sizeof(TrafficSign::mandatorysign_)
      - PROTOBUF_FIELD_OFFSET(TrafficSign, warningsign_)>(
          reinterpret_cast<char*>(&warningsign_),
          reinterpret_cast<char*>(&other->warningsign_));
}

::PROTOBUF_NAMESPACE_ID::Metadata TrafficSign::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_getter, &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_once,
      file_level_metadata_hmi_5fbasic_5ftrafficsign_2eproto[1]);
}

// ===================================================================

class BasicTrafficSign::_Internal {
 public:
  static const ::HmiInterface::TrafficSign& trafficsign(const BasicTrafficSign* msg);
};

const ::HmiInterface::TrafficSign&
BasicTrafficSign::_Internal::trafficsign(const BasicTrafficSign* msg) {
  return *msg->trafficsign_;
}
BasicTrafficSign::BasicTrafficSign(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:HmiInterface.BasicTrafficSign)
}
BasicTrafficSign::BasicTrafficSign(const BasicTrafficSign& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_trafficsign()) {
    trafficsign_ = new ::HmiInterface::TrafficSign(*from.trafficsign_);
  } else {
    trafficsign_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:HmiInterface.BasicTrafficSign)
}

inline void BasicTrafficSign::SharedCtor() {
trafficsign_ = nullptr;
}

BasicTrafficSign::~BasicTrafficSign() {
  // @@protoc_insertion_point(destructor:HmiInterface.BasicTrafficSign)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void BasicTrafficSign::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete trafficsign_;
}

void BasicTrafficSign::ArenaDtor(void* object) {
  BasicTrafficSign* _this = reinterpret_cast< BasicTrafficSign* >(object);
  (void)_this;
}
void BasicTrafficSign::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BasicTrafficSign::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BasicTrafficSign::Clear() {
// @@protoc_insertion_point(message_clear_start:HmiInterface.BasicTrafficSign)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && trafficsign_ != nullptr) {
    delete trafficsign_;
  }
  trafficsign_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BasicTrafficSign::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .HmiInterface.TrafficSign trafficsign = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_trafficsign(), ptr);
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

uint8_t* BasicTrafficSign::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:HmiInterface.BasicTrafficSign)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .HmiInterface.TrafficSign trafficsign = 1;
  if (this->_internal_has_trafficsign()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::trafficsign(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:HmiInterface.BasicTrafficSign)
  return target;
}

size_t BasicTrafficSign::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:HmiInterface.BasicTrafficSign)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .HmiInterface.TrafficSign trafficsign = 1;
  if (this->_internal_has_trafficsign()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *trafficsign_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BasicTrafficSign::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    BasicTrafficSign::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BasicTrafficSign::GetClassData() const { return &_class_data_; }

void BasicTrafficSign::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<BasicTrafficSign *>(to)->MergeFrom(
      static_cast<const BasicTrafficSign &>(from));
}


void BasicTrafficSign::MergeFrom(const BasicTrafficSign& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:HmiInterface.BasicTrafficSign)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_trafficsign()) {
    _internal_mutable_trafficsign()->::HmiInterface::TrafficSign::MergeFrom(from._internal_trafficsign());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BasicTrafficSign::CopyFrom(const BasicTrafficSign& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HmiInterface.BasicTrafficSign)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BasicTrafficSign::IsInitialized() const {
  return true;
}

void BasicTrafficSign::InternalSwap(BasicTrafficSign* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(trafficsign_, other->trafficsign_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BasicTrafficSign::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_getter, &descriptor_table_hmi_5fbasic_5ftrafficsign_2eproto_once,
      file_level_metadata_hmi_5fbasic_5ftrafficsign_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace HmiInterface
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::HmiInterface::LaneArrowArray* Arena::CreateMaybeMessage< ::HmiInterface::LaneArrowArray >(Arena* arena) {
  return Arena::CreateMessageInternal< ::HmiInterface::LaneArrowArray >(arena);
}
template<> PROTOBUF_NOINLINE ::HmiInterface::TrafficSign* Arena::CreateMaybeMessage< ::HmiInterface::TrafficSign >(Arena* arena) {
  return Arena::CreateMessageInternal< ::HmiInterface::TrafficSign >(arena);
}
template<> PROTOBUF_NOINLINE ::HmiInterface::BasicTrafficSign* Arena::CreateMaybeMessage< ::HmiInterface::BasicTrafficSign >(Arena* arena) {
  return Arena::CreateMessageInternal< ::HmiInterface::BasicTrafficSign >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>