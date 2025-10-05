#define KEYS 26
#define WORD 5
#define MAX_WORDS 50000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcion para Imprimir por pantalla un caracter con un cierto color
#define PRINT(NAME)\
		printf("\e[4"#NAME"m");\
		printf("%c", a);\
		printf("\e[49m");


typedef struct{

	//Estructura de una palabra
    char word[WORD];
}word;

typedef struct{

	//Teclas
	char key[KEYS];

	//Color de las teclas
	int color[KEYS];
}key_board;

typedef struct{

	//Palabra
	word word;

	//Color de la palabra
	int color[WORD];

}word_struct;

typedef struct{

	//Ha ganado?
	int win;

	//Palabra actual
	int actual_word;

	//Cantidad de palabras totales del fichero
	int num_of_words;

	//Lista de todas las palabras
	word all_words[MAX_WORDS];

	//Palabra ganadora
	word winner_word;

	//Lista de palabras introducidas por el usuario
	word_struct words[6];

	//Estructura del teclado
	key_board keys;

}usr;

void maj(char *w);
void get_words(usr *k, char *path);
int set_color(word_struct *w, word k);
void change_key_color(usr *w);
int exist(usr *w);
void final(usr *k, char *path);
void cambiar_color(int i, char a);
void word_line(word_struct w);
void mapa(usr k);