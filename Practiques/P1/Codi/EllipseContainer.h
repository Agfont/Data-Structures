/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 10:58 PM
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H

using namespace std;
#include "Ellipse.h"
#include <vector>

class EllipseContainer {
public:
    EllipseContainer();
    EllipseContainer(const EllipseContainer& orig);
    virtual ~EllipseContainer();
    void addEllipse(Ellipse* ellipsePunter);
    float getArea();
private:
    vector<Ellipse*> nouContenidor;
};

#endif /* ELLIPSECONTAINER_H */

