#include "azar.h"
#include <stdio.h>
#include "colores.h"
#include "cartas.h"
#include "partida.h"
 
 

int main(){

	inicializar_azar();
	int i,j,azar,k,pos_encontrado=0,partida,turno;
	char jug,carta_pregunta,carta_eliminada;

	t_partida partida;
	t_jugador jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar;
   	t_mesa mesa,mesa_auxiliar;
	t_baraja baraja;

//Inicializaremos la partida(nos da jugadores auxiliares i dimensiones de jugadores)
inicializar_partida(&jug1, &jug2, &jug3, &jug4, &jug1_auxiliar, &jug2_auxiliar, &jug3_auxiliar, &jug4_auxiliar, &baraja);

//Iniciamos tablero(nos da la mesa que iremos modificando)
inicializar_tablero(&mesa);

//Repartiremos las cartas iniciales a cada jugador(nos da jugadores con sus cartas, quien tiene el oro 5 i quien es el siguiente jugador a tirar)
repartir_cartas(&jug1,&jug2,&jug3,&jug4,&baraja,&partida);

//Preguntas iniciales
printf("\n");
printf("¿Hay algun jugador humano? [s/n] ");
scanf("%c%*c",&jug);
printf("\n\n");
printf("¿Quieres ver todas las cartas? [s/n] ");
scanf("%c%*c",&carta_pregunta);
printf("\n");

//Muestro las cartas de cada jugador dependiendo de preguntas iniciales
imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);

//Imprimir tablero
imprimir_tablero(mesa);

paritda=SI;
while(partida==SI){
	if (turno==1){ //jug1
	
		//buscar posibles tirades (fer funcio de buscar tirada)
		k=0;
		tirada_posible=NO;
		for(i=0;i<4;i++){
			j=4
			if(mesa.tablero[i][j].numero=='-'){
				tirada_posible=SI;
				posicion_tirada=j;
			}
			if(tirada_pos==SI){
				tiradas_posibles[k]=mesa_auxiliar[i][j];
				k++;
				tirada_posible=NO;
			}
			else if(mesa.tablero[i][j].numero=!'-'){
				tirada_pos=NO;
				for(j=5;j<mesa.columnas;j++){
					if(tirada_pos==NO && mesa[i][j].numero=='-'){
						tirada_pososible=SI;
						posicion_tirada=j;
					}
				}
				if(tirada_posible==SI){
						tiradas_posibles[k]=mesa_auxiliar[i][j];
						k++;
						tirada_posible=NO;
				}
				for(j=5;j>mesa.columnas;j--){
					if(tirada_posible==NO && mesa[i][j].numero=='-'){
						tirada_posible=SI;
						posicion_tirada=j;
					}
				}
				if(tirada_posible==SI){
					tiradas_posibles[k]=mesa_auxiliar[i][j];
					k++;
					tirada_posible=NO;
				}
			}
		}
		//mirar si el jug te les cartes (fer funcio i donar jug1,jug2,jug3 o jug4 depenent de per qui busquis)
		k=0;
		for(j=0;j<tiradas_posibles.numero_cartas;i++){
			for(i=0;i<jug.numero_cartas;i++){
				if(jug.cartas[i]==tirada_posibles[j]){
					l=k+1;
					printf("%d.[%c%c%c]",l,jug.cartas[i].palo,jug.cartas[i].numero2,jug.cartas[i].numero);
					tiradas_escoger.cartas[k]=jug1.cartas[i];
					k++;
				}
			}
		}

		//case para cada opcion en caso de que sea persona y azar en caso se que sea maquina.
		turno=turno+1;	
	}
}

}
