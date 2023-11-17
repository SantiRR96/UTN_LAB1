#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

// Declaración de la función
void ingresarNombres(std::string &nombre1, std::string &nombre2);
bool confirmarNombres(std::string player1, std::string player2);
void informar_carta(std::string &valor, std::string &palo);
void barajar_cartas(std::string valores[], std::string palos[], int tamano);
int obtener_indice_carta(const std::string &valor);
bool cartas_en_orden(const std::string valores[]);
int contar_cartas(const std::string valores[], const std::string &carta);
int comparar_cartas(const std::string valores_jugador1[], const std::string valores_jugador2[], const std::string &carta);
void dados_accion(int resultado_dado, std::string valores_propios[], std::string valores_contrario[], std::string mazo[]);
//int tirardados (int limite);

#endif

/*def FUNCIONES_H
#define FUNCIONES_H
