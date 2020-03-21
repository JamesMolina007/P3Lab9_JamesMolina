#pragma once
#include <iostream>
#include "pieza.hpp"

using namespace std;

class reina : public pieza{
    public:
        reina(){};
        bool validarMovimiento( int x, int y );
};

bool reina::validarMovimiento( int x, int y ){
    bool valido = false;
    if( (*this).getY() == y || (*this).getX() == x ) valido = true;
    if( x - y == (*this).getX()-(*this).getY()) valido = true;
    return valido;
}