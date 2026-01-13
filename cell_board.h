#pragma once

#include <vector>

#include "cell.h"

template <typename T>
using Array1D = std::vector<T>;

template <typename T>
using Array2D = std::vector<Array1D<T>>;

class CellBoard
{
public:
    explicit CellBoard(int N);

    Cell& operator[](int i, int j)
    {
        return arr[i][j];
    }

    const Cell& operator[](int i, int j) const
    {
        return arr[i][j];
    }

    size_t size() const
    {
        return arr.size();
    }

private:
    Array2D<Cell> arr;
};