/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.h
 * Author: arthurfont
 *
 * Created on March 6, 2019, 1:15 PM
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <vector>

class ArrayQueue {
public:
    ArrayQueue(const int max_size);
    virtual ~ArrayQueue();
    void enqueue(const int key);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void print();
    const int getFront();
private:
    int max_size;
    int size;
    std::vector<int> v;
    
};

#endif /* ARRAYQUEUE_H */

