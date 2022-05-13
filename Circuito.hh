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
        @post añade la Categoria <b style="color: #ff8033">c</b> al vector de categorias
    */
    void anadir_categoria(Categoria c);

    /**
        @brief Añade un Torneo nuevo al Circuito.
        @pre <em>cierto</em>
        @post añade el Torneo <b style="color: #ff8033">t</b> a la lista de torneos y reordena la lista por orden alfabetico
    */
    void anadir_torneo(Torneo t);

    /**
        @brief Añade los puntos por niveles a una Categoria.
        @pre 0 <= <b style="color: #ff8033">i</b> < vec_categorias.size(); <b style="color: #ff8033">v</b> no vacio
        @post los pts por nivel de la Categoria <b style="color: #ff8033">i</b> pasan a ser <b style="color: #ff8033">v</b>
    */
    void anadir_niveles(int i, const vector<int>& v);

    /**
        @brief Elimina un Torneo del Circuito.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b>
        @post elimina el Torneo con nombre <b style="color: #ff8033">t</b> de la lista de torneos y resta los puntos de la ultima edicion de tal Torneo a todos los jugadores que participaron
    */
    void eliminar_torneo(string t, Cjn_Jugadores& j);

    /**
        @brief Inicia un Torneo.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b>
        @post añade los participantes al torneo y crea los emparejamientos
    */
    void iniciar_torneo(string t, const Cjn_Jugadores& j);

    /**
        @brief Finaliza un Torneo.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b> y el Torneo <b style="color: #ff8033">t</b> ha sido iniciado previamente
        @post lee y procesa los resultados del Torneo <b style="color: #ff8033">t</b> y suma o resta los puntos correspondientes a cada Jugador
    */
    void finalizar_torneo(string t, Cjn_Jugadores& j);

    /**
        @brief Elimina un Jugador del registro de la ultima edicion de todos los torneos.
        @pre <em>cierto</em>
        @post elimina el Jugador con nombre <b style="color: #ff8033">p</b> de la lista de antiguos participantes de todos los torneos del Circuito
    */
    void eliminar_jugador_torneos(string p);

//CONSULTORES

    /**
        @brief Devuelve el Torneo seleccionado.
        @pre existe un torneo con el nombre <b style="color: #ff8033">s</b>
        @post devuelve el Torneo con el nombre <b style="color: #ff8033">s</b>
    */
    Torneo torneo(string s) const;

    /**
        @brief Devuelve el numero de categorias existente.
        @pre <em>cierto</em>
        @post devuelve el tamaño del vector de categorias
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
        @post devuelve <b>true</b> si existe un Torneo con el nombre <b style="color: #ff8033">s</b>, de lo contrario devuelve <b>false</b>
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
        @post devuelve <b>true</b> si el nombre de <b style="color: #ff8033">a</b> va antes que el de <b style="color: #ff8033">b</b>, de lo contrario devuelve <b>false</b>
    */
    static bool cmp(const Torneo& a, const Torneo& b);

};

#endif