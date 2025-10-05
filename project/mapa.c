#include "header.h"

void word_line(word_struct w){

	int i;
	printf("		");
	for(i=0; i<5; i++){

		printf("|");
		cambiar_color(w.color[i], w.word.word[i]);
	}
	printf("|\n");
}


void mapa(usr k){

	int i, j;
	printf("\n");
	for(i=0; i<6; i++){
		printf("		+-+-+-+-+-+\n");
		if(k.words[i].word.word[0] != 0){
			word_line(k.words[i]);

		} else {
			printf("		| | | | | |\n");
		}
	}
	printf("		+-+-+-+-+-+\n");
	printf("\n\n	");

	for(i=0; i<26; i++){
		printf("[");
		cambiar_color(k.keys.color[i], k.keys.key[i]);
		printf("]");
		if(i == 9){
			printf("\n 	  ");
		}
		if(i == 18){
			printf("\n	     ");
		}
	}
	printf("\n\nIntrodueix paraula: ");
}