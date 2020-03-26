#include <stdio.h>
struct empleado{//Estructura que almacena los datos de cada empleado. Icluye nombre, apellidos, edad y un numero identificador de la empresa
char nombre[50];
char apellido1[50];	
char apellido2[50];
int edad;
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
		pf = fopen("pruebas.txt", "w");//se abra el archivo para escribir en �l
		fprintf(pf,"	LISTA DE EMPLEADOS:");
		printf("\nIntroduzca el nombre del primer empleado: 	");//se le piden los datos del empleado al usuario para almacenarlos en el archivo
		scanf("%s", nuevo.nombre);
		printf("\nIntroduzca su primer apellido:	");
		scanf("%s", nuevo.apellido1);
		printf("\nIntroduzca su segundo apellido:	");
		scanf("%s", nuevo.apellido2);
		printf("\nIntroduzca su edad:	");
		scanf("%d", &nuevo.edad);
		printf("\nIntroduzca su numero de identificacion:	");
		scanf("%s", &nuevo.identificador);	
		fprintf(pf,"%s , ", nuevo.nombre);//se almacenan todos los datos de ese empleado en una �nica l�nea
		fprintf(pf,"%s , ", nuevo.apellido1);
		fprintf(pf,"%s , ", nuevo.apellido2);
		fprintf(pf,"%d , ", nuevo.edad);
		fprintf(pf,"%s ;", nuevo.identificador);
	    fclose(pf); // Cerramos fichero
	}
	else//en caso de que el archivo ya exista
	{
		do//Se a�ade m�nimo un empleado
		{
			struct empleado nuevo;
			FILE *pf = fopen("pruebas.txt","a");//Se abre para a�adir los datos de nuevos empleados
			printf("\nIntroduzca el nombre del nuevo empleado:  	 ");//se le solicitan los datos del nuevo empleado al usuario
			scanf("%s", nuevo.nombre);
			printf("\nIntroduzca su primer apellido:	");
			scanf("%s", nuevo.apellido1);
			printf("\nIntroduzca su segundo apellido:  	 ");
			scanf("%s", nuevo.apellido2);
			printf("Introduzca su edad:	");
			scanf("%d", &nuevo.edad);
			printf("Introduzca su numero de identificacion:	");
			scanf("%s", &nuevo.identificador);	
			fprintf(pf,"%s , ", nuevo.nombre);//se almacenan todos los datos de ese empleado en una �nica l�nea
			fprintf(pf,"%s , ", nuevo.apellido1);
			fprintf(pf,"%s , ", nuevo.apellido2);
			fprintf(pf,"%d , ", nuevo.edad);
			fprintf(pf,"%s ;", nuevo.identificador);
			fclose(pf);// Cerramos fichero
			printf("\n Pulse 1 para a�adir un nuevo empleado o 0 para salir:\t");
			scanf("%i",&m);
		}
		while (m!=0);//Hasta que el usuario no elija la opcion de salir, sigue a�adiendo empleados.
	}
}
void list_emp()//funcion activada por el usuario cuando elige la opcion lista de empleados
{
FILE *pf = fopen("pruebas.txt","r");
int valores[1],  i;
char palabras[3], identificador[1];
printf("\nNombre           Apellidos\t\t\tEdad\t\tN de identificacion\n\n");
while(fscanf(pf, "%s, %s, %s, %i, %s;", &palabras[0+i], &palabras[1+i], &palabras[2+i], &valores[0+i], &identificador[0+i] )!=EOF ){
i=0;
printf("%s\t\t %s %s\t\t        \t%i  \t%s\n", &palabras[0+i], &palabras[1+i], &palabras[2+i], &valores[0+i],&valores[1+i] );
i=+5;
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
	printf("\n- Pulse 2 para agregar un empleado.");//Luego poner que haga falta un c�digo para las labores de gerente
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
		default://si la opcion elegida por el usuario no est� recogida entre las que se les ofrece, se le informa
			printf("El numero introducido no es correcto.\n");
	}
	}
	while(opcion!=6 && opcion!=5 && opcion!=4 && opcion!=3 && opcion != 2 && opcion != 1);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el men� principal
	return 0;
}

