/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaxHeap.h
 * Author: arthurfont
 *
 * Created on May 13, 2019, 6:27 PM
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include "Entry.h"

using namespace std;

/* Para representar el Heap he utilizado un vector con elementos de tipo 
 * 'Entry', que contiene una llave e un valor indefinido (Template).
 * 
 * La implementación del Heap con un vector es mas eficiente que la implementacion
 * del Heap con punteros porque usamos menos memoria, es mas facil manejar los elementos
 * y los elementos estan alocados mas cerca en la memoria.
 */
template <class T>
class MaxHeap {
    public:
        // Constructors i Destructors
        MaxHeap();
        MaxHeap(const MaxHeap& orig);
        MaxHeap(const int size);
        virtual ~MaxHeap();
        
        // Consultors
        int getSize() const;
        bool isEmpty() const;
        bool isFull() const;
        const int max() const;
        const T& maxValues() const;
        void printHeap() const;
        bool search(const int key) const;
        
        // Modificadors
        void insert(const int key, const T& value);
        void removeMax();
        void upHeap();
        void downHeap();
    private:
        // Atributs
        vector<Entry<T>> v;
        int max_size;
        int size;
};

/* 
 * Constructor del heap
 */
template <class T> MaxHeap <T>::MaxHeap() {
    max_size = 100;
    size = 0;
    v = vector<Entry<T>> (size);
    cout << "Heap binari creat" << endl;
}

/* 
 * Constructor del heap
 */
template <class T> MaxHeap <T>::MaxHeap(const int max_size) {
    this->max_size = max_size;
    size = 0;
    v = vector<Entry<T>> (size);
    cout << "Heap binari creat" << endl;
}

/* 
 * Constructor copia del heap
 */
template <class T> MaxHeap <T>::MaxHeap(const MaxHeap& orig) {
    this->v = orig.v;
}

/* 
 * Destructor del heap
 */
template <class T> MaxHeap <T>::~MaxHeap() {
    cout << "Destruint heap binari" << endl;
    if (this->isEmpty()) {
        cout << "Heap is empty" << endl;
    }
    else {
        v.clear();
    }
    cout << "Heap destruit" << endl;
}

/* 
 * Metodo que retorna el tamaño del heap
 */
template <class T> int MaxHeap <T>::getSize() const {
    return this->size;
}

/* 
 * Retorna si el heap esta vacio
 */
template <class T> bool MaxHeap <T>::isEmpty() const {
    return (size == 0);
}

/* 
 * Retorna si el heap esta lleno
 */
template <class T> bool MaxHeap<T>::isFull() const {
    return (size >= max_size);
}

/* 
 * Retorna la llave maxima del heap
 * Complexity: O(1)
 */
template <class T> const int MaxHeap<T>::max() const {
    if (!isEmpty()) {
        return v.front().getKey();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

/* 
 * Retorna el valor de la llave maxima del heap
 * Complexity: O(1)
 */
template <class T> const T& MaxHeap<T>::maxValues() const {
    if (!isEmpty()) {
        return v.front().getValue();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

/* 
 * Mostra el heap en ancho en la pantalla
 * Complexity: O(n)
 */
template <class T> void MaxHeap<T>::printHeap() const {
    cout << "[";
    int i = 0;
    for (typename vector<Entry<T>>::const_iterator it = v.begin(); it != v.end(); ++it) {
        if (it == v.end()-1) {
            cout << v[i].toString();
        }
        else {
        cout << v[i].toString() << ", ";
        }
        i++;
    }
    cout << "]\n";
}

/* 
 * Retorna si una llave esta en el heap
 * Complexity: O(n)
 */
template <class T> bool MaxHeap<T>::search(const int key) const {
    if(!isEmpty()) {
        int i = 0;
        bool trobat = false, keyHigher = false;
        while (i < size && !trobat && !keyHigher) {
            if (key == v[i].getKey()) {
                trobat = true;
            }
            else if (key > v[i].getKey()) {
                keyHigher = true;
            }
        }
        return trobat;
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

/* 
 * Añade un elemento al heap
 * Complexity: O(log n) 
 */
template <class T> void MaxHeap<T>::insert(const int key, const T& value) {
    Entry<T> ent (key, value);
    if (!isFull()) {
        v.push_back(ent);
        size++;
        cout << "Element amb clau " << ent.getKey() << " agregat\n";
        upHeap();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està plena\n");
    }
}

/* 
 * Borra el elemento de llave maxima del heap
 * Complexity: O(log n)
 */
template <class T> void MaxHeap<T>::removeMax() {
    if (!isEmpty()) {
        Entry<T> front = v.front();
        cout << "Element amb clau " << front.getKey() << " eliminat\n";
        downHeap();
    }
    else {
        throw out_of_range("EXCEPTION: L'estructura està buida\n");
    }
}

/* 
 * Reordena el heap después de añadir un nuevo elemento
 * Complexity: O(log n) 
 */
template <class T> void MaxHeap<T>::upHeap() { // afegir
    int i = size-1;
    bool stop = false;
    while (!stop && i != 0) {
        if (i % 2 == 0) {
            // dret
            if (v[i].getKey() > v[(i-2)/2].getKey()) {
                // cambio            
                Entry<T> ent = v[i];
                v[i] = v[(i-2)/2];
                v[(i-2)/2] = ent;
                i = (i-2)/2;
            }
            else stop = true;
        }
        else {
            // esquerra
            if (v[i].getKey() > v[(i-1)/2].getKey()) {
                // cambio            
                Entry<T> ent = v[i];
                v[i] = v[(i-1)/2];
                v[(i-1)/2] = ent;
                i = (i-1)/2;
            }
            else stop = true;
        }
    }
}

/* 
 * Reordena el heap después de eliminar el elemento de llave maxima
 * Complexity: O(log n)
 */
template <class T> void MaxHeap<T>::downHeap() { // eliminar
    int i = size-1;
    Entry<T> ent = v[i];
    v[i] = v[0];
    v[0] = ent;
    v.erase(v.end());
    size--;
    bool stop = false;
    i = 0;
    while (!stop && (i*2)+1 < size || (i*2)+2 < size) {
        if (v[i].getKey() > v[(i*2)+1].getKey() && (v[i].getKey() > v[(i*2)+2].getKey() || (i*2)+2 >= size)) {
            stop = true;
        }
        else if (v[i].getKey() < v[(i*2)+1].getKey() && v[i].getKey() < v[(i*2)+2].getKey()) {
            // Ambos lados son mayores
            if (v[(i*2)+2].getKey() > v[(i*2)+1].getKey()) {
                // dret            
                ent = v[i];
                v[i] = v[(i*2)+2];
                v[(i*2)+2] = ent;
                i = (i*2)+2;
            }
            else {
                // esquerra
                ent = v[i];
                v[i] = v[(i*2)+1];
                v[(i*2)+1] = ent;
                i = (i*2)+1;
            }
        }
        else if (v[i].getKey() < v[(i*2)+2].getKey() && (i*2)+2 < size) {
            // dret
            ent = v[i];
            v[i] = v[(i*2)+2];
            v[(i*2)+2] = ent;
            i = (i*2)+2;
        }
        else { 
            // esquerra
            ent = v[i];
            v[i] = v[(i*2)+1];
            v[(i*2)+1] = ent;
            i = (i*2)+1;
        }        
    }
}

#endif /* MAXHEAP_H */