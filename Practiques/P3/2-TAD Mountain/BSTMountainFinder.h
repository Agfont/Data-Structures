/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.h
 * Author: arthurfont
 *
 * Created on April 20, 2019, 10:58 PM
 */

#ifndef BSTMOUNTAINFINDER_H
#define BSTMOUNTAINFINDER_H

#include "Mountain.h"
#include "BST.h"
#include "NodeTree.h"
#include <string>
#include <iostream>

using namespace std;

class BSTMountainFinder {
    public:
        // Constructors i Destructors
        BSTMountainFinder();
        BSTMountainFinder(const BSTMountainFinder& orig);
        virtual ~BSTMountainFinder();
        
        // Consultors
        string showMountain(int mountainID) const;
        Mountain findMountain(int mountainID) const;
        bool isMountain (int mountainID) const;
        void showInorderMountain() const;
        int getHeight() const;
        
        // Modificadors
        void appendMountains(string filename);
        void cercaFitxer(string filename) const;
        
    private:
        BST<Mountain>* arbre;
        void insertMountain(int mountainId, string name, int height);
        void showInorderMountain(NodeTree<Mountain>* elem, int &count) const;
        void cercaFitxer(NodeTree<Mountain>* elem, string filename) const;
        
};

#endif /* BSTMOUNTAINFINDER_H */

