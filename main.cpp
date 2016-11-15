/*
 * Author: LOPES Marco
 * Purpose: Solve a sudoku
 * Date : november 2016
 */
#include "sudokustate.h"
#include "sudokusolver.h"
#include <iostream>
#include <QElapsedTimer>

/*
 *   Create the sudoku and the call the sudoku solver
 */
int main()
{
    SudokuState sudoku;
    std::cout << "Enter your sudoku configuration" << std::endl;
    sudoku.init();
    sudoku.display();


    QElapsedTimer timer;
    qint64 nanoSec;
    timer.start();
    if(SudokuSolver::solve(sudoku)){
        nanoSec = timer.nsecsElapsed();
        std::cout << "solved in " << nanoSec/1000 << " microsecond(s)" << std::endl;
        sudoku.display();
    }else{
        std::cout << "unsolvable" << std::endl;
    }
}
