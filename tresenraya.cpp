#include "tresenraya.h"

TresEnRaya::TresEnRaya()
{
    MAX = 1;MIN = 2;GRANDE=100;
    NADIE = '-';JUGADOR = '0';COMPUTADOR = 'X';

    t[0][0] = '-';t[0][1] = '-';t[0][2] = '-';
    t[1][0] = '-';t[1][1] = '-';t[1][2] = '-';
    t[2][0] = '-';t[2][1] = '-';t[2][2] = '-';

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
        }while( (f<0 || f>=3 || c<0 || c>=3) || t[f][c] != '-' );

        t[f][c] = 'O';
        impTablero();
        bt(MAX);
        cout << "Computadora" << endl;
        cout << "Fila: " << mejorFila << endl;
        cout << "Fila: " << mejorCol << endl;
        t[mejorFila][mejorCol] = 'X';
        impTablero();
        ganador = eval();
    }while( ganador == 2 );

    if( ganador == -1)
        cout << "UD GANA...!!!" << endl;
    else if( ganador == 1)
        cout << "COMPUTADOR GANA...!!!" << endl;
    else
        cout << "EMPATE...!!!" << endl;
}

int TresEnRaya::bt(int modo)
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
            if( t[i][j] == '-' )
            {
                if( modo == MAX )
                {
                    t[i][j] = 'X';
                    impTablero();
                    val = bt(MIN);
                    if( valor < val )
                    {
                        valor = val;
                        mfLocal = i;
                        mcLocal = j;
                    }
                }else
                {
                    t[i][j] = 'O';
                    val = bt(MAX);
                    if( valor > val )
                    {
                        valor = val;
                        mfLocal = i;
                        mcLocal = j;
                    }
                }
                t[i][j] = '-';
            }
        }
    }
    mejorFila = mfLocal;
    mejorCol = mcLocal;

    return valor;
}

int TresEnRaya::eval()
{
    int i, j, ganador = 0;

    //Verifica filas
    for( i = 0; i < 3; i++ )
    {
        if( t[i][0] != '-' && t[i][0] == t[i][1] && t[i][1] == t[i][2] )
            ganador = t[i][0];
    }

    //Verifica columnas
    for( j = 0; j < 3; j++ )
    {
        if( t[0][j] != '-' && t[0][j] == t[1][j] && t[1][j] == t[2][j] )
            ganador = t[0][j];
    }

    //Verifica diagonal principal
    if( t[0][0] != '-' && t[0][0] == t[1][1] && t[1][1] == t[2][2] )
        ganador = t[0][0];

    //Verifica diagonal secundaria
    if( t[0][2] != '-' && t[0][2] == t[1][1] && t[1][1] == t[2][0] )
        ganador = t[0][2];

    //Verifica ganador
    if( ganador == '0' )
        return -1;
    if( ganador == 'X' )
        return 1;

    //Verifica si hay casillas vacias
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 3; j++ )
        {
            if( t[i][j] == '-' )
                return 2;
        }
    }

    return 0;
}

void TresEnRaya::impTablero()
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
