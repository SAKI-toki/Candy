/*****************************************************************//**
 * \file   ClassDefine.h
 * \brief  クラス定義
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_CLASS_DEFINE_H
#define CANDY_CORE_CLASS_DEFINE_H

#include <Core/CoreInclude.h>

CANDY_NAMESPACE_BEGIN

#define CANDY_DEFAULT_DELETE_CONSTRUCTOR(type, default_delete) type() = default_delete
#define CANDY_DEFAULT_DELETE_DESTRUCTOR(type, default_delete) ~type() = default_delete
#define CANDY_DEFAULT_DELETE_COPY_CONSTRUCTOR(type, default_delete) type(const type&) = default_delete
#define CANDY_DEFAULT_DELETE_COPY_OPERATOR(type, default_delete) type& operator=(const type&) = default_delete
#define CANDY_DEFAULT_DELETE_MOVE_CONSTRUCTOR(type, default_delete) type(type&&)noexcept = default_delete
#define CANDY_DEFAULT_DELETE_MOVE_OPERATOR(type, default_delete) type& operator=(type&&)noexcept = default_delete

// default
#define CANDY_DEFAULT_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_CONSTRUCTOR(type, default)
#define CANDY_DEFAULT_DESTRUCTOR(type) CANDY_DEFAULT_DELETE_DESTRUCTOR(type, default)
#define CANDY_DEFAULT_COPY_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_COPY_CONSTRUCTOR(type, default)
#define CANDY_DEFAULT_COPY_OPERATOR(type) CANDY_DEFAULT_DELETE_COPY_OPERATOR(type, default)
#define CANDY_DEFAULT_MOVE_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_MOVE_CONSTRUCTOR(type, default)
#define CANDY_DEFAULT_MOVE_OPERATOR(type) CANDY_DEFAULT_DELETE_MOVE_OPERATOR(type, default)

#define CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(type) CANDY_DEFAULT_CONSTRUCTOR(type); CANDY_DEFAULT_DESTRUCTOR(type)
#define CANDY_DEFAULT_COPY(type) CANDY_DEFAULT_COPY_CONSTRUCTOR(type); CANDY_DEFAULT_COPY_OPERATOR(type)
#define CANDY_DEFAULT_MOVE(type) CANDY_DEFAULT_MOVE_CONSTRUCTOR(type); CANDY_DEFAULT_MOVE_OPERATOR(type)

#define CANDY_DEFAULT_COPY_MOVE(type) CANDY_DEFAULT_COPY(type); CANDY_DEFAULT_MOVE(type)

// delete
#define CANDY_DELETE_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_CONSTRUCTOR(type, delete)
#define CANDY_DELETE_DESTRUCTOR(type) CANDY_DEFAULT_DELETE_DESTRUCTOR(type, delete)
#define CANDY_DELETE_COPY_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_COPY_CONSTRUCTOR(type, delete)
#define CANDY_DELETE_COPY_OPERATOR(type) CANDY_DEFAULT_DELETE_COPY_OPERATOR(type, delete)
#define CANDY_DELETE_MOVE_CONSTRUCTOR(type) CANDY_DEFAULT_DELETE_MOVE_CONSTRUCTOR(type, delete)
#define CANDY_DELETE_MOVE_OPERATOR(type) CANDY_DEFAULT_DELETE_MOVE_OPERATOR(type, delete)

#define CANDY_DELETE_COPY(type) CANDY_DELETE_COPY_CONSTRUCTOR(type); CANDY_DELETE_COPY_OPERATOR(type)
#define CANDY_DELETE_MOVE(type) CANDY_DELETE_MOVE_CONSTRUCTOR(type); CANDY_DELETE_MOVE_OPERATOR(type)

#define CANDY_DELETE_COPY_MOVE(type) CANDY_DELETE_COPY(type); CANDY_DELETE_MOVE(type)

// pair
#define CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR_DELETE_COPY_MOVE(type) CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(type); CANDY_DELETE_COPY_MOVE(type)

CANDY_NAMESPACE_END

#endif // CANDY_CORE_CLASS_DEFINE_H
