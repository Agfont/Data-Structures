/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entry.h
 * Author: arthurfont
 *
 * Created on May 15, 2019, 7:43 PM
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>

using namespace std;

template <class T>
class Entry {
    public:
        // Constructors i Destructor
        Entry();
        Entry(int key, T value);
        ~Entry();
        
        // Consultors
        int getKey() const;
        const T& getValue() const;
        
        // Modificadors
        void setKey(int key);
        void setValue(const T& value);

    private:
        // Atributs
        int key;
        T value;
};

/* 
 * Constructor de la entrada
 */
template <class T> Entry<T>::Entry() {
    this->key = 0;
}

/* 
 * Constructor copia de la entrada
 */
template <class T> Entry<T>::Entry(int key, T value) {
    this->key = key;
    this->value = value;
}

/* 
 * Destructor de la entrada
 */
template <class T> Entry<T>::~Entry() {
    this->key = 0;
}

/* 
 * Retorna la llave
 */
template <class T> int Entry<T>::getKey() const {
    return this->key;
}

/* 
 * Retorna el valor
 */
template <class T> const T& Entry<T>::getValue() const {
    return this->value;
}

/* 
 * Modifica la llave
 */
template <class T> void Entry<T>::setKey(int key) {
    this->key = key;
}


/* 
 * Modifica el valor
 */
template <class T> void Entry<T>::setValue(const T& value) {
    this->value = value;
}

#endif /* ENTRY_H */