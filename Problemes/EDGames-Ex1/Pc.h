/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pc.h
 * Author: arthurfont
 *
 * Created on March 7, 2019, 1:21 PM
 */

#ifndef PC_H
#define PC_H

class Pc {
public:
    Pc();
    Pc(const Pc& orig);
    virtual ~Pc();
    virtual void capturar();
    virtual void imprimir();
    virtual void establecer(int e);
    
private:
    int memoria;
};

#endif /* PC_H */

