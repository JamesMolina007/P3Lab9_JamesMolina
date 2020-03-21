#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


ofstream Partida("bitacoraPartidas.txt", ios::app );

class partida{
    private:
        string nombre;
        string pieza;
        string simbolo;
        vector<string> movimientos;
    public:
        partida(){};
        partida( string pieza );
        void setPieza( string pieza ){ this->pieza = pieza; }
        void setNombre( string nombre ){ this->nombre = nombre; }
        void setMovimiento( string movimiento ){ movimientos.push_back(movimiento); }
        string getPieza(){ return pieza; }
        string getNombre(){ return nombre; }
        void setSimbolo(string simbolo){ this->simbolo = simbolo; }
        vector<string> getMovimientos(){ return movimientos; }
        void guardarpartida(){
            Partida << nombre << endl;
            Partida << pieza << endl;
            for (size_t i = 0; i < movimientos.size(); i++){
                Partida <<  movimientos[i] << ";";
            }
            Partida << endl << "-------------------------" << endl;
        };
};