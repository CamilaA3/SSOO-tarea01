Tarea 1 de la asignatura "Sistemas Operativos".

El archivo hora.c es el ejecutable para la tarea. En este se importan 4 librerias del lenguaje C:
- signal.h para poder trabajar con la funcion signal(). Permitiendo la recepcion y manipulacion de las señales.
- time.h nos ayuda a definir la fecha actual en la que se ejecuta el codigo.
- stdio.h para el desarrollo de las funciones.
- unistd.h usado para la funcion getpid()

Se escribieron 3 funciones y el main.
void tiempo() Hace uso de la estructure tiempo, entregada por la libreria time. Se crea un arreglo de largo 100 que almacenara la fecha actual. Definimos la hora actual. Junto con la structura de time, adquerimos el formato pedido y lo almacenamos en el arreglo previemnte descrito.

void salida(int signum) Funcion encargada en la señal de interrupcion (ctrl+C). Poseera un contador encargado de contador las veces que es usada dicha interrupcion, al llegar a 2, el proceso termina.

void signal_handler(int signumero) Funcion que recibe la interrupcion SIGUSR1. Se compara el PID ejecutandose con el escrito en la interrumpcion SIGUSR1, de ser iguales,se avisa que la señal fue recibida. De lo contrario el programa calla.

void main(int argc, char* argv[]) Se realizan las impresiones por pantalla pedidas. Para crear el bucle infinito, se define una variable numerica que nunca cambiara de valor. Se utilizan dos funciones signal para la interrupcion (ctrl+C) y la SIGUSR1. Segun la señal se trabajara en la funcion encargada.

Autora: Camila Mireya Araya Moreno.
Correo Institucional: camila.arayamo@alumnos.uv.cl
