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

void fichar(int a, FILE *p, char b);
void agr_emp(empleado *nuevo, int N);
void list_emp();
void con_hoy();
void con_sem();
	

int main()
{
	empleado *nuevo;
	int num;
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
		case 1:
			{
			int ident,j ;
			char hora, op1;
			FILE *pf=fopen("pruebas.txt", "r");
			printf("Has seleccionado la opcion de fichar, a continuacion se abrira el fichero de empleados.\n");
			if(pf==NULL)
			{
				printf("Error al abrir el fichero.\n");
			}
			else
			{
				printf("El fichero se ha abierto correctamente.\n");
			}
			do
			{
			printf("Seleccione fichar(f) o salir (s):\n");
			scanf("%c", &op1);
			switch(op1)
			{
				case 'f':
				{
					printf("Introduce el numero de identificador:\n");
					scanf("%d", &ident);
					for(j=0;j<num;j++)
					{
					if(ident=!nuevo[j].identificador)
					printf("No se encuentra al trabajador introducido.\n");
					else
					{
						printf("Introduce la hora con formato HH:MM.\n");
						scanf("%c", hora);
						fichar(ident, pf, hora);
					}
					}
				}
			}
			}	
		while(op1!='s');
		}
			break;
		case 2:
			{
			int m;
			char op2;
			printf("Has seleccionado la opcion agregar empleado\n");
			do
			{
			printf("Seleccione continuar(c) o salir(s):\n");
			scanf("%c", &op2);
			switch(op2)
			{
				case 'c':
					{
						printf("Seleccione el numero de empleados.\n");
						scanf("%d", &num);
						agr_emp (nuevo, num);//Se incia la funcion agregar empleado
					}
			}
			}
			while(op2!='s');
			}	
			break;
		case 3:
			{
			
			char op3;
			do 
			{
				printf("Si desea consultar la lista de empleados pulse e, en caso contrario pulse s:\n");
				scanf("%c",&op3);
				switch(op3)
				{
					case 'e':
					{		
						list_emp ();
					}
				}
			}
			while(op3!='s');
		}
			break;
		case 4:
			{
				char op4;
				do
				{
					printf("Si desea consultar los datos de hoy pulse h de lo contrario pulse s:\n");
					scanf("%c", &op4);
					switch(op4)
					{
						case 'h':
						{
							con_hoy();
						}
					}
				}
				while(op4!='s');
			}
			break;
		case 5:
			 {
			 	char op5;
			 	do
			 	{
			 		printf("Si desea consultar los datos de la semana pulse w, de lo contrario pulse s:\n");
			 		scanf("%c",&op5);
			 		switch(op5)
			 		{
			 			case 'w':
			 				{
			 					con_sem();
							 }
					 }
				 }
				 while(op5!='s');
			 }
			break;
	}
	}
	while(opcion!=6);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el menú principal
	return 0;
}

void fichar(int a, FILE *p, char b)//funcion activada por el usuario cuando elige la opcion fichar.
{
	p=fopen("hoja_fichar.txt","r");
		if (p == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
	{
		printf("Error al abrir el fichero.");
	}
	else//en caso de que el archivo ya exista
	{

		p = fopen("hoja_fichar.txt", "w");//se abra el archivo para escribir en él
		fprintf(p,"	NUEVO MES:\n");
		fprintf(p,"Identificador: %d", a);//se escribe el numero de identificador
		fprintf(p, "Hora: %c", b);//se escribe la hora
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
		printf("Error al abrir el fichero,\n");
	}

	else//en caso de que el archivo ya exista
	{

		
			FILE *pf = fopen("pruebas.txt","w");//Se abre para añadir los datos de nuevos empleados
			for(i=0;i<N;i++)
			{
				printf("\nIntroduzca el nombre del nuevo empleado: ");//se le solicitan los datos del nuevo empleado al usuario
				scanf("%s", nuevo[i].nombre);
				printf("\nIntroduzca su primer apellido: ");
				scanf("%s", nuevo[i].apellido1);
				printf("\nIntroduzca su segundo apellido: ");
				scanf("%s", nuevo[i].apellido2);
				printf("Introduzca su edad:	");
				scanf("%d", &nuevo[i].edad);
				printf("Introduzca su numero de identificacion:	");
				scanf("%d", &nuevo[i].identificador);	
				fprintf(pf,"%s\t %s\t %s\t %d \t %d\n ", nuevo[i].nombre,nuevo[i].apellido1, nuevo[i].apellido2,nuevo[i].edad,nuevo[i].identificador);//se almacenan todos los datos de ese empleado en una única línea
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

