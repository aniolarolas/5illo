#ifndef CARTAS_H
#define	CARTAS_H


typedef struct {
    char palo;           // Valor de la carta (1-12)
    char numero2;
    char numero;        // Palo de la carta (Oros, Copas, Espadas, Bastos)
} t_carta;


typedef struct {
    t_carta mano[10];         // Cartas en la mano del jugador
    int cantidad_jugador;     // Número de cartas en la mano del jugador
} t_jugador;

 
void imprimir_cartas(t_jugador jug1,t_jugador jug2,t_jugador jug3, t_jugador jug4, t_jugador jug1_auxiliar,t_jugador jug2_auxiliar,t_jugador jug3_auxiliar,t_jugador jug4_auxiliar,char jug,char carta_pregunta);

#endif	/* CARTAS_H */

