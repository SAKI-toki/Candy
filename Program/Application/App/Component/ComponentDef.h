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

namespace Component
{
	class Interface
	{
    public:
        virtual ~Interface() = default;
        virtual bool isInheritedeClassId(const void* const /*_classNameId*/)const { return false; }
        virtual const void* getClassId()const { return nullptr; }
	};

    template<typename T>
    using is_base_component_interface_t = std::enable_if_t<std::is_base_of_v<Interface, T>, std::nullptr_t>;

#define CANDY_COMPONENT_DECLARE(CLASS_NAME, BASE_TYPE) \
private: \
static constexpr const char* const ClassName = #CLASS_NAME; \
static constexpr s32 InternalId = 0; \
public: \
using base_type = BASE_TYPE; \
virtual bool isInheritedeClassId(const void* const _id)const override; \
virtual const void* getClassId()const override; \
static constexpr const char* GetStaticClassName(){ return ClassName; } \
static constexpr const void* GetStaticClassId(){ return &InternalId; } \
template<typename T, typename ReturnT = std::conditional_t<std::is_const_v<T>, const std::shared_ptr<CLASS_NAME>, std::shared_ptr<CLASS_NAME>>, is_base_component_interface_t<T> = nullptr> \
static ReturnT Cast(const std::shared_ptr<T>& _v) \
{ \
    if(!_v)return nullptr; \
    if(_v->isInheritedeClassId(GetStaticClassId()))return std::static_pointer_cast<CLASS_NAME>(_v); \
    return nullptr; \
} \
template<typename T, typename ReturnT = std::conditional_t<std::is_const_v<T>, const std::shared_ptr<CLASS_NAME>, std::shared_ptr<CLASS_NAME>>, is_base_component_interface_t<T> = nullptr> \
static ReturnT Cast(const std::weak_ptr<T>& _v) \
{ \
    return Cast(_v.lock()); \
} \
private:

#define CANDY_COMPONENT_DEFINE(CLASS_NAME, BASE_TYPE) \
bool CLASS_NAME::isInheritedeClassId(const void* const _id)const \
{ \
    if(base_type::isInheritedeClassId(_id))return true; \
    return getClassId() == _id; \
} \
const void* CLASS_NAME::getClassId()const \
{ \
    return &InternalId; \
}

}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_DEF_H
