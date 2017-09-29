echec : chess.o deplacement.o
		gcc chess.o deplacement.o -o echec

chess.o : chess.c deplacement.c
		gcc -c chess.c -o chess.o

deplacement.o : deplacement.c
		gcc -c deplacement.c -o deplacement.o
