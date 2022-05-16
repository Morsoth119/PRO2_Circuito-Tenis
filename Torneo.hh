/** @file Torneo.hh
    @brief Especificación de la clase Torneo 
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;
#endif

#include "Cjn_Jugadores.hh"
#include "Categoria.hh"
#include "BinTree.hh"

class Torneo 
{
    struct Participante {
    string nombre;
    int pts;
    };
    
    string nombre;
    int categoria;
    vector<Participante> participantes;
    vector<Participante> antiguos_participantes;
    BinTree<int> emparejamientos;
    BinTree<int> resultados;
    list<string> list_resultados;

public:

//CONSTRUCTORES

    /**
        @brief Constructora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Torneo con nombre <b style="color: #ff8033">t</b> i Categoria <b style="color: #ff8033">c</b>
    */
    Torneo(string t, int c);

//MODIFICADORES

    /**
        @brief Lee y añade los participantes al Torneo.
        @pre <em>cierto</em>
        @post lee posiciones del ranking del conjunto de jugadores (Cjn_Jugadores) <b style="color: #ff8033">j</b>, añade los jugadores que ocupan tales posiciones a la lista de participantes del Torneo y les asigna 0 puntos a cada uno
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
        @post se leen los resultados, se crea el cuadro final con tales resultados, se asignan a cada uno de los participantes del Torneo los puntos correspondientes dependiendo del vector <b style="color: #ff8033">pts_nvl</b> y se suman y restan todas las estadisticas a los jugadores del conjunto de jugadores (Cjn_Jugadores) <b style="color: #ff8033">j</b> 
    */
    void procesar_torneo(Cjn_Jugadores& j, const vector<int>& pts_nvl);

    /**
        @brief Resta los puntos de los antiguos participantes del Torneo.
        @pre <em>certo</em>
        @post se restan los puntos que gano en la anterior edición del Torneo a cada Jugador que participo y que aun existe en el conjunto de jugadores (Cjn_Jugadores) <b style="color: #ff8033">j</b>
    */
    void restar_puntos(Cjn_Jugadores& j);

    /**
        @brief Borra un Jugador del vector de antiguos participantes del Torneo.
        @pre <em>cierto</em>
        @post recorre el vector de antiguos participantes y si encuentra un Jugador con nombre <b style="color: #ff8033">p</b>, lo elimina
    */
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

//DESTRUCTORA

    ~Torneo();

private:

    /**
        @brief Crea un arbol binario con los partidos.
        @pre ???
        @post ???
    */
    BinTree<int> crear_cuadro(const int& h, const bool& conflicto, const int& n_part, int pos, int nivel);
    
    /**
        @brief Escribe el cuadro por consola.
        @pre <b style="color: #ff8033">e</b> no vacio; el numero de nodos de <b style="color: #ff8033">e</b> es igual al numero de participantes del Torneo
        @post escribe el arbol <b style="color: #ff8033">e</b> por consola
    */
    void escribir_cuadro(const BinTree<int>& e);

    /**
        @brief Lee los resultados, suma las estadisticas correspondientes a los jugadores y crea un arbol binario con los partidos y sus ganadores.
        @pre <b style="color: #ff8033">c</b> no vacio; numero de participantes del Torneo == <b style="color: #ff8033">pts_nvl</b>.size() >= <b style="color: #ff8033">nvl</b>
        @post lee los resultados de cada partido, suma las estadisticas correspondientes a cada Jugador del conjunto de jugadores (Cjn_Jugadores) <b style="color: #ff8033">j</b> y devuelve un BinTree<int> con los ganadores de cada encuentro de <b style="color: #ff8033">c</b>
    */
    BinTree<int> crear_cuadro_final(Cjn_Jugadores& j, const BinTree<int>& c, const vector<int>& pts_nvl, int nvl);

    /**
        @brief Escribe el cuadro final por consola.
        @pre <b style="color: #ff8033">c</b> no vacio; <b style="color: #ff8033">it</b> apunta a un elemento
        @post escribe el arbol <b style="color: #ff8033">c</b> con los resultados correspondientes, apuntados por <b style="color: #ff8033">it</b>
    */
    void escribir_cuadro_final(const BinTree<int>& c, list<string>::iterator& it);

    /**
        @brief Lee y procesa los resultados de un partido del Torneo.
        @pre <b style="color: #ff8033">WSa</b> = <b style="color: #ff8033">LSa</b> = <b style="color: #ff8033">WGa</b> = <b style="color: #ff8033">LGa</b> = 0
        @post lee un string con los resultados, suma a cada parametro su valor correspondiente y devuelve <b>true</b> en caso que se juegue el partido o <b>false</b> en caso de que no
    */
    bool procesar_partido(int& WSa, int& LSa, int& WGa, int& LGa);

    /**
        @brief Añade los puntos ganados en el Torneo a cada Jugador.
        @pre <em>cierto</em>
        @post suma los puntos correspondientes a cada Jugador del conjunto de jugadores (Cjn_Jugadores) <b style="color: #ff8033">j</b> y tambien les incrementa el contador de torneos jugados
    */
    void anadir_puntos(Cjn_Jugadores& j);

    /**
        @brief Elimina los participantes antiguos participantes y los cambia por los participantes de esta edicion del Torneo.
        @pre <em>cierto</em>
        @post el vector de antiguos participantes pasa a ser el vector de participantes actual y se borran tanto los participantes de esta edicion como la lista cn los resultados de los partidos
    */
    void borrar_participantes();

};

#endif