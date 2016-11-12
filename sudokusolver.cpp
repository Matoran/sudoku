/*
 * Author: LOPES Marco
 * Purpose: Solve a sudoku
 * Date : november 2016
 */
#include "sudokusolver.h"
#include <QSet>

SudokuSolver::SudokuSolver(){}

/*
 *   Try to solve a sudoku with contraint method and backtracking
 *
 *   sudoku: sudoku to solve
 *
 *   returns: true if solved false otherwise
 */
bool SudokuSolver::solve(SudokuState &sudoku){
    bool foundEasyCase = false;
    QSet<int> best;
    int bestLine = 0;
    int bestColumn = 0;
    //while we have cases with 1 possibility
    do{
        int casesFilled = 0;
        foundEasyCase = false;
        for (int line = 0; line < 9; ++line) {
            for (int column = 0; column < 9; ++column) {
                if(sudoku.getCase(line, column) == EMPTY){
                    //possibilities for the case
                    QSet<int> intersect = sudoku.getIntersect(line, column);
                    //only one possibility
                    if(intersect.size() == 1){
                        sudoku.setCase(line, column, intersect.toList().first());
                        sudoku.addConstraint(line, column, intersect.toList().first());
                        foundEasyCase = true;
                    //deadend
                    }else if(intersect.size() == EMPTY){
                        return false;
                    //check if it's the best case
                    }else if(best.size() == EMPTY || best.size() > intersect.size()){
                            best = intersect;
                            bestLine = line;
                            bestColumn = column;
                    }
                }else{
                    casesFilled++;
                    //sudoku solved
                    if(casesFilled == FULL){
                        return true;
                    }
                }
            }
        }
    }while(foundEasyCase);

    //if multiple values are possible then try one by one
    foreach (int value, best.toList()) {
        //copy of the current state
        SudokuState backtracking = sudoku;
        backtracking.setCase(bestLine, bestColumn, value);
        backtracking.addConstraint(bestLine, bestColumn, value);
        //backtrack solving
        if(SudokuSolver::solve(backtracking)){
            sudoku = backtracking;
            return true;
        }
    }
    //deadend
    return false;
}
