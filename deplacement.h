extern void depPossible(piece plateau[SIZE_X][SIZE_Y], piece p, piece vide, piece videP);
extern int move(piece plateau[SIZE_X][SIZE_Y], piece p, int xDepl, int yDepl, char c[3], piece vide, piece videP);
extern int movePion(piece plateau[SIZE_X][SIZE_Y], piece p,  int xDepl, int yDepl, piece vide);
extern int moveTour(piece plateau[SIZE_X][SIZE_Y], piece p,  int xDepl, int yDepl, piece vide);
