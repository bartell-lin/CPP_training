// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bank_account.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bank_5faccount_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bank_5faccount_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019001 < PROTOBUF_MIN_PROTOC_VERSION
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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bank_5faccount_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bank_5faccount_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bank_5faccount_2eproto;
namespace BankAccount {
class Bank;
struct BankDefaultTypeInternal;
extern BankDefaultTypeInternal _Bank_default_instance_;
class bankAccount;
struct bankAccountDefaultTypeInternal;
extern bankAccountDefaultTypeInternal _bankAccount_default_instance_;
}  // namespace BankAccount
PROTOBUF_NAMESPACE_OPEN
template<> ::BankAccount::Bank* Arena::CreateMaybeMessage<::BankAccount::Bank>(Arena*);
template<> ::BankAccount::bankAccount* Arena::CreateMaybeMessage<::BankAccount::bankAccount>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace BankAccount {

// ===================================================================

class bankAccount final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:BankAccount.bankAccount) */ {
 public:
  inline bankAccount() : bankAccount(nullptr) {}
  ~bankAccount() override;
  explicit constexpr bankAccount(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  bankAccount(const bankAccount& from);
  bankAccount(bankAccount&& from) noexcept
    : bankAccount() {
    *this = ::std::move(from);
  }

  inline bankAccount& operator=(const bankAccount& from) {
    CopyFrom(from);
    return *this;
  }
  inline bankAccount& operator=(bankAccount&& from) noexcept {
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
  static const bankAccount& default_instance() {
    return *internal_default_instance();
  }
  static inline const bankAccount* internal_default_instance() {
    return reinterpret_cast<const bankAccount*>(
               &_bankAccount_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(bankAccount& a, bankAccount& b) {
    a.Swap(&b);
  }
  inline void Swap(bankAccount* other) {
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
  void UnsafeArenaSwap(bankAccount* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  bankAccount* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<bankAccount>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const bankAccount& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const bankAccount& from);
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
  void InternalSwap(bankAccount* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "BankAccount.bankAccount";
  }
  protected:
  explicit bankAccount(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kNameFieldNumber = 1,
    kSsnFieldNumber = 2,
    kAccountNumFieldNumber = 3,
    kDateOpenedFieldNumber = 4,
    kBalanceFieldNumber = 5,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string ssn = 2;
  void clear_ssn();
  const std::string& ssn() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_ssn(ArgT0&& arg0, ArgT... args);
  std::string* mutable_ssn();
  PROTOBUF_NODISCARD std::string* release_ssn();
  void set_allocated_ssn(std::string* ssn);
  private:
  const std::string& _internal_ssn() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ssn(const std::string& value);
  std::string* _internal_mutable_ssn();
  public:

  // string account_num = 3;
  void clear_account_num();
  const std::string& account_num() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_account_num(ArgT0&& arg0, ArgT... args);
  std::string* mutable_account_num();
  PROTOBUF_NODISCARD std::string* release_account_num();
  void set_allocated_account_num(std::string* account_num);
  private:
  const std::string& _internal_account_num() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_account_num(const std::string& value);
  std::string* _internal_mutable_account_num();
  public:

  // string date_opened = 4;
  void clear_date_opened();
  const std::string& date_opened() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_date_opened(ArgT0&& arg0, ArgT... args);
  std::string* mutable_date_opened();
  PROTOBUF_NODISCARD std::string* release_date_opened();
  void set_allocated_date_opened(std::string* date_opened);
  private:
  const std::string& _internal_date_opened() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_date_opened(const std::string& value);
  std::string* _internal_mutable_date_opened();
  public:

  // int32 balance = 5;
  void clear_balance();
  int32_t balance() const;
  void set_balance(int32_t value);
  private:
  int32_t _internal_balance() const;
  void _internal_set_balance(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:BankAccount.bankAccount)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ssn_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr account_num_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr date_opened_;
  int32_t balance_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_bank_5faccount_2eproto;
};
// -------------------------------------------------------------------

class Bank final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:BankAccount.Bank) */ {
 public:
  inline Bank() : Bank(nullptr) {}
  ~Bank() override;
  explicit constexpr Bank(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Bank(const Bank& from);
  Bank(Bank&& from) noexcept
    : Bank() {
    *this = ::std::move(from);
  }

  inline Bank& operator=(const Bank& from) {
    CopyFrom(from);
    return *this;
  }
  inline Bank& operator=(Bank&& from) noexcept {
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
  static const Bank& default_instance() {
    return *internal_default_instance();
  }
  static inline const Bank* internal_default_instance() {
    return reinterpret_cast<const Bank*>(
               &_Bank_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Bank& a, Bank& b) {
    a.Swap(&b);
  }
  inline void Swap(Bank* other) {
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
  void UnsafeArenaSwap(Bank* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Bank* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Bank>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Bank& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Bank& from);
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
  void InternalSwap(Bank* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "BankAccount.Bank";
  }
  protected:
  explicit Bank(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kAccountsFieldNumber = 1,
  };
  // repeated .BankAccount.bankAccount accounts = 1;
  int accounts_size() const;
  private:
  int _internal_accounts_size() const;
  public:
  void clear_accounts();
  ::BankAccount::bankAccount* mutable_accounts(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::BankAccount::bankAccount >*
      mutable_accounts();
  private:
  const ::BankAccount::bankAccount& _internal_accounts(int index) const;
  ::BankAccount::bankAccount* _internal_add_accounts();
  public:
  const ::BankAccount::bankAccount& accounts(int index) const;
  ::BankAccount::bankAccount* add_accounts();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::BankAccount::bankAccount >&
      accounts() const;

  // @@protoc_insertion_point(class_scope:BankAccount.Bank)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::BankAccount::bankAccount > accounts_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_bank_5faccount_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// bankAccount

// string name = 1;
inline void bankAccount::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& bankAccount::name() const {
  // @@protoc_insertion_point(field_get:BankAccount.bankAccount.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void bankAccount::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:BankAccount.bankAccount.name)
}
inline std::string* bankAccount::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:BankAccount.bankAccount.name)
  return _s;
}
inline const std::string& bankAccount::_internal_name() const {
  return name_.Get();
}
inline void bankAccount::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* bankAccount::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* bankAccount::release_name() {
  // @@protoc_insertion_point(field_release:BankAccount.bankAccount.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void bankAccount::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BankAccount.bankAccount.name)
}

// string ssn = 2;
inline void bankAccount::clear_ssn() {
  ssn_.ClearToEmpty();
}
inline const std::string& bankAccount::ssn() const {
  // @@protoc_insertion_point(field_get:BankAccount.bankAccount.ssn)
  return _internal_ssn();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void bankAccount::set_ssn(ArgT0&& arg0, ArgT... args) {
 
 ssn_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:BankAccount.bankAccount.ssn)
}
inline std::string* bankAccount::mutable_ssn() {
  std::string* _s = _internal_mutable_ssn();
  // @@protoc_insertion_point(field_mutable:BankAccount.bankAccount.ssn)
  return _s;
}
inline const std::string& bankAccount::_internal_ssn() const {
  return ssn_.Get();
}
inline void bankAccount::_internal_set_ssn(const std::string& value) {
  
  ssn_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* bankAccount::_internal_mutable_ssn() {
  
  return ssn_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* bankAccount::release_ssn() {
  // @@protoc_insertion_point(field_release:BankAccount.bankAccount.ssn)
  return ssn_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void bankAccount::set_allocated_ssn(std::string* ssn) {
  if (ssn != nullptr) {
    
  } else {
    
  }
  ssn_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ssn,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (ssn_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    ssn_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BankAccount.bankAccount.ssn)
}

// string account_num = 3;
inline void bankAccount::clear_account_num() {
  account_num_.ClearToEmpty();
}
inline const std::string& bankAccount::account_num() const {
  // @@protoc_insertion_point(field_get:BankAccount.bankAccount.account_num)
  return _internal_account_num();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void bankAccount::set_account_num(ArgT0&& arg0, ArgT... args) {
 
 account_num_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:BankAccount.bankAccount.account_num)
}
inline std::string* bankAccount::mutable_account_num() {
  std::string* _s = _internal_mutable_account_num();
  // @@protoc_insertion_point(field_mutable:BankAccount.bankAccount.account_num)
  return _s;
}
inline const std::string& bankAccount::_internal_account_num() const {
  return account_num_.Get();
}
inline void bankAccount::_internal_set_account_num(const std::string& value) {
  
  account_num_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* bankAccount::_internal_mutable_account_num() {
  
  return account_num_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* bankAccount::release_account_num() {
  // @@protoc_insertion_point(field_release:BankAccount.bankAccount.account_num)
  return account_num_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void bankAccount::set_allocated_account_num(std::string* account_num) {
  if (account_num != nullptr) {
    
  } else {
    
  }
  account_num_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), account_num,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (account_num_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    account_num_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BankAccount.bankAccount.account_num)
}

// string date_opened = 4;
inline void bankAccount::clear_date_opened() {
  date_opened_.ClearToEmpty();
}
inline const std::string& bankAccount::date_opened() const {
  // @@protoc_insertion_point(field_get:BankAccount.bankAccount.date_opened)
  return _internal_date_opened();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void bankAccount::set_date_opened(ArgT0&& arg0, ArgT... args) {
 
 date_opened_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:BankAccount.bankAccount.date_opened)
}
inline std::string* bankAccount::mutable_date_opened() {
  std::string* _s = _internal_mutable_date_opened();
  // @@protoc_insertion_point(field_mutable:BankAccount.bankAccount.date_opened)
  return _s;
}
inline const std::string& bankAccount::_internal_date_opened() const {
  return date_opened_.Get();
}
inline void bankAccount::_internal_set_date_opened(const std::string& value) {
  
  date_opened_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* bankAccount::_internal_mutable_date_opened() {
  
  return date_opened_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* bankAccount::release_date_opened() {
  // @@protoc_insertion_point(field_release:BankAccount.bankAccount.date_opened)
  return date_opened_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void bankAccount::set_allocated_date_opened(std::string* date_opened) {
  if (date_opened != nullptr) {
    
  } else {
    
  }
  date_opened_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), date_opened,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (date_opened_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    date_opened_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BankAccount.bankAccount.date_opened)
}

// int32 balance = 5;
inline void bankAccount::clear_balance() {
  balance_ = 0;
}
inline int32_t bankAccount::_internal_balance() const {
  return balance_;
}
inline int32_t bankAccount::balance() const {
  // @@protoc_insertion_point(field_get:BankAccount.bankAccount.balance)
  return _internal_balance();
}
inline void bankAccount::_internal_set_balance(int32_t value) {
  
  balance_ = value;
}
inline void bankAccount::set_balance(int32_t value) {
  _internal_set_balance(value);
  // @@protoc_insertion_point(field_set:BankAccount.bankAccount.balance)
}

// -------------------------------------------------------------------

// Bank

// repeated .BankAccount.bankAccount accounts = 1;
inline int Bank::_internal_accounts_size() const {
  return accounts_.size();
}
inline int Bank::accounts_size() const {
  return _internal_accounts_size();
}
inline void Bank::clear_accounts() {
  accounts_.Clear();
}
inline ::BankAccount::bankAccount* Bank::mutable_accounts(int index) {
  // @@protoc_insertion_point(field_mutable:BankAccount.Bank.accounts)
  return accounts_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::BankAccount::bankAccount >*
Bank::mutable_accounts() {
  // @@protoc_insertion_point(field_mutable_list:BankAccount.Bank.accounts)
  return &accounts_;
}
inline const ::BankAccount::bankAccount& Bank::_internal_accounts(int index) const {
  return accounts_.Get(index);
}
inline const ::BankAccount::bankAccount& Bank::accounts(int index) const {
  // @@protoc_insertion_point(field_get:BankAccount.Bank.accounts)
  return _internal_accounts(index);
}
inline ::BankAccount::bankAccount* Bank::_internal_add_accounts() {
  return accounts_.Add();
}
inline ::BankAccount::bankAccount* Bank::add_accounts() {
  ::BankAccount::bankAccount* _add = _internal_add_accounts();
  // @@protoc_insertion_point(field_add:BankAccount.Bank.accounts)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::BankAccount::bankAccount >&
Bank::accounts() const {
  // @@protoc_insertion_point(field_list:BankAccount.Bank.accounts)
  return accounts_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace BankAccount

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bank_5faccount_2eproto
