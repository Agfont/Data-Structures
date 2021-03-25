/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on April 16, 2019, 2:28 PM
 */

#include <cstdlib>
#include "NodeTree.h"
#include "BST.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BST <int>* arbre2 = new BST<int>();
    int array_ex2 [] = {5, 2, 1, 3, 12, 9, 21, 19, 25};
    int size_array_ex2 = sizeof(array_ex2)/sizeof(*array_ex2);
    for (int i = 0; i < size_array_ex2; i++) {
        arbre2->insert(array_ex2[i]);
    }
    
    arbre2->showMMIN(24);
    arbre2->showMMIN(10);
    arbre2->showMMIN(5);
    arbre2->showMMIN(4);
    arbre2->showMMIN(0);

    
    delete arbre2;
    
    
    
    BST <int>* arbre = new BST<int>();
    int array_ex3 [] = {20,10,11,13,12};
    int size_array_ex3 = sizeof(array_ex3)/sizeof(*array_ex3);
    for (int i = 0; i < size_array_ex3; i++) {
        arbre->insert(array_ex3[i]);
    }
    
    arbre->hasOnlyOneChild();
    arbre->insert(30);
    arbre->hasOnlyOneChild();
    
    delete arbre;

    return 0;
}

