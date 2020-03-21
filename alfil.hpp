#pragma once

#include "pieza.hpp"
#include <iostream>

using namespace std;

class alfil : public pieza{
    public:
        alfil(){};
        bool validarMovimiento( int x, int y );
};

bool alfil::validarMovimiento( int x, int y ){
    bool valido = false;
    if( x - y == (*this).getX()-(*this).getY()) valido = true;
    return valido;
}