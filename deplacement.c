#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defPiece.h"
#include "fct.h"
#include "deplacement.h"

void depPossible(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){ //Trace les chemins empruntable par la pièce choisit
    int pX, pY;
    switch (p.valeur) {
        case 'P':
            depPion(plateau, p, vide, videP);
            break;

        case 'T':
            depTour(plateau, p, vide, videP);
            break;

        case 'C':
            depCav(plateau, p, vide, videP);
            break;

        case 'F':
            depFou(plateau, p, vide, videP);
            break;

        case 'D':
            depFou(plateau, p, vide, videP);
            depTour(plateau, p, vide, videP);
            break;

        case 'R':
            depRoi(plateau, p, vide, videP);
            break;

    }
    aff(plateau, p.couleur);

}

int move(piece plateau[SIZE_X][SIZE_Y], piece p, int xDepl, int yDepl, char c[3], piece vide, piece videP){ //Un des joueur joue (redirection en fonction de la pièce joué)
    if(plateau[yDepl][xDepl].valeur == 'X'){ //La place est libre
        plateau[yDepl][xDepl] = p;
        plateau[p.posX][p.posY] = vide;

        //On déplace la pièce

        plateau[yDepl][xDepl].posX = yDepl;
        plateau[yDepl][xDepl].posY = xDepl;
    }else{
        printf("La case (%d;%d) est occupé\n", yDepl, xDepl);
    }

    if(strncmp(c, "31", 3) == 0){
        strcpy(c, "34");
    }else{
        strcpy(c,"31");
    }

    for(int i=0; i<SIZE_X; i++) {
        for (int j=0; j<SIZE_Y; j++) {
            if(plateau[i][j].valeur == 'X'){
                plateau[i][j].valeur = ' ';
            }
            // if(strncmp(&plateau[i][j].valeur,"32", 3) == 0){
            //     strcpy(&plateau[i][j].valeur, c);
            // }
        }
    }


    // initialisation(plateau);
    // aff(c);
    return 0;
}

int depPion(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){ //Déplacement du pion
    int pX;
    int pY;

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
    return 0;
}

int depTour(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){
    int pX, pY;
    pX = p.posX+1;
    pY = p.posY+1;
    if(p.posX<7){
        while ((plateau[pX][p.posY].enVie == 0) && (pX<=7)) {
            plateau[pX][p.posY] = videP;
            pX++;
        }
        if((plateau[pX][p.posY].enVie == 1) && (strcmp(plateau[pX][p.posY].couleur, p.couleur)!=0)){
            strcpy(plateau[pX][p.posY].couleur, "32");
        }
    }
    if(p.posY<7){
        while ((plateau[p.posX][pY].enVie == 0) && (pY<=7)) {
            plateau[p.posX][pY] = videP;
            pY++;
        }
        if((plateau[p.posX][pY].enVie == 1) && (strcmp(plateau[p.posX][pY].couleur, p.couleur)!=0)){
            strcpy(plateau[p.posX][pY].couleur, "32");
        }
    }
    pX = p.posX-1;
    pY = p.posY-1;
    if(p.posX>0){
        while ((plateau[pX][p.posY].enVie == 0) && (pX>=0)) {
            plateau[pX][p.posY] = videP;
            pX--;
        }
        if((plateau[pX][p.posY].enVie == 1) && (strcmp(plateau[pX][p.posY].couleur, p.couleur)!=0)){
            strcpy(plateau[pX][p.posY].couleur, "32");
        }
    }
    if(p.posY>0){
        while ((plateau[p.posX][pY].enVie == 0) && (pY>=0)) {
            plateau[p.posX][pY] = videP;
            pY--;
        }
        if((plateau[p.posX][pY].enVie == 1) && (strcmp(plateau[p.posX][pY].couleur, p.couleur)!=0)){
            strcpy(plateau[p.posX][pY].couleur, "32");
        }
    }
    return 0;
}

int depCav(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){
    if((plateau[p.posX+2][p.posY+1].enVie == 0) && (p.posX<6) && (p.posY<7)){
        plateau[p.posX+2][p.posY+1] = videP;
    }
    else if((plateau[p.posX+2][p.posY+1].enVie == 1) && (strcmp(plateau[p.posX+2][p.posY+1].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX+2][p.posY+1].couleur, "32");
    }
    if((plateau[p.posX+2][p.posY-1].enVie == 0) && (p.posX<6) && (p.posY>0)){
        plateau[p.posX+2][p.posY-1] = videP;
    }
    else if((plateau[p.posX+2][p.posY-1].enVie == 1) && (strcmp(plateau[p.posX+2][p.posY-1].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX+2][p.posY-1].couleur, "32");
    }
    if((plateau[p.posX+1][p.posY+2].enVie == 0) && (p.posX<7) && (p.posY<6)){
        plateau[p.posX+1][p.posY+2] = videP;
    }
    else if((plateau[p.posX+1][p.posY+2].enVie == 1) && (strcmp(plateau[p.posX+1][p.posY+2].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX+1][p.posY+2].couleur, "32");
    }
    if((plateau[p.posX+1][p.posY-2].enVie == 0) && (p.posX<7) && (p.posY>1)){
        plateau[p.posX+1][p.posY-2] = videP;
    }
    else if((plateau[p.posX+1][p.posY-2].enVie == 1) && (strcmp(plateau[p.posX+1][p.posY-2].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX+1][p.posY-2].couleur, "32");
    }
    if((plateau[p.posX-1][p.posY+2].enVie == 0) && (p.posX>0) && (p.posY<6)){
        plateau[p.posX-1][p.posY+2] = videP;
    }
    else if((plateau[p.posX-1][p.posY+2].enVie == 1) && (strcmp(plateau[p.posX-1][p.posY+2].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX-1][p.posY+2].couleur, "32");
    }
    if((plateau[p.posX-1][p.posY-2].enVie == 0) && (p.posX>0) && (p.posY>1)){
        plateau[p.posX-1][p.posY-2] = videP;
    }
    else if((plateau[p.posX-1][p.posY-2].enVie == 1) && (strcmp(plateau[p.posX-1][p.posY-2].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX-1][p.posY-2].couleur, "32");
    }
    if((plateau[p.posX-2][p.posY+1].enVie == 0) && (p.posX>1) && (p.posY<7)){
        plateau[p.posX-2][p.posY+1] = videP;
    }
    else if((plateau[p.posX-2][p.posY+1].enVie == 1) && (strcmp(plateau[p.posX-2][p.posY+1].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX-2][p.posY+1].couleur, "32");
    }
    if((plateau[p.posX-2][p.posY-1].enVie == 0) && (p.posX>1) && (p.posY>0)){
        plateau[p.posX-2][p.posY-1] = videP;
    }
    else if((plateau[p.posX-2][p.posY-1].enVie == 1) && (strcmp(plateau[p.posX-2][p.posY-1].couleur, p.couleur)!=0)){
        strcpy(plateau[p.posX-2][p.posY-1].couleur, "32");
    }
    return 0;
}

int depFou(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){
    int pX, pY;
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
        while ((plateau[pX][pY].enVie == 0) && (pX>=0) && (pY<7)) {
            plateau[pX][pY] = videP;
            pX--;
            pY++;
        }
    }
    return 0;
}

int depRoi(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP){
    int pX, pY;
    pX = p.posX+1;
    pY = p.posY+1;
    if((p.posX<7) && (plateau[pX][p.posY].enVie == 0)){
        plateau[pX][p.posY] = videP;
    }
    if((p.posX<7) && (p.posY<7) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[pX][pY] = videP;
    }
    if((p.posY<7) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[p.posX][pY] = videP;
    }
    pX = p.posX-1;
    pY = p.posY-1;
    if((p.posX>0) && (plateau[pX][p.posY].enVie == 0)) {
        plateau[pX][p.posY] = videP;
    }
    if((p.posX>0) && (p.posY>0) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[pX][pY] = videP;
    }
    if((p.posY>0) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[p.posX][pY] = videP;
    }
    pX = p.posX-1;
    pY = p.posY+1;
    if((p.posX>=0) && (p.posY<7) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[pX][pY] = videP;
    }
    pX = p.posX+1;
    pY = p.posY-1;
    if((p.posX<7) && (p.posY>0) && (plateau[p.posX][pY].enVie == 0)) {
        plateau[pX][pY] = videP;
    }
    return 0;
}
