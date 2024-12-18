#include "azar.h"
#include <stdio.h>
#include "colores.h"
#include "cartas.h"
#include "partida.h"
#include "estructuras.h"
#include "duerme.h"
#define SI 1
#define NO 0
 

int main(){

	inicializar_azar();
	int i,j,azar,k,pos_encontrado=0,l,Partida=SI,opcio_escollida,ganador;
	long sec=3;
	char jug,carta_pregunta,carta_eliminada;
	t_partida partida;
	t_jugador jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,tiradas_posibles,tiradas_escoger;
   	t_mesa mesa,mesa_auxiliar= {{{{'O', ' ', '1'}, {'C', ' ', '1'}, {'E', ' ', '1'}, {'B', ' ', '1'}},{{'O', ' ', '2'}, {'C', ' ', '2'}, {'E', ' ', '2'}, {'B', ' ', '2'}},{{'O', ' ', '3'}, {'C', ' ', '3'}, {'E', ' ', '3'}, {'B', ' ', '3'}},{{'O', ' ', '4'}, {'C', ' ', '4'}, {'E', ' ', '4'}, {'B', ' ', '4'}},{{'O', ' ', '5'}, {'C', ' ', '5'}, {'E', ' ', '5'}, {'B', ' ', '5'}},{{'O', ' ', '6'}, {'C', ' ', '6'}, {'E', ' ', '6'}, {'B', ' ', '6'}},{{'O', ' ', '7'}, {'C', ' ', '7'}, {'E', ' ', '7'}, {'B', ' ', '7'}},{{'O', '1', '0'}, {'C', '1', '0'}, {'E', '1', '0'}, {'B', '1', '0'}},{{'O', '1', '1'}, {'C', '1', '1'}, {'E', '1', '1'}, {'B', '1', '1'}},{{'O', '1', '2'}, {'C', '1', '2'}, {'E', '1', '2'}, {'B', '1', '2'}}},10,4};
	t_baraja baraja;

//Inicializaremos la partida;
inicializar_partida(&jug1, &jug2, &jug3, &jug4, &jug1_auxiliar, &jug2_auxiliar, &jug3_auxiliar, &jug4_auxiliar, &baraja);

//Repartiremos las cartas iniciales a cada jugador
repartir_cartas(&jug1,&jug2,&jug3,&jug4,&baraja,&partida);

//Iniciamos tablero
inicializar_tablero(&mesa);

//Preguntas iniciales
printf("\n");
printf("¿Hay algun jugador humano? [s/n] ");
scanf("%c%*c",&jug);
printf("\n\n");
printf("¿Quieres ver todas las cartas? [s/n] ");
scanf("%c%*c",&carta_pregunta);
printf("\n");


while(Partida==SI){

//turno jug1
if (partida.turno_actual==1){ 

	//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
	imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);

	//Muestro el tablero/mesa
	imprimir_tablero(mesa);
	printf("\n");
	
	//busco les cartes que es poden dur a terme
	buscar_tirades_posibles(mesa,mesa_auxiliar,&tiradas_posibles);
	
	//busco quines pot tirar el jugador
	comparar_cartas_jugador(jug1, tiradas_posibles, &tiradas_escoger);
	
	//mostra quines tirades te i pregunta quina escolleix
	if(tiradas_escoger.cantidad_jugador != 0){
		printf("Turno de JUG#1:\nTirades posibles: ");
		j=1;
		for (i=0;i<tiradas_escoger.cantidad_jugador;i++){
			if(tiradas_escoger.numero=='O'){
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='C'){
			printf_color_num(1);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='E'){
			printf_color_num(4);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else{
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}}
		printf("\nQue tirada realizas? ");
		if(jug=='n' || jug=='N'){
			opcio_escollida = numero_al_azar(tiradas_escoger.cantidad_jugador);
			opcio_escollida++;
			printf("%d\n",opcio_escollida);
		}
		else{
			scanf("%d%*c",&opcio_escollida);
		}
		
		
		//tira la carta escollida
		triar_carta(&jug1,&jug1_auxiliar,tiradas_escoger,opcio_escollida,&mesa,mesa_auxiliar);
	}
	else{
		printf("Turno de JUG#1:\n");
		printf("Paso! Niguna tirada posible :/\n");
	}
	if(jug1.cantidad_jugador==0){
		Partida=NO;
		partida.turno_actual=5;
		ganador=1;

	}
	else{
	//canvi de torn
	partida.turno_actual=2;}

	printf("\n");
}

//turno jug2
if (partida.turno_actual==2){ 

	//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
	imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);

	//Muestro el tablero/mesa
	imprimir_tablero(mesa);
	printf("\n");
	
	//busco les cartes que es poden dur a terme
	buscar_tirades_posibles(mesa,mesa_auxiliar,&tiradas_posibles);
	
	//busco quines pot tirar el jugador
	comparar_cartas_jugador(jug2, tiradas_posibles, &tiradas_escoger);
	
	//escolleix una a l'atzar
	if(tiradas_escoger.cantidad_jugador != 0){
		printf("Turno de JUG#2:\nTirades posibles: ");
		j=1;
		for (i=0;i<tiradas_escoger.cantidad_jugador;i++){
			if(tiradas_escoger.numero=='O'){
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='C'){
			printf_color_num(1);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='E'){
			printf_color_num(4);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else{
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}
		}
		printf("\nQue tirada realizas? ");
		opcio_escollida = numero_al_azar(tiradas_escoger.cantidad_jugador);
		opcio_escollida++;
		printf("%d\n",opcio_escollida);

	//tira la carta escollida
	triar_carta(&jug2,&jug2_auxiliar,tiradas_escoger,opcio_escollida,&mesa,mesa_auxiliar);
	}else{
		printf("Turno de JUG#2:\n");
		printf("Paso! Niguna tirada posible :/\n");
	}
	if(jug2.cantidad_jugador==0){
		Partida=NO;
		partida.turno_actual=5;
		ganador=2;

	}
	else{
	//canvi de torn
	partida.turno_actual=3;}
	
	//espera 5sec para continuar
	duerme_n_segundos(sec);
	printf("\n");
}

//turno jug3
if (partida.turno_actual==3){ 
	
	//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
	imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);

	//Muestro el tablero/mesa
	imprimir_tablero(mesa);
	printf("\n");
	
	//busco les cartes que es poden dur a terme
	buscar_tirades_posibles(mesa,mesa_auxiliar,&tiradas_posibles);
	
	//busco quines pot tirar el jugador
	comparar_cartas_jugador(jug3, tiradas_posibles, &tiradas_escoger);
	
	//escolleix una a l'atzar
	if(tiradas_escoger.cantidad_jugador != 0){
		printf("Turno de JUG#3:\nTirades posibles: ");
		j=1;
		for (i=0;i<tiradas_escoger.cantidad_jugador;i++){
			if(tiradas_escoger.numero=='O'){
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='C'){
			printf_color_num(1);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='E'){
			printf_color_num(4);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else{
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}
		}
		printf("\nQue tirada realizas? ");
		opcio_escollida = numero_al_azar(tiradas_escoger.cantidad_jugador);
		opcio_escollida++;			
		printf("%d\n",opcio_escollida);

	//tira la carta escollida
	triar_carta(&jug3,&jug3_auxiliar,tiradas_escoger,opcio_escollida,&mesa,mesa_auxiliar);

	}else{
		printf("Turno de JUG#3:\n");
		printf("Paso! Niguna tirada posible :/\n");
	}
	if(jug3.cantidad_jugador==0){
		Partida=NO;
		partida.turno_actual=5;
		ganador=3;

	}
	else{
	//canvi de torn
	partida.turno_actual=4;}
	
	//espera 5sec para continuar
	duerme_n_segundos(sec);
	printf("\n");
}

//turno jug4
if (partida.turno_actual==4){ 
	
	//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
	imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);

	//Muestro el tablero/mesa
	imprimir_tablero(mesa);
	printf("\n");
	
	//busco les cartes que es poden dur a terme
	buscar_tirades_posibles(mesa,mesa_auxiliar,&tiradas_posibles);
	
	//busco quines pot tirar el jugador
	comparar_cartas_jugador(jug4, tiradas_posibles, &tiradas_escoger);
	
	//escolleix una a l'atzar
	if(tiradas_escoger.cantidad_jugador != 0){
		printf("Turno de JUG#4:\nTirades posibles: ");
		j=1;
		for (i=0;i<tiradas_escoger.cantidad_jugador;i++){
			if(tiradas_escoger.numero=='O'){
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='C'){
			printf_color_num(1);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else if(tiradas_escoger.numero=='E'){
			printf_color_num(4);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}else{
			printf_color_num(3);
			printf("%d:  [%c%c%c] ",j,tiradas_escoger.mano[i].palo, tiradas_escoger.mano[i].numero2,tiradas_escoger.mano[i].numero);
			j++;
		}
		}
		printf("\nQue tirada realizas? ");
		opcio_escollida = numero_al_azar(tiradas_escoger.cantidad_jugador);
		opcio_escollida++;
		printf("%d\n",opcio_escollida);

		//tira la cartas escollida
		triar_carta(&jug4,&jug4_auxiliar,tiradas_escoger,opcio_escollida,&mesa,mesa_auxiliar);

		}else{
		printf("Turno de JUG#4:\n");
		printf("Paso! Niguna tirada posible :/\n");}
	
	if(jug4.cantidad_jugador==0){
		Partida=NO;
		partida.turno_actual=5;
		ganador=4;

	}
	else{
	//canvi de torn
	partida.turno_actual=1;}
	
	
	//tira la carta escollida
	triar_carta(&jug4,&jug4_auxiliar,tiradas_escoger,opcio_escollida,&mesa,mesa_auxiliar);
	
	//canvi de torn
	partida.turno_actual=1;
	
	//espera 5sec para continuar
	duerme_n_segundos(sec);
	printf("\n");
}}

printf("Partida finalizada, HA GANADO EL JUGADOR #%d\n",ganador);
}

