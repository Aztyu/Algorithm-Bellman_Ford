/* 
 * File:   Matrice.h
 * Author: Aztyu
 *
 * Created on 9 mars 2015, 11:25
 */

/* 
 * File:   Matrice.h
 * Author: Aztyu
 *
 * Created on 7 mars 2015, 20:37
 */

#ifndef MATRICE_H
#define	MATRICE_H

#include <iostream>

class Matrice {
public:
    Matrice();
    Matrice(int taille);
    Matrice(const Matrice& orig);
    virtual ~Matrice();
    int GetValue(int ligne, int colonne);

private:
    int taille;
    int** mat_tab;
};

char IntToLetter(int nombre);

#endif	/* MATRICE_H */



