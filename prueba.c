#include "azar.h"
#include <stdio.h>
#include "colores.h"
#include "cartas.h"

#define MAX 3


typedef struct {
    int turno_jug;            //Jug1,Jug2,Jug2,Jug4
    t_baraja baraja;         // La baraja que se está utilizando en la partida
    t_mesa mesa;             // La mesa, donde están las cartas jugadas
    t_jugador jugadores[4];  // Hasta 4 jugadores en la partida
    int turno_actual;         // Índice del jugador actual (0-3)
} t_partida;
 
 

int main(){

    inicializar_azar();
    int i,j,azar,k,pos_encontrado=0;
    char jug,carta_pregunta,carta_eliminada;
	

	t_partida partida;
    t_jugador jug1,jug2,jug3,jug4;
	jug1.cantidad_jugador=10;
	jug2.cantidad_jugador=10;
	jug3.cantidad_jugador=10;
	jug4.cantidad_jugador=10;
	
    t_jugador jug1_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},10},
		  jug2_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},10},
		  jug3_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},10},
		  jug4_auxiliar={{{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'},{'-',' ', '-'}},10};
   t_mesa mesa = {
    {
        // Inicialización del tablero 10x4
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'O', ' ', '5'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}},
        {{'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}, {'-', ' ', '-'}}
    },
    10, 
    4 };

    
    t_baraja baraja={{{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'},
    {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'},
    {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'},
    {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'},
    {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}},40};

    t_baraja baraja2={{{'O', ' ', '1'}, {'O', ' ', '2'}, {'O', ' ', '3'}, {'O', ' ', '4'}, {'O', ' ', '5'}, {'O', ' ', '6'}, {'O', ' ', '7'},
    {'O', '1', '0'}, {'O', '1', '1'}, {'O', '1', '2'}, {'C', ' ', '1'}, {'C', ' ', '2'}, {'C', ' ', '3'}, {'C', ' ', '4'}, {'C', ' ', '5'}, {'C', ' ', '6'}, {'C', ' ', '7'},
    {'C', '1', '0'}, {'C', '1', '1'}, {'C', '1', '2'}, {'E', ' ', '1'}, {'E', ' ', '2'}, {'E', ' ', '3'}, {'E', ' ', '4'}, {'E', ' ', '5'}, {'E', ' ', '6'}, {'E', ' ', '7'},
    {'E', '1', '0'}, {'E', '1', '1'}, {'E', '1', '2'}, {'B', ' ', '1'}, {'B', ' ', '2'}, {'B', ' ', '3'}, {'B', ' ', '4'}, {'B', ' ', '5'}, {'B', ' ', '6'}, {'B', ' ', '7'},
    {'B', '1', '0'}, {'B', '1', '1'}, {'B', '1', '2'}},40};


t_jugador jug1 jug2 jug3 jug4=repartir_cartas(t_jugador jug1, t_jugador jug2,t_jugador jug3,t_jugador jug4,t_baraja baraja)

i=0;
while(i<12 && pos_encontrado==0){
	if (jug1.mano[i].palo=='O' && jug1.mano[i].numero=='5'){
		partida.turno_actual=1;
		pos_encontrado=i;

		for(j=i;j<jug1.cantidad_jugador; j++){
        jug1.mano[j]=jug1.mano[j+1];}
		jug1.cantidad_jugador--;

	} else if (jug2.mano[i].palo=='O' && jug2.mano[i].numero=='5'){
		partida.turno_actual=2;
		pos_encontrado=i;
		for(j=i;j<jug2.cantidad_jugador; j++){
        jug2.mano[j]=jug2.mano[j+1];}
		jug2.cantidad_jugador--;
	} else if (jug3.mano[i].palo=='O' && jug3.mano[i].numero=='5'){
		partida.turno_actual=3;
		pos_encontrado=i;
		for(j=i;j<jug3.cantidad_jugador; j++){
        jug3.mano[j]=jug3.mano[j+1];}
		jug3.cantidad_jugador--;
	}else if(jug4.mano[i].palo=='O' && jug4.mano[i].numero=='5'){
		partida.turno_actual=4;
		pos_encontrado=i;
		for(j=i;j<jug4.cantidad_jugador; j++){
        jug4.mano[j]=jug4.mano[j+1];}
		jug4.cantidad_jugador--;
		}
	i++;
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
imprimir_cartas(jug1,jug2,jug3,jug4,jug1_auxiliar,jug2_auxiliar,jug3_auxiliar,jug4_auxiliar,jug,carta_pregunta);


//Mostrar tablero inicial
printf_color_num(3);
printf("[ORO]");
printf_color_num(1);
printf("[COP]");
printf_color_num(6);
printf("[ESP]");
printf_color_num(2);
printf("[BAS]");
printf_reset_color();
for(i=0;i<10;i++){
    printf("\n");
    for(j=0;j<4;j++){
		if (mesa.tablero[i][j].palo == 'O'){
			printf_color_num(3);//Groc
		    printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);}
	 	else if (mesa.tablero[i][j].palo == 'C'){
			printf_color_num(1);//Vermell
		    printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);}
	 	else if (mesa.tablero[i][j].palo == 'E'){
			printf_color_num(6);//Blau
			printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);}
		else if (mesa.tablero[i][j].palo == 'B'){
			printf_color_num(2);//Verd
			printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);}
			 
		else {
			printf("[%c%c%c]",mesa.tablero[i][j].palo,mesa.tablero[i][j].numero2,mesa.tablero[i][j].numero);
		}
		printf_reset_color();
		}
}

printf("\n");



//Extraer carta al azar de la baraja y verificar que se ha sacado correctamente
k=numero_al_azar(baraja2.cantidad_baraja);
for(i=k;i<baraja2.cantidad_baraja;i++){
    baraja2.cartas[i]=baraja2.cartas[i+1];
}
baraja2.cantidad_baraja--;
printf("\n");



}
