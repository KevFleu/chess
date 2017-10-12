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
            if(strncmp(p.couleur,"34",3) == 0){ //Blanc
                pX = p.posX+1;
                int dep = 1;
                int max = 1;
                if (p.posX==1){
                    max = 2;
                }
                while ((plateau[pX][p.posY].enVie == 0) && (dep<=max)) {
                    plateau[pX][p.posY] = videP;
                    pX++;
                    dep++;
                }
            }else{ //Noir
                pX = p.posX-1;
                int dep = 1;
                int max = 1;
                if (p.posX==6){
                    max = 2;
                }
                while ((plateau[pX][p.posY].enVie == 0) && (dep<=max)) {
                    plateau[pX][p.posY] = videP;
                    pX--;
                    dep++;
                }
            }
            break;

        case 'T':
            if(strncmp(p.couleur,"34",3) == 0){ //Blanc
                pX = p.posX+1;
                pY = p.posY+1;
                if(p.posX<7){
                    while (plateau[pX][p.posY].enVie == 0) {
                        plateau[pX][p.posY] = videP;
                        pX++;
                    }
                }
                if(p.posY<7){
                    while (plateau[p.posX][pY].enVie == 0) {
                        plateau[p.posX][pY] = videP;
                        pY++;
                    }
                }
                pX = p.posX-1;
                pY = p.posY-1;
                if(p.posX>0){
                    while (plateau[pX][p.posY].enVie == 0) {
                        plateau[pX][p.posY] = videP;
                        pX--;
                    }
                }
                if(p.posY>0){
                    while (plateau[p.posX][pY].enVie == 0) {
                        plateau[p.posX][pY] = videP;
                        pY--;
                    }
                }
            }
            break;

        case 'C':
            // pX = p.posX;
            // pY = p.posY;
            if(plateau[p.posX+2][p.posY+1].enVie == 0){
                plateau[p.posX+2][p.posY+1] = videP;
            }
            if(plateau[p.posX+2][p.posY-1].enVie == 0){
                plateau[p.posX+2][p.posY-1] = videP;
            }
            if(plateau[p.posX+1][p.posY+2].enVie == 0){
                plateau[p.posX+1][p.posY+2] = videP;
            }
            if(plateau[p.posX+1][p.posY-2].enVie == 0){
                plateau[p.posX+1][p.posY-2] = videP;
            }
            if(plateau[p.posX-1][p.posY+2].enVie == 0){
                plateau[p.posX-1][p.posY+2] = videP;
            }
            if(plateau[p.posX-1][p.posY-2].enVie == 0){
                plateau[p.posX-1][p.posY-2] = videP;
            }
            if(plateau[p.posX-2][p.posY+1].enVie == 0){
                plateau[p.posX-2][p.posY+1] = videP;
            }
            if(plateau[p.posX-2][p.posY-1].enVie == 0){
                plateau[p.posX-2][p.posY-1] = videP;
            }
            break;

        case 'F':
            pX = p.posX+1;
            pY = p.posY+1;
            if((p.posX<7) && (p.posY<7)){
                while ((plateau[pX][pY].enVie == 0) && (pX<=7) && (pY<=7)) {
                    plateau[pX][pY] = videP;
                    pX++;
                    pY++;
                }
            }
            pX = p.posX+1;
            pY = p.posY-1;
            if((p.posX<7) && (p.posY>0)){
                while((plateau[pX][pY].enVie==0) && (pX<=7) && (pY>=0)) {
                    plateau[pX][pY] = videP;
                    pX++;
                    pY--;
                }
            }
            pX = p.posX-1;
            pY = p.posY-1;
            if((p.posX>0) && (p.posY>0)){
                while ((plateau[pX][pY].enVie == 0) && (pX>=0) && (pY>=0)) {
                    plateau[pX][pY] = videP;
                    pX--;
                    pY--;
                }
            }
            pX = p.posX-1;
            pY = p.posY+1;
            if((p.posX>=0) && (p.posY<7)){
                while ((plateau[pX][pY].enVie == 0) && (pX>=0) && (pY<=7)) {
                    plateau[pX][pY] = videP;
                    pX--;
                    pY++;
                }
            }
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
            if(moveTour(plateau, p, xDepl, yDepl, vide) != 0){
                printf("Err\n");
                return 1;
            }
            break;

        case 'C':
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

int moveTour(piece plateau[SIZE_X][SIZE_Y], piece p, int xDepl, int yDepl, piece vide){ //Déplacement du tour
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
        for(int j=0; j<SIZE_Y; j++) {
            if(plateau[i][j].valeur == 'X'){
                plateau[i][j].valeur = ' ';
            }
        }
    }

    return 0;
}
