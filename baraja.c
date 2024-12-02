#include <stdio.h>	
#include "azar.h"
#include "colores.h"
#include "baraja.h"
#include "cartas.h"


t_jugador repartir_cartas(t_jugador jug1, t_jugador jug2,t_jugador jug3,t_jugador jug4,t_baraja baraja){
for(i=0;i<10;i++){
    azar=numero_al_azar(baraja.cantidad_baraja);
    jug1.mano[i]=baraja.cartas[azar];
    for(j = azar; j <baraja.cantidad_baraja; j++){
        baraja.cartas[j]=baraja.cartas[j+1];}
    baraja.cantidad_baraja--;

    azar=numero_al_azar(baraja.cantidad_baraja);
    jug2.mano[i]=baraja.cartas[azar];
    for(j = azar; j <baraja.cantidad_baraja; j++){
        baraja.cartas[j]=baraja.cartas[j+1];}
    baraja.cantidad_baraja--;

    azar=numero_al_azar(baraja.cantidad_baraja);
    jug3.mano[i]=baraja.cartas[azar];
    for(j = azar; j <baraja.cantidad_baraja; j++){
        baraja.cartas[j]=baraja.cartas[j+1];}
    baraja.cantidad_baraja--;

    azar=numero_al_azar(baraja.cantidad_baraja);
    jug4.mano[i]=baraja.cartas[azar];
        for(j = azar; j <baraja.cantidad_baraja; j++){
            baraja.cartas[j]=baraja.cartas[j+1];}
    baraja.cantidad_baraja--;}}


