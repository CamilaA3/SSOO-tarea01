#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void tiempo(){
    char final[100];//Cadena de caracteres que nos indicara el tiempo al final de la funcion.
    time_t tiempo= time(0);//Se crea la variable y la definimos vacia para evitar problemas futuros.
    struct tm*tlocal = localtime(&tiempo);// Se usa la estructura de tiempo junto con la funcion localtime para que la variable tiempo almacene el tiempo actual.
    strftime(final,100,"%a %b %d %X %Z %Y ",tlocal);//Se utiliza esta funcion para que se almacenen los datos pedidos dentro de la cadena de caracteres.
    printf("%s\n", final);
}

void salida(int signum){
	int conta=0;
	conta++;
	if(conta==2){
		exit(signum);
	}
}

//Verifica el PID de la señal
void signal_handler (int signumero)
{
	if (signumero == getpid()){
		printf("Senal SIGUSR1 recibida: ");
		tiempo();
	}
}

void main(int argc, char* argv[]){
	int contad=0;
	printf("Proceso hora ejecutandose. PID=%d ",getpid());
	while(contad==0){
		sleep(3);
		printf("Listo para recibir la senal SIGUSR1.\n"
		signal(SIGUSR1, signal_handler);
		signal(SIGINT, salida);
		signal(SIGUSR2,SIG_IGN);
		signal(SIGTERM,SIG_IGN);
	}
}
