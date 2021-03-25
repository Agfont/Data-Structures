/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.h
 * Author: arthurfont
 *
 * Created on April 20, 2019, 3:55 PM
 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <string>
using namespace std;

class Mountain {
public:
    // Constructor i Destructor
    Mountain();
    Mountain(int id, string nom, int alcada);
    Mountain(const Mountain& orig);
    virtual ~Mountain();
    
    // Consultors
    int getId() const;
    int getHeight() const;
    string getName() const;
    string toString() const;
    
    // Modificadors
    void setId(int id);
    void setHeight(int alcada);
    void setName(string nom);
    
private:
    // Atributs
    int id, alcada;
    string nom;
};

#endif /* MOUNTAIN_H */

