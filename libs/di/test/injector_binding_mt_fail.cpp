//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/injector.hpp"

#include <boost/test/unit_test.hpp>

#include "boost/di.hpp"
#include "data.hpp"

namespace boost {
namespace di {

BOOST_AUTO_TEST_CASE(injector_binding_fail) {
    injector<
        generic_module<
            bind<if0, c0if0>
        >
      , generic_module<
            bind<if0, c0if0>
        >
    >().create<c8>();
}

} // namespace di
} // namespace boost

