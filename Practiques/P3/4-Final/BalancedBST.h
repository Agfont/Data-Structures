/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBST.h
 * Author: arthurfont
 *
 * Created on April 25, 2019, 11:21 AM
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H

#include <iostream>
#include <vector>
#include "NodeTree.h"

using namespace std;

template <class T>
class BalancedBST{
    public:
        // Constructors i Destructors
        BalancedBST();
        BalancedBST(const BalancedBST& orig);
        virtual ~BalancedBST();
        
        // Consultors
        int size() const;
        bool isEmpty() const;
        NodeTree<T>* root();
        bool search(const T& element) const;
        const int height() const ;
        void showInorder() const;
        void showPreorder() const;
        void showPostorder() const;
        void showLeafNodes() const;
        void depthMinMax() const;
        const int height (NodeTree<T>* node) const;
        NodeTree<T>* nodeDesb(NodeTree<T>* node) const;
        
        // Modificadors
        void insert(const T& element);
        void setRoot(NodeTree<T>* p);
        void setDepth(int depth);
        void rebalance(NodeTree<T>* node);
        
    private:
        // Atributs
        NodeTree<T>* pRoot;
        
        // Metodos internos
        int size(NodeTree<T>* p) const;
        void showPreorder(NodeTree<T>* p) const;
        void showPostorder(NodeTree<T>* p) const;
        void showInorder(NodeTree<T>* p) const;
        void showLeafNodes(NodeTree<T>* elem) const;
        void destructor(NodeTree<T>* elem) const; 
        void leftRotation(NodeTree<T>* node);
        void rightRotation(NodeTree<T>* node);
        int maxDepth(NodeTree<Mountain>* node) const;
        int minDepth(NodeTree<Mountain>* node) const;
};

/* 
 * Constructor del arbole balanceado
 */
template <class T> BalancedBST <T>::BalancedBST() {
    this->pRoot = 0;
    cout << "Arbre binari creat" << endl;
}

/* 
 * Constructor copia del arbole balanceado
 */
template <class T> BalancedBST <T>::BalancedBST(const BalancedBST& orig) {
    this->pRoot = orig.pRoot;
}

/* 
 * Destructor del arbole balanceado
 */
template <class T> BalancedBST <T>::~BalancedBST() {
    cout << "Destruint arbre binari" << endl;
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        this->destructor(this->pRoot);
    }
    this->pRoot = nullptr;
    cout << "Arbre binari destruit" << endl;
}

/* 
 * Metodo que retorna la profunditat del arbole
 */
template <class T> const int BalancedBST <T>::height() const {
    return this->height(this->pRoot);
}

/* 
 * Metodo que retorna la profunditat de un node
 */
template <class T> const int BalancedBST <T>::height(NodeTree<T>* node) const {
    return node->getAlcada();
}

/* 
 * Metodo que retorna el tamaño del arbole
 */
template <class T> int BalancedBST <T>::size() const {
    if (pRoot == 0) {
        return 0;
    }
    else {
        return this->size(pRoot);
    }
}

/* 
 * Metodo que inserta un elemento al arbole
 */
template <class T> void BalancedBST<T>::insert(const T& element) {
    cout << "Inserta a l’arbre element " << element << endl;
    if (this->isEmpty())  {
        this->setRoot(new NodeTree<T>(element)); 
    }
    else {
        NodeTree <T>* nou;
        NodeTree <T>* guia = this->pRoot;
        while(guia->getElement() != element) {
            if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else {
                    nou = new NodeTree<T>(element);
                    nou->setParent(guia);
                    guia->setLeft(nou);
                    guia = nou;
                }
            }
            else {
                if (guia->right() != 0) guia = guia->right(); 
                else {
                    nou = new NodeTree<T>(element);
                    nou->setParent(guia);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
        }
        guia = nodeDesb(guia);
        if(guia != 0) rebalance(guia);
    }
}

/* 
 * Metodo que cambia el root del arbole
 */
template <class T> void BalancedBST <T>::setRoot(NodeTree<T>* elem) {
    this->pRoot = elem;
}

/* 
 * Metodo interno que retorna la profunditat de un node
 */
template <class T> int BalancedBST <T>::size(NodeTree<T>* p) const {
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

/* 
 * Metodo que retorna el root del arbole
 */
template <class T> NodeTree<T>* BalancedBST<T>::root() {
    return this->pRoot;
}

/* 
 * Metodo que verifica si el arbole esta vacio
 */
template <class T> bool BalancedBST <T>::isEmpty() const {
    return (this->size() == 0);
}

/* 
 * Metodo que verefica si existe un elemento especificado
 */
template <class T> bool BalancedBST<T>::search(const T& element) const {
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

/* 
 * Metodo que mostra el arbole en preOrdrer
 */
template <class T> void BalancedBST<T>::showPreorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Preordre = {";
        this->showPreorder(this->pRoot);
        cout << "}\n";
    }
}

/* 
 * Metodo que mostra el arbole en postOrder
 */
template <class T> void BalancedBST<T>::showPostorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Postordre = {";
        this->showPostorder(this->pRoot);
        cout << "}\n";
    }
}

/* 
 * Metodo que mostra el arbole en inOrder
 */
template <class T> void BalancedBST<T>::showInorder() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Inordre = {";
        this->showInorder(this->pRoot);
        cout << "}\n";
    }
}

/* 
 * Metodo interno que mostra el arbole en preOrder
 */
template <class T> void BalancedBST<T>::showPreorder(NodeTree<T>* elem) const {
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


/* 
 * Metodo interno que mostra el arbole en postOrder
 */
template <class T> void BalancedBST <T>::showPostorder(NodeTree<T>* elem) const {
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


/* 
 * Metodo interno que mostra el arbole en inOrder
 */
template <class T> void BalancedBST <T>::showInorder(NodeTree<T>* elem) const {
    if (!elem->isExternal() && elem->hasLeft()) {
        showInorder (elem->left());
    }
    cout << elem->getElement() << ", ";
    if (!elem->isExternal() && elem->hasRight()) {
        showInorder (elem->right());
    }
}


/* 
 * Metodo que mostra las hojas del arbole
 */
template <class T> void BalancedBST<T>::showLeafNodes() const {
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Fulles = {";
        this->showLeafNodes(this->pRoot);
        cout << "}\n";
    }
}


/* 
 * Metodo interno que mostra las hojas del arbole
 */
template <class T> void BalancedBST<T>::showLeafNodes(NodeTree<T>* elem) const {
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

/* 
 * Metodo interno destructor del arbole
 */
template <class T> void BalancedBST <T>::destructor(NodeTree<T>* node) const {
    if (node != NULL)	{
        destructor(node->left());
        node->setLeft(NULL);
        destructor(node->right());
        node->setRight(NULL);
	delete node;
    }
}

/* 
 * Metodo interno retorna la minima alçada del arbole
 */
template<class T> int BalancedBST<T>::minDepth(NodeTree<Mountain>* node) const {
    if (node->left() != 0 && node->right() != 0) {
        return 1;
    }
    if (node->left() != 0 ) {
        return minDepth(node->right()) + 1;
    }
    if (node->right() != 0 ){ 
        return minDepth(node->left()) + 1;
    }
    return min(minDepth(node->left()), minDepth(node->right())) + 1; 
}

/* 
 * Metodo interno retorna la maxima alçada del arbole
 */
template<class T> int BalancedBST<T>::maxDepth(NodeTree<Mountain>* node) const {
    if (node == NULL) {  
        return 0;
    }
    else {
        int heightLeft = maxDepth(node->left());  
        int heightRight = maxDepth(node->right());  
        if (heightLeft > heightRight) {
            return (heightLeft + 1);
        }
        else return (heightRight + 1);
    }
}


/* 
 * Metodo retorna la minima y la maxima alçada del arbole
 */
template<class T> void BalancedBST<T>::depthMinMax() const {
    if (isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Minim: " << minDepth(pRoot) << endl;
        cout << "Maxim: " << maxDepth(pRoot) << endl;
    }
}


/* 
 * Metodo que verifica si el arbole esta desbalanceado
 */
template<class T> NodeTree<T>* BalancedBST<T>::nodeDesb(NodeTree<T>* nodeInserted) const {
    int balanceFactor = 0; 
    int heightLeft = 0;
    int heightRight = 0;
    NodeTree<T>* nodeSon = nodeInserted;
    while(nodeSon != this->pRoot && balanceFactor < 2) {
        heightLeft = (nodeSon->parent()->left() != 0)? nodeSon->parent()->left()->getAlcada():0;
        heightRight = (nodeSon->parent()->right() != 0)? nodeSon->parent()->right()->getAlcada():0;
        balanceFactor = abs(heightLeft - heightRight);
        nodeSon->parent()->setAlcada(max(nodeSon->parent()->getAlcada(), nodeSon->getAlcada() + 1));
        nodeSon = nodeSon->parent();
    }
    if(balanceFactor >= 2) return nodeSon; // retorna node alfa si esta desbalanceado
    else return 0;
}

/* 
 * Metodo que rebalancea el arbole
 */
template<class T> void BalancedBST<T>::rebalance(NodeTree<T>* treeToRebalance) {
    int heightLeft = 0;
    int heightRight = 0;
    heightLeft = (treeToRebalance->left() != 0)? treeToRebalance->left()->getAlcada():0;
    heightRight = (treeToRebalance->right() != 0)? treeToRebalance->right()->getAlcada():0;
    
    // SubArbre Esquerra
    if(heightLeft > heightRight) {
        heightLeft = (treeToRebalance->left()->left() != 0)? treeToRebalance->left()->left()->getAlcada():0;
        heightRight = (treeToRebalance->left()->right() != 0)? treeToRebalance->left()->right()->getAlcada():0;
        if(heightLeft > heightRight) {
            // Cas extern esquerra
            rightRotation(treeToRebalance->left());
        }
        else {
            // Cas intern esquerra
            leftRotation(treeToRebalance->left()->right());
            rightRotation(treeToRebalance->left());
        }
    }
    else {
        heightLeft = (treeToRebalance->right()->left() != 0)? treeToRebalance->right()->left()->getAlcada():0;
        heightRight = (treeToRebalance->right()->right() != 0)? treeToRebalance->right()->right()->getAlcada():0;
        if(heightLeft > heightRight) {
            // Cas intern dreta
            rightRotation(treeToRebalance->right()->left());
            leftRotation(treeToRebalance->right());
        }
        else {
            // Cas extern dreta
            leftRotation(treeToRebalance->right());
        }
    }
}

/* 
 * Metodo que realiza la rotación derecha
 */
template <class T> void BalancedBST<T>::rightRotation(NodeTree<T>* nodeToRebalanceSon) {
    NodeTree<T>* nodeParent = nodeToRebalanceSon->parent();
    NodeTree<T>* nodeParentParent = nodeParent->parent(); 
    NodeTree<T>* nodeSon = nodeToRebalanceSon;
    if(nodeParentParent != 0) {
        if(nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); // Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon); // Era el hijo derecho
        nodeSon->setParent(nodeParentParent);
    }
    else {
        nodeSon->setParent(0);
        this->pRoot = nodeSon;
    }
    
    if (nodeSon->right() != 0) {
        nodeSon->right()->setParent(nodeParent);
        nodeParent->setLeft(nodeSon->right()); 
    }
    else nodeParent->setLeft(0);
    
    // Realizamos el giro
    nodeParent->setParent(nodeSon);
    nodeSon->setRight(nodeParent);
    // Set las nuevas alturas
    nodeParent->setAlcada(max(((nodeParent->left() != 0)? nodeParent->left()->getAlcada(): 0),((nodeParent->right() != 0)? nodeParent->right()->getAlcada():0)) + 1);
    nodeSon->setAlcada(max(((nodeSon->left() != 0)? nodeSon->left()->getAlcada(): 0),((nodeSon->right() != 0)? nodeSon->right()->getAlcada():0)) + 1);
}

/* 
 * Metodo que realiza la rotación izquierda
 */
template<class T> void BalancedBST<T>::leftRotation(NodeTree<T>* nodeToRebalanceSon) {
    NodeTree<T>* nodeParent = nodeToRebalanceSon->parent();
    NodeTree<T>* nodeParentParent = nodeParent->parent(); 
    NodeTree<T>* nodeSon = nodeToRebalanceSon;
    if(nodeParentParent != 0) {
        if(nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); // Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon); // Era el hijo derecho
        nodeSon->setParent(nodeParentParent);
    }
    else {
        nodeSon->setParent(0);
        this->pRoot = nodeSon;
    } 
    
    if(nodeSon->left() != 0) {
        nodeSon->left()->setParent(nodeParent);
        nodeParent->setRight(nodeSon->left()); 
    }
    else nodeParent->setRight(0);
    
    // Realizamos el giro
    nodeParent->setParent(nodeSon);
    nodeSon->setLeft(nodeParent);
    // Set las nuevas alturas
    nodeParent->setAlcada(max(((nodeParent->left() != 0)? nodeParent->left()->getAlcada(): 0),((nodeParent->right() != 0)? nodeParent->right()->getAlcada():0)) + 1);
    nodeSon->setAlcada(max(((nodeSon->left() != 0)? nodeSon->left()->getAlcada(): 0),((nodeSon->right() != 0)? nodeSon->right()->getAlcada():0)) + 1);
}

#endif /* BALANCEDBST_H */