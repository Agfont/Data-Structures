/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: arthurfont
 *
 * Created on April 25, 2019, 11:21 AM
 */

#ifndef NODETREE_H
#define NODETREE_H

#include <iostream>
using namespace std;

template <class T>
class NodeTree {
    public:
        // Constructor i destructor
        NodeTree(const T& data);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree();
        
        // Consultors
        NodeTree<T>* right() const;
        NodeTree<T>* left() const;
        NodeTree<T>* parent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const T& getElement() const;
        int getKey() const;
        int getAlcada() const;
        
        // Modificadors
        void setElement(const T& data);
        void setRight(NodeTree<T>* newRight);
        void setLeft(NodeTree<T>* newLeft);
        void setParent(NodeTree<T>* newParent);
        void setKey(int newKey);
        void setAlcada(int newAlcada);

    private:
        NodeTree<T>* pParent;
        NodeTree<T>* pLeft;
        NodeTree<T>* pRight;
        T element;
        int key;
        int alcada;
};

template <class T> NodeTree <T>::NodeTree(const T& data) {
    this->alcada = 1;
    this->element = data;
    this->pLeft = 0;
    this->pRight = 0;
}

template <class T> NodeTree <T>::NodeTree(const NodeTree& orig) {
    this->alcada = orig.alcada;
    this->element = orig.element;
    this->pParent = orig.pParent;
    this->pLeft = orig.pLeft;
    this->pRight = orig.pRight;
}

template <class T> NodeTree <T>::~NodeTree() {
    cout << "Eliminant node " << this->getKey() << endl;
    delete this->pLeft, this->pParent, this->pRight;
}

template <class T> NodeTree<T>* NodeTree <T>::right() const {
    return this->pRight;
}

template <class T> NodeTree<T>* NodeTree <T>::left() const {
    return this->pLeft;
}

template <class T> NodeTree<T>* NodeTree <T>::parent() const {
    return this->pParent;
}

template <class T> bool NodeTree <T>::hasRight() const {
    return (this->pRight != 0);
}

template <class T> bool NodeTree <T>::hasLeft() const {
    return (this->pLeft != 0);
}

template <class T> bool NodeTree <T>::isRoot() const {
    return (this->parent() == 0);
}

template <class T> bool NodeTree <T>::isExternal() const {
    return (!this->hasLeft() && !this->hasRight());
}

template <class T> const T& NodeTree<T>::getElement() const {
    return this->element;
}

template <class T> void NodeTree <T>::setElement(const T& newElement) {
    this->element = newElement;
}

template <class T> void NodeTree <T>::setLeft(NodeTree<T>* newLeft) {
    this->pLeft = newLeft;
}

template <class T> void NodeTree <T>::setRight(NodeTree<T>* newRight) {
    this->pRight = newRight;
}

template <class T> void NodeTree <T>::setParent(NodeTree<T>* newParent) {
    this->pParent = newParent;
}

template <class T> void NodeTree <T>::setKey(int newKey) {
    this->key = newKey;
}

template <class T> int NodeTree <T>::getKey() const {
    return this->key;
}

template <class T> void NodeTree <T>::setAlcada(int newAlcada) {
    this->alcada = newAlcada;
}

template <class T> int NodeTree <T>::getAlcada() const {
    return this->alcada;
}

#endif /* NODETREE_H */

