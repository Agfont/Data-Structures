/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on April 25, 2019, 11:20 AM
 */
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BSTMountainFinder.h"
#include <ctime>

using namespace std;

/*          Inserció Fitxer SMALL    Inserció Fitxer LLARG    Cerca Fitxer SMALL    Cerca Fitxer LLARG
BST          O(log n) to O(n)          O(log n) to O(n)        O(log n) to O(n)      O(log n) to O(n)
BalancedBST     O(log n)                  O(log n)                O(log n)              O(log n)
 * 
 * En estructuras de pequeño tamaño, la diferencia del tiempo de execución de una inserció o una cerca
 * és desconsiderable.
 * Entretanto, cuanto mayor es la estructura, mas se nota la diferencia del tiempo de execución.
 * Por eso, en grande escala es extremamente necessario tener el arbole balanceado.
 */
int main(int argc, char** argv) {
    int i;
    BSTMountainFinder arbreMountain;
    do {
        cout << "\n1. Llegir un fitxer amb les entrades de muntanyas\n"
                "2. Mostrar l’arbre segons l’ID en ordre creixent\n"
                "3. Cerca en l'arbre a partir d' un fitxer\n"
                "4. Profunditat de l'arbre.\n"
                "5. Muntanya més llarga.\n"
                "6. Valor d’alçada màxim i mínim\n"
                "7. Muntanya més alta\n"
                "8. Muntanya més baixa\n"
                "9. Sortir\n";
        cin >> i;
        switch(i) {
            case 1: {
                char fitxer;
                clock_t t;
                cout << "Quin fitxer vols (P/G)?" << endl;
                cin >> fitxer;
                t = clock();
                if (fitxer == 'P') {
                    arbreMountain.appendMountains("Mountain_list_small.txt");
                }
                else if (fitxer = 'G') {
                    arbreMountain.appendMountains("Mountain_list.txt");
                }
                t = clock() - t;
                cout << t/(double)CLOCKS_PER_SEC << "s" << endl;
            }
                break;
            case 2:
                try {
                    arbreMountain.showInorderMountain();
                }
                catch (out_of_range e) {
                    cout << e.what() << endl;
                }
                break;
            case 3: {
                clock_t t = clock();
                arbreMountain.cercaFitxer("cercaMuntanyes.txt");
                t = clock() - t;
                cout << t/(double)CLOCKS_PER_SEC << "s" << endl;
            }
                break;
            case 4:
                cout << "Profunditat: " << arbreMountain.getHeight() << endl;
                break;
            case 5:
                arbreMountain.nomMuntayaMesLlarga("Mountain_list.txt");
                break;
            case 6:
                arbreMountain.depthMinMax();
                break;
            case 7:
                arbreMountain.tallestMountain("Mountain_list.txt");
                break;
            case 8:
                arbreMountain.shortestMountain("Mountain_list.txt");
                break;
            case 9:
                break;
            default:
                cout << "Entrada no valida" << endl;
        }
    } while(i != 9);
    return 0;
}