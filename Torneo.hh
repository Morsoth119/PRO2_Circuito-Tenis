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
        @pre <em>cierto</em>
        @post añade 'p' a la lista de participantes del Torneo y le asigna 0 puntos
    */
    void anadir_participantes(const Cjn_Jugadores& j);

    /**
        @brief Crea el cuadro de emparejamientos y lo imprime.
        @pre <em>cierto</em>
        @post crea el arbol de emparejamientos y lo imprime por consola
    */
    void crear_emparejamientos();

    /*
        @brief Borra todos los participantes del Torneo.
        @pre <em>cierto</em>
        @post elimina a los participantes del Torneo actual y tambien el arbol de partidos
    */
    //void borrar_participantes();

//CONSULTORES

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
    vector< pair<string, int> > participantes; //nombre del jugador y ¿puntos que gana al final del torneo?
    BinTree<int> emparejamientos;

    /**
        @brief Crea el arbol binario con los partidos.
        @pre <em>cierto</em>
        @post se destruye el parametro implícito
    */
    BinTree<int> crear_cuadro(const int& h, const bool& conflicto, const int& n_part, int pos, int nivel);
    
    /**
        @brief Escribe el cuadro por consola.
        @pre 'e' no vacio; el numero de nodos de 'e' es igual a p.size()
        @post escribe el arbol 'e' por consola
    */
    void escribir_cuadro(const BinTree<int>& e, const vector< pair<string, int> >& p);

};

#endif