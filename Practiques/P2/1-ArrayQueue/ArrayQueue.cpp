/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.cpp
 * Author: arthurfont
 * 
 * Created on March 6, 2019, 1:15 PM
 */

#include "ArrayQueue.h"
#include <vector>
#include <iostream>

using namespace std;

// Constructor
ArrayQueue::ArrayQueue(const int max_size) {
    this->max_size = max_size;
    size = 0;
    v = vector<int> (size);
    cout << "Estructura creada\n";
}

// Destructor
ArrayQueue::~ArrayQueue() {
}

// Añade un elemento al final del vector
void ArrayQueue::enqueue(const int key) {
    if (!isFull()) {
        v.push_back(key);
        size++;
        cout << "Element " << key << " agregat\n";
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està plena\n");
    }
}

// Borra el primero elemento del vector
void ArrayQueue::dequeue() {
    if (!isEmpty()) {
        int front = v.front();
        v.erase(v.begin());
        size--;
        cout << "Element " << front << " eliminat\n";
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

// Verifica si el vector esta lleno
bool ArrayQueue::isFull(){
    return (size >= max_size);
}

// Verifica si el vector esta vacio
bool ArrayQueue::isEmpty() {
    return (size == 0);
}

// Enseña por pantalla el vector
void ArrayQueue::print() {
    cout << "[";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (it == v.end()-1) {
            cout << *it;
        }
        else {
        cout << *it << ", ";
        }
    }
    cout << "]\n";
}
const int ArrayQueue::getFront() {
    if (!isEmpty()) {
        return v.front();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}