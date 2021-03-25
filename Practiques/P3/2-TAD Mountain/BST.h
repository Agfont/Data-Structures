/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.h
 * Author: arthurfont
 *
 * Created on April 16, 2019, 3:19 PM
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include "NodeTree.h"

using namespace std;

template <class T>
class BST{
    public:
        // Constructors i Destructors
        BST();
        BST(const BST& orig);
        virtual ~BST();
        
        // Consultors
        int size() const;
        int height() const;
        bool isEmpty() const;
        NodeTree<T>* root();
        bool search(const T& element);
        void showInorder() const;
        void showPreorder() const;
        void showPostorder() const;
        void showLeafNodes() const;
        
        // Modificadors
        void insert(const T& element);
        void setRoot(NodeTree<T>* p);
        void setDepth(int depth);
        
    private:
        // Atributs
        NodeTree<T>* pRoot;
        int depth;
        
        int size(NodeTree<T>* p) const;
        void showPreorder(NodeTree<T>* p) const;
        void showPostorder(NodeTree<T>* p) const;
        void showInorder(NodeTree<T>* p) const;
        void showLeafNodes(NodeTree<T>* elem) const;
        void destructor(NodeTree<T>* elem) const;
};

template <class T> BST <T>::BST() {
    this->pRoot = 0;
    cout << "Arbre binari creat" << endl;
}

template <class T> BST <T>::BST(const BST& orig) {
    this->pRoot = orig.pRoot;
}

template <class T> BST <T>::~BST() {
    cout << "Destruint arbre binari" << endl;
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        this->destructor(this->pRoot);
    }
    this->depth = 0;
    this->pRoot = nullptr;
    cout << "Arbre binari destruit" << endl;
}

template <class T> int BST <T>::size() const {
    if (pRoot == 0) {
        return 0;
    }
    else {
        return this->size(pRoot);
    }
}

template <class T> int BST <T>::height() const {
    return this->depth;
}

template <class T> void BST<T>::insert(const T& element) {
    cout << "Inserta a l’arbre element " << element << endl;
    if (this->isEmpty())  {
        this->pRoot = new NodeTree<T>(element);
        this->depth = 1;
    }
    else {
        NodeTree<T>* aux = this->pRoot;
        int i = 0;
        
        while(aux->getElement!= element) {
            if (aux->getElement() > element) {
                if (aux->hasLeft()) {
                    aux = aux->left();
                }
                else {
                    NodeTree<T>* node = new NodeTree<T>(element);
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
                    NodeTree<T>* node = new NodeTree<T>(element);
                    aux->setRight(node);
                    node->setParent(aux);
                    aux = node;
                }
            }
            i++;
        }
        if (i > this->height()) {
            this->depth = i;
        }
    }
}

template <class T> void BST <T>::setRoot(NodeTree<T>* elem) {
    this->pRoot = elem;
}

template <class T> void BST <T>::setDepth(int depth) {
    this->depth = depth;
}

template <class T> int BST <T>::size(NodeTree<T>* p) const {
    if (p->isExternal()) {
        return 1;
    }
    else if (p->hasLeft() && p->hasRight()) {
        return size (p->left()) + size(p->right()) + 1;
    }
    else if(p->hasRight()) {
        return size (p->right()) + 1;
    }
    else {
        return size (p->left()) + 1;
    }
}

template <class T> NodeTree<T>* BST<T>::root() {
    return this->pRoot;
}

template <class T> bool BST <T>::isEmpty() const {
    return (this->size() == 0);
}

template <class T> bool BST<T>::search(const T& element) {
    NodeTree<int>* aux = this->pRoot;
    bool trobat = false, isEnd = false;
        while(!trobat && !isEnd) {
            if (aux->getElement() == element) {
                trobat = true;
            }
            else if(aux->getElement() > element) {
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

template <class T> void BST<T>::showPreorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Preordre = {";
        this->showPreorder(this->pRoot);
        cout << "}\n";
    }
}

template <class T> void BST<T>::showPostorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Postordre = {";
        this->showPostorder(this->pRoot);
        cout << "}\n";
    }
}

template <class T> void BST<T>::showInorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Inordre = {";
        this->showInorder(this->pRoot);
        cout << "}\n";
    }
}

template <class T> void BST<T>::showPreorder(NodeTree<T>* elem) const {
    if (elem == this->pRoot) {
        cout << elem->getElement();
    }
    else { 
        cout << ", " << elem->getElement();
    }
    if (!elem->isExternal()) {
        if(elem->hasLeft()) {
            showPreorder (elem->left());
        }
        if(elem->hasRight()) {
            showPreorder (elem->right());
        }
    }
}

template <class T> void BST <T>::showPostorder(NodeTree<T>* elem) const {
    if (!elem->isExternal()) {
        if(elem->hasLeft()) {
            showPostorder (elem->left());
        }
        if(elem->hasRight()) {
            showPostorder (elem->right());
        }
    }
    if (elem == this->pRoot) {
        cout << elem->getElement();
    }
    else { 
        cout << elem->getElement() << ", ";
    }
}

template <class T> void BST <T>::showInorder(NodeTree<T>* elem) const {
    if (!elem->isExternal() && elem->hasLeft()) {
        showInorder (elem->left());
    }
    cout << elem->getElement() << ", ";
    if (!elem->isExternal() && elem->hasRight()) {
        showInorder (elem->right());
    }
}

template <class T> void BST<T>::showLeafNodes() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Fulles = {";
        this->showLeafNodes(this->pRoot);
        cout << "}\n";
    }
}

template <class T> void BST<T>::showLeafNodes(NodeTree<T>* elem) const {
    if (elem->isExternal()) {
        cout << elem->getElement() << ", ";
    }
    if (elem->hasLeft()) {
        showLeafNodes(elem->left());
    }
    if (elem->hasRight()) {
        showLeafNodes(elem->right());
    }
}

template <class T> void BST <T>::destructor(NodeTree<T>* node) const {
    if (node != NULL) {
        destructor(node->left());
        node->setLeft(NULL);
        destructor(node->right());
        node->setRight(NULL);
	delete node;
    }
}

#endif /* BST_H */