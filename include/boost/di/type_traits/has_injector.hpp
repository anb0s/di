//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_TYPE_TRAITS_HAS_INJECTOR_HPP
#define BOOST_DI_TYPE_TRAITS_HAS_INJECTOR_HPP

#include "boost/di/aux_/config.hpp"

#include <boost/preprocessor/cat.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/non_type.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/aux_/yes_no.hpp>

namespace boost {
namespace di {
namespace type_traits {

template<typename T>
class BOOST_PP_CAT(has_, BOOST_DI_INJECTOR)
{
    struct base_impl { void BOOST_DI_INJECTOR(...) { } };
    struct base
        : base_impl
        , mpl::if_<is_class<T>, T, mpl::void_>::type
    { };

    template<typename U>
    static mpl::aux::no_tag test(
        U*
      , non_type<void (base_impl::*)(...), &U::BOOST_DI_INJECTOR>* = 0
    );

    static mpl::aux::yes_tag test(...);

public:
    typedef BOOST_PP_CAT(has_, BOOST_DI_INJECTOR) type;

    BOOST_STATIC_CONSTANT(
        bool
      , value = sizeof(test((base*)0)) == sizeof(mpl::aux::yes_tag)
    );
};

} // namespace type_traits
} // namespace di
} // namespace boost

#endif

