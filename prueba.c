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
		//case para cada opcion en caso de que sea persona y azar en caso se que sea maquina.
		turno=turno+1;	
	}
}

}
void buscar_tirades_posibles(t_mesa mesa,t_mesa mesa_auxiliar,t_jugador tiradas_posibles){//buscar posibles tirades (fer funcio de buscar tirada)
		k=0;
		tirada_posible=NO;
		for(i=0;i<4;i++){
			j=4
			if(mesa.tablero[i][j].numero=='-'){
				tirada_posible=SI;
				posicion_tirada=j;
			}
			if(tirada_pos==SI){
				tiradas_posibles->mano[k]=mesa_auxiliar[i][j];
				tiradas_posibles->cantidad_jugador++;
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
						tiradas_posibles->mano[k]=mesa_auxiliar[i][j];
						tiradas_posibles->cantidad_jugador++;
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
					tiradas_posibles->mano[k]=mesa_auxiliar[i][j];
					tiradas_posibles->cantidad_jugador++;
					k++;
					tirada_posible=NO;
				}
			}
		}
}
void comparar_cartas_jugador(t_jugador jug,t_jugador tirades_posibles,t_jugador tiradas_escoger){//mirar si el jug te les cartes (fer funcio i donar jug1,jug2,jug3 o jug4 depenent de per qui busquis)
		k=0;
		for(j=0;j<tiradas_posibles.cantidad_jugador;i++){
			for(i=0;i<jug.cantidad_jugador;i++){
				if(jug.mano[i]==tirada_posibles.mano[j]){
					l=k+1;
					printf("%d.[%c%c%c]",l,jug.mano[i].palo,jug.mano[i].numero2,jug.mano[i].numero);
					tiradas_escoger->mano[k]=jug.mano[i];
					tiradas_escoger->cantidad_jugador++;
					k++;
				}
			}
		}
}
