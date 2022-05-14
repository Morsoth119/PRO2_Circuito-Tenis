# PRO2_Circuito-Tenis
TEXTOOOOO
### Instalación
Para instalar el programa solamente hace falta clonar el repositorio en tu ordenador:
```sh
clone
```
### Ejecución
El programa puede ejecutarse de dos formas: la manual o la automática.
##### Forma manual
Para ejecutar el programa manualmente simplemente hay q hacer uso de la Makefile ya creada:
```sh
make
```
Ahora ya tenemos todos los archivos compilados y listos para ser ejecutados.
Para ello podemos introducir las entradas manualmente: 
```sh
./program.exe
```
Y después escribiendo la entrada por consola. 
O podemos tener el texto de entrada guardada en un archivo y guardar la salida en otro:
```sh
./program.exe < tests/inp.txt > tests/out.txt
```
En este caso introducimos el texto de `tests/inp.txt` como entrada y guardamos la salida en `tests/out.txt`.
Ademas podemos 
##### Forma automática
Para hacernos la vida más fácil hay creado un archivo `run` el qual automatiza todo lo que hemos visto en el apartado manual. Para usarlo simplemente ejecutarmeos el archivo `run`:
```sh
./run
```
### Doxygen