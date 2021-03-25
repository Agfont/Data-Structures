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

#include "NodeTree.h"
#include <iostream>

using namespace std;

template <class T>
class BST{
    public:
        // Constructor i Destructor
        BST();
        BST(const BST& orig);
        virtual ~BST();
        
        // Consultors
        int size() const;
        int height() const;
        bool isEmpty() const;
        NodeTree<T>* root();
        bool search(const T& element);
        void showPreorder() const;
        void showPostorder() const;
        void showInorder() const;
        void showLeafNodes() const;
        void hasOnlyOneChild() const;
        void hasOnlyOneChild(NodeTree<T>* elem) const;
        void showACMB(const T& i1, const T& i2) const;
        void showACMB(NodeTree<T>* elem, const T& i1, const T& i2) const;
        void showMMIN(const T& i1) const;
 
        // Modificadors
        void insert(const T& element);
    private:
        
        int size(NodeTree<T>* p) const;
        void showPreorder(NodeTree<T>* p) const;
        void showPostorder(NodeTree<T>* p) const;
        void showInorder(NodeTree<T>* p) const;
        void showLeafNodes(NodeTree<T>* elem) const;
        void destructor(NodeTree<T>* elem) const;
        
        // Atributs
        NodeTree<T>* pRoot;
        int depth;
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
        
        while(aux->getElement() != element) {
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
    NodeTree<int>* aux = new NodeTree<int>(this->pRoot);
    bool trobat = false, isEnd = false;
        while(!trobat && !isEnd) {
            if (aux->getElement() == element) {
                trobat = true;
            }
            else if(aux->getElement() > element) {
                if (aux->hasLeft()) {
                    aux = aux->left();
                }
                else isEnd = true;
            }
            else {
                if (aux->hasRight()) {
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
    if (node != NULL)	{
        destructor(node->left());
        node->setLeft(NULL);
        destructor(node->right());
        node->setRight(NULL);
	delete node;
    }
}

template <class T> void BST <T>::hasOnlyOneChild() const {
    if (!isEmpty()){
        this->hasOnlyOneChild(this->pRoot);
    }
}

template <class T> void BST <T>::hasOnlyOneChild(NodeTree<T>* elem) const {
    if (!elem->isExternal()) {
        if (elem->hasLeft() && elem->hasRight()) {
            cout << "False" << endl;
        }
        else { 
            if (elem->hasLeft()) {
                hasOnlyOneChild(elem->left());
            }
            if (elem->hasRight()) {
                hasOnlyOneChild(elem->right());
            }
        }
    }
    else {
        cout << "True" << endl;
    }
}

template <class T> void BST<T>::showMMIN(const T& element) const {
    NodeTree<int>* aux = this->pRoot;
    int min = -1;
    bool trobat = false, isEnd = false;
        while(!trobat && !isEnd) {
            if (aux->getElement() == element) {
                min = aux->getElement();
                trobat = true;
            }
            else if(aux->getElement() > element) {
                if (aux->hasLeft()) {
                    aux = aux->left();
                }
                else isEnd = true;
            }
            else {
                if (aux->hasRight()) {
                    aux = aux->right();
                    if (aux->getElement() < element) {
                        min = aux->getElement();
                    }
                }
                else {
                    min = aux->getElement();
                    isEnd = true;
                }
            }
        }
    cout << min << endl;
}

template <class T> void BST <T>::showACMB(const T& i1, const T& i2) const {
    if (!isEmpty()){
        this->showACMB(this->pRoot, i1, i2);
    }
}

template <class T> void BST <T>::showACMB(NodeTree<T>* elem, const T& i1, const T& i2) const {
    
}


#endif /* BST_H */