# 馃幘 PRO2 - Circuito Tenis 馃幘

**Explicaci贸n del Proyecto**

* [Instalaci贸n](#instalacion)
* [Ejecuci贸n](#ejecucion)
* [Doxygen](#doxygen)
* [Crear practica.tar](#practica-tar)
* [Eliminar ejecutables](#clean)
* [Modificar proyecto](#modificar)
    * [Modificar Makefile](#modificar-makefile)
    * [Modificar entrada y salida](#modificar-io)
    * [Modificar Doxyfile](#modificar-doxyfile)
    * [Modificar Pr谩ctica](#modificar-prac)

![Tama帽o](https://img.shields.io/github/repo-size/Morsoth119/PRO2_Circuito-Tenis)

<a id="instalacion"></a>

## Instalaci贸n
1. Clonar el repositorio en tu ordenador:
```sh
git clone https://github.com/Morsoth119/PRO2_Circuito-Tenis.git
```

<a id="ejecucion"></a>

## Ejecuci贸n
1. Instalar **make**:
```sh
sudo apt install make
```
2. Instalar **meld**:
```sh
sudo apt install meld
```
3. Ejecutar el archivo [run](run):
```sh
./run
```

<a id="doxygen"></a>

## Doxygen
1. Instalar **doxygen**:
```sh
sudo apt install doxygen
```
2. Crear una carpeta con nombre `DOXYGEN`:
```sh
mkdir DOXYGEN
```
3. Ejecutar el archivo [dg](dg):
```sh
./dg
```

<a id="practica-tar"></a>

## Crear practica.tar
1. Tener instalado **make**.
2. Ejecutar la funci贸n:
```sh
make practica.tar
```

<a id="clean"></a>

## Eliminar ejecutables
1. Tener instalado **make**.
2. Ejecutar la funci贸n:
```sh
make clean
```

<a id="modificar"></a>

## Modificar proyecto

<a id="modificar-makefile"></a>

#### Modificar el archivo [Makefile](Makefile):

Este archivo nos automatiza tareas en las que se ven envueltos varios archivos.
* En caso de necesitar un nuevo archivo para compilar simplemente habr谩 que a帽adir estas lineas de c贸digo al archivo [Makefile](Makefile) ya existente:

![Compilacion](img/comp.png) 

* Adem谩s habr谩 que a帽adir los nuevos archivos al "practica.tar":

![Practica](img/practica.png)

* Tambi茅n podremos modificar nuestra funci贸n "clean" para que elimine otros archivos no deseados:

![Clean](img/clean.png)

<a id="modificar-io"></a>

#### Modificar los archivos [run](run), [inp.txt](tests/inp.txt) y [sample_out.txt](tests/sample_out.txt):

Estos archivos se encargan de automatizar la tarea de introducir la entrada y comparar la salida del programa.

* En el caso de necesitar modificar la entrada, simplemente deberemos modificar el archivo [inp.txt](tests/inp.txt).

* En el caso de necesitar comparar nuestra salida con otro archivo, tendremos que sustituir el contenido del archivo [sample_out.txt](tests/sample_out.txt) con el deseado.

* En el caso del archivo [run](run), no recomiendo modificarlo.

![Run](img/run_.png)

<a id="modificar-doxyfile"></a>

#### Modificar el archivo [dg](dg) y el [Doxyfile](Doxtfile):

Doxygen es una herramienta web para visualizar de forma clara la estructura de un programa modular.

* En el caso de querer modificar el archivo [Doxyfile](Doxtfile), dentro de este se encuentra una breve explicaci贸n de lo que hace cada opci贸n, por lo que s贸lo has de ir leyendo y modificando a tu gusto.
* Tambi茅n existe la opci贸n de crear un archivo Doxyfile totalmente nuevo. Para ello primero deberemos eliminar el ya existente:
```sh
sudo rm Doxyfile
```
* Y a continuaci贸n escribir:
```sh
doxygen -g
```

* En el caso del archivo [dg](dg), s贸lo recomiendo modificar el navegador con el que se abre la documentaci贸n creada. En mi caso utilizo Firefox.

![Doxygen](img/dg.png)

<a id="modificar-prac"></a>

#### Modificar los archivos de la pr谩ctica:

Estos s贸n todos lo archivos que yo he usado para la pr谩ctica (todos escritos por mi excepto [BinTree.hh](BinTree.hh)).

* [program.cc](program.cc)
* [Circuito.hh](Circuito.hh)
* [Circuito.cc](Circuito.cc)
* [Torneo.hh](Torneo.hh)
* [Torneo.cc](Torneo.cc)
* [Categoria.hh](Categoria.hh)
* [Categoria.cc](Categoria.cc)
* [Cjn_Jugadores.hh](Cjn_Jugadores.hh)
* [Cjn_Jugadores.cc](Cjn_Jugadores.cc)
* [Jugador.hh](Jugador.hh)
* [Jugador.cc](Jugador.cc)
* [BinTree.hh](BinTree.hh) _(recomiendo no modificarlo)_
