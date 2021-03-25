/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FlightNode.h
 * Author: arthurfont
 *
 * Created on March 10, 2019, 8:47 PM
 */

#ifndef FLIGHTNODE_H
#define FLIGHTNODE_H

// Class template -> utilizable para cualquier tipo de dados
template <class T> 
class FlightNode {
    public:
    FlightNode(const T& elemento); // Constructor
    virtual ~FlightNode(); // Destructor
    const T& getElement() const; // Retorna el elemento del node
    void setNext(FlightNode* next); // Cambia el endereço del seguinte node
    FlightNode <T>* getNext() const; // Retorna el endereço del seguinte node
private:
    T element;
    FlightNode* next;
};

template <class T> FlightNode <T>::FlightNode(const T& element) {
    this->element = element;
    this->next = 0;
}

template <class T> FlightNode <T>::~FlightNode() {
    this-> setNext(0);
    delete next;
}

template <class T> const T& FlightNode <T>::getElement() const {
    return this->element;
}

template <class T> void FlightNode <T>::setNext(FlightNode<T>* next) {
    this->next = next;
}

template <class T> FlightNode <T>* FlightNode <T>::getNext() const {
    return this->next;
}


#endif /* FLIGHTNODE_H */

