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
        @post el resultado es una Categoria con el nombre 's'
    */
    Categoria(string s);

//MODIFICADORES

    /**
        @brief Añade los puntos de cada nivel de la Categoria.
        @pre 'v' no esta vacio
        @post sustituye el vector de pts_nivel por 'v'
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
        @brief Devuelve los puntos del nivel 'i' de la Categoria.
        @pre 0 <= 'i' < pts_size
        @post devuelve pts_Nivel[i]
    */
    int consultar_pts_nivel(int i) const;

    /**
        @brief Devuelve los puntos obtenidos por cada nivel de la Categoria.
        @pre <em>cierto</em>
        @post devuelve pts_Nivel
    */
    vector<int> consultar_niveles() const;

    /**
        @brief Devuelve el numero de niveles que tiene la categoria.
        @pre <em>cierto</em>
        @post devuelve el tamaño de pts_nivel
    */
    int num_niveles() const;

private:

};

#endif