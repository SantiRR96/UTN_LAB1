#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

// Declaración de la función
void juego();

void creditos();

void estadisticas();

void ingresarNombres(std::string &nombre1, std::string &nombre2);

bool confirmarNombres(std::string player1, std::string player2);

void informar_carta(std::string &valor,  std::string &palo);

void barajar_cartas(std::string valores[], std::string palos[], int tamano);

int obtener_indice_carta(const std::string &valor);

bool cartas_en_orden(const std::string valores[]);

int contar_cartas(const std::string valores[], const std::string &carta);

int comparar_cartas(const std::string valores_jugador1[], const std::string valores_jugador2[], const std::string &carta);

int tirardados (int tam); 

void mostrar_ronda(int ronda);

void cambiar_ronda(int &ronda);

void accion_dado(int dado, int turnoJugador, std::string valores[], std::string palos[], std::string valores_jugador1[], std::string valores_jugador2[], std::string palos_jugador1[], std::string palos_jugador2[]);

/*void cambiar_jugador();*/
//int tirardados (int limite);
//void mazo(int cartas);
//void barajarMazo(int mazo[], int n)
//void repartirCartas(int mazo[], int jugador1[], int jugador2[])
//void mostrarCartas(int jugador[], int numJugador)

#endif

/*def FUNCIONES_H
#define FUNCIONES_H

#endif*/ /*a esto se le llama guards esta para que el archivo no sea incluido mas de una vez en un archivo cpp.
*/
