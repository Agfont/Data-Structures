/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on March 7, 2019, 12:44 PM
 */

#include <cstdlib>

#include "Time.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Time t1; // = Time t1() [Stack]
    t1.print();
    Time t2(10,50,00); // [Stack]
    t2.print();
    
    Time *ptr = &t1;
    ptr->print(); // = (*ptr).print()
    
    Time &ptr2 = t2;
    ptr2.print(); // imprimeix [10, 50, 00]
    
    Time *ptr3 = new Time(4,5,6);
    ptr3->print();
    return 0;
    
    Time array[2];
    (*array).print(); // array[0].print()
    (*array+1).print(); // array[1].print()
    
    Time array2[2] = {Time (2,4,5), Time (3)}
    
    Time *array3 = new Time[2];
    //
    delete [] array3;
    
    Time *array4 = new Time[2] {Time (3), Time (23,5)};
    array4[0].print(); // (*array4).print();
    array4->print();
    
    array4[1].print();
    (*array4+1).print();
    (array4+1)->print();
}

