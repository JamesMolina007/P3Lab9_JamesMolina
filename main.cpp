#include <iostream>
#include "jugador.hpp"
#include "pieza.hpp"
#include "reina.hpp"
#include "rey.hpp"
#include "peon.hpp"
#include "caballo.hpp"
#include "alfil.hpp"
#include "torre.hpp"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void comienzo();
void jugar();
void recrear();
void tablero();
int getCoordenadaX( string coordenada, int eje);
int getCoordenadaY( string coordenada, int eje);
void mover(int,int,int,int);

rey _r1, _r2;
pieza matrix[8][8];
jugador *player1 = new jugador;
jugador *player2 = new jugador; 
pieza *aux;
caballo c;
reina r;
rey R;
alfil a;
peon p;
torre t;

ofstream Partida("Partida.txt", ios::app );

int main(){
    int opcion;
    do{
        cout << "0- Salir" << endl;
        cout << "1- Jugar Partida" << endl;
        cout << "2- Recrear Partida" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        if( opcion == 1 ) jugar();
        if( opcion == 2 ) recrear();
    }while( opcion );
    return 0;
}

void escogerPieza( ){
    int numero;
    do{
        cout << endl << endl;
        cout << "1- Reina\n2- Torre\n3- Alfil\n4- Caballo\n5- Peon\n";
        cout << "Ingrese una Pieza: ";
        cin >> numero;
        switch( numero ){
            case 1:{
                aux = &r;
                aux->posX1 = 3;
                aux->posX2 = 3;
                aux->posY1 = 0;
                aux->posY2 = 7;
                aux->setSimbolo( "r" );
            }
                    break;
            case 2:{
                aux = &t;
                aux->posX1 = 0;
                aux->posX2 = 7;
                aux->posY1 = 0;
                aux->posY2 = 7;
                aux->setSimbolo( "t" );
            }
                    break;
            case 3:{
                aux = &a;
                aux->posX1 = 2;
                aux->posX2 = 5;
                aux->posY1 = 0;
                aux->posY2 = 7;
                aux->setSimbolo( "a" );
            }
                    break;
            case 4:{
                aux = &c;
                aux->posX1 = 1;
                aux->posX2 = 6;
                aux->posY1 = 0;
                aux->posY2 = 7;
                aux->setSimbolo( "c" );
            }
                    break;
            case 5:{
                aux = &p;
                aux->posX1 = 4;
                aux->posX2 = 4;
                aux->posY1 = 1;
                aux->posY2 = 6;
                aux->setSimbolo( "p" );
            }
                    break;
        }
    }while( numero < 1 || numero > 5);
    aux->setX( aux->posX1 );
    aux->setY( aux->posY1 );
    player1->setPieza( *aux );
    aux->setX( aux->posX2 );
    aux->setY( aux->posY2 );
    player2->setPieza( *aux );
    cout << "Direccion " << &aux << endl;
    cout << "Contenido " << aux->toString();
}


void jugar(){
    string j1, j2, partida;
    cout << "Ingrese el nombre de la partida: ";
    cin >> partida; 
    cout << endl;
    cout << "Ingrese el nombre del jugador #1: ";
    cin >> j1;
    player1->setNombre( j1 );
    cout << "Ingrese el nombre del jugador #2: ";
    cin >> j2;
    Partida << j1 << " VS. " << j2 << endl;
    Partida << partida << endl;
    player2->setNombre( j2 );
    escogerPieza();
    _r1.setY(0);
    _r1.setX(4);
    _r1.setSimbolo("R");
    _r2.setSimbolo("R");
    _r2.setY(7);
    _r2.setX(4);
    player1->setRey(_r1);
    player1->setRey(_r2);
    matrix[0][4] = _r1;
    matrix[7][4] = _r2;
    matrix[player1->getPieza().getY()][player1->getPieza().getX()] = player1->getPieza();
    matrix[player2->getPieza().getY()][player2->getPieza().getX()] = player2->getPieza();
    tablero();
    comienzo();
}

void tablero(){
    cout << endl;
    cout << endl;
    pieza vacio;
    for (size_t i = 0; i < 8; i++){
        cout << 8 - i << " ";
        for (size_t j = 0; j < 8; j++){
            cout << "[";
            if( matrix[i][j].toString() == "" ) cout << " ]";
            else cout << matrix[i][j].toString() << "]";
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
    cout << endl;
}

void comienzo(){
    char continuar;
    int cont = 1;
    do{   
        cout << endl << endl;
        string coordenada;
        cout << "Jugador #1: " << endl;
        cout << "Ingrese las coordenadas(Ejemplo->[e1,f2]): ";
        cin >> coordenada;
        int piezaX = (getCoordenadaX( coordenada, 1)-8)*-1;
        int piezaY = (getCoordenadaY( coordenada, 1 ));
        aux->setX( piezaX );
        aux->setY( piezaY );
        int paraderoX = (getCoordenadaX( coordenada, 2)-8)*-1 ;
        int paraderoY = (getCoordenadaY( coordenada, 2 ));
       if( aux->validarMovimiento(paraderoX, paraderoY) ){
            mover( piezaX,piezaY,paraderoX,paraderoY);
        }
        else{
            cout << endl << endl;
            cout << "Movimiento no permitido" << endl;
        }
        Partida << "[" << paraderoX << "," << paraderoY << "];";
        tablero();
        cout << "Jugador #2: " << endl;
        cout << "Ingrese las coordenadas(Ejemplo->[e1,f2]): ";
        cin >> coordenada;
        aux->setX( piezaX );
        aux->setY( piezaY );
        piezaX = (getCoordenadaX( coordenada, 1 )  - 8)*-1;
        piezaY = getCoordenadaY( coordenada, 1);
        paraderoX = (getCoordenadaX( coordenada, 2 ) -8)*-1 ;
        paraderoY = getCoordenadaY( coordenada, 2 );
        if( aux->validarMovimiento(paraderoX, paraderoY) ){
            mover( piezaX,piezaY,paraderoX,paraderoY);
        }
        else{
            cout << endl << endl;
            cout << "Movimiento no permitido" << endl;
        }
       Partida << "[" << paraderoX << "," << paraderoY << "];";
        tablero();
        if( cont % 2 ){
            cout << "Desea continuar[s/n]: ";
            cin >> continuar;
        }
        cont++;
    }while( continuar != 'n' );
    delete player1;
    delete player2;
    Partida << endl << "------------------------------" << endl;
}

int getCoordenadaX( string coordenada, int eje ){
    if( eje == 1 )return (int)coordenada[2]-48;
    else return (int)coordenada[5]-48;
}

int getCoordenadaY( string coordenada, int eje){
    if( eje == 1 )return (int)coordenada[1]-97;
    else return (int)coordenada[4]-97;
}

void mover( int x, int y, int fx, int fy ){
    pieza temp = matrix[x][y];
    pieza vacio;
    matrix[x][y] = vacio;
    matrix[fx][fy] = temp;
}

void recrear(){
   
}