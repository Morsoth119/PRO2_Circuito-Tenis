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

    void anadir_niveles(int i, vector<int>& v);

    /**
        @brief Elimina un Torneo del Circuito.
        @pre existe el Torneo con nombre 't'
        @post elimina el Torneo con nombre 't' del vector de torneos
    */
    void eliminar_torneo(string t);

    //void anadir_participante(string p);

    void iniciar_torneo(string t, const Cjn_Jugadores& j);

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
        @post devuelve 'true' si existe un Torneo con el nombre 's', de lo contrario devuelve 'false'
    */
    bool existe_torneo(string s) const;

//IMPRIMIR

    /**
        @brief Escribe el vector de categorias por consola.
        @pre <em>cierto</em>
        @post escribe el vector de categorias por order de nombre en consola
    */
    void escribir_categorias() const;

    /**
        @brief Escribe la lista de torneos por consola.
        @pre <em>cierto</em>
        @post escribe la lista de torneos por order de nombre en consola
    */
    void escribir_torneos() const;

private:
    vector<Categoria> vec_categorias;
    list<Torneo> list_torneos;

    static bool cmp(Torneo a, Torneo b);

};

#endif