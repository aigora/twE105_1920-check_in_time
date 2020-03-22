#include <stdio.h>
struct empleado{
char nombre[50];
char apellido1[50];	
char apellido2[50];
int edad;
int identificador;
};
void fichar()//funcion activada por el usuario cuando elige la opcion fichar.
{
	printf("\n Funcion fichar");
}
void agr_emp()//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
	FILE * pf = fopen("pruebas.txt", "r");
if (pf == NULL)
{
	struct empleado nuevo;
	pf = fopen("pruebas.txt", "w");
	fprintf(pf,"	LISTA DE EMPLEADOS:");
	printf("\nIntroduzca el nombre del primer empleado: 	");
	scanf("%s", nuevo.nombre);
	printf("\nIntroduzca su primer apellido:	");
	scanf("%s", nuevo.apellido1);
	printf("\nIntroduzca su segundo apellido:	");
	scanf("%s", nuevo.apellido2);
	printf("Introduzca su edad:	");
	scanf("%d", &nuevo.edad);
	printf("Introduzca su numero de identificacion:	");
	scanf("%d", &nuevo.identificador);	
	fprintf(pf,"\nNombre: %s", nuevo.nombre);
	fprintf(pf,"	Primer apellido: %s", nuevo.apellido1);
	fprintf(pf,"	Segundo apellido: %s", nuevo.apellido2);
	fprintf(pf,"	Edad: %d", nuevo.edad);
	fprintf(pf,"	Identificador: %d", nuevo.identificador);
    fclose(pf); // Cerramos fichero
}
else
{
	struct empleado nuevo;
	FILE *pf = fopen("pruebas.txt","a");
	printf("\nIntroduzca el nombre del nuevo empleado: 	");
	scanf("%s", nuevo.nombre);
	printf("\nIntroduzca su primer apellido:	");
	scanf("%s", nuevo.apellido1);
	printf("\nIntroduzca su segundo apellido:	");
	scanf("%s", nuevo.apellido2);
	printf("Introduzca su edad:	");
	scanf("%d", &nuevo.edad);
	printf("Introduzca su numero de identificacion:	");
	scanf("%d", &nuevo.identificador);	
	fprintf(pf,"\nNombre: %s", nuevo.nombre);
	fprintf(pf,"	Primer apellido: %s", nuevo.apellido1);
	fprintf(pf,"	Segundo apellido: %s", nuevo.apellido2);
	fprintf(pf,"	Edad: %d", nuevo.edad);
	fprintf(pf,"	Identificador: %d", nuevo.identificador);
	fclose(pf);
	
}
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
	printf("	MENU PRINCIPAL\n");//Se muestra el menu principal y las diferentes opciones .
	printf("\n- Pulse 1 para fichar.");
	printf("\n- Pulse 2 para agregar un empleado.");//Luego poner que haga falta un código para las labores de gerente
	printf("\n- Pulse 3 para consultar los datos de hoy.");
	printf("\n- Pulse 4 para consultar los datos de esta semana.\n\n");
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

