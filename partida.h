#ifndef PARTIDA_H
#define PARTIDA_H

#include "estructuras.h"

void inicializar_partida(t_jugador *jug1,t_jugador *jug2,t_jugador *jug3,t_jugador *jug4,t_jugador *jug1_auxiliar,t_jugador *jug2_auxiliar,t_jugador *jug3_auxiliar,t_jugador *jug4_auxiliar,t_baraja *baraja);
void inicializar_tablero(t_mesa *mesa);
void imprimir_tablero(t_mesa mesa);
void buscar_tirades_posibles(t_mesa mesa,t_mesa mesa_auxiliar,t_jugador *tiradas_posibles);


#endif
