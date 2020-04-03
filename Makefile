all:
		gcc -o fourier main.c funcoes.c -lm -I.
run:
		./fourier