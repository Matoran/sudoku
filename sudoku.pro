QT += core
QT -= gui

CONFIG += c++11

TARGET = sudoku
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sudokustate.cpp \
    sudokusolver.cpp

HEADERS += \
    sudokustate.h \
    sudokusolver.h
