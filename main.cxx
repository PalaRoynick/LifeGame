#include <format>
#include <iostream>
#include <algorithm>

#include "state_machine.h"

int main(int argc, char* argv[])
{
    // for now, there is no error checks

    int N, M, i, j;

    // board size
    std::cin >> N;

    // initial amout of cells alive
    std::cin >> M;

    // next read M pair of numbers (i,j): positions of cells alive
    std::vector<i_pair> init_alive_cells;
    init_alive_cells.reserve(M);
    for (auto p = 0; p < M; ++p)
    {
        std::cin >> i;
        std::cin >> j;
        init_alive_cells.push_back(std::make_pair(i,j));
    }

    std::cout << std::format("Size of the board: {}\n", N);
    std::cout << std::format("Initial amount of cells alive: {}\n", M);
    std::cout << "Initial positions of cells alive:\n";
    for (auto i = 0; i < N; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            if (std::find(
                init_alive_cells.begin(), init_alive_cells.end(), i_pair{i,j})
                != init_alive_cells.end())
            {
                std::cout << "0 ";
            }
            else
            {
                std::cout << "+ ";
            }
        }
        std::cout << "\n";
    }

    // Cell cell(0,0);
    // std::cout << "Neigbours of cell(0,0):\n";
    // for (auto& p : cell.neibs)
    // {
    //     std::cout << std::format("({}, {}) ", p.first, p.second);
    // }

    // =================================================== //

    CellBoard board{N};
    for (const auto& p : init_alive_cells)
    {
        board[p.first, p.second].alive = true;
    }

    StateMachine machine(std::move(board));

    // for now just do a couple of iterations
    machine.step();
    machine.draw();

    machine.step();
    machine.draw();

    machine.step();
    machine.draw();

    machine.step();
    machine.draw();
}