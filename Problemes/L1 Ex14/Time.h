/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: arthurfont
 *
 * Created on March 7, 2019, 12:45 PM
 */

#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time();
    Time(const Time& orig);
    Time(int hour, int minute, int second);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    int getHour() const;
    int getMinute() const;
    int getSecond () const;
    int nextSecond();
    void print() const;
    virtual ~Time();
private:
    int hour, minute, second;

};

#endif /* TIME_H */

