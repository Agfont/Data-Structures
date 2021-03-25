/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedQueue.cpp
 * Author: arthurfont
 * 
 * Created on March 6, 2019, 3:07 PM
 */

#include "LinkedQueue.h"
#include "FlightNode.h"
#include "Flight.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Constructors
LinkedQueue::LinkedQueue() {
    _size = 0;
    _front = 0;
    _rear = 0;
    cout << "Estructura creada\n";
}

LinkedQueue::LinkedQueue(const LinkedQueue& orig) {
    _size = 0;
    cout << "\nCopia iniciada\n";
    
    if (orig._size != 0) {
        Flight f;
        FlightNode<Flight> *aux = new FlightNode<Flight> (f); // nueva memória (punter)
        *aux = orig.getFront(); // guarda el contenido del front de la cua original
        aux->setNext(orig._front->getNext()); // guarda la adreça del siguiente
        
        this->enqueue(aux->getElement()); // El enqueue() define el _front de la nueva cua
        
        while (aux->getNext() != nullptr) { // aux != _rear
            aux = aux->getNext(); // aux itera sobre la cua original
            this->enqueue(aux->getElement());
        }
    }
     
    
    cout << "Copia finalizada\n";
}

// Destructor
LinkedQueue::~LinkedQueue() {
    FlightNode<Flight> *current = _front;
    if (!isEmpty()) {
        while (current != _rear) {
            current = current->getNext();
            delete _front;
            _front = current;
        }
        delete current;
    }
    delete _front;
    delete _rear;
}

// Verifica si esta vacio
bool LinkedQueue::isEmpty() const {
    return(_size == 0);
}

// Retorna el primero elemento (head)
const Flight& LinkedQueue::getFront() const {
    if(!isEmpty()) {
        return _front->getElement();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

// Adiciona un elemento al final (rear)
void LinkedQueue::enqueue(const Flight& f) {
    FlightNode<Flight> *node = new FlightNode<Flight> (f);
    if (!isEmpty()) {
        _rear->setNext(node);
    }
    else {
        _front = node;
    }
    _rear = node;
    _size++;
     cout << "Vol " << f.toString() << " agregat\n";
}

// Elimina el primero elemento (head)
void LinkedQueue::dequeue() {
    if (!isEmpty()) {
        Flight f1;
        FlightNode<Flight> *node = new FlightNode<Flight> (f1);
        node->setNext(_front->getNext());
        cout << "Vol " <<  _front->getElement().toString() << " eliminat\n";
        delete _front;
        _front = node->getNext();
        delete node;
        _size--;
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

// Enseña los elemntos por pantalla
void LinkedQueue::print() const {
    FlightNode<Flight> *current = _front;
    cout << "[";
    if (!isEmpty()) {
        while (current != _rear) {
            cout << current->getElement().toString() << endl;
            current = current->getNext();
        }
        cout << _rear->getElement().toString();
    }
    cout << "]\n";
}