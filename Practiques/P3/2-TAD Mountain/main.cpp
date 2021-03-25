/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on April 20, 2019, 3:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BSTMountainFinder.h"
#include <ctime>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    BSTMountainFinder arbreMountain;
    do {
        cout << "\n1. Llegir un fitxer amb les entrades de muntanyas\n"
                "2. Mostrar l’arbre segons l’ID en ordre creixent\n"
                "3. Cerca en l'arbre a partir d' un fitxer\n"
                "4. Profunditat de l'arbre.\n"
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
                break;
            default:
                cout << "Entrada no valida" << endl;
        }
    } while(i != 5);
    return 0;
}

