/** @file Categoria.hh
    @brief Especificación de la clase Categoria 
*/

#ifndef CATEGORIA_HH
#define CATEGORIA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif

class Categoria 
{
    string nombre;
    vector<int> pts_nivel;

public:

//CONSTRUCTORES

    /**
        @brief Creadora por defecto.
        @pre <em>cierto</em>
        @post el resultado es una Categoria con el nombre <b style="color: #ff8033">s</b>
    */
    Categoria(const string& s);

//MODIFICADORES

    /**
        @brief Añade los puntos de cada nivel de la Categoria.
        @pre <b style="color: #ff8033">v</b> no esta vacio
        @post sustituye el vector de pts_nivel por <b style="color: #ff8033">v</b>
    */
    void anadir_pts_nivel(const vector<int>& v);

//CONSULTORES

    /**
        @brief Devuelve el nombre de la Categoria.
        @pre <em>cierto</em>
        @post devuelve la variable nombre
    */
    string consultar_nombre() const;

    /**
        @brief Devuelve los puntos del nivel de la Categoria seleccionado.
        @pre 0 <= <b style="color: #ff8033">i</b> < pts_nivel.size()
        @post devuelve pts_nivel[<b style="color: #ff8033">i</b>]
    */
    int consultar_pts_nivel(int i) const;

    /**
        @brief Devuelve el numero de niveles que tiene la Categoria.
        @pre <em>cierto</em>
        @post devuelve el tamaño de pts_nivel
    */
    int num_niveles() const;

private:

};

#endif