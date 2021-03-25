/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: arthurfont
 * 
 * Created on March 6, 2019, 10:58 PM
 */

#include "Ellipse.h"
#include <iostream>

using namespace std;

Ellipse::Ellipse() {
    this->r1 = 0;
    this->r2 = 0;
    cout << "Constructor de l'El·lipse\n";
}

Ellipse::Ellipse(const Ellipse& orig) {
}

Ellipse::~Ellipse() {
    cout << "Destructor de l'elipse\n";
}

void Ellipse::setRadis(int r1, int r2){
    this->r1 = r1;
    this->r2 = r2;
}

float Ellipse::getArea(){
    return r1*r2*(3.14);
}

int Ellipse::excepcio(int a, int b){
    if(a <=0 || b <= 0){
        throw invalid_argument{"Valor negatiu"};
        return -1;
    }
    else return 0;
}

