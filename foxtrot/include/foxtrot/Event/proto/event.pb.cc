// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: event.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "event.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ProtoEvent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ProtoEvent_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_event_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_event_2eproto() {
  protobuf_AddDesc_event_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "event.proto");
  GOOGLE_CHECK(file != NULL);
  ProtoEvent_descriptor_ = file->message_type(0);
  static const int ProtoEvent_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, int_field_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, uint_field_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, string_field_),
  };
  ProtoEvent_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ProtoEvent_descriptor_,
      ProtoEvent::default_instance_,
      ProtoEvent_offsets_,
      -1,
      -1,
      -1,
      sizeof(ProtoEvent),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ProtoEvent, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_event_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ProtoEvent_descriptor_, &ProtoEvent::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_event_2eproto() {
  delete ProtoEvent::default_instance_;
  delete ProtoEvent_reflection_;
}

void protobuf_AddDesc_event_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_event_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013event.proto\"W\n\nProtoEvent\022\014\n\004type\030\001 \001("
    "\005\022\021\n\tint_field\030\002 \003(\005\022\022\n\nuint_field\030\003 \003(\r"
    "\022\024\n\014string_field\030\004 \003(\tb\006proto3", 110);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "event.proto", &protobuf_RegisterTypes);
  ProtoEvent::default_instance_ = new ProtoEvent();
  ProtoEvent::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_event_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_event_2eproto {
  StaticDescriptorInitializer_event_2eproto() {
    protobuf_AddDesc_event_2eproto();
  }
} static_descriptor_initializer_event_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ProtoEvent::kTypeFieldNumber;
const int ProtoEvent::kIntFieldFieldNumber;
const int ProtoEvent::kUintFieldFieldNumber;
const int ProtoEvent::kStringFieldFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ProtoEvent::ProtoEvent()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ProtoEvent)
}

void ProtoEvent::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

ProtoEvent::ProtoEvent(const ProtoEvent& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ProtoEvent)
}

void ProtoEvent::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0;
}

ProtoEvent::~ProtoEvent() {
  // @@protoc_insertion_point(destructor:ProtoEvent)
  SharedDtor();
}

void ProtoEvent::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ProtoEvent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ProtoEvent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ProtoEvent_descriptor_;
}

const ProtoEvent& ProtoEvent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_event_2eproto();
  return *default_instance_;
}

ProtoEvent* ProtoEvent::default_instance_ = NULL;

ProtoEvent* ProtoEvent::New(::google::protobuf::Arena* arena) const {
  ProtoEvent* n = new ProtoEvent;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ProtoEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtoEvent)
  type_ = 0;
  int_field_.Clear();
  uint_field_.Clear();
  string_field_.Clear();
}

bool ProtoEvent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ProtoEvent)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 type = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_int_field;
        break;
      }

      // repeated int32 int_field = 2;
      case 2: {
        if (tag == 18) {
         parse_int_field:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_int_field())));
        } else if (tag == 16) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 18, input, this->mutable_int_field())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_uint_field;
        break;
      }

      // repeated uint32 uint_field = 3;
      case 3: {
        if (tag == 26) {
         parse_uint_field:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_uint_field())));
        } else if (tag == 24) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 26, input, this->mutable_uint_field())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_string_field;
        break;
      }

      // repeated string string_field = 4;
      case 4: {
        if (tag == 34) {
         parse_string_field:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_string_field()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->string_field(this->string_field_size() - 1).data(),
            this->string_field(this->string_field_size() - 1).length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ProtoEvent.string_field"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_string_field;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ProtoEvent)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ProtoEvent)
  return false;
#undef DO_
}

void ProtoEvent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ProtoEvent)
  // optional int32 type = 1;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->type(), output);
  }

  // repeated int32 int_field = 2;
  if (this->int_field_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_int_field_cached_byte_size_);
  }
  for (int i = 0; i < this->int_field_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(
      this->int_field(i), output);
  }

  // repeated uint32 uint_field = 3;
  if (this->uint_field_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_uint_field_cached_byte_size_);
  }
  for (int i = 0; i < this->uint_field_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->uint_field(i), output);
  }

  // repeated string string_field = 4;
  for (int i = 0; i < this->string_field_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->string_field(i).data(), this->string_field(i).length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ProtoEvent.string_field");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->string_field(i), output);
  }

  // @@protoc_insertion_point(serialize_end:ProtoEvent)
}

::google::protobuf::uint8* ProtoEvent::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtoEvent)
  // optional int32 type = 1;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->type(), target);
  }

  // repeated int32 int_field = 2;
  if (this->int_field_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _int_field_cached_byte_size_, target);
  }
  for (int i = 0; i < this->int_field_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32NoTagToArray(this->int_field(i), target);
  }

  // repeated uint32 uint_field = 3;
  if (this->uint_field_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _uint_field_cached_byte_size_, target);
  }
  for (int i = 0; i < this->uint_field_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->uint_field(i), target);
  }

  // repeated string string_field = 4;
  for (int i = 0; i < this->string_field_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->string_field(i).data(), this->string_field(i).length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ProtoEvent.string_field");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->string_field(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:ProtoEvent)
  return target;
}

int ProtoEvent::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:ProtoEvent)
  int total_size = 0;

  // optional int32 type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->type());
  }

  // repeated int32 int_field = 2;
  {
    int data_size = 0;
    for (int i = 0; i < this->int_field_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->int_field(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _int_field_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated uint32 uint_field = 3;
  {
    int data_size = 0;
    for (int i = 0; i < this->uint_field_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->uint_field(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _uint_field_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated string string_field = 4;
  total_size += 1 * this->string_field_size();
  for (int i = 0; i < this->string_field_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->string_field(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ProtoEvent::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ProtoEvent)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const ProtoEvent* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ProtoEvent>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ProtoEvent)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ProtoEvent)
    MergeFrom(*source);
  }
}

void ProtoEvent::MergeFrom(const ProtoEvent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtoEvent)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  int_field_.MergeFrom(from.int_field_);
  uint_field_.MergeFrom(from.uint_field_);
  string_field_.MergeFrom(from.string_field_);
  if (from.type() != 0) {
    set_type(from.type());
  }
}

void ProtoEvent::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ProtoEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ProtoEvent::CopyFrom(const ProtoEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtoEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProtoEvent::IsInitialized() const {

  return true;
}

void ProtoEvent::Swap(ProtoEvent* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ProtoEvent::InternalSwap(ProtoEvent* other) {
  std::swap(type_, other->type_);
  int_field_.UnsafeArenaSwap(&other->int_field_);
  uint_field_.UnsafeArenaSwap(&other->uint_field_);
  string_field_.UnsafeArenaSwap(&other->string_field_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ProtoEvent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ProtoEvent_descriptor_;
  metadata.reflection = ProtoEvent_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ProtoEvent

// optional int32 type = 1;
void ProtoEvent::clear_type() {
  type_ = 0;
}
 ::google::protobuf::int32 ProtoEvent::type() const {
  // @@protoc_insertion_point(field_get:ProtoEvent.type)
  return type_;
}
 void ProtoEvent::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:ProtoEvent.type)
}

// repeated int32 int_field = 2;
int ProtoEvent::int_field_size() const {
  return int_field_.size();
}
void ProtoEvent::clear_int_field() {
  int_field_.Clear();
}
 ::google::protobuf::int32 ProtoEvent::int_field(int index) const {
  // @@protoc_insertion_point(field_get:ProtoEvent.int_field)
  return int_field_.Get(index);
}
 void ProtoEvent::set_int_field(int index, ::google::protobuf::int32 value) {
  int_field_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtoEvent.int_field)
}
 void ProtoEvent::add_int_field(::google::protobuf::int32 value) {
  int_field_.Add(value);
  // @@protoc_insertion_point(field_add:ProtoEvent.int_field)
}
 const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ProtoEvent::int_field() const {
  // @@protoc_insertion_point(field_list:ProtoEvent.int_field)
  return int_field_;
}
 ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ProtoEvent::mutable_int_field() {
  // @@protoc_insertion_point(field_mutable_list:ProtoEvent.int_field)
  return &int_field_;
}

// repeated uint32 uint_field = 3;
int ProtoEvent::uint_field_size() const {
  return uint_field_.size();
}
void ProtoEvent::clear_uint_field() {
  uint_field_.Clear();
}
 ::google::protobuf::uint32 ProtoEvent::uint_field(int index) const {
  // @@protoc_insertion_point(field_get:ProtoEvent.uint_field)
  return uint_field_.Get(index);
}
 void ProtoEvent::set_uint_field(int index, ::google::protobuf::uint32 value) {
  uint_field_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtoEvent.uint_field)
}
 void ProtoEvent::add_uint_field(::google::protobuf::uint32 value) {
  uint_field_.Add(value);
  // @@protoc_insertion_point(field_add:ProtoEvent.uint_field)
}
 const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
ProtoEvent::uint_field() const {
  // @@protoc_insertion_point(field_list:ProtoEvent.uint_field)
  return uint_field_;
}
 ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
ProtoEvent::mutable_uint_field() {
  // @@protoc_insertion_point(field_mutable_list:ProtoEvent.uint_field)
  return &uint_field_;
}

// repeated string string_field = 4;
int ProtoEvent::string_field_size() const {
  return string_field_.size();
}
void ProtoEvent::clear_string_field() {
  string_field_.Clear();
}
 const ::std::string& ProtoEvent::string_field(int index) const {
  // @@protoc_insertion_point(field_get:ProtoEvent.string_field)
  return string_field_.Get(index);
}
 ::std::string* ProtoEvent::mutable_string_field(int index) {
  // @@protoc_insertion_point(field_mutable:ProtoEvent.string_field)
  return string_field_.Mutable(index);
}
 void ProtoEvent::set_string_field(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:ProtoEvent.string_field)
  string_field_.Mutable(index)->assign(value);
}
 void ProtoEvent::set_string_field(int index, const char* value) {
  string_field_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:ProtoEvent.string_field)
}
 void ProtoEvent::set_string_field(int index, const char* value, size_t size) {
  string_field_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ProtoEvent.string_field)
}
 ::std::string* ProtoEvent::add_string_field() {
  // @@protoc_insertion_point(field_add_mutable:ProtoEvent.string_field)
  return string_field_.Add();
}
 void ProtoEvent::add_string_field(const ::std::string& value) {
  string_field_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:ProtoEvent.string_field)
}
 void ProtoEvent::add_string_field(const char* value) {
  string_field_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:ProtoEvent.string_field)
}
 void ProtoEvent::add_string_field(const char* value, size_t size) {
  string_field_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:ProtoEvent.string_field)
}
 const ::google::protobuf::RepeatedPtrField< ::std::string>&
ProtoEvent::string_field() const {
  // @@protoc_insertion_point(field_list:ProtoEvent.string_field)
  return string_field_;
}
 ::google::protobuf::RepeatedPtrField< ::std::string>*
ProtoEvent::mutable_string_field() {
  // @@protoc_insertion_point(field_mutable_list:ProtoEvent.string_field)
  return &string_field_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)