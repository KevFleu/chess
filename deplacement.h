#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

extern void depPossible(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP);
extern int move(piece plateau[SIZE_X][SIZE_Y] ,piece p, int xDep, int yDep, char c[3], piece vide, piece videP);
extern int movePion(piece plateau[SIZE_X][SIZE_Y], piece p, int xDep, int yDep, piece vide, piece videP);
#endif /* DEPLACEMENT_H*/
