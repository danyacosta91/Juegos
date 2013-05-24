#ifndef TRESENRAYA_H
#define TRESENRAYA_H

#include <iostream>
using namespace std;

class TresEnRaya
{
    private:
        char t[][3];
        int mejorFila, mejorCol, MAX, GRANDE, MIN;
        char NADIE, JUGADOR, COMPUTADOR;
    public:
        TresEnRaya();
        void impTablero();
        int bt(int);
        int eval();
};

#endif // TRESENRAYA_H
