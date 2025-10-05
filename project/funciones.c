#include "header.h"

//Poner una palabra en majusculas
void maj(char *w){

	int i=0;

	while(w[i] != 0){
		if(w[i]>= 'a' && w[i]<='z'){
			w[i] = w[i] - ('a'-'A');
		}
		i++;
	}
}
//Obtiene todas las palabras del fichero i las almacena, tambien elije la palbra ganadora
void get_words(usr *k, char *path){

    FILE *fp;

    int i, n;
	char c;
	word word = {0};

    fp = fopen(path, "r");
	//Obtiene todas las palabras

	while(fscanf(fp,"%c",&c)!=EOF){

		if(c<'A'||c>'Z');
		else{
			k->all_words[k->num_of_words].word[i]=c;
			i++;
			if(i==WORD){
				i=0;
				k->num_of_words++;
			}
		}
	}


   /* while (fscanf(fp,"%s", word.word)!= EOF){
		for(i=0;i<WORD;i++){
			k->all_words[k->num_of_words].word[i]=word.word[i];
		}
		k->num_of_words++;
		//k->all_words[k->num_of_words++] = word;
	}
*/
    fclose(fp);

	//Crea un numero aleatorio, este sera el numero de la palbra gandora
    n = rand() % (k->num_of_words+1);
    k->winner_word = k->all_words[n];
    
}

// Compara la palbra introducida por el usuario con la palabra ganadora, canvia el color de cada caracter. Devuelve un int que indica si es la palabra ganadora 
int set_color(word_struct *w, word k){

	int i, j, true, win=0;

	for(i=0; i<5; i++){

		if(w->word.word[i] != k.word[i]){

			for(j=0, true=0; j<5; j++){
				
				true = true+(w->word.word[i] == k.word[j]);

				if(w->color[j]==2&&w->word.word[j]==w->word.word[i]){
					true = 0;
					j=5;
				}
			}
			if(true){
				w->color[i] = 2;
			} else {
				w->color[i] = 1;
			}
		} else {
			w->color[i] = 3;
			win++;
		}
	}
	return win;
}
//Funcion para canviar el color de los caracteres del teclado
void change_key_color(usr *w){

    int i, j, k;

        for(i=0; i<6 && w->words[i].word.word[1]; i++){

                for(k=0; k<5; k++){

                        for(j= 0; j<26;j++){
                                if(w->keys.key[j] == w->words[i].word.word[k] && w->keys.color[j] < w->words[i].color[k]){
                                        w->keys.color[j] = w->words[i].color[k];
				                }
                        }
                }
        }
}
//Comprueba si existe la palabra en la lista de palabras
int exist(usr *w){

	int i=0,j=0, true=0, f=0;

	while(true<5 && i<w->num_of_words){

		if(w->words[w->actual_word].word.word[j] == w->all_words[i].word[j]){
			j++;
			true++;
		} else {
			true = 0;
			j = 0;
			i++;
		}
	}
	if( true == 5){
		return 1;
	} else {
		return 0;
	}
}
//Junta todo en una funcion
void final(usr *k, char *path){

    get_words(k, path);
    mapa(*k);
	k->actual_word = 0;
    do{
        
        scanf("%s",k->words[k->actual_word].word.word);
        maj(k->words[k->actual_word].word.word);
        if(exist(k)){
            k->win = set_color(&k->words[k->actual_word], k->winner_word);
            change_key_color(k);
            k->actual_word++;
            mapa(*k);
        } else {
            printf("Paraula no valida\n\nIntrodueix paraula: ");
        }
    }while(k->actual_word <6 && k->win< 5);

    if(k->win== 5){
        printf("\nFeliçitats has endevinat la paraula\n");
    } else{
        printf("\nQuna pena! La paraula guanyadora era %s\n\n", k->winner_word.word);
    }

}
