#include "state_machine.h"

#include <iostream>
#include <cassert>
#include <algorithm>

StateMachine::StateMachine(const CellBoard& board)
    : board(board) {}

StateMachine::StateMachine(CellBoard&& board)
    : board(std::move(board)) {}

constexpr bool StateMachine::check(const Cell& cell) const
{
    return check(cell.i, cell.j);
}

constexpr bool StateMachine::check(int i, int j) const
{
    /*
        A live cell with fewer than two live neighbors dies.
        A live cell with two or three live neighbors survives to the next generation.
        A live cell with more than three live neighbors dies from overpopulation.
        A dead cell with exactly three live neighbors becomes alive.
    */

    // find the number of neibs alive
    const auto& cell  = board[i, j];
    const auto& neibs = cell.neibs;
    auto n_neib_alive = std::count_if(neibs.begin(), neibs.end(),
        [this] (const auto& p) {
            int i = p.first;
            int j = p.second;
            const auto& neib = board[i, j];
            return neib.alive;
    });
    assert(n_neib_alive > -1);
    assert(n_neib_alive < 9);

    if (cell.alive)
    {
        if (n_neib_alive < 2 || n_neib_alive > 3)
            return true; // alive -> dead
        return false;    // alive -> alive
    }
    else // cell is dead
    {
        if (n_neib_alive == 3)
            return true; // dead -> alive
    }

    return false;
}

void StateMachine::step()
{
    auto N = board.size();
    for (auto i = 0; i < N; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            board[i, j].change = check(i, j);
        }
    }

    for (auto i = 0; i < N; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            if (board[i, j].change)
            {
                board[i, j].alive = !board[i, j].alive;
            }
        }
    }
}

void StateMachine::draw()
{
    auto N = board.size();
    std::cout << "\n";
    for (auto i = 0; i < N; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            if (board[i, j].alive)
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
}