/*****************************************************************//**
 * \file   ComponentDef.h
 * \brief  コンポーネントの定義
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_DEF_H
#define CANDY_APP_COMPONENT_DEF_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

using ComponentClassIdType = u32;

class ComponentInterface
{
public:
	virtual ~ComponentInterface() = default;
	virtual bool isInheritedeClassId(const ComponentClassIdType /*_classNameId*/)const { return false; }
	virtual ComponentClassIdType getClassId()const { return 0; }
};

template<typename T>
using IsBaseComponentComponentInterfaceT = std::enable_if_t<std::is_base_of_v<ComponentInterface, T>, std::nullptr_t>;

#define CANDY_COMPONENT_DECLARE(CLASS_NAME, BASE_TYPE) \
private: \
static constexpr const char* const ClassName = #CLASS_NAME; \
static constexpr ComponentClassIdType InternalId = CANDY_STATIC_FNV_HASH32(#CLASS_NAME); \
public: \
using Super = BASE_TYPE; \
virtual bool isInheritedeClassId(const ComponentClassIdType _id)const override; \
virtual ComponentClassIdType getClassId()const override; \
static constexpr const char* GetStaticClassName(){ return ClassName; } \
static constexpr ComponentClassIdType GetStaticClassId(){ return InternalId; } \
template<typename T, typename ReturnT = std::conditional_t<std::is_const_v<T>, const std::shared_ptr<CLASS_NAME>, std::shared_ptr<CLASS_NAME>>, IsBaseComponentComponentInterfaceT<T> = nullptr> \
static ReturnT Cast(const std::shared_ptr<T>& _v) \
{ \
    if(!_v)return nullptr; \
    if(_v->isInheritedeClassId(GetStaticClassId()))return std::static_pointer_cast<CLASS_NAME>(_v); \
    return nullptr; \
} \
template<typename T, typename ReturnT = std::conditional_t<std::is_const_v<T>, const std::shared_ptr<CLASS_NAME>, std::shared_ptr<CLASS_NAME>>, IsBaseComponentComponentInterfaceT<T> = nullptr> \
static ReturnT Cast(const std::weak_ptr<T>& _v) \
{ \
    return Cast(_v.lock()); \
} \
private:

#define CANDY_COMPONENT_DEFINE(CLASS_NAME, Super) \
bool CLASS_NAME::isInheritedeClassId(const ComponentClassIdType _id)const \
{ \
    if(Super::isInheritedeClassId(_id))return true; \
    return getClassId() == _id; \
} \
ComponentClassIdType CLASS_NAME::getClassId()const \
{ \
    return InternalId; \
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_DEF_H
