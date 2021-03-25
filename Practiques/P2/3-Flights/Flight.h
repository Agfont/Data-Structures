/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.h
 * Author: arthurfont
 *
 * Created on March 10, 2019, 9:15 PM
 */

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using namespace std;

class Flight {
public:
    Flight();
    Flight(const Flight& orig);
    virtual ~Flight();
    void setId(string s);
    void setOrigen(string s);
    void setDesti(string s);
    void setHora(string s);
    string getId() const;
    string getOrigen() const;
    string getDesti() const;
    string getHora() const;
    string toString() const;
private:
    string id;
    string origen;
    string desti;
    string hora_sortida;

};

#endif /* FLIGHT_H */

