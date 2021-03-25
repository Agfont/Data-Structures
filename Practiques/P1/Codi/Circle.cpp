/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: arthurfont
 * 
 * Created on March 6, 2019, 10:57 PM
 */

#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() {
    cout << "Constructor del Cercle\n";
}

Circle::Circle(const Circle& orig) {
}

Circle::~Circle() {
    cout << "Destructor del cercle\n";
}

float Circle::getArea(){
    return (3.14)*r1*r1;
}

void Circle::setRadis(int r1){
    this->r1 = r1;
}

int Circle::excepcio(int a){
    if(a <= 0){
        throw invalid_argument{"Valor negatiu"};
        return -1;
    }
    else return 0;
}