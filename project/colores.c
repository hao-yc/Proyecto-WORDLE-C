#include "header.h"



//Funcion switch para tener mejor organizacion de lo que se imprime por pantalla
void cambiar_color(int i, char a){

	switch(i){
		//DEFAULT
		case(0):
			PRINT(9);
			break;
		//AZUL
		case(3):
			PRINT(2);
			break;
		//NARANJA
		case(2):
			PRINT(3);
			break;
		//BLANCO
		case(1):
			PRINT(7);
			break;
	}
}
