#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//Contador para la interrupcion "CTRL+C". Se crea fuera de la funcion salida() ya que si se crea dentro, se reinicia la cuenta y no avanza.
int conta=0;

//Calcula las veces que se ingresa la interrupcion "CTRL+C". Si llega a 2, el proceso termina.
void salida(int signum){
	conta++;
	if(conta==2){
		exit(signum);
	}
}
//Establece el tiempo segun los requirimientos para la tarea.
void tiempo(){
    char final[100];//Cadena de caracteres que nos indicara el tiempo al final de la funcion.
    time_t tiempo= time(0);//Se crea la variable y la definimos vacia para evitar problemas futuros.
    struct tm*tlocal = localtime(&tiempo);// Se usa la estructura de tiempo junto con la funcion localtime para que la variable tiempo almacene el tiempo actual.
    strftime(final,100,"%a %b %d %X %Z %Y ",tlocal);//Se utiliza esta funcion para que se almacenen los datos pedidos dentro de la cadena de caracteres.
    printf("%s\n", final);
}

//Verifica el PID de la señal
void signal_handler (int signumero){
	//Verifica si es una señal SIGUSR1
	if (signumero == SIGUSR1){
		printf("Senal SIGUSR1 recibida: ");
		tiempo();
	}
}

int main(int argc, char* argv[]){
	int contad=0;//Variable para el ciclo infinito.
	printf("Proceso hora ejecutandose. PID=%d \n",getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGINT, salida);
	//Ignora las señales SIGUSR2 y la SIGTERM
	signal(SIGUSR2,SIG_IGN);
	signal(SIGTERM,SIG_IGN);
	while(contad==0){
		sleep(2);//Duerme por dos segundos para que se pueda apreciar lo que hace el proceso.
		printf("Listo para recibir la senal SIGUSR1.\n");
	}
	return 0;
}
