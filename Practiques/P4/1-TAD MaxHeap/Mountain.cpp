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

/* 
 * Constructor de la muntanya
 */
Mountain::Mountain() {
    this->id = 0;
    this->nom = "";
    this->alcada = 0;
}

/* 
 * Constructor de la muntanya
 */
Mountain::Mountain(int id, string nom, int alcada) {
    this->id = id;
    this->nom = nom;
    this->alcada = alcada;   
}

/* 
 * Constructor copia de la muntanya
 */
Mountain::Mountain(const Mountain& orig) {
    this->id = orig.id;
    this->nom = orig.nom;
    this->alcada = orig.alcada; 
}

/* 
 * Destructor de la muntanya
 */
Mountain::~Mountain() {
    this->id = 0;
    this->nom = "";
    this->alcada = 0; 
}

/* 
 * Retorna el ID de la muntanya
 */
int Mountain::getId() const {
    return this->id;
}

/* 
 * Retorna el nombre de la muntanya
 */
string Mountain::getName() const {
    return this->nom;
}

/* 
 * Retorna la altura de la muntanya
 */
int Mountain::getHeight() const {
    return this->alcada;
}

/* 
 * Modifica el ID de la muntanya
 */
void Mountain::setId(int id) {
    this->id = id;
}

/* 
 * Modifica  el nombre de la muntanya
 */
void Mountain::setName(string nom) {
    this->nom = nom;
}

/* 
 * Modifica  la altura de la muntanya
 */
void Mountain::setHeight(int alcada) {
    this->alcada = alcada;
}

/* 
 * Retorna un string con los dados de la muntanya
 */
string Mountain::toString() const{
    return (to_string(this->id) + "::" + this->nom + "::" + to_string(this->alcada) + "\n");
}