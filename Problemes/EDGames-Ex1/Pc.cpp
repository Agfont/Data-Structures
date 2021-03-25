/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pc.cpp
 * Author: arthurfont
 * 
 * Created on March 7, 2019, 1:21 PM
 */

#include "Pc.h"
#include <iostream>

using namespace std;

Pc::Pc() {
    this->memoria = 0;
}

Pc::Pc(const Pc& orig) {
}

Pc::~Pc() {
}

void Pc::capturar() {
    int e;
    cout << "Memoria: ";
    cin >> e;
    this->establecer(e);
}

void Pc::establecer(int e) {
    this->memoria = e;
}

void Pc::imprimir() {
    cout << "Soc un pc con " << this->memoria << " GB de memoria." << endl;
}
