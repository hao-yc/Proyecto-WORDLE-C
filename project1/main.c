#include "header.h"

int main(){

    int i, type;
    usr k = {0};

    //inicializa el numero aleatorio
    time_t t;
    srand((unsigned) time(&t));
    
    //Incializamos todas las letras
    char keys[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};

    for(i=0;i<26;i++){

	    k.keys.key[i] = keys[i];

	}

    //Imprime por pantalla la opcion de juego
	printf("\n\nSeleciona opcion para jugar\n0 Debug\n1 Catala\n2 Castella\n3 Angles\n4 Fidlandes\n5 Utiliza document propi\n\nSeleciona opcio: ");

    //Escanea el numero introducido por el usuario
	scanf("%d%*c", &type);

    switch (type)
    {
    case 0:
        //Caso default: Es lo mismo que la funcion "Final" pero sin leer fichero
        printf("\nIntrodueix la paraula guanyadora\n");
        scanf("%s", k.winner_word.word);
        maj(k.winner_word.word);
        mapa(k);
        k.actual_word = 0;

        do{
            
            scanf("%s",k.words[k.actual_word].word.word);
            printf("\n");
            maj(k.words[k.actual_word].word.word);
        
            k.win = set_color(&k.words[k.actual_word], k.winner_word);
            change_key_color(&k);
            k.actual_word++;
            mapa(k);
        }while(k.actual_word <6 && k.win< 5);

        if(k.win == 5){
            printf("\nFeliçitats has endevinat la paraula");
        } else{
            printf("\nQuna pena! La paraula guanyadora era %s", k.winner_word.word);
        }

        break;

    case 1: 
        final(&k, "palabras_cat.txt");
        break;
    case 2:
    
        final(&k, "palabras_es.txt");
        break;
    case 3:
        final(&k, "palabras_en.txt");
        break;
    case 4:
        final(&k, "palabras_fi.txt");
        break;
    case 5:
        final(&k, "palabras_mio.txt");
        break;

    default:
        break;
    }
}