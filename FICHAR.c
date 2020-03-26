#include <stdio.h>
#include <string.h>


struct empleado{//Estructura que almacena los datos de cada empleado. Icluye nombre, apellidos, edad y un numero identificador de la empresa
char nombre[50];
char apellido1[50];	
char apellido2[50];
char edad[2];
char identificador[3];
};
void fichar()//funcion activada por el usuario cuando elige la opcion fichar.
{
	printf("\n Funcion fichar");
}
void agr_emp()//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
	int m;
	FILE * pf = fopen("pruebas.txt", "r");//se intenta abrir el archivo que almacena los datos de los empleados
	if (pf == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
	{
		struct empleado nuevo;
		pf = fopen("pruebas.txt", "w");//se abra el archivo para escribir en él
		fprintf(pf,"	LISTA DE EMPLEADOS:");
		printf("\nIntroduzca el nombre del primer empleado: 	");//se le piden los datos del empleado al usuario para almacenarlos en el archivo
		scanf("%s", nuevo.nombre);
		printf("\nIntroduzca su primer apellido:	");
		scanf("%s", nuevo.apellido1);
		printf("\nIntroduzca su segundo apellido:	");
		scanf("%s", nuevo.apellido2);
		printf("\nIntroduzca su edad:	");
		scanf("%s", &nuevo.edad);
		printf("\nIntroduzca su numero de identificacion:	");
		scanf("%s", &nuevo.identificador);	
		fprintf(pf,"%s ", nuevo.nombre);//se almacenan todos los datos de ese empleado en una única línea
		fprintf(pf,"%s ", nuevo.apellido1);
		fprintf(pf,"%s ", nuevo.apellido2);
		fprintf(pf,"%s ", nuevo.edad);
		fprintf(pf,"%s \n", nuevo.identificador);
	    fclose(pf); // Cerramos fichero
	}
	else//en caso de que el archivo ya exista
	{
		do//Se añade mínimo un empleado
		{
			struct empleado nuevo;
			FILE *pf = fopen("pruebas.txt","a");//Se abre para añadir los datos de nuevos empleados
			printf("\nIntroduzca el nombre del nuevo empleado:  	 ");//se le solicitan los datos del nuevo empleado al usuario
			scanf("%s", nuevo.nombre);
			printf("\nIntroduzca su primer apellido:	");
			scanf("%s", nuevo.apellido1);
			printf("\nIntroduzca su segundo apellido:  	 ");
			scanf("%s", nuevo.apellido2);
			printf("Introduzca su edad:	");
			scanf("%s", &nuevo.edad);
			printf("Introduzca su numero de identificacion:	");
			scanf("%s", &nuevo.identificador);	
			fprintf(pf,"%s ", nuevo.nombre);//se almacenan todos los datos de ese empleado en una única línea
			fprintf(pf,"%s ", nuevo.apellido1);
			fprintf(pf,"%s ", nuevo.apellido2);
			fprintf(pf,"%s ", nuevo.edad);
			fprintf(pf,"%s \n", nuevo.identificador);
	    	fclose(pf); // Cerramos fichero
			printf("\n Pulse 1 para añadir un nuevo empleado o 0 para salir:\t");
			scanf("%i",&m);
		}
		while (m!=0);//Hasta que el usuario no elija la opcion de salir, sigue añadiendo empleados.
	}
}
void list_emp()//funcion activada por el usuario cuando elige la opcion lista de empleados
{
FILE *pf = fopen("pruebas.txt","r");
int  i=0, s=5, veces=0, v;
char nombre[30], apellido1[30], apellido2[30], Apellidos[60], Edad[2], Identificador[3];
printf("\nNombre\t\tApellidos\t\t\tEdad\tNº de identificacion\n\n");
while(fscanf(pf, "%20s %20s %20s %20s %20s", nombre,apellido1 ,apellido2 ,Edad ,Identificador )!= EOF ){
strcpy(Apellidos, apellido1); 
strcat(Apellidos, " "); 
strcat(Apellidos, apellido2); 


printf("%s\t\t\t%s\t\t\t\t\t%s\t%s\n", nombre, Apellidos, Edad, Identificador);

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
	printf("\n- Pulse 3 para ver la lista de empleados.");
	printf("\n- Pulse 4 para consultar los datos de hoy.");
	printf("\n- Pulse 5 para consultar los datos de esta semana.");
	printf("\n- Pulse 6 para salir.\n\n");
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
			list_emp ();
			break;
		case 4:
			con_hoy();
			break;
		case 5:
			con_sem();
			break;
		case 6:
			printf("\nSaliendo de la aplicacion");
			return 0;
		default://si la opcion elegida por el usuario no está recogida entre las que se les ofrece, se le informa
			printf("El numero introducido no es correcto.\n");
	}
	}
	while(opcion!=6 && opcion!=5 && opcion!=4 && opcion!=3 && opcion != 2 && opcion != 1);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el menú principal
	return 0;
}

