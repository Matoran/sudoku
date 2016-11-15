#ifndef SUDOKUSTATE_H
#define SUDOKUSTATE_H

#include <QSet>


class SudokuState
{
public:
    SudokuState();
    void init();
    void display() const;
    bool solve();
    void addConstraint(int line, int column, int value);
    int getCase(int line, int column) const;
    void setCase(int line, int column, int value);
    QSet<int> getIntersect(int line, int column) const;
    bool getBacktracking() const;
    void setBacktracking(bool value);

private:
    int squareNumber(int line, int column) const;
    int cases[9][9];
    QSet<int> linesConstraints[9];
    QSet<int> columnsConstraints[9];
    QSet<int> squaresConstraints[9];
    bool backtracking = false;
};

#endif // SUDOKUSTATE_H
