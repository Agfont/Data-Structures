/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on March 10, 2019, 8:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "LinkedQueue.h"
#include "Flight.h"
#include <fstream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    int i;
    // Llamada al constructor
    LinkedQueue cola;
    
    do {
        cout << "\n1. Llegir un fitxer amb les entrades de vols\n"
                "2. Eliminar un vol\n"
                "3. Inserir n entrades de vols des de teclat (0 per finalizar)\n"
                "4. Imprimir tot el contingut de l'LinkedQueue\n"
                "5. Sortir\n";
        cin >> i;
        switch(i) {
            case 1: {
                // Llegir de un fitxer 
                ifstream infile;
                string vol;

                infile.open("flights.csv");
                if (infile.is_open()) {
                    char delimiter = ',';
                    while (getline(infile, vol)) {
                        Flight f1;
                        string aux;

                        aux = vol.substr(0, vol.find(delimiter));
                        f1.setId(aux);
                        vol = vol.substr(vol.find(delimiter)+1);

                        aux = vol.substr(0, vol.find(delimiter));
                        f1.setOrigen(aux);
                        vol = vol.substr(vol.find(delimiter)+1);

                        aux = vol.substr(0, vol.find(delimiter));
                        f1.setDesti(aux);
                        vol = vol.substr(vol.find(delimiter)+1);
                        
                        f1.setHora(vol);
                        try {
                            cola.enqueue(f1);
                        }
                        catch (out_of_range e) {
                            cout << e.what() << endl;
                        }
                    }
                infile.close();
                }
                else cout << "Unable to open file";
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
            case 3: {
                // Inserir n entrades de vols de teclat (0 per acabar)
                
                bool sortir = false;
                
                do {
                    cout << "\nIdentificador (0 per acabar): ";
                    Flight flight1;
                    string aux;
                    
                    cin >> aux;
                    if (aux == "0") { // (0 per acabar)
                        sortir = true;
                        break;
                    }
                    flight1.setId(aux);

                    cout << "Origen: ";
                    cin >> aux;
                    flight1.setOrigen(aux);

                    cout << "Destí: ";
                    cin >> aux;
                    flight1.setDesti(aux);

                    cout << "Hora de sortida: ";
                    cin >> aux;
                    flight1.setHora(aux);

                    try {
                        cola.enqueue(flight1);
                    }
                    catch (out_of_range e) {
                        cout << e.what() << endl;
                    }
                } while (!sortir);
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