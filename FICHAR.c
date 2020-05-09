#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{//Estructura que almacena los datos de cada empleado. Icluye nombre, apellidos, edad y un numero identificador de la empresa
char nombre[50];
char apellido1[50];	
char apellido2[50];
int edad;
int identificador;
} empleado;

void fichar();//funcion activada por el usuario cuando elige la opcion fichar.
void fichar(int a, FILE *p);
void agr_emp(empleado *nuevo, int N);
void list_emp();
void con_hoy();
void con_sem();
	

int main()
{
	system ("color 70");
	int opcion;//variable que almacena la opcion elegida por el usuario 
	do//Se ejecuta el menu principal una vez y mientras la opcion que el usuario elija no sea correcta
	{
	printf("	MENU PRINCIPAL\n");//Se muestra el menu principal y las diferentes opciones.
	printf("Bienvenido a nuestro sistema de fichado del personal de la empresa, para comenzar seleccione una de las siguientes opciones:\n");
	printf("\n- Pulse 1 para fichar.");
	printf("\n- Pulse 2 para agregar un empleado.");//Luego poner que haga falta un código para las labores de gerente
	printf("\n- Pulse 3 para ver la lista de empleados.");
	printf("\n- Pulse 4 para consultar los datos de hoy.");
	printf("\n- Pulse 5 para consultar los datos de esta semana.");
	printf("\n- Pulse 6 para salir.\n\n");
	scanf("%d", &opcion);// se guarda la opcion elegida por el usuario en una variable
	switch (opcion)//en funcion de la opcion elegida se realizan las distintas opciones
	{
		case 1:;
			int ident;
			FILE *pf=fopen("pruebas.txt", "r");
			printf("Has seleccionado la opcion de fichar, a continuacion se abrira el fichero de empleados.\n");
			if(pf==NULL)
			{
				printf("Error al abrir el fichero.\n");
				return -1;
			}
			else
			{
				printf("El fichero se ha abierto correctamente.\n");
				return 0;
			}
			printf("Introduce el numero de identificador:\n");
			scanf("%d", &ident);
			if(ident=!pf)
			printf("No se encuentra al trabajador introducido.\n");
			else
				fichar(ident, pf);
			break;
		case 2:;
			int m, num;
			printf("Has seleccionado la opcion agregar empleado,\n");
			printf("Seleccione el numero de empleados.\n");
			scanf("%d", &num);
			empleado *nuevo;
			agr_emp (nuevo, num);//Se incia la funcion agregar empleadp
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

void fichar(int a, FILE *p)//funcion activada por el usuario cuando elige la opcion fichar.
{
	p=fopen("hoja_fichar.txt","r");
		if (p == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
	{
		p = fopen("hoja_fichar.txt", "w");//se abra el archivo para escribir en él
		fprintf(p,"	NUEVO MES:\n");
		fprintf(p,"Identificador: %d", a);//se escribe el numero de identificador
		printf("Introduce la hora con formato HH:MM :\n");
		char hora;
		fprintf(p, "Hora: %c", hora);//se escribe la hora
	    fclose(p); // Cerramos fichero
	}
	else//en caso de que el archivo ya exista
	{

		p = fopen("hoja_fichar.txt", "w");//se abra el archivo para escribir en él
		fprintf(p,"	NUEVO MES:\n");
		fprintf(p,"Identificador: %d", a);//se escribe el numero de identificador
		printf("Introduce la hora con formato HH:MM :\n");
		char hora;
		fprintf(p, "Hora: %c", hora);//se escribe la hora
	    fclose(p); // Cerramos fichero
		}
}
void agr_emp(empleado *nuevo, int N)//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
	int m, i ;
	nuevo=malloc(sizeof(int)*N);
	//Se comprueba si malloc ha funcionado
	//El vector tiene N elementos
	if(nuevo==NULL)
	{
		printf("Error: memoria no disponible.\n");
		exit(-1);
	}
	FILE * pf = fopen("pruebas.txt", "r");//se intenta abrir el archivo que almacena los datos de los empleados
	if (pf == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
	{
		pf = fopen("pruebas.txt", "w");//se abra el archivo para escribir en él
		fprintf(pf,"	LISTA DE EMPLEADOS:");
		printf("\nIntroduzca el nombre del empleado: 	");//se le piden los datos del empleado al usuario para almacenarlos en el archivo
		scanf("%s", nuevo[0].nombre);
		printf("\nIntroduzca su primer apellido:	");
		scanf("%s", nuevo[0].apellido1);
		printf("\nIntroduzca su segundo apellido:	");
		scanf("%s", nuevo[0].apellido2);
		printf("\nIntroduzca su edad:	");
		scanf("%d", &nuevo[0].edad);
		printf("\nIntroduzca su numero de identificacion:	");
		scanf("%d", &nuevo[0].identificador);	
		fprintf(pf,"\nNombre: %s", nuevo[0].nombre);//Se escriben todos los datos del empleado en una misma línea
		fprintf(pf,"	Primer apellido: %s", nuevo[0].apellido1);
		fprintf(pf,"	Segundo apellido: %s", nuevo[0].apellido2);
		fprintf(pf,"	Edad: %d", nuevo[0].edad);
		fprintf(pf,"	Identificador: %d", nuevo[0].identificador);
		fclose(pf); // Cerramos fichero
	}

	else//en caso de que el archivo ya exista
	{
		for(i=0;i<N;i++)
		{
		
			FILE *pf = fopen("pruebas.txt","a");//Se abre para añadir los datos de nuevos empleados
				printf("\nIntroduzca el nombre del nuevo empleado:  	 ");//se le solicitan los datos del nuevo empleado al usuario
				scanf("%s", nuevo[i+1].nombre);
				printf("\nIntroduzca su primer apellido:	");
				scanf("%s", nuevo[i+1].apellido1);
				printf("\nIntroduzca su segundo apellido:  	 ");
				scanf("%s", nuevo[i+1].apellido2);
				printf("Introduzca su edad:	");
				scanf("%s", &nuevo[i+1].edad);
				printf("Introduzca su numero de identificacion:	");
				scanf("%s", &nuevo[i+1].identificador);	
				fprintf(pf,"%s ", nuevo[i].nombre);//se almacenan todos los datos de ese empleado en una única línea
				fprintf(pf,"%s ", nuevo[i+1].apellido1);
				fprintf(pf,"%s ", nuevo[i+1].apellido2);
				fprintf(pf,"%s ", nuevo[i+1].edad);
				fprintf(pf,"%s \n", nuevo[i+1].identificador);
		    	fclose(pf); // Cerramos fichero
			}
	
}
	free(nuevo);//Liberamos el puntero-vector
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


printf("\nNombre\t\tApellidos\t\tEdad\t\tN de identificacion\n");
printf("");

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

