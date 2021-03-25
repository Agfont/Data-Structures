/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 3:16 PM
 */

#ifndef NODE_H
#define NODE_H

// Class template -> utilizable para cualquier tipo de dados
template <class T> class Node {
    public:
    Node(const T& elemento); // Constructor
    virtual ~Node(); // Destructor
    const T& getElement() const; // Retorna el elemento del node
    void setNext(Node* next); // Cambia el endereço del seguinte node
    Node <T>* getNext() const; // Retorna el endereço del seguinte node
private:
    T element;
    Node* next;
};

template <class T> Node <T>::Node(const T& element) {
    this->element = element;
    this->next = 0;
}

template <class T> Node <T>::~Node() {
    this-> setNext(0);
    delete next;
}

template <class T> const T& Node <T>::getElement() const {
    return this->element;
}

template <class T> void Node <T>::setNext(Node<T>* next) {
    this->next = next;
}

template <class T> Node <T>* Node <T>::getNext() const {
    return this->next;
}

#endif /* NODE_H */

