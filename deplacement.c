#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defPiece.h"
#include "fct.h"
#include "deplacement.h"

void depPossible(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){ //Trace les chemins empruntable par la pièce choisit
    int pX;
    int pY;
    switch (p.valeur) {
        case 'P':
            // if()
            if(strncmp(p.couleur,"34",3) == 0){
                pX = p.posX+1;
                while (plateau[pX][p.posY].enVie == 0) {
                    plateau[pX][p.posY] = videP;
                    pX++;
                }
            }else{
                pX = p.posX-1;
                while (plateau[pX][p.posY].enVie == 0) {
                    plateau[pX][p.posY] = videP;
                    pX--;
                }
            }
            break;

        case 'T':

            break;

        case 'C':

            break;

        case 'F':

            break;

        case 'D':

            break;

        case 'R':

            break;

    }
    aff(plateau, p.couleur);

}

int move(piece plateau[SIZE_X][SIZE_Y], piece p, int xDep, int yDep, char c[3], piece vide, piece videP){ //Un des joueur joue (redirection en fonction de la pièce joué)
    switch (p.valeur) {
        case 'P':
            if(movePion(plateau, p, xDep, yDep, vide, videP) != 0){
                printf("Err\n");
                return 1;
            }
            break;

        case 'T':

            break;

        case 'C':

            break;

        case 'F':

            break;

        case 'D':

            break;

        case 'R':

            break;

    }

    if(strncmp(c, "31", 3) == 0){
        strcpy(c, "34");
    }else{
        strcpy(c,"31");
    }


    initialisation(plateau);
    aff(plateau, c);
    return 0;
}

int movePion(piece plateau[SIZE_X][SIZE_Y], piece p, int xDep, int yDep, piece vide, piece videP){ //Déplacement du pion
    int newX = p.posX;
    int newY = p.posY;

    // if(((strncmp(p.couleur, "31", 3) == 0) && (p.posX == 6)) || ((strncmp(p.couleur, "34", 3) == 0) && (p.posX == 2))){
    //     newX -= 2;
    // }else{
    //     newX --;
    // }

    if(plateau[yDep][xDep].enVie == 0){ //La place est libre
        //On prépare les coordonnées
        newX = yDep;
        newY = xDep;

        //On déplace la pièce
        plateau[newX][newY] = p;
        plateau[p.posX][p.posY] = vide;
        plateau[newX][newY].posX = newX;
        plateau[newX][newY].posY = newY;
    }else{
        printf("La case (%d;%d) est occupé\n", yDep, xDep);
    }

    return 0;
}
