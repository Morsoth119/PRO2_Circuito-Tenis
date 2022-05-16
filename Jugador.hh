/** @file Jugador.hh
    @brief Especificación de la clase Jugador 
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @brief Clase Jugador */
class Jugador 
{
    /** @brief Nombre del Jugador */
    string nombre;
    /** @brief Puntos que tiene el Jugador */
    int puntos;
    /** @brief Ranking del Jugador */
    int Rk;
    /** @brief Torneos jugados del Jugador */
    int Ts;
    /** @brief Partidos ganados del Jugador */
    int WM;
    /** @brief Partidos perdidos del Jugador */
    int LM;
    /** @brief Sets ganados del Jugador */
    int WS;
    /** @brief Sets perdidos del Jugador */
    int LS;
    /** @brief Juegos ganados del Jugador */
    int WG;
    /** @brief Juegos perdidos del Jugador */
    int LG;

public:

//CONSTRUCTORES

    /**
        @brief Constructora por defecto.
        @pre <em>cierto</em>
        @post el resultado es un Jugador con nombre <b style="color: #ff8033">p</b>, Rk = <b style="color: #ff8033">rank</b> y 0 en todas sus estadísticas
    */
    Jugador(const string& p, int rank);

//MODIFICADORES

    /**
        @brief Modifica una estadística del Jugador.
        @pre <em>cierto</em>
        @post suma / modifica la variable con identificador el <b style="color: #ff8033">stat</b> la cantidad <b style="color: #ff8033">n</b>
    */
    void modificar_stats(const string& stat, int n);

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
    
    /**
        @brief Devuelve la posición del ranking que ocupa el Jugador.
        @pre <em>cierto</em>
        @post devuelve la variable Rk
    */
    int consultar_ranking() const;

//IMPRIMIR

    /**
        @brief Escribe las estadísticas del Jugador.
        @pre <em>cierto</em>
        @post escribe el nombre, el ranking, los puntos y las demás estadísticas por consola
    */
    void escribir_jug() const;

//DESTRUCTORES

    /**
        @brief Destructora por defecto.
        @pre <em>cierto</em>
        @post se destruye el parámetro implícito
    */
    ~Jugador();

private:

};

#endif