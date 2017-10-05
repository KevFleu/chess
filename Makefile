echec : chess.o deplacement.o fct.o
		gcc chess.o deplacement.o fct.o -o echec

chess.o : chess.c deplacement.c
		gcc -c chess.c -o chess.o

deplacement.o : deplacement.c
		gcc -c deplacement.c -o deplacement.o

fct.o : fct.c
		gcc -c fct.c -o fct.o
