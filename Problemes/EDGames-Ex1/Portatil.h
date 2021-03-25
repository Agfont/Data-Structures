/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   portatil.h
 * Author: arthurfont
 *
 * Created on March 7, 2019, 1:21 PM
 */

#ifndef PORTATIL_H
#define PORTATIL_H

#include "Pc.h"

class Portatil: public Pc {
public:
    Portatil();
    Portatil(const Portatil& orig);
    virtual ~Portatil();
    void capturar();
    void imprimir();
    void establecer(int e);
private:
    double duracionBat;

};

#endif /* PORTATIL_H */

