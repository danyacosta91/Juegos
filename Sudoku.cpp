#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(){
    IniciarTablero();

    cout<<"sudoku antes de resolver:\n";
    imprimir();
    if( Backtracking() ){
        cout<<"esta es la respuesta:\n";
        imprimir();
        cout<<"solucion!!\n";
    }else
        cout<<" no hay solucion\n";
}

void Sudoku::IniciarTablero(){
    tablero[0][0]=0;tablero[0][1]=6;tablero[0][2]=0;tablero[0][3]=4;tablero[0][4]=7;tablero[0][5]=0;tablero[0][6]=0;tablero[0][7]=2;tablero[0][8]=5;
    tablero[1][0]=0;tablero[1][1]=7;tablero[1][2]=4;tablero[1][3]=0;tablero[1][4]=1;tablero[1][5]=0;tablero[1][6]=8;tablero[1][7]=0;tablero[1][8]=3;
    tablero[2][0]=1;tablero[2][1]=0;tablero[2][2]=0;tablero[2][3]=0;tablero[2][4]=0;tablero[2][5]=6;tablero[2][6]=7;tablero[2][7]=9;tablero[2][8]=0;
    tablero[3][0]=0;tablero[3][1]=9;tablero[3][2]=5;tablero[3][3]=0;tablero[3][4]=3;tablero[3][5]=2;tablero[3][6]=4;tablero[3][7]=0;tablero[3][8]=0;
    tablero[4][0]=7;tablero[4][1]=0;tablero[4][2]=2;tablero[4][3]=0;tablero[4][4]=0;tablero[4][5]=9;tablero[4][6]=0;tablero[4][7]=0;tablero[4][8]=1;
    tablero[5][0]=0;tablero[5][1]=0;tablero[5][2]=0;tablero[5][3]=5;tablero[5][4]=0;tablero[5][5]=7;tablero[5][6]=2;tablero[5][7]=8;tablero[5][8]=0;
    tablero[6][0]=6;tablero[6][1]=0;tablero[6][2]=1;tablero[6][3]=3;tablero[6][4]=5;tablero[6][5]=0;tablero[6][6]=0;tablero[6][7]=0;tablero[6][8]=0;
    tablero[7][0]=0;tablero[7][1]=0;tablero[7][2]=0;tablero[7][3]=7;tablero[7][4]=0;tablero[7][5]=0;tablero[7][6]=6;tablero[7][7]=1;tablero[7][8]=8;
    tablero[8][0]=4;tablero[8][1]=8;tablero[8][2]=0;tablero[8][3]=0;tablero[8][4]=9;tablero[8][5]=0;tablero[8][6]=3;tablero[8][7]=0;tablero[8][8]=0;
}

void Sudoku::setValor(int x,int y,int valor){
    tablero[x][y] = valor;
}

int Sudoku::getValor(int x,int y){
    return tablero[x][y];
}

void Sudoku::imprimir(){
    cout<<"-------------------------------------\n";
    for( int i = 0; i < 9; i++){
        for( int j = 0; j < 9;j++){
            cout<<"| ";
            if( tablero[i][j] == 0){
                cout<<" ";
            } else {
                cout<<tablero[i][j];
            }
            cout<<" ";
        }
        cout<<"|\n-------------------------------------\n";
    }
}

bool Sudoku::esSolucion(){
    int tmp;
    for(int i= 0 ;i<9;i++){
        for(int j = 0;j < 9;j++){
            if( getValor(i,j) == 0) {
                return false;
            }
        }
    }

    int temp[9];
    int cont;
    for(int i = 0;i<9;i++){
        for(int j = 0;j <9;j++){
            temp[j] = getValor(i,j);
        }

        for (int j = 1; j <= 9; j++) {
            for (int i=0; i< 8; i++) {
                if (temp[i] > temp[i+1]){
                    tmp = temp[i];
                    temp[i] = temp[i+1];
                    temp[i+1] = tmp;
                }
            }
        }
        for( int i = 0; i < 9; i++){
            if( temp[i] != i+1){
                return false;
            }
        }


    }

    for(int i = 0;i<9;i++){
        for(int j = 0;j <9;j++){
            temp[j] = getValor(j,i);
        }
        for (int j = 1; j <= 9; j++) {
            for (int i=0; i< 8; i++) {
                if (temp[i] > temp[i+1]){
                    tmp = temp[i];
                    temp[i] = temp[i+1];
                    temp[i+1] = tmp;
                }
            }
        }

        for( int i = 0; i < 9; i++){
            if( temp[i] != i+1){
                return false;
            }
        }


    }

    int uno,dos,tres,cuatro;
    for(int i = 0;i<9;i++){
        switch(i){
        case 0: uno = 0;dos = 3; tres = 0; cuatro = 3; break;
        case 1: uno = 0;dos = 3; tres = 3; cuatro = 6; break;
        case 2: uno = 0;dos = 3; tres = 6; cuatro = 9; break;
        case 3: uno = 3;dos = 6; tres = 0; cuatro = 3; break;
        case 4: uno = 3;dos = 6; tres = 3; cuatro = 6; break;
        case 5: uno = 3;dos = 6; tres = 6; cuatro = 9; break;
        case 6: uno = 6;dos = 9; tres = 0; cuatro = 3; break;
        case 7: uno = 6;dos = 9; tres = 3; cuatro = 6; break;
        case 8: uno = 6;dos = 9; tres = 6; cuatro = 9; break;
        }
        cont = 0;
        for(int i = uno; i < dos; i++){
            for(int j = tres; j < cuatro;j++){
                temp[cont] = getValor(i,j);
                cont++;
            }
        }

        for (int j = 1; j <= 9; j++) {
            for (int i=0; i< 8; i++) {
                if (temp[i] > temp[i+1]){
                    tmp = temp[i];
                    temp[i] = temp[i+1];
                    temp[i+1] = tmp;
                }
            }
        }

        for( int i = 0; i < 9; i++){
            if( temp[i] != i+1) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::Repetidos(){
    int temp[9];
    int cont,uno,dos,tres,cuatro;
    for(int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++){
            temp[j] = getValor(i,j);
        }
        for (int j = 0;j < 9; j++){
            if( temp[j] != 0){
                cont = 0;
                for(int x = 0;x<9;x++){
                    if( temp[j] == temp[x]){
                        cont++;
                    }
                }
                if(cont != 1) {
                    return true;
                }
            }
        }


        for (int j = 0; j < 9;j++){
            temp[j] = getValor(j,i);
        }
        for (int j = 0;j < 9; j++){
            if( temp[j] != 0){
                cont = 0;
                for(int x = 0;x<9;x++){
                    if( temp[j] == temp[x]){
                        cont++;
                    }
                }
                if(cont != 1) {
                    return true;
                }
            }
        }



        switch(i){
        case 0: uno = 0;dos = 3; tres = 0; cuatro = 3; break;
        case 1: uno = 0;dos = 3; tres = 3; cuatro = 6; break;
        case 2: uno = 0;dos = 3; tres = 6; cuatro = 9; break;
        case 3: uno = 3;dos = 6; tres = 0; cuatro = 3; break;
        case 4: uno = 3;dos = 6; tres = 3; cuatro = 6; break;
        case 5: uno = 3;dos = 6; tres = 6; cuatro = 9; break;
        case 6: uno = 6;dos = 9; tres = 0; cuatro = 3; break;
        case 7: uno = 6;dos = 9; tres = 3; cuatro = 6; break;
        case 8: uno = 6;dos = 9; tres = 6; cuatro = 9; break;
        }
        cont = 0;
        for(int i = uno; i < dos; i++){
            for(int j = tres; j < cuatro;j++){
                temp[cont] = getValor(i,j);
                cont++;
            }
        }

        for (int j = 0;j < 9; j++){
            if( temp[j] != 0){
                cont = 0;
                for(int x = 0;x<9;x++){
                    if( temp[j] == temp[x]){
                        cont++;
                    }
                }
                if(cont != 1) {
                    return true;
                }
            }
        }

    }
    return false;
}

bool Sudoku::Backtracking(){
    if( esSolucion() ){
        return true;
    } else {
        for(int x = 1; x < 10;x++) {
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){

                    if( getValor(i,j) == 0){
                        setValor(i,j,x);
                        if(Repetidos()){
                        } else {
                            if( Backtracking() ){
                                return true;
                            }
                        }
                        setValor(i,j,0);
                    }

                }
            }
        }
        return false;
    }
}
