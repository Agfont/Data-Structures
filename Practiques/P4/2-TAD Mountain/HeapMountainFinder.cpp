/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMountainFinder.cpp
 * Author: arthurfont
 * 
 * Created on May 17, 2019, 6:19 PM
 */

#include "HeapMountainFinder.h"
#include "Mountain.h"
#include <string>
#include <iostream>
#include <fstream>

/* 
 * Constructor del cercador de muntanyas
 */
HeapMountainFinder::HeapMountainFinder() {
    this->heap = new MaxHeap<Mountain>();
}

/* 
 * Constructor copi del cercador de muntanyas
 */
HeapMountainFinder::HeapMountainFinder(const HeapMountainFinder& orig) {
    this->heap = orig.heap;
}

/* 
 * Destructor del cercador de muntanyas
 */
HeapMountainFinder::~HeapMountainFinder() {
    this->heap->~MaxHeap();
}

/* 
 * Metodo que añade una lista de elemntos 'Mountain' de un fichero al heap
 */
void HeapMountainFinder::appendMountains(string filename) {
    ifstream infile;
    string dados;
    infile.open(filename);
    if (infile.is_open()) {
        string delimiter = "::";
        while (getline(infile, dados)) {
            int mountainId;
            string name;
            int height;
            
            mountainId = stoi(dados.substr(0, dados.find(delimiter)));
            // Cortar los caracteres "::"
            dados = dados.substr(dados.find(delimiter)+2);
            
            name = dados.substr(0, dados.find(delimiter));
            height = stoi(dados.substr(dados.find(delimiter)+2));
        
            this->insertMountain(mountainId, name, height);
        }
    infile.close();
    }
}

/* 
 * Metodo que añade un elemento 'Mountain' en el heap
 */
void HeapMountainFinder::insertMountain(int mountainId, string name, int height) {
    Mountain element (mountainId, name, height);
    cout << "Inserta al heap el element " << element.toString();
    this->heap->insert(mountainId, element);
}

/* 
 * Mostra el heap en anchura en la pantalla
 */
void HeapMountainFinder::showHeapMountain() const {
    this->heap->printHeap();
}

/* 
 * Metodo que retorna un string con los dados de la mountanya a partir de seu ID
 */
string HeapMountainFinder::showMountain(const int mountainID) const {
    this->heap->getElement(mountainID).toString();
}

/* 
 * Metodo que retorna un elemento Mountain a partir de seu ID
 */
Mountain HeapMountainFinder::findMountain(const int mountainID) const {
    this->heap->getElement(mountainID);
}

/* 
 * Metodo que verifica si un elemento Mountain  esta en el heap a partir de seu ID
 */
bool HeapMountainFinder::isMountain(const int mountainID) const {
    return (this->heap->search(mountainID));
}

/* 
 * Metodo que mostra cuantos elementos de la lista de 
 * muntanyas contenida en un fichero estan en el heap
 */
void HeapMountainFinder::cercaFitxer(string filename) const {
    if (this->heap->isEmpty()) {
        cout << "Heap is empty" << endl;
    }
    else {
        int count = 0;
        ifstream infile;
        string dados;
        infile.open(filename);
        if (infile.is_open()) {
            while (getline(infile, dados)) {
                int mountainId = stoi(dados);
                if (isMountain(mountainId)) {
                    count++;
                }
            }
            infile.close();
        }
        cout << "Contador: " << count << endl;
    }
}

/*
 * Metodo que retorna la profunditat del heap
 */
void HeapMountainFinder::showDepth() const {
    cout << "Profunditat: " << this->heap->height() << endl;
}