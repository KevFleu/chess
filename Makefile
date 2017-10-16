echec : chess.o deplacement.o fct.o
		gcc chess.o deplacement.o fct.o -o echec

chess.o : chess.c deplacement.c defPiece.h fct.h deplacement.h
		gcc -c chess.c -o chess.o

deplacement.o : deplacement.c defPiece.h fct.h deplacement.h
		gcc -c deplacement.c -o deplacement.o

fct.o : fct.c defPiece.h fct.h deplacement.h main.h
		gcc -c fct.c -o fct.o
