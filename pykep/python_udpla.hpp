// Copyright 2023, 2024 Dario Izzo (dario.izzo@gmail.com), Francesco Biscani
// (bluescarni@gmail.com)
//
// This file is part of the kep3 library.
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef PYKEP_PLANET_HPP
#define PYKEP_PLANET_HPP

#include <array>
#include <string>

#include <kep3/epoch.hpp>
#include <pybind11/pybind11.h>

namespace pykep
{
namespace py = pybind11;
struct python_udpla {
    py::object m_obj;

    python_udpla();
    explicit python_udpla(py::object obj);

    // Mandatory methods
    [[nodiscard]] std::array<std::array<double, 3>, 2> eph(const kep3::epoch &ep) const;

    // Optional methods
    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] std::string get_extra_info() const;
    [[nodiscard]] double get_mu_central_body() const;
    [[nodiscard]] double get_mu_self() const;
    [[nodiscard]] double get_radius() const;
    [[nodiscard]] double get_safe_radius() const;
    [[nodiscard]] double period() const;
};
} // namespace pykep

#endif