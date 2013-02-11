#ifndef GLUE_HPP
#define GLUE_HPP

#include "types.hpp"

namespace mru
{

//FIXME: disable this generic implementation:
template<typename DstType, typename SrcType> inline
DstType
glue_cast(const SrcType &a_value)
{
  //FIXME: throw?
  return DstType(a_value);
}


} /* namespace mru */

#define GLUE_IMPL_HPP
#include "glue_impl.hpp"
#undef GLUE_IMPL_HPP

#endif /* GLUE_HPP */

