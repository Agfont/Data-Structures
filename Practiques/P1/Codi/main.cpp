/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arthurfont
 *
 * Created on March 6, 2019, 10:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Ellipse.h"
#include "Circle.h"
#include "EllipseContainer.h"
#include <limits>

using namespace std;

void afegirFigura(int &nCercle, int &nEllipse, EllipseContainer &contenidor1){
    char seleccioFigura;
    int R1;
    int R2;
    
    cout << "Entra les dades de la teva figura ( tipus[C o E] data1 data2[buit si el tipus es C] )\n";
    cin >> seleccioFigura;
    
    switch (seleccioFigura){
        case 'C':{
            cin >> R1;
            Circle *cercle1;
            try {
                int res = cercle1->excepcio(R1);
                if (res == -1) break;
                cercle1 = new Circle();
                cercle1->setRadis(R1);
            
                contenidor1.addEllipse(cercle1);
                cercle1->getArea();
                nCercle++;
            
                cout << "L’àrea d’aquesta cercle és de: " << cercle1->getArea() << "\n";
            }
            catch(const invalid_argument& e){
                cout << e.what() << "\n";
                cout << "S’ha produït una excepció\n";
            }
            
            break;
        }
        
        case 'E':{ 
            cin >> R1 >> R2;
            Ellipse *elipse1;
            try {
                int res = elipse1->excepcio(R1,R2);
                if (res == -1) break;
                elipse1 = new Ellipse();
                elipse1->setRadis(R1, R2);
                contenidor1.addEllipse(elipse1);

                elipse1->getArea();
                nEllipse++;

                cout << "L’àrea d’aquesta el·lipse és de: " << elipse1->getArea() << "\n";
            }
            catch(const invalid_argument& e){
                cout << e.what() << "\n";
                cout << "S’ha produït una excepció\n";
            }
            break;
        }
        
        default:{
            cout << "Case Error!\n";
            break;
        }
    }
}

void afegirFiguraFitxer(int &nCercle, int &nEllipse, EllipseContainer &contenidor1){
    char seleccioFigura;
    int R1;
    int R2;
    ifstream fitxer("figures.txt");
    
    while(!fitxer.eof()){
        
    fitxer >> seleccioFigura;
    if (fitxer.eof()) break;
    
    switch (seleccioFigura){
        case 'C':{
            fitxer >> R1;
            Circle *cercle1;
            try {
                int res = cercle1->excepcio(R1);
                if (res == -1) break;
                cercle1 = new Circle();
                cercle1->setRadis(R1);
            
                contenidor1.addEllipse(cercle1);
                cercle1->getArea();
                nCercle++;
            
                cout << "L’àrea d’aquesta cercle és de: " << cercle1->getArea() << "\n";
            }
            catch(const invalid_argument& e){
                cout << e.what() << "\n";
                cout << "S’ha produït una excepció\n";  
            }
            
            break;}
        
        case 'E':{ 
            fitxer >> R1 >> R2;
            Ellipse *elipse1;
            try {
                int res = elipse1->excepcio(R1,R2);
                if (res == -1) break;
                elipse1 = new Ellipse();
                elipse1->setRadis(R1, R2);
                contenidor1.addEllipse(elipse1);

                elipse1->getArea();
                nEllipse++;

                cout << "L’àrea d’aquesta el·lipse és de: " << elipse1->getArea() << "\n";
            }
            catch(const invalid_argument& e){
                cout << e.what() << "\n";
                cout << "S’ha produït una excepció\n";  
            }
            break;}
        
        default:{
            cout << "Case Error!\n";
            break;}
        }      
    }
    fitxer.close();
}

void menu(vector<string> v, int &contadorC, int &contadorE, EllipseContainer &contenidor1){
    int option;    
        do  {  
        for(int i = 1; i <= v.size(); i++){
            cout << i << ". " << v[i-1] << "\n";
        }
     
        cin >> option;
        if(!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            option = 6;
        }
        switch(option){
            case 1:
                break;
            case 2:
                afegirFigura(contadorC, contadorE, contenidor1);
                break;
            case 3:
                cout << "Nombre de Cercles: " << contadorC << "\n";
                cout << "Nombre d'Ellipses: " << contadorE << "\n";
                break;
            case 4:
                afegirFiguraFitxer(contadorC, contadorE, contenidor1);
                break;
            case 5:
                cout << "La suma és: " << contenidor1.getArea() << "\n";
                break;
            default:
                cout << "Tria una opció diferent, aquesta no existeix!\n";
                break;
        }
    }while(option != 1);
}

int main(int argc, char** argv) {
    
    int contadorCercles = 0;
    int contadorEllipses = 0;
    
    string arr_options[] = {"Sortir", "Afegir Figura", "Glossari de figures", "Llegir fitxer", "Suma d'Areas"};
    vector<string> options(begin(arr_options), end(arr_options));
    
    EllipseContainer contenidor1;

    cout << "Hola, que vols fer?\n";

    menu(options, contadorCercles, contadorEllipses, contenidor1);
    return 0;

}
