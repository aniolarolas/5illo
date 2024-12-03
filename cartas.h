#ifndef CARTAS_H
#define	CARTAS_H

#include "estructuras.h"

//En esta libreria, se incluyen las funciones de imprimir las cartas y repartilas
 
void imprimir_cartas(t_jugador jug1,t_jugador jug2,t_jugador jug3, t_jugador jug4, t_jugador jug1_auxiliar,t_jugador jug2_auxiliar,t_jugador jug3_auxiliar,t_jugador jug4_auxiliar,char jug,char carta_pregunta);
void repartir_cartas(t_jugador *jug1, t_jugador *jug2,t_jugador *jug3,t_jugador *jug4,t_baraja *baraja,t_partida *partida);
#endif	/* CARTAS_H */

