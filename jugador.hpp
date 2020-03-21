#pragma once

#include <string>
#include "pieza.hpp"
#include "rey.hpp"

using namespace std;

class jugador{
    private:
        pieza p;
        rey r;
        string nombre;
    public:
        jugador(){};
        jugador( pieza p, string nombre );
        void setNombre( string nombre ){ this-> nombre = nombre; }
        void setPieza( pieza p ){ this-> p = p; }
        void setRey( rey r ){ this-> r = r; }
        string getNombre(){ return nombre; }
        pieza getPieza(){ return p; }
        rey getRey(){ return r; }
        string toString(){ return nombre; }
};