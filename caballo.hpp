#pragma once

#include "pieza.hpp"
#include <iostream>

using namespace std;


class caballo : public pieza{
    public:
        caballo(){};
        bool validarMovimiento( int x, int y );
};

bool caballo::validarMovimiento( int x, int y ){
    bool valido = false;
    if( (x == (*this).getX()+2 && ( y == (*this).getY() + 1 || y == (*this).getY() - 1 ) ) ) valido = true;
    if( (x == (*this).getX()-2 && ( y == (*this).getY() + 1 || y == (*this).getY() - 1 ) ) ) valido = true;
    if( (y == (*this).getY()+2 && ( x == (*this).getX() + 1 || x == (*this).getX() - 1 ) ) ) valido = true;
    if( (y == (*this).getY()-2 && ( x == (*this).getX() + 1 || x == (*this).getX() - 1 ) ) ) valido = true;
    return valido;
}