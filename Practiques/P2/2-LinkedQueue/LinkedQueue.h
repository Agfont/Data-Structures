/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedQueue.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 3:07 PM
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(const int key);
    void dequeue();
    bool isEmpty() const;
    void print() const;
    const int getFront() const;
private:
    int _size;
    Node<int> *_front;
    Node<int> *_rear;
};

#endif /* LINKEDQUEUE_H */

