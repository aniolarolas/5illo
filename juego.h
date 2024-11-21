#ifndef JUEGO_H
#include JUEGO_H

#include "cartas.h"
#include "jugador.h"

//Definimos la estructura la cual utilizaremos mientras el juego este en proceso

typedef struct {
    t_carta baraja [48];    //La baraja de cartas
    t_jugador jugadores[2];     //Dos jugadores (Humano y maquina)
    char turno_actual;           //Turno actual ()
    t_carta mesa[12];
}