#include <stdio.h>	
#include "azar.h"
#include "colores.h"
#include "partida.h"


void inicializar_tablero(t_mesa *mesa,t_jugador *jug1,t_jugador *jug2,t_jugador *jug3,t_jugador *jug4){
    int i,j;
    // Inicialización del tablero 10x4 directamente sobre el puntero recibido
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 4; j++) {
            mesa->tablero[i][j].palo = '-';
            mesa->tablero[i][j].numero2 = ' ';
            mesa->tablero[i][j].numero = '-';
        }
    }

    // Colocar la carta 'O 5' en la posición específica
    mesa->tablero[4][0].palo = 'O';
    mesa->tablero[4][0].numero2 = ' ';
    mesa->tablero[4][0].numero = '5';

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
            if (mesa->tablero[i][j].palo == 'O') {
                printf_color_num(3); // Groc
                printf("[%c%c%c]", mesa->tablero[i][j].palo, mesa->tablero[i][j].numero2, mesa->tablero[i][j].numero);
            } else if (mesa->tablero[i][j].palo == 'C') {
                printf_color_num(1); // Vermell
                printf("[%c%c%c]", mesa->tablero[i][j].palo, mesa->tablero[i][j].numero2, mesa->tablero[i][j].numero);
            } else if (mesa->tablero[i][j].palo == 'E') {
                printf_color_num(6); // Blau
                printf("[%c%c%c]", mesa->tablero[i][j].palo, mesa->tablero[i][j].numero2, mesa->tablero[i][j].numero);
            } else if (mesa->tablero[i][j].palo == 'B') {
                printf_color_num(2); // Verd
                printf("[%c%c%c]", mesa->tablero[i][j].palo, mesa->tablero[i][j].numero2, mesa->tablero[i][j].numero);
            } else {
                printf("[%c%c%c]", mesa->tablero[i][j].palo, mesa->tablero[i][j].numero2, mesa->tablero[i][j].numero);
            }
            printf_reset_color();
        }
    }}



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
    jug1_auxiliar->mano[i].palo = '-';
    jug1_auxiliar->mano[i].numero = '-';
    jug1_auxiliar->mano[i].numero2 = ' ';
}
jug2_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug2_auxiliar->mano[i].palo = '-';
    jug2_auxiliar->mano[i].numero = '-';
    jug2_auxiliar->mano[i].numero2 = ' ';
}
jug3_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug3_auxiliar->mano[i].palo = '-';
    jug3_auxiliar->mano[i].numero = '-';
    jug3_auxiliar->mano[i].numero2 = ' ';
}
jug1_auxiliar->cantidad_jugador = 10;
for (i = 0; i < 10; i++) {
    jug4_auxiliar->mano[i].palo = '-';
    jug4_auxiliar->mano[i].numero = '-';
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
