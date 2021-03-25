/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on March 7, 2019, 1:19 PM
 */

#include <cstdlib>

#include "Pc.h"
#include "Portatil.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Pc* ptrPc = new Pc();
    Pc nokia;
    Portatil computer;
    
    ptrPc->capturar();
    ptrPc->imprimir();
    
    computer.capturar();
    computer.imprimir();
    
    return 0;
}
