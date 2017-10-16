#ifndef DEFPIECE_H
#define DEFPIECE_H
//On définie une structure pièce
typedef struct piece piece;
struct piece{
    int enVie; //booléen 1=vrai, 0=faux
    int posX; //position sur l'axe vertical
    int posY; //position sur l'axe horizontal
    char couleur[3]; // '34'=blanc(bleu), '31'=noir(rouge)
    char valeur; //'T'=tour, 'C'=cavalier, 'F'=fou, 'D'=dame, 'R'=roi, 'P'=pion
};

#define SIZE_X 8
#define SIZE_Y 8

#endif /* DEFPIECE_H*/
