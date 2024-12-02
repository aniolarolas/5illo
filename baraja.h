#ifndef BARAJA_H
#define	BARAJA_H



typedef struct {
    char palo;           // Valor de la carta (1-12)
    char numero2;
    char numero;        // Palo de la carta (Oros, Copas, Espadas, Bastos)
} t_carta;

typedef struct {
    t_carta cartas[40];     // Máximo de 40 cartas en la baraja española
    int cantidad_baraja;         // Número de cartas en la baraja
} t_baraja;

t_jugador repartir_cartas(t_jugador jug1, t_jugador jug2,t_jugador jug3,t_jugador jug4,t_baraja baraja);


#endif
