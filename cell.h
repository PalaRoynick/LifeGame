#pragma once

#include <vector>
#include <memory>
#include <ranges>

using i_pair = std::pair<int, int>;

class Cell
{
public:
    Cell(int i, int j);

public:
    // cell position in a board
    int i, j;

    // flag to check this cell is alive
    bool alive = false;

    // flag to check if the change of the state is needed
    bool change = false;

    // number of neibs
    static constexpr int nn = 8;

    // list of this cell's neighbors
    std::vector<i_pair> neibs;

private:
    constexpr void fill_neibs() noexcept;
};
