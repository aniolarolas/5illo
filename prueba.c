#include "azar.h"
#include <stdio.h>
#include "colores.h"
#include "cartas.h"
#include "partida.h"
#define SI 1
#define NO 0
 

int main(){

	inicializar_azar();
    int i,j,azar,k,pos_encontrado=0;
    char jug,carta_pregunta,carta_eliminada;

	t_partida partida;
    t_jugador jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,tiradas_posibles,tiradas_escoger;
   	t_mesa mesa;
    t_baraja baraja;

//Inicializaremos la partida;
inicializar_partida(&jug1, &jug2, &jug3, &jug4, &jug1_auxiliar, &jug2_auxiliar, &jug3_auxiliar, &jug4_auxiliar, &baraja);

//Repartiremos las cartas iniciales a cada jugador
repartir_cartas(&jug1,&jug2,&jug3,&jug4,&baraja,&partida);

//Preguntas iniciales
printf("\n");
printf("¿Hay algun jugador humano? [s/n] ");
scanf("%c%*c",&jug);
printf("\n\n");
printf("¿Quieres ver todas las cartas? [s/n] ");
scanf("%c%*c",&carta_pregunta);
printf("\n");

//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);


//Iniciamos tablero
inicializar_tablero(&mesa,&jug1,&jug2,&jug3,&jug4);

printf("\n");

Paritda=SI;
while(Partida==SI){
	if (turno==1){ //jug1
		buscar_tirades_posibles(t_mesa mesa,t_mesa mesa_auxiliar,t_jugador tiradas_posibles);
		comparar_cartas_jugador(t_jugador jug1,t_jugador tirades_posibles,t_jugador tiradas_escoger);
		turno=turno+1;	
	}
}

}
}

