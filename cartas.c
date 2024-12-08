#include <stdio.h>	
#include "azar.h"
#include "colores.h"
#include "cartas.h"

void imprimir_cartas(t_jugador jug1,t_jugador jug2,t_jugador jug3, t_jugador jug4, t_jugador jug1_auxiliar,t_jugador jug2_auxiliar,t_jugador jug3_auxiliar,t_jugador jug4_auxiliar,char jug,char carta_pregunta){
    int i;
    if(jug=='S'||jug=='s'){
		if(carta_pregunta=='S'||carta_pregunta=='s'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<11;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<jug1.cantidad_jugador;i++){
			if (jug1.mano[i].palo == 'O')
			        {
			            printf_color_num(3);//Groc
			            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);

			        }
			        if (jug1.mano[i].palo == 'C')
			        {
			            printf_color_num(1);//Vermell
			            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			        }
			        if (jug1.mano[i].palo == 'E')
			        {
			            printf_color_num(6);//Blau
			            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			        }
			        if (jug1.mano[i].palo == 'B')
			        {
			            printf_color_num(2);//Verd
			            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
			        }
		            printf_reset_color();
		        }
			printf("\n");
			printf("J#2: ");
			for(i=0;i<jug2.cantidad_jugador;i++){
				if (jug2.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);

				        }
				        if (jug2.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
				        if (jug2.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
				        if (jug2.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
				            printf_reset_color();
		        }
			printf("\n");
			printf("J#3: ");
			for(i=0;i<jug3.cantidad_jugador;i++){
				if (jug3.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);

				        }
				        if (jug3.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
				        if (jug3.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
				        if (jug3.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
				            printf_reset_color();
		        }
			printf("\n");
			printf("J#4: ");
			for(i=0;i<jug4.cantidad_jugador;i++){
				if (jug4.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);

				        }
				        if (jug4.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				        if (jug4.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				        if (jug4.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				            printf_reset_color();
				        }
			printf("\n\n");
		}
		else if(carta_pregunta=='N'||carta_pregunta=='n'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<11;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<jug1.cantidad_jugador;i++){
				if (jug1.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);

				        }
				        if (jug1.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
				        if (jug1.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
				        if (jug1.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
				            printf_reset_color();
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<jug2.cantidad_jugador;i++){
				printf("[%c%c%c]",jug2_auxiliar.mano[i].palo,jug2_auxiliar.mano[i].numero2,jug2_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<jug3.cantidad_jugador;i++){
				printf("[%c%c%c]",jug3_auxiliar.mano[i].palo,jug3_auxiliar.mano[i].numero2,jug3_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<jug4.cantidad_jugador;i++){
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
			for(i=10;i<11;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<jug1.cantidad_jugador;i++){
				if (jug1.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				
				        }
				        if (jug1.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
				        if (jug1.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
				        if (jug1.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug1.mano[i].palo,jug1.mano[i].numero2,jug1.mano[i].numero);
				        }
	          	 printf_reset_color();
	       		 }
			printf("\n");
			printf("J#2: ");
			for(i=0;i<jug2.cantidad_jugador;i++){
				if (jug2.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				
				        }
				        if (jug2.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
				        if (jug2.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
				        if (jug2.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug2.mano[i].palo,jug2.mano[i].numero2,jug2.mano[i].numero);
				        }
		        printf_reset_color();
		        }
			printf("\n");
			printf("J#3: ");
			for(i=0;i<jug3.cantidad_jugador;i++){
				if (jug3.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				
				        }
				        if (jug3.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
				        if (jug3.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
				        if (jug3.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug3.mano[i].palo,jug3.mano[i].numero2,jug3.mano[i].numero);
				        }
		        printf_reset_color();
		        }
			printf("\n");
			printf("J#4: ");
			for(i=0;i<jug4.cantidad_jugador;i++){
				if (jug4.mano[i].palo == 'O')
				        {
				            printf_color_num(3);//Groc
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				
				        }
				        if (jug4.mano[i].palo == 'C')
				        {
				            printf_color_num(1);//Vermell
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				        if (jug4.mano[i].palo == 'E')
				        {
				            printf_color_num(6);//Blau
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				        if (jug4.mano[i].palo == 'B')
				        {
				            printf_color_num(2);//Verd
				            printf("[%c%c%c]",jug4.mano[i].palo,jug4.mano[i].numero2,jug4.mano[i].numero);
				        }
				            printf_reset_color();
				        }
			printf("\n\n");
		}
		else if(carta_pregunta=='N'||carta_pregunta=='n'){
			printf("     ");
			for(i=1;i<10;i++){
				printf("[ %d ]",i);
			}
			for(i=10;i<11;i++){
				printf("[%d ]",i);
			}
			printf("\n");
			printf("J#1: ");
			for(i=0;i<jug1.cantidad_jugador;i++){
				printf("[%c%c%c]",jug1_auxiliar.mano[i].palo,jug1_auxiliar.mano[i].numero2,jug1_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#2: ");
			for(i=0;i<jug2.cantidad_jugador;i++){
				printf("[%c%c%c]",jug2_auxiliar.mano[i].palo,jug2_auxiliar.mano[i].numero2,jug2_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#3: ");
			for(i=0;i<jug3.cantidad_jugador;i++){
				printf("[%c%c%c]",jug3_auxiliar.mano[i].palo,jug3_auxiliar.mano[i].numero2,jug3_auxiliar.mano[i].numero);
			}
			printf("\n");
			printf("J#4: ");
			for(i=0;i<jug4.cantidad_jugador;i++){
				printf("[%c%c%c]",jug4_auxiliar.mano[i].palo,jug4_auxiliar.mano[i].numero2,jug4_auxiliar.mano[i].numero);
			}
			printf("\n\n");
}
	}
}

void repartir_cartas(t_jugador *jug1, t_jugador *jug2,t_jugador *jug3,t_jugador *jug4,t_baraja *baraja,t_partida *partida){
    int i,j,azar,pos_encontrado=0;
for(i = 0; i < 10; i++) {
	for (i = 0; i < 10; i++) {
   
    azar = numero_al_azar(baraja->cantidad_baraja);
    jug1->mano[i] = baraja->cartas[azar];
    for (j = azar; j < baraja->cantidad_baraja - 1; j++) {
        baraja->cartas[j] = baraja->cartas[j + 1];
    }baraja->cantidad_baraja--;

    azar = numero_al_azar(baraja->cantidad_baraja);
    jug2->mano[i] = baraja->cartas[azar];
    for (j = azar; j < baraja->cantidad_baraja - 1; j++) {
        baraja->cartas[j] = baraja->cartas[j + 1];
    }baraja->cantidad_baraja--;

   
    azar = numero_al_azar(baraja->cantidad_baraja);
    jug3->mano[i] = baraja->cartas[azar];
    for (j = azar; j < baraja->cantidad_baraja - 1; j++) {
        baraja->cartas[j] = baraja->cartas[j + 1];
    }baraja->cantidad_baraja--;

   
    azar = numero_al_azar(baraja->cantidad_baraja);
    jug4->mano[i] = baraja->cartas[azar];
    for (j = azar; j < baraja->cantidad_baraja - 1; j++) {
        baraja->cartas[j] = baraja->cartas[j + 1];
    }baraja->cantidad_baraja--;
}
}
//Buscamos (O 5) y lo colocamos, sabremos tambien quien empieza el turno
i=0;
while(i < 10 && pos_encontrado == 0) {
    if (jug1->mano[i].palo == 'O' && jug1->mano[i].numero == '5') {
        partida->turno_actual = 1;
        pos_encontrado = i;

        for (j = i; j < jug1->cantidad_jugador-1; j++) {
            jug1->mano[j] = jug1->mano[j + 1];
        }
        jug1->cantidad_jugador--;

    } else if (jug2->mano[i].palo == 'O' && jug2->mano[i].numero == '5') {
        partida->turno_actual = 2;
        pos_encontrado = i;
        
        for (j = i; j < jug2->cantidad_jugador-1; j++) {
            jug2->mano[j] = jug2->mano[j + 1];
        }
        jug2->cantidad_jugador--;

    } else if (jug3->mano[i].palo == 'O' && jug3->mano[i].numero == '5') {
        partida->turno_actual = 3;
        pos_encontrado = i;

        for (j = i; j < jug3->cantidad_jugador-1; j++) {
            jug3->mano[j] = jug3->mano[j + 1];
        }
        jug3->cantidad_jugador--;

    } else if (jug4->mano[i].palo == 'O' && jug4->mano[i].numero == '5') {
        partida->turno_actual = 4;
        pos_encontrado = i;

        for (j = i; j < jug4->cantidad_jugador-1; j++) {
            jug4->mano[j] = jug4->mano[j + 1];
        }
        jug4->cantidad_jugador--;
    }
    i++;
}}


