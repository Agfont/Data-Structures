/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 10:58 PM
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    Ellipse();
    Ellipse(const Ellipse& orig);
    virtual ~Ellipse();
    void setRadis(int r1, int r2);
    int excepcio(int a, int b);
    virtual float getArea();
private:
    float r1,r2;
};

#endif /* ELLIPSE_H */

