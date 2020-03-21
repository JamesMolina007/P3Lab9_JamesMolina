#pragma once
#include <string>
#include <iostream>
using namespace std;

class pieza{
    private:
        string nombre;
        int x;
        int y;
        string simbolo;
    public:
        pieza(){};
        pieza(string nombre){};
        int posX1;
        int posX2;
        int posY1;
        int posY2;
        void setX( int x ){ this-> x = x; }
        void setY( int y ){ this-> y = y; }
        void setSimbolo( string simbolo ){ this->simbolo = simbolo; }
        int getX(){ return x; }
        int getY(){ return y; }
        string toString(){ return simbolo; }
        virtual bool validarMovimiento( int x, int y ){cout << "Entro al que no debia" << endl;}
        
};


