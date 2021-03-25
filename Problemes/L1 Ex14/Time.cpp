/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: arthurfont
 * 
 * Created on March 7, 2019, 12:45 PM
 */

#include "Time.h"
#include <stdexcept>
#include <vector>

Time::Time() {
}

Time::Time(int h, int m, int s) {
    this->setHour(h);
    this->setMinute(m);
    this->setSecond(s); // = (*this.setSecond(s))
}

Time::Time(const Time& orig) {
}

Time::~Time() {
}

void Time::setHour(int h) {
    if (h <= 23 && h>=0) {
        this->hour = h;
    }
    else {
        throw std::invalid_argument("Hour out of range");
    }
}

void Time::setMinute(int m) {
    if (m <= 59 && m>=0) {
        this->minute = m;
    }
    else {
        throw std::invalid_argument("Minute out of range");
    }
}

void Time::setSecond(int s) {
    if (s <= 59 && s>=0) {
        this->minute = s;
    }
    else {
        throw std::invalid_argument("Minute out of range");
    }
}

void Time::print() const{
    // for (std::vector<int>::iterator it;)
}

