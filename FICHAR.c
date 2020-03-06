#include <stdio.h>
void fichar()//funcion activada por el usuario cuando elige la opcion fichar.
{
	printf("\n Funcion fichar");
}
void agr_emp()//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
	printf("\n Funcion agregar empleado");
}
void con_hoy()//funcion activada por el usuario cuando elige la opcion consultar los datos de hoy.
{
	printf("\n Funcion consultar hoy");
}
void con_sem()//funcion activada por el usuario cuando elige la opcion consultar los datos de la semana.
{
	printf("\n Funcion consultar semana");
}
int main()
{
	int opcion;//variable que almacena la opcion elegida por el usuario 
	do//Se ejecuta el menu principal una vez y mientras la opcion que el usuario elija no sea correcta
	{
	printf("	MENU PRINCIPAL");//Se muestra el menu principal y las diferentes opciones .
	printf("\nPulse 1 para fichar.");
	printf("\nPulse 2 para agregar un empleado.");//Luego poner que haga falta un código para las labores de gerente
	printf("\nPulse 3 para consultar los datos de hoy.");
	printf("\nPulse 4 para consultar los datos de esta semana.\n");
	scanf("%d", &opcion);// se guarda la opcion elegida por el usuario en una variable
	switch (opcion)//en funcion de la opcion elegida se realizan las distintas opciones
	{
		case 1:
			fichar();
			break;
		case 2:
			agr_emp ();
			break;
		case 3:
			con_hoy();
			break;
		case 4:
			con_sem();
			break;
		default://si la opcion elegida por el usuario no está recogida entre las que se les ofrece, se le informa
			printf("El numero introducido no es correcto.\n");
	}
	}
	while(opcion!=4 && opcion!=3 && opcion != 2 && opcion != 1);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el menú principal
	return 0;
}

