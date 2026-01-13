#include "cell.h"
#include "cell_board.h"

class StateMachine
{
public:
    StateMachine(const CellBoard&);

    StateMachine(CellBoard&&);

    // make one iteration of the process
    void step();

    // make output to chosen UI system
    void draw();

private:
    // checks if it is needed to change the state of the given cell
    // returns true if needed
    constexpr bool check(const Cell&) const;
    constexpr bool check(int i, int j) const;

public:
    // cell board to check states of cells
    CellBoard board;
};