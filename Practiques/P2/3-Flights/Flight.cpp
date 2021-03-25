/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.cpp
 * Author: arthurfont
 * 
 * Created on March 10, 2019, 9:15 PM
 */

#include "Flight.h"
#include <string>

using namespace std;

Flight::Flight() {
}

Flight::Flight(const Flight& orig) {
}

Flight::~Flight() {
}

void Flight::setId(string s){
    this->id = s;
}
    
void Flight::setOrigen(string s){
    this->origen = s;
}
    
void Flight::setDesti(string s){
    this->desti = s;
}
    
void Flight::setHora(string s){
    this->hora_sortida = s;
}

string Flight::getId() const{
    return this->id;
}
    
string Flight::getOrigen() const{
    return this->origen;
}
    
string Flight::getDesti() const{
    return this->desti;
}
    
string Flight::getHora() const{
    return this->hora_sortida;
}

string Flight::toString() const{
    return (this->id + ", " + this->origen + ", " + this->desti + ", " + this->hora_sortida);
}