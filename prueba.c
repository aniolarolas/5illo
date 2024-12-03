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
}
