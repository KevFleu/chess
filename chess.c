#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defPiece.h"
#include "fct.h"
#include "deplacement.h"

#define clrscr() printf("\033[H\033[2J")
#define couleur(param1, param2) printf("\033[%s;%sm", param1, param2)
#define couleur1(param) printf("\033[%sm", param)

void viderBuffer(){
   int c = 0;
   while (c != '\n' && c != EOF)
   {
       c = getchar();
   }
}

int main(int argc, char const *argv[]) {
    //Déclaration des variables
    piece plateau[SIZE_X][SIZE_Y];
    //Déclaration de pièce null
    piece vide = {0, 0, 0, "32", ' '};
    piece videP = {0, 0, 0, "32", 'X'};
    int xInit = 0; //Coordonnée X de la pièce que l'user veut bouger
    int yInit = 0; //Coordonnée Y de la pièce que l'user veut bouger
    int xDepl = 0; //Coordonnée X de la case ou l'user veut aller
    int yDepl = 0; //Coordonnée Y de la case ou l'user veut aller
    char posInit[3] = "00"; //Coordonnées de la pièce saisie par l'user
    char posDepl[3] = "00"; //Coordonnées de la case saisie par l'user
    char whoPlay[3] = "34"; //Couleur du joueur qui doit jouer

    //Initialisation
    initialisation(plateau, vide); //On rempli le plateau avant de commmencer la partie

    while(1){
        aff(plateau, whoPlay);
        //On demande les coordonnées de déplacement à l'utilisateur
        if(strncmp(whoPlay, "31", 3) == 0){
            printf("Joueur Noir: \n");
        }else{
            printf("Joueur Blanc: \n");
        }

        //On demande les coordonées de la pièce à déplacer
        printf("Coordonnées de la pièce à déplacer:\n");
        fgets(posInit, sizeof(posInit), stdin);
        printf("Position initiale: (%c;%c)\n", posInit[0], posInit[1]);
        //On cast les coordonnées de string en int
        xInit = (int) posInit[0] - 48;
        yInit = (int) posInit[1] - 48;
        viderBuffer();
        printf("Positon visé char: (%c;%c)\n", posInit[0], posInit[1]);
        printf("Positon visé int: (%d;%d)\n", xInit, yInit);
        depPossible(plateau, plateau[yInit][xInit], vide, videP);
        printf("1PieceI: %c\n", plateau[yInit][xInit].valeur);

        //On demande les coordonnées où déplacer la pièce
        printf("Coordonnées de déplacement:\n");
        fgets(posDepl, sizeof(posDepl), stdin);
        printf("Positon visé: (%c;%c)\n", posDepl[0], posDepl[1]);
        viderBuffer();
        //On cast les coordonnées de string en int
        xDepl = (int) posDepl[0] - 48;
        yDepl = (int) posDepl[1] - 48;
        printf("Piece: %c\n", plateau[yDepl][xDepl].valeur);
        printf("2PieceI: %c\n", plateau[yInit][xInit].valeur);

        // if (plateau[yDepl][xDepl].valeur == 'X'){
            printf("ok\n");
            move(plateau, plateau[yInit][xInit], xDepl, yDepl, whoPlay, vide, videP);
        // }
    }

    couleur("37","40");
    return 0;
}
