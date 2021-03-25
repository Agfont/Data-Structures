/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMountainFinder.h
 * Author: arthurfont
 *
 * Created on May 17, 2019, 6:19 PM
 */

#ifndef HEAPMOUNTAINFINDER_H
#define HEAPMOUNTAINFINDER_H

#include <string>
#include <iostream>
#include "MaxHeap.h"
#include "Mountain.h"
#include "Entry.h"

using namespace std;

class HeapMountainFinder {
public:
    // Constructors i Destructors
    HeapMountainFinder();
    HeapMountainFinder(const HeapMountainFinder& orig);
    virtual ~HeapMountainFinder();
    
    // Consultors
    string showMountain(const int mountainID) const;
    Mountain findMountain(const int mountainID) const;
    bool isMountain (const int mountainID) const;
    void showHeapMountain() const;
    void cercaFitxer(string filename) const;
    void showDepth() const;
    
    // Modificadors
    void appendMountains(string filename);
    
private:
    // Atributs
    MaxHeap<Mountain>* heap;
    // Metodos internos
    void insertMountain(int mountainId, string name, int height);
};

#endif /* HEAPMOUNTAINFINDER_H */