#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{//Estructura que almacena los datos de cada empleado. Icluye nombre, apellidos, edad y un numero identificador de la empresa
char nombre[50];
char apellido1[30];	
char apellido2[30];
int edad;
int identificador;
} empleado;

typedef struct{
char *nombres;
int numeros;
}empleados;


void agr_emp(empleado *nuevo, int N);
void list_emp();
void con_hoy();
void con_sem();


void vaciar(char temp []){
	int i;
	
	for(i=0;i<50;i++){
		temp[i]='\0';
	}
}

void copiar (char temp[], int i, empleados *empl){//esta funcion sirve para 
//meter el contenido de la variable temp dentro del string dinámico nombre
	int N = strlen(temp)+1;//Primero reservamos espacio al string dinamico 
	//nombre. Sumamos uno para tener en cuenta el '\0'
	empl[i].nombres = (char*)malloc(N*sizeof(char));
	if (empl[i].nombres==NULL){
		printf("\nNo se ha podido reservar memoria");
		exit(1);
	}
	strcpy(empl[i].nombres, temp);
}


void fichar (){
	empleados *empl;
	int nLineas=0, l, b, var, hora, minutos;
	char x, aux, temp[50];
	FILE *fp;
	FILE *cp;
	fp = fopen ("auxiliar.txt","r");
	cp = fopen ("hoja_fichar.txt","a");
	if (fp==NULL){
		printf("No se ha podido abrir el fichero.Cierre el programa\n");
	}
	
/*Ahora,a partir de aquí y hasta el siguiente comentario estamos sacando el 
número de linea que hay en el fichero*/	
	while (fscanf(fp, " %c", &x) != EOF)
			{
			//Si lo leído es un salto de línea
			if (x == '-')
			{
			++nLineas;			//incrementamos el contador
			}
			}
			printf(" \nNumero de empleados: %i\n", nLineas);
/*Aquí acabamos de contar el número de línea*/
	rewind(fp);//Ponemos el cursor al inicio del fichero
	
	empl = (empleados*)malloc(nLineas*sizeof(empleados));//Reservamos la memoria
	if(empl==NULL){
		printf("\n No se ha podido reservar la memoria\nCierre el programa");
	}
	/*Ahora vamos a leer el nombre*/
	for (l=0; !feof(fp); l++){
		vaciar(temp);
		aux='0';
		for (b=0; aux!='-'; b++){
			aux=fgetc(fp);
			if(aux!='-'){
				temp[b] = aux;
			}
		}
		copiar(temp, l, empl);
		
		fgets(temp,6,fp);	
		empl[l].numeros = atoi(temp);
		printf("\nNombre: %s. Numero de identificacion: %i", empl[l].nombres, empl[l].numeros);
	}
	printf("\nIntroduzca un numero de identificacion: ");
	scanf("%i", &var);
	for(l=0; l<nLineas; l++){
		if(empl[l].numeros==var){
		printf("\nCoincidencia: El numero de identificacion: %i corresponde al empleado con el nombre: %s\n", empl[l].numeros, empl[l].nombres);
		printf("\nBienvenido %s, introduzca la hora:\n",  empl[l].nombres);
		scanf("%i",&hora);
		printf("\nGracias, %s introduzca los minutos:\n",  empl[l].nombres);
		scanf("%i", &minutos);
		fprintf(cp,"El empleado: %s con numero de identificacion: %i ha fichado a las %i:%i\n", empl[l].nombres,empl[l].numeros, hora, minutos);
		}	
	}
}


void agr_emp(empleado *nuevo, int N)//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
				int i;
				FILE * fp = fopen("auxiliar.txt", "r");
				FILE * pf = fopen("pruebas.txt", "r");//se intenta abrir el archivo que almacena los datos de los empleados
				if (pf == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
				{
					printf("Error al abrir el fichero de empleados\n");
				}
							
				else//en caso de que el archivo ya exista
				{
				if (pf == NULL)//si el archivo aun no existe (es el primer empleado que se agrega)
				{
					printf("Error al abrir el fichero de auxiliar de fichar\n");
				} 
				else{					
				FILE *pf = fopen("pruebas.txt","a");//Se abre para aÃƒÂ±adir los datos de nuevos empleados
				FILE *fp = fopen("auxiliar.txt","a");
				for(i=0;i<N;i++)
				{
					fprintf(pf,"-%s\t %s\t %s\t %d \t %d\n ", nuevo[i].nombre,nuevo[i].apellido1, nuevo[i].apellido2,nuevo[i].edad,nuevo[i].identificador);//se almacenan todos los datos de ese empleado en una ÃƒÂºnica lÃƒÂ­nea
					fprintf(fp,"\n%s-%d", nuevo[i].nombre,nuevo[i].identificador);	    	
			}
				fclose(pf); // Cerramos fichero
				fclose(fp);			
			}
	
}
}

void list_emp()//funcion activada por el usuario cuando elige la opcion lista de empleados
{
FILE *pf = fopen("pruebas.txt","r");
int  i=0;
char nombre[50], apellido1[30], apellido2[30], Apellidos[60];
int Edad[2], Identificador[3];
printf("\n Nombre\t\tApellidos\t\tEdad\tNÂº de identificacion\n\n");
while(fscanf(pf, "%50s %30s %30s %d %d", nombre,apellido1 ,apellido2 ,Edad ,Identificador )!= EOF ){
strcpy(Apellidos, apellido1); 
strcat(Apellidos, " "); 
strcat(Apellidos, apellido2); 





printf(" %s\t\t%s\t\t%d\t%d\n", nombre, Apellidos, Edad, Identificador);

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
	empleado *nuevo;
	int num;
	system ("color 70");
	int opcion;//variable que almacena la opcion elegida por el usuario 
	do//Se ejecuta el menu principal una vez y mientras la opcion que el usuario elija no sea correcta
	{
	printf("	MENU PRINCIPAL\n");//Se muestra el menu principal y las diferentes opciones.
	printf("Bienvenido a nuestro sistema de fichado del personal de la empresa, para comenzar seleccione una de las siguientes opciones:\n");
	printf("\n- Pulse 1 para fichar.");
	printf("\n- Pulse 2 para agregar un empleado.");//Luego poner que haga falta un cÃƒÂ³digo para las labores de gerente
	printf("\n- Pulse 3 para ver la lista de empleados.");
	printf("\n- Pulse 4 para consultar los datos de hoy.");
	printf("\n- Pulse 5 para consultar los datos de esta semana.");
	printf("\n- Pulse 6 para salir.\n\n");
	scanf("%d", &opcion);// se guarda la opcion elegida por el usuario en una variable
	switch (opcion)//en funcion de la opcion elegida se realizan las distintas opciones
	{
		case 1:
			{
			int sal;
			do{
				fichar();
				printf("\nInserte 1 si desea salir. Inserte cualquier otro numero para continuar: ");
				scanf("%i",&sal);
				system("cls");
			}
			while (sal!=1);
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
						int i ;
						nuevo=malloc(sizeof(empleado)*num);
						//Se comprueba si malloc ha funcionado
						//El vector tiene N elementos
						if(nuevo==NULL)
						{
							printf("Error: memoria no disponible.\n");
							exit(-1);
						}
						for(i=0;i<num;i++)
						{
							printf("\nIntroduzca el nombre del nuevo empleado: ");//se le solicitan los datos del nuevo empleado al usuario
							scanf(" %49[^\n]", nuevo[i].nombre);
							printf("\nIntroduzca su primer apellido: ");
							scanf(" %49[^\n]", nuevo[i].apellido1);
							printf("\nIntroduzca su segundo apellido: ");
							scanf(" %49[^\n]", nuevo[i].apellido2);
							printf("Introduzca su edad:	");
							scanf("%d", &nuevo[i].edad);
							printf("Introduzca su numero de identificacion (numero de cuatro cifras):	");
							scanf("%d", &nuevo[i].identificador);	
						}
						
						agr_emp (nuevo, num);//Se incia la funcion agregar empleado
						free(nuevo);//Liberamos el puntero-vector
					}
			}
			system("cls");
			}
			while(op2!='s');
			}	
			break;
		case 3:
			{
			char op3;
			do
			{
			system("cls");
			printf("Si desea consultar la lista de empleados pulse e, en caso contrario pulse s:\n");
			scanf("%c",&op3);
			switch(op3)
				{
				case 'e':
					{
					list_emp();
							
							}
				getch();
				system("cls");
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
				system("cls");
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
	while(opcion!=6);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el menÃƒÂº principal
	return 0;
}

