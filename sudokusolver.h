#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "sudokustate.h"
#define EMPTY 0
#define FULL 81


class SudokuSolver
{
public:
    SudokuSolver();
    static bool solve(SudokuState &sudoku);
};

#endif // SUDOKUSOLVER_H
