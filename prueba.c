#include "azar.h"
#include <stdio.h>
#include "colores.h"
#include "cartas.h"
#include "partida.h"
 
 

int main(){

	inicializar_azar();
    int i,j,azar,k,pos_encontrado=0;
    char jug,carta_pregunta,carta_eliminada;

	t_partida partida;
    t_jugador jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar;
   	t_mesa mesa;
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

//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);


//Imprimir tablero
imprimir_tablero(mesa);

printf("\n");


t_baraja baraja2={{{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'},
    {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'},
    {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'},
    {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'},
    {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}},40};


//Extraer carta al azar de la baraja y verificar que se ha sacado correctamente

k=numero_al_azar(baraja2.cantidad_baraja);
for(i=k;i<baraja2.cantidad_baraja;i++){
    baraja2.cartas[i]=baraja2.cartas[i+1];
}
baraja2.cantidad_baraja--;
printf("\n");

Paritda=SI;
while(Partida==SI){
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
