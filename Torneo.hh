/** @file Torneo.hh
    @brief Especificación de la clase Torneo 
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#endif

#include "Cjn_Jugadores.hh"
#include "Categoria.hh"
#include "BinTree.hh"

class Torneo 
{
public:

//CONSTRUCTORES

    /**
        @brief Constructora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Torneo con nombre 't' i Categoria 'c'
    */
    Torneo(string t, int c);

//MODIFICADORES

    /**
        @brief Añade un participante al Torneo.
        @pre no existe un participante con nombre 'p'
        @post añade 'p' a la lista de participantes del Torneo y le asigna 0 puntos
    */
    void anadir_participantes(const Cjn_Jugadores& j);

    /**
        @brief Crea el cuadro de emparejamientos.
        @pre ???
        @post crea el arbol de emparejamientos
    */
    void crear_emparejamientos();

    /**
        @brief Borra todos los participantes del Torneo.
        @pre <em>cierto</em>
        @post elimina a los participantes del Torneo actual y tambien el arbol de partidos
    */
    void borrar_participantes();

//CONSULTORES

    //int num_participantes() const;

    /**
        @brief Devuelve el nombre del Torneo.
        @pre <em>cierto</em>
        @post devuelve la variable nombre
    */
    string consultar_nombre() const;

    /**
        @brief Devuelve el indice de la Categoria del Torneo.
        @pre <em>cierto</em>
        @post devuelve la variable categoria
    */
    int consultar_categoria() const;

//DESTRUCTORES

    /**
        @brief Destructora por defecto.
        @pre <em>cierto</em>
        @post se destruye el parametro implícito
    */
    ~Torneo();

private:
    string nombre;
    int categoria;
    vector< pair<string, int> > participantes; //nombre del jugador y puntos que gana al final del torneo
    //vector< pair<string,int> > participantes;
    BinTree<int> emparejamientos;

};

#endif