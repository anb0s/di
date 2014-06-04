
//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_TYPE_TRAITS_IS_CONVERTIBLE_HPP
#define BOOST_DI_TYPE_TRAITS_IS_CONVERTIBLE_HPP

#include "boost/di/aux_/config.hpp"

#include <boost/non_type.hpp>
#include <boost/mpl/aux_/yes_no.hpp>

namespace boost {
namespace di {
namespace type_traits {

template<
    typename T
  , typename TSignature
>
class is_convertible
{
    template<typename U>
    static mpl::aux::yes_tag test(non_type<TSignature, &U::operator()>*);

    template<typename>
     static mpl::aux::no_tag test(...);

public:
    typedef is_convertible type;

    BOOST_STATIC_CONSTANT(
        bool
      , value = sizeof(test<T>(0)) == sizeof(mpl::aux::yes_tag)
    );
};

} // namespace type_traits
} // namespace di
} // namespace boost

#endif

