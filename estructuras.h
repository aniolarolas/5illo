#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

//En este archivo '.h' estan definidas todas las estructuras para no tener que ir escribiendolas cada vez

typedef struct {
    char palo;           // Valor de la carta (1-12)
    char numero2;
    char numero;        // Palo de la carta (Oros, Copas, Espadas, Bastos)
} t_carta;


typedef struct {
    t_carta mano[10];         // Cartas en la mano del jugador
    int cantidad_jugador;     // Número de cartas en la mano del jugador
} t_jugador;

typedef struct {
    t_carta cartas[40];     // Máximo de 40 cartas en la baraja española
    int cantidad_baraja;         // Número de cartas en la baraja
} t_baraja;

typedef struct {
    t_carta tablero[10][4];      // Representa las cartas jugadas en el tablero
    int cantidad_filas,cantidad_columnas;     // Número de cartas en el tablero
} t_mesa;

typedef struct {
    int turno_jug;            //Jug1,Jug2,Jug2,Jug4
    t_baraja baraja;         // La baraja que se está utilizando en la partida
    t_mesa mesa;             // La mesa, donde están las cartas jugadas
    t_jugador jugador[4];    // Hasta 4 jugadores en la partida
    int turno_actual;         // Índice del jugador actual (0-3)
} t_partida;




#endif
