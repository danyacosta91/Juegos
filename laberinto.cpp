#include "laberinto.h"

laberinto::laberinto()
{
    int n = 10;

    char** tablero;
    tablero = new char*[n];

    for (int i = 0; i < n; i++)
        tablero[i] = new char[n];

    //se crea un tablero temporal
    char tmp[10][10] = {{'E', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
                        {'*', ' ', '*', ' ', '*', '*', ' ', '*', '*', ' '},
                        {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
                        {'*', ' ', '*', '*', ' ', '*', ' ', '*', '*', '*'},
                        {'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' '},
                        {'*', '*', ' ', '*', '*', '*', '*', '*', ' ', '*'},
                        {' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*'},
                        {' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', '*'},
                        {' ', '*', ' ', '*', ' ', '*', '*', '*', '*', '*'},
                        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', 'S'}};

    //Copiamos todo al tablero original
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            tablero[i][j] = tmp[i][j];
    }

    cout << "TABLERO INICIAL:" << endl;

    for (int i = 0; i < n;  i++)
    {
        for (int j = 0; j < n; j++)
            cout << tablero[i][j];
        cout << endl;
    }

    if ( bt(tablero, n, 0, 0) )
    {
        cout << "\nHAY SOLUCION" << endl;
        cout << endl << "TABLERO RESUELTO:" << endl;

        for (int i = 0; i < n;  i++)
        {
            for (int j = 0; j < n; j++)
                cout << tablero[i][j];
            cout << endl;
        }
    }
    else
        cout << "No hay solucion\n" << endl;

    //liberamos la memoria
    for (int i = 0; i < n; i++)
        if (tablero[i])
            delete tablero[i];
    if (tablero)
        delete tablero;
}

bool laberinto::bt(char** tablero, int n, int fila, int columna)
{
    if( (fila == (n-1)) && (columna == (n-1)) )//pregunta si es una solucion, si se llego al final, osea que la fila y columna sean la ultima posicion del arreglo{
    {
        tablero[fila][columna] = '#';
        return true;//retorna verdadero si es una solucion
    }

    tablero[fila][columna] = '#';//marca camino por donde paso

    //Revisamos si podemos movernos hacia la derecha
    if( ((columna + 1) < (n)) && (tablero[fila][columna + 1] == ' ' || tablero[fila][columna + 1] == 'E' || tablero[fila][columna + 1] == 'S') )//pregunta si la columna siguiente en el arreglo esta vacia para ver opcion
    {
        if( bt(tablero, n, fila, columna + 1) )//mira opcion en siguiente columna
            return true;//retorna verdadero si es una opcion
    }

    //Revisamos si podemos movernos hacia abajo
    if( ((fila + 1) < (n)) && (tablero[fila + 1][columna] == ' ' || tablero[fila][columna + 1] == 'E' || tablero[fila][columna + 1] == 'S') )
    {
        if( bt(tablero, n, fila + 1, columna) )
            return true;
    }

    //Revisamos si podemos movernos hacia la izquierda
    if( ((columna - 1) > 0) && (tablero[fila][columna - 1] == ' ' || tablero[fila][columna + 1] == 'E' || tablero[fila][columna + 1] == 'S') )
    {
        if( bt(tablero, n, fila, columna - 1) )
            return true;
    }

    //Revisamos si podemos movernos hacia arriba
    if( ((fila - 1) > 0) && (tablero[fila - 1][columna] == ' ' || tablero[fila][columna + 1] == 'E' || tablero[fila][columna + 1] == 'S') )
    {
        if( bt(tablero, n, fila - 1, columna) )
            return true;
    }

    tablero[fila][columna] = ' ';//desmarca el camino si no es una opcion
    return false;//retorna falso ya que no es opcion
}//fin backtracking

