/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.cpp
 * Author: arthurfont
 * 
 * Created on April 20, 2019, 3:55 PM
 */

#include "Mountain.h"
#include <string>

using namespace std;

Mountain::Mountain() {
    this->id = 0;
    this->nom = "";
    this->alcada = 0;
}

Mountain::Mountain(int id, string nom, int alcada) {
    this->id = id;
    this->nom = nom;
    this->alcada = alcada;   
}

Mountain::Mountain(const Mountain& orig) {
    this->id = orig.id;
    this->nom = orig.nom;
    this->alcada = orig.alcada; 
}

Mountain::~Mountain() {
    this->id = 0;
    this->nom = "";
    this->alcada = 0; 
}

int Mountain::getId() const {
    return this->id;
}

string Mountain::getName() const {
    return this->nom;
}

int Mountain::getHeight() const {
    return this->alcada;
}

void Mountain::setId(int id) {
    this->id = id;
}

void Mountain::setName(string nom) {
    this->nom = nom;
}

void Mountain::setHeight(int alcada) {
    this->alcada = alcada;
}

string Mountain::toString() const{
    return (to_string(this->id) + "::" + this->nom + "::" + to_string(this->alcada) + "\n");
}



