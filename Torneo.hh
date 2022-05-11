/** @file Torneo.hh
    @brief Especificación de la clase Torneo 
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
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

    /**
        @brief Lee y procesa los resultados del Torneo.
        @pre existe un Torneo iniciado
        @post ???
    */
    void procesar_torneo(Cjn_Jugadores& j, const vector<int>& pts_nvl);

    bool procesar_partido(int& WSa, int& LSa, int& WGa, int& LGa);

    void anadir_puntos(Cjn_Jugadores& j);

    void restar_puntos(Cjn_Jugadores& j);

    void borrar_participantes();

    void borrar_jugador(string p);

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
    vector< pair<string, int> > participantes;
    vector< pair<string, int> > antiguos_participantes;
    BinTree<int> emparejamientos;
    BinTree<int> resultados;
    list<string> list_resultados;

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
    void escribir_cuadro(const BinTree<int>& e);

    BinTree<int> crear_cuadro_final(Cjn_Jugadores& j, const BinTree<int>& c, const vector<int>& pts_nvl, int nvl);

    void escribir_cuadro_final(const BinTree<int>& c, list<string>::iterator& it);

};

#endif