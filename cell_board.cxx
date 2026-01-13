#include "cell_board.h"

CellBoard::CellBoard(int N)
{
    arr.reserve(N);

    for (auto i = 0; i < N; ++i)
    {
        // create a new line in the board and add it
        Array1D<Cell> line;
        line.reserve(N);

        for (auto j = 0; j < N; ++j)
        {
            // line.push_back(Cell{i, j});
            line.emplace_back(i, j);
        }

        arr.push_back(line);
    }


}