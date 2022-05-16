/** @file Circuito.hh
    @brief Especificación de la clase Circuito 
*/

#ifndef CIRCUITO_HH
#define CIRCUITO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#endif

#include "Categoria.hh"
#include "Torneo.hh"

class Circuito 
{
    /** @brief Vector donde se almacenan todas las categorías del Circuito por orden de creación */
    vector<Categoria> vec_categorias;
    /** @brief Mapa con el nombre de cada Torneo y el propio Torneo, ordenados automáticamente por orden alfabético */
    map<string, Torneo> torneos;

public:

//CONSTRUCTORES

    /**
        @brief Creadora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Circuito sin categorías ni torneos
    */
    Circuito();

//MODIFICADORES

    /**
        @brief Añade una Categoria nueva al Circuito.
        @pre <em>cierto</em>
        @post añade la Categoria <b style="color: #ff8033">c</b> al vector de categorías
    */
    void anadir_categoria(Categoria c);

    /**
        @brief Añade los puntos por niveles a una Categoria.
        @pre 1 <= <b style="color: #ff8033">i</b> <= vec_categorias.size(); <b style="color: #ff8033">v</b> no vacío
        @post los puntos por nivel de la Categoria <b style="color: #ff8033">i</b> pasan a ser <b style="color: #ff8033">v</b>
    */
    void anadir_niveles(int i, const vector<int>& v);

    /**
        @brief Añade un Torneo nuevo al Circuito.
        @pre <em>cierto</em>
        @post añade el Torneo con nombre <b style="color: #ff8033">t</b> y Categoria <b style="color: #ff8033">c</b> a la lista de torneos
    */
    void anadir_torneo(string t, int c);

    /**
        @brief Elimina un Torneo del Circuito.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b>
        @post elimina el Torneo con nombre <b style="color: #ff8033">t</b> de la lista de torneos y resta los puntos de la última edición de tal Torneo a todos los jugadores del Cjn_Jugadores (conjunto de jugadores) <b style="color: #ff8033">j</b> que participaron
    */
    void eliminar_torneo(const string& t, Cjn_Jugadores& j);

    /**
        @brief Inicia un Torneo.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b>
        @post lee y añade los participantes por posición en el Cjn_Jugadores (conjunto de jugadores) <b style="color: #ff8033">j</b> al Torneo con nombre <b style="color: #ff8033">t</b> y crea los emparejamientos
    */
    void iniciar_torneo(const string& t, const Cjn_Jugadores& j);

    /**
        @brief Finaliza un Torneo.
        @pre existe el Torneo con nombre <b style="color: #ff8033">t</b> y este ha sido iniciado préviamente
        @post lee y procesa los resultados del Torneo con nombre <b style="color: #ff8033">t</b> y suma o resta los puntos correspondientes a cada Jugador del Cjn_Jugadores (conjunto de jugadores) <b style="color: #ff8033">j</b>
    */
    void finalizar_torneo(const string& t, Cjn_Jugadores& j);

    /**
        @brief Elimina un Jugador del registro de la última edición de todos los torneos.
        @pre <em>cierto</em>
        @post pone a 0 los puntos ganados del Jugador con nombre <b style="color: #ff8033">p</b> de la lista de antiguos participantes de todos los torneos del Circuito
    */
    void eliminar_jugador_torneos(const string& p);

//CONSULTORES

    /**
        @brief Devuelve el Torneo seleccionado.
        @pre existe un torneo con el nombre <b style="color: #ff8033">t</b>
        @post devuelve el Torneo con el nombre <b style="color: #ff8033">t</b>
    */
    Torneo torneo(const string& t) const;

    /**
        @brief Devuelve el número de categorías existente.
        @pre <em>cierto</em>
        @post devuelve el tamaño del vector de categorías
    */
    int num_categorias() const;

    /**
        @brief Devuelve el número de torneos existentes actualmente.
        @pre <em>cierto</em>
        @post devuelve el tamaño del mapa de torneos
    */
    int num_torneos() const;
    
    /**
        @brief Comprueba si existe el Torneo seleccionado.
        @pre <em>cierto</em>
        @post devuelve <b>true</b> si existe un Torneo con el nombre <b style="color: #ff8033">t</b>, de lo contrario devuelve <b>false</b>
    */
    bool existe_torneo(const string& t) const;

//IMPRIMIR

    /**
        @brief Escribe el vector de categorías por consola.
        @pre <em>cierto</em>
        @post escribe el vector de categorías por order alfabético en consola
    */
    void escribir_categorias() const;

    /**
        @brief Escribe la lista de torneos por consola.
        @pre <em>cierto</em>
        @post escribe la lista de torneos por order alfabético en consola
    */
    void escribir_torneos() const;

private:

};

#endif