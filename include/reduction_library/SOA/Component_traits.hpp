#pragma once

#include "reduction_library/SOA/Dataset_traits.hpp"
#include "reduction_library/SOA/Component.hpp"

namespace reduction_library{
namespace SOA{

/** Derive a new component type based on the given component type using alpaka-dataset
 *
 * For component based on non-alpaka datasets, return the given component type.
 * \tparam T_Acc_New alpaka accelerator type
 * \tparam T_Component componet type, follows concept Component
 */
template<typename T_Acc_New, typename T_Component>
struct Acc_Component{
     using type = T_Component;
};

/** Partal specialization for components based on SOA::Component
 *
 *  return type of Component based Alpaka dataset type with new accelerator
 *
 * \tparam T_Acc_New new Alpaka accelerator type
 * \tparam T_Dataset type of old dataset
 */
template<typename T_Acc_New, typename T_Dataset>
struct Acc_Component<T_Acc_New, Component<T_Dataset>> {
    using type = Component< Acc_dataset_t<T_Acc_New, T_Dataset>>;
};

template<typename T_Acc_New, typename T_Component>
using Acc_Component_t = typename Acc_Component<T_Acc_New, T_Component>::type;

} // namespace SOA
} // namespace reduction_library
