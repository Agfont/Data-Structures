/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.cpp
 * Author: arthurfont
 * 
 * Created on April 20, 2019, 10:58 PM
 */

#include "BSTMountainFinder.h"
#include "Mountain.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

BSTMountainFinder::BSTMountainFinder(){
    this->arbre = new BST<Mountain>();
}

BSTMountainFinder::~BSTMountainFinder() {
    
}

void BSTMountainFinder::appendMountains(string filename) {
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

void BSTMountainFinder::insertMountain(int mountainId, string name, int height) {
    Mountain element (mountainId, name, height);
    cout << "Inserta a l’arbre element " << element.toString() << endl;
    if (arbre->isEmpty())  {
        arbre->setRoot(new NodeTree<Mountain>(element));
        arbre->setDepth(1);
    }
    else {
        NodeTree<Mountain>* aux = arbre->root();
        int i = 0;
        
        while(aux->getElement().getId() != element.getId()) {
            if (aux->getElement().getId() > element.getId()) {
                if (aux->hasLeft()) {
                    aux = aux->left();
                }
                else {
                    NodeTree<Mountain>* node = new NodeTree<Mountain>(element);
                    aux->setLeft(node);
                    node->setParent(aux);
                    aux = node;
                }
            }           
            else {
                if (aux->hasRight()) {
                    aux = aux->right();
                }
                else {
                    NodeTree<Mountain>* node = new NodeTree<Mountain>(element);
                    aux->setRight(node);
                    node->setParent(aux);
                    aux = node;
                }
            }
            i++;
        }
        if (i > arbre->height()) {
            arbre->setDepth(i);
        }
    }
}

string BSTMountainFinder::showMountain(int mountainID) const {
    string s = NULL;
    NodeTree<Mountain>* aux = this->arbre->root();
    bool trobat = false, isEnd = false;
    while(!trobat && !isEnd) {
        if (aux->getElement().getId() == mountainID) {
            trobat = true;
            s = aux->getElement().toString();
        }
        else if(aux->getElement().getId() > mountainID) {
            if (!aux->left() == 0) {
                aux = aux->left();
            }
            else isEnd = true;
        }
        else {
            if (!aux->right() == 0) {
                aux = aux->right();
            }
            else isEnd = true;
        }
    }
    return s;
}

Mountain BSTMountainFinder::findMountain(int mountainID) const {
    Mountain m;
    NodeTree<Mountain>* aux = this->arbre->root();
    bool trobat = false, isEnd = false;
    while(!trobat && !isEnd) {
        if (aux->getElement().getId() == mountainID) {
            trobat = true;
            m = aux->getElement();
        }
        else if(aux->getElement().getId() > mountainID) {
            if (!aux->left() == 0) {
                aux = aux->left();
            }
            else isEnd = true;
        }
        else {
            if (!aux->right() == 0) {
                aux = aux->right();
            }
            else isEnd = true;
        }
    }
    return m;
}

bool BSTMountainFinder::isMountain(int mountainID) const {
    NodeTree<Mountain>* aux = this->arbre->root();
    bool trobat = false, isEnd = false;
    while(!trobat && !isEnd) {
        if (aux->getElement().getId() == mountainID) {
            trobat = true;
        }
        else if(aux->getElement().getId() > mountainID) {
            if (!aux->left() == 0) {
                aux = aux->left();
            }
            else isEnd = true;
        }
        else {
            if (!aux->right() == 0) {
                aux = aux->right();
            }
            else isEnd = true;
        }
    }
    return trobat;
}

void BSTMountainFinder::showInorderMountain() const {
    int count = 0;
    if (this->arbre->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "{";
        this->showInorderMountain(this->arbre->root(), count);
        cout << "}\n";
    }
}

void BSTMountainFinder::showInorderMountain(NodeTree<Mountain>* elem, int &count) const {
    if (!elem->isExternal() && elem->left() != 0 && count < 40) {
        showInorderMountain (elem->left(), count);
    }
    
    if (count < 40) {
        cout << " " << elem->getElement().toString();
        count++;
    }
    if (count == 40) {
        char aux;
        cout << "Vols seguir mostrant l'abre(S/N)?" << endl;
        cin >> aux;
        if (aux == 'N') {
            count++;
        }
        else if (aux == 'S'){
            count = 0;
        }
        else {
            throw out_of_range("EXCEPTION: Entrada no válida");
        }
    }
    
    if (!elem->isExternal() && elem->right() != 0 && count < 40)  {
        showInorderMountain (elem->right(), count);
    }
    
}

int BSTMountainFinder::getHeight() const {
    return this->arbre->height();
}

void BSTMountainFinder::cercaFitxer(string filename) const {
    if (this->arbre->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Contador: ";
        this->cercaFitxer(this->arbre->root(), filename);
        cout << "\n";
    }
}

void BSTMountainFinder::cercaFitxer(NodeTree<Mountain>* elem, string filename) const {
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
        cout << count;
    infile.close();
    }
}
