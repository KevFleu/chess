//On définie une structure pièce
typedef struct piece piece;
struct piece{
    int enVie; //booléen 1=vrai, 0=faux
    int posX; //position sur l'axe vertical
    int posY; //position sur l'axe horizontal
    char couleur[3]; // '34'=blanc(bleu), '31'=noir(rouge)
    char valeur; //'T'=tour, 'C'=cavalier, 'F'=fou, 'D'=dame, 'R'=roi, 'P'=pion
};

// On déclare un tableau à 2 dimension représentant l'échiquier
piece plateau[8][8];

//Déclaration des pièces blanches;
piece tourGB = {1, 0, 0, "34", 'T'};
piece cavalierGB = {1, 0, 1, "34", 'C'};
piece fouGB = {1, 0, 2, "34", 'F'};
piece dameB = {1, 0, 3, "34", 'D'};
piece roiB = {1, 0, 4, "34", 'R'};
piece fouDB = {1, 0, 5, "34", 'F'};
piece cavalierDB = {1, 0, 6, "34", 'C'};
piece tourDB = {1, 0, 7, "34", 'T'};
//Déclaration des pions blancs
piece pion0B = {1, 1, 0, "34", 'P'};
piece pion1B = {1, 1, 1, "34", 'P'};
piece pion2B = {1, 1, 2, "34", 'P'};
piece pion3B = {1, 1, 3, "34", 'P'};
piece pion4B = {1, 1, 4, "34", 'P'};
piece pion5B = {1, 1, 5, "34", 'P'};
piece pion6B = {1, 1, 6, "34", 'P'};
piece pion7B = {1, 1, 7, "34", 'P'};

//Déclaration des pièces noires;
piece tourGN = {1, 7, 0, "31", 'T'};
piece cavalierGN = {1, 7, 1, "31", 'C'};
piece fouGN = {1, 7, 2, "31", 'F'};
piece roiN = {1, 7, 3, "31", 'D'};
piece dameN = {1, 7, 4, "31", 'R'};
piece fouDN = {1, 7, 5, "31", 'F'};
piece cavalierDN = {1, 7, 6, "31", 'C'};
piece tourDN = {1, 7, 7, "31", 'T'};
//Déclaration des pions noirs
piece pion0N = {1, 6, 0, "31", 'P'};
piece pion1N = {1, 6, 1, "31", 'P'};
piece pion2N = {1, 6, 2, "31", 'P'};
piece pion3N = {1, 6, 3, "31", 'P'};
piece pion4N = {1, 6, 4, "31", 'P'};
piece pion5N = {1, 6, 5, "31", 'P'};
piece pion6N = {1, 6, 6, "31", 'P'};
piece pion7N = {1, 6, 7, "31", 'P'};

//Déclaration de pièce null
piece vide = {0, 0, 0, "30", ' '};
