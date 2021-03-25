/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on May 17, 2019, 6:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "HeapMountainFinder.h"

using namespace std;

/* -Tiempo de generación del heap         -Tiempo de acceso al heap
 * Lista pequeña: 0.002087s                Lista pequeña: 0.004004s 
 * Lista grande: 0.021453s                 Lista grande: 0.012277s
 * 
 * -Insertion on Heap               -Search on Heap
 * Worst case: O(log n)             Worst case: O(n)
 * Average case: O(1)               Average case: O(1)
 * 
 * En la estructura menor, la diferencia del tiempo de execución 
 * de una inserción o una búsqueda és desconsiderable.
 * En la estructura mayor, la generación del heap ha tardado mas que la
 * búsqueda de todos elementos del heap.
 * 
 * La búsqueda en un MaxHeap para encontrar el elemento máximo tiene complexidad O(1)
 * y la busqueda de un elemento en un heap se ha mostrado muy eficiente.
 */
int main(int argc, char** argv) {
    int i;
    HeapMountainFinder heapMountain;
    do {
        cout << "\n1. Llegir un fitxer amb les entrades de muntanyas\n"
                "2. Mostrar l’heap en amplada\n"
                "3. Cerca en l'heap a partir d' un fitxer\n"
                "4. Profunditat de l'heap.\n"
                "5. Sortir\n";
        cin >> i;
        switch(i) {
            case 1: {
                char fitxer;
                clock_t t;
                cout << "Quin fitxer vols (P/G)?" << endl;
                cin >> fitxer;
                t = clock();
                if (fitxer == 'P') {
                    heapMountain.appendMountains("Mountain_list_small.txt");
                }
                else if (fitxer = 'G') {
                    heapMountain.appendMountains("Mountain_list.txt");
                }
                t = clock() - t;
                cout << t/(double)CLOCKS_PER_SEC << "s" << endl;
            }
                break;
            case 2:
                try {
                    heapMountain.showHeapMountain();
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 3: {
                clock_t t = clock();
                heapMountain.cercaFitxer("cercaMuntanyes.txt");
                t = clock() - t;
                cout << t/(double)CLOCKS_PER_SEC << "s" << endl;
            }
                break;
            case 4:
                heapMountain.showDepth();
                break;
            case 5:
                break;
            default:
                cout << "Entrada no valida" << endl;
        }
    } while(i != 5);

    return 0;
}