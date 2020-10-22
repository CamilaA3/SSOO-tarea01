//Importacion de librerias
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//Se inicializa el contador fuera de la funcion, ya que si lo inicializamos dentro, siemre sera 0 y no avanzara.
int conta=0;
//Se establece el tiempo segun los requerimientos pedidos.
void tiempo(){
    char final[100];//Cadena de caracteres que nos indicara el tiempo al final de la funcion.
    time_t tiempo= time(0);//Se crea la variable y la definimos vacia para evitar problemas futuros.
    struct tm*tlocal = localtime(&tiempo);// Se usa la estructura de tiempo junto con la funcion localtime para que la variable tiempo almacene el tiempo actual.
    strftime(final,100,"%a %b %d %X %Z %Y ",tlocal);//Se utiliza esta funcion para que se almacenen los datos pedidos dentro de la cadena de caracteres.
    printf("%s\n", final);
}

//Verifica el PID de la señal
void signal_handler (int signumero){
	//Se realiza la comparacion ara verificar que sea una señal SIGUSR1.
	if (signumero == SIGUSR1){
		printf("Senal SIGUSR1 recibida: ");
		tiempo();
	}
}
//Reestringe a 2 las veces que se presiona "CTRL+C" antes de que todo termine.
void salida(int signum){
	conta++;
	if(conta==2){
		exit(signum);
	}
}

int main(int argc, char* argv[]){
	int contad=0;//Contador usado para el ciclo infinito
	printf("Proceso hora ejecutandose. PID=%d \n",getpid());//Entrega el PID del proceso en ejecucion.
	signal(SIGUSR1, signal_handler);//Capta la señal SIGUSR1, la cual es tratada en la funcion signal_handler()
	signal(SIGINT, salida);//Capta la señal de interrumpcion "CTRL+C" que se controla en la funcion salida()
	//Ignora las señales SIGUSR2 y SIGTERM
	signal(SIGUSR2,SIG_IGN);
	signal(SIGTERM,SIG_IGN);
	//Ciclo infinito 
	while(contad==0){
		sleep(2);//Se realiza un sleep para que el usuario pueda leer y no se imprima todo rapidamente.
		printf("Listo para recibir la senal SIGUSR1.\n");
	}
	return 0;
}
