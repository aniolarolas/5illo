#include <stdio.h>	
#include "azar.h"
#include "colores.h"
#include "partida.h"
#define NO 0
#define SI 1


void inicializar_tablero(t_mesa *mesa){
    int i,j;
    // Inicialización del tablero 10x4 directamente sobre el puntero recibido
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 4; j++) {
            mesa->tablero[i][j].palo = '-';
            mesa->tablero[i][j].numero2 = ' ';
            mesa->tablero[i][j].numero = '-';
        }
    }
	mesa->cantidad_filas=10;
	mesa->cantidad_columnas=4;
	
    // Colocar la carta 'O 5' en la posición específica
    mesa->tablero[4][0].palo = 'O';
    mesa->tablero[4][0].numero2 = ' ';
    mesa->tablero[4][0].numero = '5';
}
void imprimir_tablero(t_mesa mesa){
	int i,j;
    printf_color_num(3);
    printf("[ORO]");
    printf_color_num(1);
    printf("[COP]");
    printf_color_num(6);
    printf("[ESP]");
    printf_color_num(2);
    printf("[BAS]");
    printf_reset_color();

    for(i = 0; i < 10; i++) {
        printf("\n");
        for(j = 0; j < 4; j++) {
            if (mesa.tablero[i][j].palo == 'O') {
                printf_color_num(3); // Groc
                printf("[%c%c%c]", mesa.tablero[i][j].palo, mesa.tablero[i][j].numero2, mesa.tablero[i][j].numero);
            } else if (mesa.tablero[i][j].palo == 'C') {
                printf_color_num(1); // Vermell
                printf("[%c%c%c]", mesa.tablero[i][j].palo, mesa.tablero[i][j].numero2, mesa.tablero[i][j].numero);
            } else if (mesa.tablero[i][j].palo == 'E') {
                printf_color_num(6); // Blau
                printf("[%c%c%c]", mesa.tablero[i][j].palo, mesa.tablero[i][j].numero2, mesa.tablero[i][j].numero);
            } else if (mesa.tablero[i][j].palo == 'B') {
                printf_color_num(2); // Verd
                printf("[%c%c%c]", mesa.tablero[i][j].palo, mesa.tablero[i][j].numero2, mesa.tablero[i][j].numero);
            } else {
                printf("[%c%c%c]", mesa.tablero[i][j].palo, mesa.tablero[i][j].numero2, mesa.tablero[i][j].numero);
            }
            printf_reset_color();
        }
    }
}



void inicializar_partida(t_jugador *jug1,t_jugador *jug2,t_jugador *jug3,t_jugador *jug4,t_jugador *jug1_auxiliar,t_jugador *jug2_auxiliar,t_jugador *jug3_auxiliar,t_jugador *jug4_auxiliar,t_baraja *baraja){
    int i,j;
    
    typedef struct {
    char palo;           
    char numero2;
    char numero;        
} t_cartas_iniciales;

	jug1->cantidad_jugador=10;
	jug2->cantidad_jugador=10;
	jug3->cantidad_jugador=10;
	jug4->cantidad_jugador=10;

//Inicializamos la matriz de jug[i]_auxiliar a traves de fors
jug1_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug1_auxiliar->mano[i].palo = '?';
    jug1_auxiliar->mano[i].numero = '?';
    jug1_auxiliar->mano[i].numero2 = ' ';
}
jug2_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug2_auxiliar->mano[i].palo = '?';
    jug2_auxiliar->mano[i].numero = '?';
    jug2_auxiliar->mano[i].numero2 = ' ';
}
jug3_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug3_auxiliar->mano[i].palo = '?';
    jug3_auxiliar->mano[i].numero = '?';
    jug3_auxiliar->mano[i].numero2 = ' ';
}
jug1_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug4_auxiliar->mano[i].palo = '?';
    jug4_auxiliar->mano[i].numero = '?';
    jug4_auxiliar->mano[i].numero2 = ' ';
}
	
    //Inicialicamos las cartas iniciales
    t_cartas_iniciales cartas[40]={{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'},
    {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'},
    {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'},
    {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'},
    {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}};
    //Las pasamos a la variable baraja del main
    for(i=0;i<40;i++){
        baraja->cartas[i].palo=cartas[i].palo;
        baraja->cartas[i].numero2=cartas[i].numero2;
        baraja->cartas[i].numero=cartas[i].numero;
    }
    baraja->cantidad_baraja=40;    
}

void buscar_tirades_posibles(t_mesa mesa,t_mesa mesa_auxiliar,t_jugador *tiradas_posibles){//buscar posibles tirades (fer funcio de buscar tirada)
		int i,j,k=0,tirada_posible,posicion_tirada;
		
		tiradas_posibles->cantidad_jugador=0;		
		for(i=0;i<4;i++){
		//BUSCAR EN LA POSICION 4 DEL VECTOR
			j=4;
			if(mesa.tablero[j][i].palo=='-'){
				tiradas_posibles->mano[k]=mesa_auxiliar.tablero[j][i];
				tiradas_posibles->cantidad_jugador++;
				k++;
			}
		//SINO BUSCAR POR EL RESTO DEL VECTOR POR ARRIB A Y POR ABAJO
			else if(mesa.tablero[j][i].numero!='-'){
				tirada_posible=NO;
				for(j=5;j<mesa.cantidad_filas;j++){
					if(tirada_posible==NO && mesa.tablero[j][i].palo=='-'){
						tirada_posible=SI;
						tiradas_posibles->mano[k]=mesa_auxiliar.tablero[j][i];
						tiradas_posibles->cantidad_jugador++;
						k++;
					}
				}
				tirada_posible=NO;
				for(j=3;j>0;j--){
					if(tirada_posible==NO && mesa.tablero[j][i].palo=='-'){
						tirada_posible=SI;
						tiradas_posibles->mano[k]=mesa_auxiliar.tablero[j][i];
						tiradas_posibles->cantidad_jugador++;
						k++;
					}
				}
			}
		}
}

void comparar_cartas_jugador(t_jugador jug,t_jugador tiradas_posibles,t_jugador *tiradas_escoger){//mirar si el jug te les cartes (fer funcio i donar jug1,jug2,jug3 o jug4 depenent de per qui busquis)
		int j,i,k=0;
		tiradas_escoger->cantidad_jugador=0;
		for(j=0;j<tiradas_posibles.cantidad_jugador;j++){
			for(i=0;i<jug.cantidad_jugador;i++){
				if(jug.mano[i].palo==tiradas_posibles.mano[j].palo && jug.mano[i].numero2==tiradas_posibles.mano[j].numero2 && jug.mano[i].numero==tiradas_posibles.mano[j].numero){
					tiradas_escoger->mano[k]=jug.mano[i];
					tiradas_escoger->cantidad_jugador++;
					k++;
				}
				}
			}
		printf("\n");
		}
		
void triar_carta(t_jugador *jug, t_jugador *jug_aux, t_jugador tiradas_escoger, int opcio_escollida, t_mesa *mesa, t_mesa mesa_auxiliar){
	int i,j;
	for(i=0;i<jug->cantidad_jugador;i++){
		if(jug->mano[i].palo==tiradas_escoger.mano[opcio_escollida-1].palo && jug->mano[i].numero2==tiradas_escoger.mano[opcio_escollida-1].numero2 && jug->mano[i].numero==tiradas_escoger.mano[opcio_escollida-1].numero){
			for (j = i; j < jug->cantidad_jugador-1; j++) {
				jug->mano[j] = jug->mano[j + 1];
		}
			jug->cantidad_jugador--;
			jug_aux->cantidad_jugador--;
		}
	}
	for(j=0;j<mesa_auxiliar.cantidad_filas;j++){
		for(i=0;i<mesa_auxiliar.cantidad_columnas;i++){
			if(mesa_auxiliar.tablero[j][i].palo==tiradas_escoger.mano[opcio_escollida-1].palo && mesa_auxiliar.tablero[j][i].numero2==tiradas_escoger.mano[opcio_escollida-1].numero2 && mesa_auxiliar.tablero[j][i].numero==tiradas_escoger.mano[opcio_escollida-1].numero){
				mesa->tablero[j][i]=tiradas_escoger.mano[opcio_escollida-1];
			}
		}
	}
}

