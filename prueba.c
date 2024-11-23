#include "azar.h"
#include <stdio.h>

#define MAX 3


typedef struct {
	char palo;          // Valor de la carta (1-12)
	char numero2;	 //
	char numero;        // Palo de la carta (Oros, Copas, Espadas, Bastos)
} t_carta;


typedef struct {
	t_carta cartas[48];     // Máximo de 48 cartas en la baraja española
	int cantidad_baraja;         // Número de cartas en la baraja
} t_baraja;


typedef struct {
	t_carta mano[12];         // Cartas en la mano del jugador
	int cantidad_jugador;     // Número de cartas en la mano del jugador
} t_jugador;

typedef struct {
	t_carta tablero[12][4];      // Representa las cartas jugadas en el tablero
	int cantidad_filas,cantidad_columnas;     // Número de cartas en el tablero
} t_mesa;


typedef struct {
	int turno_jug;            //Jug1,Jug2,Jug2,Jug4
	t_baraja baraja;         // La baraja que se está utilizando en la partida
	t_mesa mesa;             // La mesa, donde están las cartas jugadas
	t_jugador jugadores[4];  // Hasta 4 jugadores en la partida
	int turnoActual;         // Índice del jugador actual (0-3)
} t_partida;

int main(){

//Definimos las funciones
	inicializar_azar();
	
//Definimos las diferentes variables
	int i,j,azar,k;
	char jug,carta_pregunta,carta_eliminada;
	t_jugador jug1,jug2,jug3,jug4;
	t_jugador jug1_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},12},
		  jug2_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},12},
		  jug3_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},12},
		  jug4_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},12};
	t_mesa mesa={{{{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}, {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}},12,4};
	t_baraja baraja={{{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'}, {'O', ' ', '8'}, {'O', ' ', '9'}, {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'}, {'C', ' ', '8'}, {'C', ' ', '9'}, {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'}, {'E', ' ', '8'}, {'E', ' ', '9'}, {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'}, {'B', ' ', '8'}, {'B', ' ', '9'}, {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}},48};
	t_baraja baraja2={{{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'}, {'O', ' ', '8'}, {'O', ' ', '9'}, {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'}, {'C', ' ', '8'}, {'C', ' ', '9'}, {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'}, {'E', ' ', '8'}, {'E', ' ', '9'}, {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'}, {'B', ' ', '8'}, {'B', ' ', '9'}, {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}},48};

//Repartimos cartas al azar a todos los jugadores
	for(i=0;i<12;i++){
		azar=numero_al_azar(baraja.cantidad_baraja);
		jug1.mano[i]=baraja.cartas[azar];
		for(j = azar; j <baraja.cantidad_baraja; j++){
			baraja.cartas[j]=baraja.cartas[j+1];
		}
		baraja.cantidad_baraja--;
		azar=numero_al_azar(baraja.cantidad_baraja);
		jug2.mano[i]=baraja.cartas[azar];
		for(j = azar; j <baraja.cantidad_baraja; j++){
			baraja.cartas[j]=baraja.cartas[j+1];
		}
		baraja.cantidad_baraja--;
		azar=numero_al_azar(baraja.cantidad_baraja);
		jug3.mano[i]=baraja.cartas[azar];
		for(j = azar; j <baraja.cantidad_baraja; j++){
			baraja.cartas[j]=baraja.cartas[j+1];
		}
		baraja.cantidad_baraja--;
		azar=numero_al_azar(baraja.cantidad_baraja);
		jug4.mano[i]=baraja.cartas[azar];
		for(j = azar; j <baraja.cantidad_baraja; j++){
			baraja.cartas[j]=baraja.cartas[j+1];
		}
		baraja.cantidad_baraja--;
	}

//Preguntas iniciales
	printf("\n");
	printf("¿Hay algun jugador humano? [s/n] ");
	scanf("%c%*c",&jug);
	printf("\n\n");
	printf("¿Quieres ver todas las cartas? [s/n] ");
	scanf("%c%*c",&carta_pregunta);
	printf("\n");
    
//Muestro las cartas de cada jugador dependiendo de si quiere no no quiere verlas
	if(jug=='S'||jug=='s'){
		if(carta_pregunta=='S'||carta_pregunta=='s'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<13;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
			}
			printf("\n\n");
		}
		else if(carta_pregunta=='N'||carta_pregunta=='n'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<13;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug2_auxiliar.mano[i].palo,jug2_auxiliar.mano[i].numero2,jug2_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug3_auxiliar.mano[i].palo,jug3_auxiliar.mano[i].numero2,jug3_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug4_auxiliar.mano[i].palo,jug4_auxiliar.mano[i].numero2,jug4_auxiliar.mano[i].numero);
			}
			printf("\n\n");
		}
	}
	else if(jug=='N'||jug=='n'){
		if(carta_pregunta=='S'||carta_pregunta=='s'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<13;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
			}
			printf("\n\n");
 		}
		else if(carta_pregunta=='N'||carta_pregunta=='n'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<13;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug1_auxiliar.mano[i].palo,jug1_auxiliar.mano[i].numero2,jug1_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug2_auxiliar.mano[i].palo,jug2_auxiliar.mano[i].numero2,jug2_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug3_auxiliar.mano[i].palo,jug3_auxiliar.mano[i].numero2,jug3_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<12;i++){
				printf("[%c%c%c]",jug4_auxiliar.mano[i].palo,jug4_auxiliar.mano[i].numero2,jug4_auxiliar.mano[i].numero);
			}
			printf("\n\n");
		}
	}

//Mostrar tablero inicial
	printf("[ORO][COP][ESP][BAS]");
	for(i=0;i<12;i++){
		printf("\n");
		for(j=0;j<4;j++){
			printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);
		}
	} 
	printf("\n");

//Extraer carta al azar de la baraja y verificar que se ha sacado correctamente
	k=numero_al_azar(baraja2.cantidad_baraja);
	printf("Se eliminara la carta: [%c%c%c]\n",baraja2.cartas[k].palo,baraja2.cartas[k].numero2,baraja2.cartas[k].numero);
	for(i=k;i<baraja2.cantidad_baraja;i++){
		baraja2.cartas[i]=baraja2.cartas[i+1];
	}
	baraja2.cantidad_baraja--;
	//Aqui verifico que la carta ha sido eliminada correctamente
	for(i=0;i<baraja2.cantidad_baraja;i++){
		printf("[%c%c%c]",baraja2.cartas[i].palo,baraja2.cartas[i].numero2,baraja2.cartas[i].numero);
	}
	printf("\n");
}
