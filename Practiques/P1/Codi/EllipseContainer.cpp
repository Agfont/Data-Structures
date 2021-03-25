/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: arthurfont
 * 
 * Created on March 6, 2019, 10:58 PM
 */

#include "EllipseContainer.h"
#include "Circle.h"
#include "Ellipse.h"
#include <vector>
#include <iostream>

using namespace std;


EllipseContainer::EllipseContainer() {
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
    cout << "Cridant destructor del contenidor\n";
    Ellipse* elipsePunterAux;
    for(vector<Ellipse*>::iterator it = nouContenidor.begin(); it!= nouContenidor.end(); ++it){
        elipsePunterAux = *it;
        if(dynamic_cast<Circle*>(elipsePunterAux)){
            delete(Circle*)(elipsePunterAux);
        }
        else if(dynamic_cast<Ellipse*>(elipsePunterAux)){
            delete(Ellipse*)(elipsePunterAux);
        }
    }
    nouContenidor.clear();
}

void EllipseContainer::addEllipse(Ellipse* ellipsePunter){
    this->nouContenidor.push_back(ellipsePunter);
}

float EllipseContainer::getArea() {
    Ellipse* ellipsePunterAux;
    float suma = 0;
    for(vector<Ellipse*>::iterator it = nouContenidor.begin(); it != nouContenidor.end(); ++it){
        ellipsePunterAux = *it;
        suma += ellipsePunterAux->getArea();
    }
    return suma;
}