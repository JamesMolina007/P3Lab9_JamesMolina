#pragma once

#include "pieza.hpp"


class peon : public pieza{
    public:
        peon(){};
        bool validarMovimiento( int x, int y );
};

bool peon::validarMovimiento( int x, int y ){
    bool valido = false;
    if( (*this).getX()-1 == x && (*this).getY() == y ) valido = true;
    if( (*this).getX()+1 == x && (*this).getY() == y ) valido = true;
    return valido;
}