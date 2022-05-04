/** @file Jugador.hh
    @brief Especificación de la clase Jugador 
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif

class Jugador 
{
public:

//CONSTRUCTORES

    /**
        @brief Constructora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Jugador con nombre 'p' i 0 puntos
    */
    Jugador(string p);

//MODIFICADORES

    /**
        @brief Se le suman (o restan) los puntos al Jugador.
        @pre puntos - 'pts' >= 0
        @post puntos += 'pts' ('pts' puede ser negativo)
    */
    void modificar_pts(int pts);

//CONSULTORES

    /**
        @brief Devuelve el nombre del Jugador.
        @pre <em>cierto</em>
        @post devuelve la variable nombre
    */
    string consultar_nombre() const;

    /**
        @brief Devuelve los puntos del Jugador.
        @pre <em>cierto</em>
        @post devuelve la variable puntos
    */
    int consultar_puntos() const; 
    
    //hacer un funcion para consultar stats con parametro

//IMPRIMIR

    /**
        @brief Escribe las estadisticas del Jugador.
        @pre <em>cierto</em>
        @post escribe el nombre, el ranking, los puntos y las demas estadisticas por consola
    */
    void escribir_jug(int pos) const;

//DESTRUCTORES

    /**
        @brief Destructora por defecto.
        @pre <em>cierto</em>
        @post se destruye el parametro implícito
    */
    ~Jugador();

private:
    string nombre;
    int puntos;
    int rank;
    //map<string, int> hist_torneos; //historial torneos en los que ha participado y los puntos obtenidos
    vector< pair<string,int> > hist_torneos; //historial torneos en los que ha participado y los puntos obtenidos

};

#endif