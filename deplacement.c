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

int move(piece plateau[SIZE_X][SIZE_Y], piece p, int xDepl, int yDepl, char c[3], piece vide, piece videP){ //Un des joueur joue (redirection en fonction de la pièce joué)
    switch (p.valeur) {
        case 'P':
            if(movePion(plateau, p, xDepl, yDepl, vide) != 0){
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


    // initialisation(plateau);
    // aff(c);
    return 0;
}

int movePion(piece plateau[SIZE_X][SIZE_Y], piece p, int xDepl, int yDepl, piece vide){ //Déplacement du pion
    if(plateau[yDepl][xDepl].valeur == 'X'){ //La place est libre
        plateau[yDepl][xDepl] = p;
        plateau[p.posX][p.posY] = vide;

        //On déplace la pièce

        plateau[yDepl][xDepl].posX = yDepl;
        plateau[yDepl][xDepl].posY = xDepl;
    }else{
        printf("La case (%d;%d) est occupé\n", yDepl, xDepl);
    }
    for(int i=0; i<SIZE_X; i++) {
        for (int j=0; j<SIZE_Y; j++) {
            if(plateau[i][j].valeur == 'X'){
                plateau[i][j].valeur = ' ';
            }
        }
    }

    return 0;
}
