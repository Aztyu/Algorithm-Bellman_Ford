/* 
 * File:   Matrice.cpp
 * Author: Aztyu
 * 
 * Created on 7 mars 2015, 20:37
 */

#include "Matrice.h"

using namespace std;

Matrice::Matrice() {
}

Matrice::Matrice(int taille) {
    this->taille = taille;
    this->mat_tab = new int*[taille];
    
    for(int i=0; i<taille; i++){
        this->mat_tab[i] = new int[taille];
    }
    
    /*mat_tab[0][0] = 0;
    mat_tab[0][1] = 7;
    mat_tab[0][2] = 1;
    mat_tab[0][3] = 100;
    mat_tab[0][4] = 100;
    mat_tab[0][5] = 100;
    
    mat_tab[1][0] = 100;
    mat_tab[1][1] = 0;
    mat_tab[1][2] = 100;
    mat_tab[1][3] =4;
    mat_tab[1][4] =100;
    mat_tab[1][5] = 1;
    
    mat_tab[2][0] = 100;
    mat_tab[2][1] = 5;
    mat_tab[2][2] = 0;
    mat_tab[2][3] = 100;
    mat_tab[2][4] = 2;
    mat_tab[2][5] = 7;
    
    mat_tab[3][0] = 100;
    mat_tab[3][1] = 100;
    mat_tab[3][2] = 100;
    mat_tab[3][3] = 0;
    mat_tab[3][4] = 100;
    mat_tab[3][5] = 100;
    
    mat_tab[4][0] = 100;
    mat_tab[4][1] = 2;
    mat_tab[4][2] = 100;
    mat_tab[4][3] = 5;
    mat_tab[4][4] = 0;
    mat_tab[4][5] = 100;
    
    mat_tab[5][0] = 100;
    mat_tab[5][1] = 100;
    mat_tab[5][2] = 100;
    mat_tab[5][3] = 100;
    mat_tab[5][4] = 3;
    mat_tab[5][5] = 0;*/
    
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            cout << "Rentrez la valeur en " << i << " - " << j << endl;
            int valeur;
            cin >> valeur;
            this->mat_tab[i][j] = valeur;
        }
    }
    
    cout << "Fin" << endl;
}

Matrice::Matrice(const Matrice& orig) {
}

Matrice::~Matrice() {
    for(int i=0; i<taille; i++){
        delete [] this->mat_tab[i];
    }
    delete [] this->mat_tab;
}

int Matrice::GetValue(int ligne, int colonne){
    return this->mat_tab[ligne][colonne];
}

char IntToLetter(int nombre){
    return nombre+65;
}


