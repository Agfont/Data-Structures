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

#include "FlightNode.h"
#include "Flight.h"

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(const Flight& f);
    void dequeue();
    bool isEmpty() const;
    void print() const;
    const Flight& getFront() const;
private:
    int _size;
    FlightNode<Flight> *_front;
    FlightNode<Flight> *_rear;
};

#endif /* LINKEDQUEUE_H */

