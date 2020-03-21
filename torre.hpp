#pragma once

#include "pieza.hpp"
#include <iostream>

using namespace std;

class torre : public pieza{
    public:
        torre(){};
        bool validarMovimiento( int x, int y );
};

bool torre::validarMovimiento( int x, int y ){
    bool valido = false;
    if( (*this).getY() == y || (*this).getX() == x ) valido = true;
    return valido;
}