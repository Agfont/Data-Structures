/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on March 6, 2019, 1:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "ArrayQueue.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    
    int i, max_size;
    cout << "Tamany del vector: ";
    cin >> max_size;
    // Llamada al constructor
    ArrayQueue cola(max_size);
    do {
        cout << "\n1. Inserir element a la cua\n"
                "2. Treure element de la cua\n"
                "3. Consultar el primer element\n"
                "4. Imprimir tot el contingut de l'ArrayQueue\n"
                "5. Sortir\n";
        cin >> i;
        switch(i) {
            case 1:
                int elementAdd;
                cout << "Element: ";
                cin >> elementAdd;
                try {
                    cola.enqueue(elementAdd);
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try {
                    cola.dequeue();
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << cola.getFront() << endl;
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                cola.print();
                break;
            case 5:
                break;
        }
    } while (i != 5);
    return 0;
}