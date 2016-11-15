/*
 * Author: LOPES Marco
 * Purpose: Stock a sudoku state
 * Date : november 2016
 */
#include "sudokustate.h"
#include <iostream>
#include <QStack>

/*
 *   Constructor, Initialise sudoku without any constraint
 */
SudokuState::SudokuState()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            this->linesConstraints[i].insert(j);
            this->columnsConstraints[i].insert(j);
            this->squaresConstraints[i].insert(j);
        }
    }
}

/*
 *   Read sudoku configuration from console and add constraints
 *
 *   returns: void
 */
void SudokuState::init()
{
    for (int line = 0; line < 9; ++line) {
        for (int column = 0; column < 9; ++column) {
            int number;
            std::cin >> number;
            this->cases[line][column] = number;
            this->addConstraint(line, column, number);
        }
    }
}

/*
 *   Display the disposition of the sudoku
 *
 *   returns: void
 */
void SudokuState::display() const
{
    std::cout << std::endl;
    for (int line = 0; line < 9; ++line) {
        if(line % 3 == 0)
            std::cout << "+-------+-------+-------+" << std::endl;
        for (int column = 0; column < 9; ++column) {
            if(column % 3 == 0)
                std::cout << "| ";
            if(this->cases[line][column] != 0)
                std::cout << this->cases[line][column] << " ";
            else
                std::cout << "- ";
        }
        std::cout << "| ";
        std::cout << std::endl;
    }
    std::cout << "+-------+-------+-------+" << std::endl;
    std::cout << std::endl;
}


/*
 *   Add a constraint in line, column and subsquare
 *
 *   line: where make the constraint
 *   column: where make the constraint
 *   value: the constraint
 *
 *   returns: void
 */
void SudokuState::addConstraint(int line, int column, int value)
{
    this->linesConstraints[line].remove(value);
    this->columnsConstraints[column].remove(value);
    this->squaresConstraints[this->squareNumber(line, column)].remove(value);
}

/*
 *   Make the intersection between line, column and square constraints
 *
 *   line: the line of the case
 *   column: the column of the case
 *
 *   returns: QSet<int> which contain the possibilities for one case
 */
QSet<int> SudokuState::getIntersect(int line, int column) const
{
    return this->linesConstraints[line] & this->columnsConstraints[column] & this->squaresConstraints[this->squareNumber(line, column)];
}

/*
 *   Get a value of one case
 *
 *   line: the line of the case
 *   column: the column of the case
 *
 *   returns: the value of the case
 */
int SudokuState::getCase(int line, int column) const
{
    return this->cases[line][column];
}

/*
 *   Set a value of one case
 *
 *   line: the line of the case
 *   column: the column of the case
 *   value: the value to set
 *
 *   returns: void
 */
void SudokuState::setCase(int line, int column, int value)
{
    this->cases[line][column] = value;
}

/*
 *   Get the number of the subsquare
 *
 *   line: the line of the case
 *   column: the column of the case
 *
 *   returns: the number of the subsquare
 */
int SudokuState::squareNumber(int line, int column) const
{
    return line/3*3+column/3;
}

bool SudokuState::getBacktracking() const
{
    return backtracking;
}

void SudokuState::setBacktracking(bool value)
{
    backtracking = value;
}
