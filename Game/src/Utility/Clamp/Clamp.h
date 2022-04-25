#ifndef CANDY_CLAMP_H
#define CANDY_CLAMP_H

CANDY_NAMESPACE_BEGIN

template<typename T, typename MinT, typename MaxT, typename ResultT = std::common_type_t<T, MinT, MaxT>>
ResultT Clamp(const T _v, const MinT _min, const MaxT _max);

template<typename T>
T Clamp01(const T _v);

CANDY_NAMESPACE_END

#include "Clamp.inl"

#endif // CANDY_CLAMP_H
