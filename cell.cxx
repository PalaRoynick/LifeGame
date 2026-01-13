#include "cell.h"
#include "state_machine.h"

#include <format>
#include <iostream>

namespace{
auto neib_loc_inds = std::views::cartesian_product(
    std::array{-1, 0, 1}, std::array{-1, 0, 1})
        | std::views::filter([] (const auto& p) {
            return std::get<0>(p) != 0 || std::get<1>(p) != 0;});
}

Cell::Cell(int i, int j)
    : i(i), j(j)
{
    neibs.reserve(nn);
    fill_neibs();
}

constexpr void Cell::fill_neibs() noexcept
{
    for (const auto& t : neib_loc_inds)
    {
        const auto [x, y] = t;
        neibs.push_back({(i + x + nn) % nn, (j + y + nn) % nn});
    }
}