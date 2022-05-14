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
Para ello podemos ejecutar el programa: 
```sh
./program.exe
```
Y después escribir la entrada por consola. 
O podemos tener el texto de entrada guardado en un archivo y guardar la salida en otro:
```sh
./program.exe < tests/inp.txt > tests/out.txt
```
En este útimo caso introducimos el texto de `tests/inp.txt` como entrada y guardamos la salida en `tests/out.txt`.
Por útimo, opcionalmente podemos comparar la salida de nuestro programa con la salida esperada. Para ello primero habra qu instalar un programa que nos haga la tarea. En mi caso utilizo *meld*:
```sh
sudo apt isntall meld
```
Para hacer uso de *meld* escribimos:
```sh
meld tests/out.txt tests/sample_out.txt
```
En este caso nos compara el archivo `tests/out.txt`con `tests/sample_out.txt` donde el primero es la salida de nuestro programa y el segundo es la salida que esperamos que tenga.
##### Forma automática
Para hacernos la vida más fácil hay creado un archivo `run` el qual automatiza todo lo que hemos visto en el apartado manual. Para usarlo simplemente ejecutarmeos el archivo `run`:
```sh
./run
```
### Doxygen