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
        @brief Añade un Jugador nuevo al ranking.
        @pre no existe un Jugador con el mismo nombre que 'p' en el ranking
        @post añade el Jugador 'p' a la lista ranking y la reordena por puntos
    */
    void anadir_jugador(string s, Jugador p);

    /**
        @brief Elimina un Jugador del ranking.
        @pre existe un Jugador con el nombre 'p' en el ranking
        @post elimina el Jugador 'p' de la lista ranking
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
        @brief Comprueba si el Jugador esta en el ranking.
        @pre <em>cierto</em>
        @post devuelve 'true' si existe un Jugador con el nombre 's' en el ranking
    */
    bool existe_jugador(string s) const;

    /**
        @brief Devuelve el Jugador que ocupa esa posicion en el ranking.
        @pre existe un jugador en la posicion 'n' del ranking
        @post devuelve el jugador en el puesto de ranking 'n'
    */
    string jugador_ranking(int n) const;

    /**
        @brief Devuelve el numero de jugadores que hay en el ranking.
        @pre <em>cierto</em>
        @post devuelve el numero de jugadores actuales en el ranking
    */
    int num_jugadores() const;

//IMPRIMIR

    /**
        @brief Escribe el ranking por consola.
        @pre <em>cierto</em>
        @post escribe la lista ranking (por order de puntuacion) en consola
    */
    void escribir_ranking() const;

    /**
        @brief Escribe la lista de jugadores por orden alfabético por consola.
        @pre <em>cierto</em>
        @post escribe la lista de jugadores por order alfabetico en consola
    */
    void escribir_jugadores() const;

    void escribir_jugador(string s) const;

private:
    vector< pair<string, int> > ranking;
    //list<Jugador> ranking;
    //vector< pair<string, int> > ranking; //nombre, puntos
    map<string, Jugador> jugadores; //nombre, Jugador

    //static bool cmp1(string a, string b);

    //static bool cmp2(Jugador a, Jugador b);
        
};

#endif