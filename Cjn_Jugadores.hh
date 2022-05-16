/** @file Cjn_Jugadores.hh
    @brief Especificación de la clase Cjn_Jugadores 
*/

#ifndef CJN_JUGADORES_HH
#define CJN_JUGADORES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#endif

#include "Jugador.hh"

class Cjn_Jugadores 
{
    /** @brief Vector de iteradores que apuntan a cada Jugador del mapa de jugadores, ordenados por puntos */
    vector< map<string, Jugador>::iterator > ranking;
    /** @brief Mapa con el nombre de cada Jugador seguido del objecto Jugador */
    map<string, Jugador> jugadores;

public:

//CONSTRUCTORES

    /**
        @brief Constructora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Cjn_Jugadores (conjunto de jugadores) vacío
    */
    Cjn_Jugadores();

//MODIFICADORES

    /**
        @brief Añade un nuevo Jugador al ranking y al mapa de jugadores.
        @pre no existe un Jugador con el nombre <b style="color: #ff8033">p</b>
        @post añade el Jugador con nombre <b style="color: #ff8033">p</b> y posición en el ranking <b style="color: #ff8033">rk</b> al final del vector ranking y al mapa de jugadores
    */
    void anadir_jugador(const string& p, int rk);

    /**
        @brief Elimina un Jugador del ranking y del mapa de jugadores.
        @pre existe un Jugador con el nombre <b style="color: #ff8033">p</b>
        @post elimina el Jugador con nombre <b style="color: #ff8033">p</b> del vector ranking y del mapa de jugadores y reasigna la posición del ranking a todos los Jugadores
    */
    void eliminar_jugador(const string& p);

    /**
        @brief Modifica una estadística del Jugador seleccionado.
        @pre existe un Jugador con el nombre <b style="color: #ff8033">p</b>
        @post modifica la estadística <b style="color: #ff8033">stat</b> con el valor <b style="color: #ff8033">n</b> del Jugador con nombre <b style="color: #ff8033">p</b>
    */
    void modificar_jugador(const string& p, const string& stat, int n);

    /**
        @brief Reordena el ranking.
        @pre <em>cierto</em>
        @post reordena el vector ranking y asigna a cada Jugador la posición del ranking correspondiente
    */
    void actualizar_ranking();

//CONSULTORES

    /**
        @brief Comprueba si existe el Jugador.
        @pre <em>cierto</em>
        @post devuelve <b>true</b> si existe un Jugador con el nombre <b style="color: #ff8033">p</b>, devuelve <b>false</b> en caso contrario
    */
    bool existe_jugador(const string& p) const;

    /**
        @brief Devuelve el nombre del Jugador que ocupa esa posición en el ranking.
        @pre 1 <= <b style="color: #ff8033">n</b> <= ranking.size()
        @post devuelve el nombre del jugador en el puesto <b style="color: #ff8033">n</b> del ranking
    */
    string jugador_ranking(int n) const;

    /**
        @brief Devuelve el numero de jugadores que hay inscritos.
        @pre <em>cierto</em>
        @post devuelve ranking.size()
    */
    int num_jugadores() const;

//IMPRIMIR

    /**
        @brief Escribe el ranking por consola.
        @pre <em>cierto</em>
        @post escribe el vector ranking (por order de puntuación) en consola
    */
    void escribir_ranking() const;

    /**
        @brief Escribe el mapa de jugadores por orden alfabético en consola.
        @pre <em>cierto</em>
        @post escribe el mapa de jugadores por order alfabético en consola
    */
    void escribir_jugadores() const;

    /**
        @brief Escribe un Jugador por consola.
        @pre existe el Jugador con nombre <b style="color: #ff8033">p</b>
        @post escribe el Jugador con nombre <b style="color: #ff8033">p</b> por consola
    */
    void escribir_jugador(const string& p) const;

private:

    /**
        @brief Compara los puntos de dos Jugadores.
        @pre <b style="color: #ff8033">a</b> y <b style="color: #ff8033">b</b> apuntan a un elemento
        @post devuelve <b>true</b> si el Jugador al que apunta <b style="color: #ff8033">a</b> tiene mas puntos que el que apunta <b style="color: #ff8033">b</b>, devuelve <b>false</b> en caso contrario
    */
    static bool cmp(const map<string, Jugador>::iterator& a, const map<string, Jugador>::iterator& b);
        
};

#endif