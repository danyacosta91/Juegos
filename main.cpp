#include "tresenraya.h"
#include "laberinto.h"
#include "Sudoku.h"
#include <iostream>
using namespace std;
#define GRANDE 100

#define MAX 1
#define MIN 2

#define NADIE       '-'
#define JUGADOR     'O'
#define COMPUTADOR  'X'

int mejorFila, mejorCol;

char t[][3]=
{
    {NADIE,NADIE,NADIE},
    {NADIE,NADIE,NADIE},
    {NADIE,NADIE,NADIE}
};
void iniciarTablero()
{
    t[0][0] = NADIE;t[0][1] = NADIE;t[0][2] = NADIE;
    t[1][0] = NADIE;t[1][1] = NADIE;t[1][2] = NADIE;
    t[2][0] = NADIE;t[2][1] = NADIE;t[2][2] = NADIE;
}

void impTablero()
{
    int i, j;

    cout << "\nTablero\n 012"<<endl;
    for( i = 0; i < 3; i++ )
    {
        cout << i;
        for( j = 0; j < 3; j++ )
            cout << t[i][j];
        cout << endl;
    }
    cout << endl;
}
int eval()
{
    int i, j, ganador = NADIE;

    //Verifica filas
    for( i = 0; i < 3; i++ )
    {
        if( t[i][0] != NADIE && t[i][0] == t[i][1] && t[i][1] == t[i][2] )
            ganador = t[i][0];
    }

    //Verifica columnas
    for( j = 0; j < 3; j++ )
    {
        if( t[0][j] != NADIE && t[0][j] == t[1][j] && t[1][j] == t[2][j] )
            ganador = t[0][j];
    }

    //Verifica diagonal principal
    if( t[0][0] != NADIE && t[0][0] == t[1][1] && t[1][1] == t[2][2] )
        ganador = t[0][0];

    //Verifica diagonal secundaria
    if( t[0][2] != NADIE && t[0][2] == t[1][1] && t[1][1] == t[2][0] )
        ganador = t[0][2];

    //Verifica ganador
    if( ganador == JUGADOR )
        return -1;
    if( ganador == COMPUTADOR )
        return 1;

    //Verifica si hay casillas vacias
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 3; j++ )
        {
            if( t[i][j] == NADIE )
                return 2;
        }
    }

    return 0;
}
int bt( int modo )
{
    int i, j, val, mfLocal, mcLocal;
    int valor = eval();

    if( valor != 2 )
        return valor;

    if( modo == MAX )
        valor = -GRANDE;
    else
        valor = GRANDE;

    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 3; j++ )
        {
            if( t[i][j] == NADIE )
            {
                if( modo == MAX )
                {
                    t[i][j] = COMPUTADOR;
                    val = bt(MIN);
                    if( valor < val )
                    {
                        valor = val;
                        mfLocal = i;
                        mcLocal = j;
                    }
                }else
                {
                    t[i][j] = JUGADOR;
                    val = bt(MAX);
                    if( valor > val )
                    {
                        valor = val;
                        mfLocal = i;
                        mcLocal = j;
                    }
                }
                t[i][j] = NADIE;
            }
        }
    }
    mejorFila = mfLocal;
    mejorCol = mcLocal;

    return valor;
}

int menu()
{
    int opcion = 0;

    cout << "Menu\n1) X-0.\n2) SUDOKU.\n3) LABERINTO.\n4) SALIR.\n\nIngrese opcion:" <<endl;
    cin >> opcion;

    return opcion;
}

int main()
{
    int m;
    laberinto *l;Sudoku *s;

    do
    {
        m = menu();
        switch( m )
        {
        case 1:
            int f, c, ganador;
            impTablero();
            do
            {
                do
                {
                    cout << "Su turno"<<endl;
                    cout << "Fila: ";
                    cin >> f;
                    cout << "Columna: ";
                    cin >> c;
                }while( (f<0 || f>=3 || c<0 || c>=3) || t[f][c] != NADIE );

                t[f][c] = JUGADOR;
                impTablero();
                bt(MAX);
                cout << "Computadora" << endl;
                cout << "Fila: " << mejorFila << endl;
                cout << "Fila: " << mejorCol << endl;
                t[mejorFila][mejorCol] = COMPUTADOR;
                impTablero();
                ganador = eval();
            }while( ganador == 2 );

            if( ganador == -1)
                cout << "UD GANA...!!!" << endl;
            else if( ganador == 1)
                cout << "COMPUTADOR GANA...!!!" << endl;
            else
                cout << "EMPATE...!!!" << endl;
            iniciarTablero();

            break;
        case 2:
            s = new Sudoku();
            delete s;
            break;
        case 3:
            l = new laberinto();
            delete l;
            break;
        case 4:
            break;
        default:
            cout << "Error de datos ingresados... \n" << endl;
        }
    }while( m != 4 );

    return 0;
}
