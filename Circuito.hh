/** @file Circuito.hh
    @brief Especificación de la clase Circuito 
*/

#ifndef CIRCUITO_HH
#define CIRCUITO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#endif

#include "Categoria.hh"
#include "Torneo.hh"

class Circuito 
{
    vector<Categoria> vec_categorias;
    list<Torneo> list_torneos;

public:

//CONSTRUCTORES

    /**
        @brief Creadora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Circuito sin categorias ni torneos
    */
    Circuito();

//MODIFICADORES

    /**
        @brief Añade una Categoria nueva al Circuito.
        @pre <em>cierto</em>
        @post añade la Categoria 'c' al vector de categorias
    */
    void anadir_categoria(Categoria c);

    /**
        @brief Añade un Torneo nuevo al Circuito.
        @pre <em>cierto</em>
        @post añade el Torneo 't' a la lista de torneos y reordena la lista por orden alfabetico
    */
    void anadir_torneo(Torneo t);

    /**
        @brief Añade los puntos por niveles a una Categoria.
        @pre 0 <= 'i' < vec_categorias.size(); 'v' no vacio
        @post los pts por nivel de la Categoria 'i' pasan a ser 'v'
    */
    void anadir_niveles(int i, const vector<int>& v);

    /**
        @brief Elimina un Torneo del Circuito.
        @pre existe el Torneo con nombre 't'
        @post elimina el Torneo con nombre 't' de la lista de torneos
    */
    void eliminar_torneo(string t, Cjn_Jugadores& j);

    /**
        @brief Inicia un Torneo.
        @pre existe el Torneo con nombre 't'
        @post añade los participantes al torneo y crea los emparejamientos
    */
    void iniciar_torneo(string t, const Cjn_Jugadores& j);

    /**
        @brief Finaliza un Torneo.
        @pre existe el Torneo con nombre 't' y el Torneo 't' ha sido iniciado previamente
        @post ???
    */
    void finalizar_torneo(string t, Cjn_Jugadores& j);

    /**
        @brief Finaliza un Torneo.
        @pre existe el Torneo con nombre 't' y el Torneo 't' ha sido iniciado previamente
        @post ???
    */
    void eliminar_jugador_torneos(string p);

//CONSULTORES

    /**
        @brief Devuelve el Torneo seleccionado.
        @pre existe un torneo con el nombre 's'
        @post devuelve el Torneo con el nombre 's'
    */
    Torneo torneo(string s) const;

    /**
        @brief Devuelve el numero de categorias existente.
        @pre <em>cierto</em>
        @post devuelve el tamaño del vector categorias
    */
    int num_categorias() const;

    /**
        @brief Devuelve el numero de torneos existentes actualmente.
        @pre <em>cierto</em>
        @post devuelve el tamaño de la lista de torneos
    */
    int num_torneos() const;
    
    /**
        @brief Comprueba si existe el Torneo seleccionado.
        @pre <em>cierto</em>
        @post devuelve true si existe un Torneo con el nombre 's', de lo contrario devuelve false
    */
    bool existe_torneo(string s) const;

//IMPRIMIR

    /**
        @brief Escribe el vector de categorias por consola.
        @pre <em>cierto</em>
        @post escribe el vector de categorias por order alfabetico en consola
    */
    void escribir_categorias() const;

    /**
        @brief Escribe la lista de torneos por consola.
        @pre <em>cierto</em>
        @post escribe la lista de torneos por order alfabetico en consola
    */
    void escribir_torneos() const;

private:

    /**
        @brief Compara dos torneos por orden alfabetico.
        @pre <em>cierto</em>
        @post devuelve true si el nombre de 'a' va antes que el de 'b', de lo contrario devuelve false
    */
    static bool cmp(const Torneo& a, const Torneo& b);

};

#endif