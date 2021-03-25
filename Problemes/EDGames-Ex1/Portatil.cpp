/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   portatil.cpp
 * Author: arthurfont
 * 
 * Created on March 7, 2019, 1:21 PM
 */

#include "Portatil.h"
#include "Pc.h"
#include <iostream>
using namespace std; 

Portatil::Portatil(){
    // this->super();
    this->duracionBat = 0;
}

Portatil::Portatil(const Portatil& orig) {
}

Portatil::~Portatil() {
}

void Portatil::capturar() {
    int e;
    cout << "Horas de bateria: ";
    cin >> e; 
    this->establecer(e);
}

void Portatil::establecer(int e) {
    this->duracionBat = e;
}

void Portatil::imprimir() {
    cout << "Soc un portatil con " << this->duracionBat << " hrs de bateria." << endl;
}


