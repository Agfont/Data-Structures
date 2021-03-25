/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 10:57 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Ellipse.h"
class Circle : public Ellipse {
public:
    Circle();
    Circle(const Circle& orig);
    virtual ~Circle();
    float getArea();
    int excepcio(int a);
    void setRadis(int r1);
private:
    float r1;
};

#endif /* CIRCLE_H */

