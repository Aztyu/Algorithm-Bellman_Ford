/* 
 * File:   main.cpp
 * Author: Aztyu
 *
 * Created on 9 mars 2015, 11:24
 */

#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include "Matrice.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int nbre_lettre = 0;
    int depart = 1;     //On demarre de la premiere lettre : A
    
    cout << "Rentrez la taille de la matrice" << endl;
    cin >> nbre_lettre;
    
    Matrice matrix = Matrice(nbre_lettre);
    
    //init
    map<int, int> dist;
    map<int, int> pred;
    
    for(int i=0;i<nbre_lettre;i++){
        if(i == depart-1){
            dist.insert(pair<int, int>(i, 0));
            pred.insert(pair<int, int>(i, 0));
        }else{
            dist.insert(pair<int, int>(i, 100));
            pred.insert(pair<int, int>(i, -1));
        }
    }
    
    bool hasChanged = true;
    
    while(hasChanged){
        hasChanged = false;
        for(map<int, int>::iterator it_x = dist.begin(); it_x != dist.end(); it_x++){
            for(map<int, int>::iterator it_y = dist.begin(); it_y != dist.end(); it_y++){
                if((*it_y).first != (*it_x).first){
                    //Tri des successeurs du point
                    if(matrix.GetValue((*it_x).first, (*it_y).first) != 0 && matrix.GetValue((*it_x).first, (*it_y).first) != 100){ //Si c'est un sucesseur du point
                        cout << (*it_x).first << "." << (*it_x).second << "." << (*it_y).first << "." << (*it_y).second << endl; 
                        if(dist[(*it_y).first] > dist[(*it_x).first] + matrix.GetValue((*it_x).first, (*it_y).first)){
                            (*it_y).second = dist[(*it_x).first] + matrix.GetValue((*it_x).first, (*it_y).first);
                            pred[(*it_y).first] = (*it_x).first;
                            hasChanged = true;
                        }
                    }
                }
            }
        }
    }
    
    for(map<int, int>::iterator it = dist.begin(); it != dist.end(); it++){ //Affichage des distances
        cout << IntToLetter((*it).first) << ":" << (*it).second << endl;
    }
    
    cout << endl;
    for(map<int, int>::iterator it = pred.begin(); it != pred.end(); it++){ //Affichage des predecesseurs
        cout << IntToLetter((*it).first) << ":" << IntToLetter((*it).second) << endl;
    }
    
    cout << "Appuyer sur n'importe quelle touche pour terminer" << endl;
    cin.get();
    cin.get();
    return 0;
}



