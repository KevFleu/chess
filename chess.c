#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defPiece.h"
#include "main.h"
#include "fct.h"
#include "deplacement.h"

#define clrscr() printf("\033[H\033[2J")
#define couleur(param1, param2) printf("\033[%s;%sm", param1, param2)

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
    int xInit = 0; //Coordonnée X de la pièce que l'user veut bouger
    int yInit = 0; //Coordonnée Y de la pièce que l'user veut bouger
    int xDepl = 0; //Coordonnée X de la case ou l'user veut aller
    int yDepl = 0; //Coordonnée Y de la case ou l'user veut aller
    char posInit[3] = "00"; //Coordonnées de la pièce saisie par l'user
    char posDepl[3] = "00"; //Coordonnées de la case saisie par l'user
    char whoPlay[3] = "34"; //Couleur du joueur qui doit jouer

    //Initialisation
    initialisation(plateau); //On rempli le plateau avant de commmencer la partie
    aff(plateau, whoPlay);

    while(1){
        //On demande les coordonnées de déplacement à l'utilisateur
        if(strncmp(whoPlay, "31", 3) == 0){
            printf("Joueur Noire: \n");
        }else{
            printf("Joueur Blanc: \n");
        }

        //On demande les coordonées de la pièce à déplacer
        printf("Coordonnées de la pièce à déplacer:\n");
        fgets(posInit, sizeof(posInit), stdin);
        printf("Position initiale: (%c;%c)\n", posInit[0], posInit[1]);
        viderBuffer();
        //On cast les coordonnées de string en int
        xInit = (int) posInit[0] - 48;
        yInit = (int) posInit[1] - 48;
        depPossible(plateau, plateau[yInit][xInit], vide, videP);

        //On demande les coordonnées où déplacer la pièce
        printf("Coordonnées de déplacement:\n");
        fgets(posDepl, sizeof(posDepl), stdin);
        printf("Positon visé: (%c;%c)\n", posDepl[0], posDepl[1]);
        viderBuffer();
        //On cast les coordonnées de string en int
        xDepl = (int) posDepl[0] - 48;
        yDepl = (int) posDepl[1] - 48;


        if ((xInit<8)&&(xInit>=0)&&(yInit<8)&&(yInit>=0)&&(xDepl<8)&&(xDepl>=0)&&(yDepl<8)&&(yDepl>=0))
            move(plateau, plateau[yInit][xInit], xDepl, yDepl, whoPlay);
        // move(plateau[4][0], "31");
    }

    couleur("37","40");
    return 0;
}

void initialisation(piece plateau[SIZE_X][SIZE_Y]){ //Modification de l'échiquier (déplacement de pièce)
    //On remplit le plateau de caractère vide (ou de zéro)
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++){
            plateau[i][j] = vide;
        }
    }

    //On positionne les pièces blanche
    plateau[tourGB.posX][tourGB.posY] = tourGB;
    plateau[cavalierGB.posX][cavalierGB.posY] = cavalierGB;
    plateau[fouGB.posX][fouGB.posY] = fouGB;
    plateau[dameB.posX][dameB.posY] = dameB;
    plateau[roiB.posX][roiB.posY] = roiB;
    plateau[fouDB.posX][fouDB.posY] = fouDB;
    plateau[cavalierDB.posX][cavalierDB.posY] = cavalierDB;
    plateau[tourDB.posX][tourDB.posY] = tourDB;
    //On positionne les pions blanches
    plateau[pion0B.posX][pion0B.posY] = pion0B;
    plateau[pion1B.posX][pion1B.posY] = pion1B;
    plateau[pion2B.posX][pion2B.posY] = pion2B;
    plateau[pion3B.posX][pion3B.posY] = pion3B;
    plateau[pion4B.posX][pion4B.posY] = pion4B;
    plateau[pion5B.posX][pion5B.posY] = pion5B;
    plateau[pion6B.posX][pion6B.posY] = pion6B;
    plateau[pion7B.posX][pion7B.posY] = pion7B;

    //On positionne les pièces noires
    plateau[tourGN.posX][tourGN.posY] = tourGN;
    plateau[cavalierGN.posX][cavalierGN.posY] = cavalierGN;
    plateau[fouGN.posX][fouGN.posY] = fouGN;
    plateau[dameN.posX][dameN.posY] = dameN;
    plateau[roiN.posX][roiN.posY] = roiN;
    plateau[fouDN.posX][fouDN.posY] = fouDN;
    plateau[cavalierDN.posX][cavalierDN.posY] = cavalierDN;
    plateau[tourDN.posX][tourDN.posY] = tourDN;
    //On positionne les pions noires
    plateau[pion0N.posX][pion0N.posY] = pion0N;
    plateau[pion1N.posX][pion1N.posY] = pion1N;
    plateau[pion2N.posX][pion2N.posY] = pion2N;
    plateau[pion3N.posX][pion3N.posY] = pion3N;
    plateau[pion4N.posX][pion4N.posY] = pion4N;
    plateau[pion5N.posX][pion5N.posY] = pion5N;
    plateau[pion6N.posX][pion6N.posY] = pion6N;
    plateau[pion7N.posX][pion7N.posY] = pion7N;
}

void aff(piece plateau[SIZE_X][SIZE_Y], char coul[3]){ //Affichage del'échiquier
    clrscr();
    char cas[] = "40"; //Couleur de fond des case (par défaut: noire)
    couleur("40", "37"); //On change les couleurs d'affichage

    if(strncmp(coul, "31", 3) == 0){
        printf("   0  1  2  3  4  5  6  7 \n");
        for (int i=0; i<8; i++) { //On parcourt le tableau
            couleur("40", "37"); //On change les couleurs d'affichage
            printf("%d ", i);
            for (int j=0; j<8; j++) {
                if(i%2 == 0){ //On blanchit les cases paires des lignes paires
                    if(j%2 == 0){
                        strcpy(cas, "47"); //cas = "47";
                    }else{
                        strcpy(cas, "40");
                    }
                }else{ //On blanchit les cases impaires des lignes impaires
                    if(j%2 != 0){
                        strcpy(cas, "47");
                    }else{
                        strcpy(cas, "40");
                    }
                }
                couleur(cas, plateau[i][j].couleur); //On change les couleurs d'affichage
                printf(" %c ", plateau[i][j].valeur); //On affiche
            }
            printf("\n"); //Passage à la ligne
        }
    }else{
        printf("   7  6  5  4  3  2  1  0 \n");
        for (int i=7; i>=0; i--) { //On parcourt le tableau
            couleur("40", "37"); //On change les couleurs d'affichage
            printf("%d ", i);
            for (int j=7; j>=0; j--) {
                if(i%2 == 0){ //On blanchit les cases paires des lignes paires
                    if(j%2 == 0){
                        strcpy(cas, "47"); //cas = "47";
                    }else{
                        strcpy(cas, "40");
                    }
                }else{ //On blanchit les cases impaires des lignes impaires
                    if(j%2 != 0){
                        strcpy(cas, "47");
                    }else{
                        strcpy(cas, "40");
                    }
                }
                couleur(cas, plateau[i][j].couleur); //On change les couleurs d'affichage
                printf(" %c ", plateau[i][j].valeur); //On affiche
            }
            printf("\n"); //Passage à la ligne
        }
    }


    printf("\n");

    couleur("37","40");
}
