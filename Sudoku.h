#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
using namespace std;

class Sudoku{
   private:
    int tablero[9][9];
   
   public:
     Sudoku();
     void IniciarTablero();
     void setValor(int,int,int);
     int getValor(int,int);
     void imprimir();   
     bool esSolucion();
     bool Repetidos();
     bool Backtracking();
};

#endif
