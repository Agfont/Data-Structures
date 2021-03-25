/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on May 13, 2019, 6:25 PM
 */

#include <cstdlib>
#include "Mountain.h"
#include "MaxHeap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    MaxHeap<int> cola (10);
    do {
        cout << "\n1. Inserir element al heap\n"
                "2. Remove max element del heap\n"
                "3. Max Key heap\n"
                "4. Max Values heap\n"
                "5. Imprimir tot el contingut del heap\n"
                "6. Sortir\n";
        cin >> i;
        switch(i) {
            case 1: {
                int key, elementAdd;
                cout << "Clau: ";
                cin >> key;
                cout << "Value: ";
                cin >> elementAdd;
                try {
                    cola.insert(key, elementAdd);
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
            }
                break;
            case 2:
                try {
                    cola.removeMax();
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << cola.max() << endl;
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    cout << cola.maxValues() << endl;
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                cola.printHeap();               
                break;
        }
    } while (i != 6);
    return 0;
}

