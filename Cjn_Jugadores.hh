/** @file Cjn_Jugadores.hh
    @brief Especificación de la clase Cjn_Jugadores 
*/

#ifndef CJN_JUGADORES_HH
#define CJN_JUGADORES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;
#endif

#include "Jugador.hh"

class Cjn_Jugadores 
{
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
        @pre no existe un Jugador con el mismo nombre 'p'
        @post añade el Jugador 'p' al final del vector ranking y al mapa de jugadores
    */
    void anadir_jugador(string s, Jugador p);

    /**
        @brief Elimina un Jugador del ranking y del mapa de jugadores.
        @pre existe un Jugador con el nombre 'p'
        @post elimina el Jugador 'p' del vector ranking y del mapa de jugadores
    */
    void eliminar_jugador(string p);

    /**
        @brief Elimina los puntos de anteriores ediciones del Torneo.
        @pre ???
        @post elimina los puntos que ganaron de todos los jugadores que participaron en el Torneo 't'
    */
    void actualizar_puntos_torneo(string t);

//CONSULTORES

    /**
        @brief Comprueba si existe el Jugador.
        @pre <em>cierto</em>
        @post devuelve true si existe un Jugador con el nombre 's'
    */
    bool existe_jugador(string s) const;

    /**
        @brief Devuelve el Jugador que ocupa esa posicion en el ranking.
        @pre 1 <= 'n' <= ranking.size()
        @post devuelve el jugador en el puesto 'n' del ranking
    */
    map<string, Jugador>::iterator jugador_ranking(int n) const;

    /**
        @brief Devuelve el numero de jugadores que hay inscritos.
        @pre <em>cierto</em>
        @post devuelve el numero de jugadores actuales
    */
    int num_jugadores() const;

//IMPRIMIR

    /**
        @brief Escribe el ranking por consola.
        @pre <em>cierto</em>
        @post escribe el vector ranking (por order de puntuacion) en consola
    */
    void escribir_ranking() const;

    /**
        @brief Escribe el mapa de jugadores por orden alfabético en consola.
        @pre <em>cierto</em>
        @post escribe el mapa de jugadores por order alfabetico en consola
    */
    void escribir_jugadores() const;

    /**
        @brief Escribe un Jugador por consola.
        @pre existe el Jugador con nombre 's'
        @post escribe el Jugador con nombre 's' por consola
    */
    void escribir_jugador(string s) const;

private:
    vector< map<string, Jugador>::iterator > ranking;
        //vector< pair<string, int> > ranking;
        //list<Jugador> ranking;
        //vector< pair<string, int> > ranking; //nombre, puntos
    map<string, Jugador> jugadores; //nombre, Jugador
        
};

#endif