#pragma once

#include "pieza.hpp"


class rey : public pieza{
    public:
        rey(){};
        bool validarMovimiento( int x, int y);
};

bool rey::validarMovimiento( int x, int y ){
    bool valido = false;
    if( ( x == (*this).getX()-1 && y == (*this).getY() ) || (x == (*this).getX()+1 && y == (*this).getY() ) ) valido = true;
    if( ( y == (*this).getY()-1 && x == (*this).getX() ) || (y == (*this).getY()+1 && x == (*this).getX() ) ) valido = true;
    if( ( x == (*this).getX()+1 && y == (*this).getY()+1)|| (x == (*this).getX()-1 && y == (*this).getY()+1)) valido = true;
    if( ( x == (*this).getX()-1 && y == (*this).getY()-1)|| (x == (*this).getX()+1 && y == (*this).getY()-1)) valido = true;
    return valido;
}