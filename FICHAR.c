#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*EL CODIGO DE GERENTE ES 123*/

typedef struct{//Estructura que almacena los datos de cada empleado. Incluye nombre, apellidos, edad y un numero identificador de la empresa
char nombre[50];
char apellido1[30];	
char apellido2[30];
int edad;
int identificador;
} empleado;

typedef struct{//Estructura auxiliar de empleados sin datos personales, solo nombre y numero de identificacion
char *nombres;
int numeros;
}empleados;


void agr_emp(empleado *nuevo, int N);
void list_emp();
void con_dia(int dia, int mes);
void con_mes(int mes);
float calcular_salario();
void fichar ();
void copiar (char temp[], int i, empleados *empl);
void vaciar(char temp []);


int main()
{
	time_t tiempo = time (0);
	struct tm *tlocal = localtime(&tiempo);
	char fecha [128];
	strftime(fecha,128,"%a %d/%m/%y %H:%M:%S", tlocal);
	empleado *nuevo;
	int num, codigo;
	system ("color 70");
	int opcion;//variable que almacena la opcion elegida por el usuario 
	do//Se ejecuta el menu principal una vez y mientras la opcion que el usuario elija no sea correcta
	{
		printf("%s\n\n", fecha);
	printf("	MENU PRINCIPAL\n");//Se muestra el menu principal y las diferentes opciones.
	printf("Bienvenido a nuestro sistema de fichado del personal de la empresa, para comenzar seleccione una de las siguientes opciones:\n");
	printf("\n- Pulse 1 para fichar.");
	printf("\n- Pulse 2 para agregar un empleado.");
	printf("\n- Pulse 3 para ver la lista de empleados.");
	printf("\n- Pulse 4 para consultar los datos de un dia.");
	printf("\n- Pulse 5 para consultar los datos de un mes.");
	printf("\n- Pulse 6 para consultar el salario de un empleado.");
	printf("\n- Pulse 7 para salir.\n\n");
	scanf("%d", &opcion);// se guarda la opcion elegida por el usuario en una variable
	switch (opcion)//en funcion de la opcion elegida se realizan las distintas opciones
	{
		case 1: // aqui es para fichar
			{
			int sal;
			system("cls");
			printf("Funcion fichar.");
			
			do{
				fichar();
				printf("\nInserte 1 si desea salir. Inserte cualquier otro numero para continuar: ");
				scanf("%i",&sal);
				system("cls");
			}
			while (sal!=1);
			}
			break;
		case 2: // aquí agregamos un empleado
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
				case 'c'://cuando el usuario decide continuar
					{
						printf("Seleccione el numero de empleados.\n");
						scanf("%d", &num);
						int i ;
						nuevo=malloc(sizeof(empleado)*num);
						//Se comprueba si malloc ha funcionado
						//El vector tiene N elementos
						if(nuevo==NULL)// entramos en el caso del error
						{
							printf("Error: memoria no disponible.\n");
							exit(-1);
						}
						for(i=0;i<num;i++)
						{
							printf("\nIntroduzca el nombre del nuevo empleado: ");//se le solicitan los datos del nuevo empleado al usuario
							scanf(" %49[^\n]", nuevo[i].nombre);// recogemos los datos uno a uno para almacenarlos correctamente en la estructura
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
		case 3://consultar lista de empleados
			{
			printf("Introduzca el codigo de gerente\n");//Se pide codigo de gerente para aquellas funciones a las que no deban acceder todos los usuarios
			scanf("%i", &codigo);
			if (codigo!=123)//Se niega el acceso si el codigoe es incorrecto
			{
				printf("CODIGO INCORRECTO");
				exit (1);
			}
			char op3;
			do//Mientras no seleccione la opcion salir el usuario estará dentro de la opcion de consulta
			{
			system("cls");
			printf("Si desea consultar la lista de empleados pulse e, en caso contrario pulse s:\n");
			scanf("%c",&op3);
			switch(op3)
				{
				case 'e'://En caso de que decida consultar se inicia la funcion que lleva a cabo dicha consulta
					{
					list_emp();
					}
				getch();
				system("cls");
					}
			}			
			while(op3!='s');
			system("cls");
				}	
				break;
				
		case 4://aquí se consultan los datos de un día en concreto
			{
				printf("Introduzca el codigo de gerente\n");
				scanf("%i", &codigo);
				if (codigo!=123)
				{
					printf("CODIGO INCORRECTO");
					exit (1);
				}
				char op4;
				system ("cls");
				int dia, mes;
				do//se ejecuta el menu de la opcion mientras el usuario no introduzca la opcion salir
				{
					printf("Si desea consultar los datos de un dia pulse d de lo contrario pulse s:\n");
					scanf(" %c", &op4);
					switch(op4)
					{
						case 'd'://cuando el usuario decide continuar
						{
						system("cls");
						printf("Introduzca el dia:	");//el usuario indica el mes y el día que quiere consultar
						scanf("%i", &dia);
						printf("Introduzca el mes:	");
						scanf("%i", &mes);
						con_dia(dia, mes);//con estos datos se inicia la funcion que imprime por pantalla los datos de los empleados que ficharon ese dia
						}
					}
				}
				while(op4!='s');
				system("cls");
			}
			break;
		case 5://aquí se consultan los datos de un mes en concreto
			{
				printf("Introduzca el codigo de gerente\n");
				scanf("%i", &codigo);
				if (codigo!=123)
				{
					printf("CODIGO INCORRECTO");
					exit (1);
				}
				char op4;
				system ("cls");
				int mes;
				do//se ejecuta el menu de la opcion mientras el usuario no introduzca la opcion salir
				{
					printf("Si desea consultar los datos de un mes pulse m de lo contrario pulse s:\n");
					scanf(" %c", &op4);
					switch(op4)
					{
						case 'm'://cuando el usuario decide continuar
						{
						system("cls");
						printf("Introduzca el mes:	");//el usuario indica el mes que quiere consultar
						scanf("%i", &mes);
						con_mes (mes);//con ese dato se inicia la funcion que imprime por pantalla los datos de los empleados que ficharon ese mes
					}
					}
				}
				while(op4!='s');
				system("cls");
			}
			break;
		case 6://Aqui se calcula el salario del empleado en funcion de su posicion dentro de la empresa
			{
				printf("Introduzca el codigo de gerente\n");
				scanf("%i", &codigo);
				if (codigo!=123)
				{
					printf("CODIGO INCORRECTO");
					exit (1);
				}
				char op6;
				do//se ejecuta el menu de la opcion salario mientras el usuario no introduzca la opcion salir
				{
					printf("Si desea calcular el salario aproximado pulse c, de lo contrario pulse s:\n");
					scanf(" %c",&op6);
					switch(op6)
					{
						case 'c'://cuando el usuario decide continuar
							{
							int dep, numh; //numh es el numero de horas extras
							float salbase, horaextra, thx, px, bccc, bccp, dev, ded, aport, irpf, sal;//yhx es el total que le corresponde por las horas extras y px es la paga extra
							//bccc base de cotizacion por contingencias comunes bccp base de cotizacion por contingencias profesionales
							//dev es el total devengado ded es el total a deducir
							//aport son las aportaciones
							printf("Este es un simulador del salario de un empleado,\n la informacion es aproximada.");
							printf("Seleccione el departamento al que pertenece cada trabajador:\n DEPARTAMENTO 1\tDEPARTAMENTO 2\tDEPARTAMENTO 3\tDEPARTAMENTO 4\tDEPARTAMENTO 5\t ");
							scanf("%d", &dep);
							switch(dep)//en funcion del departamento al que pertenezca el empleado varía el calculo del salario
							{
								case 1://en caso de que pertenezca al departamento uno
									{
										salbase=950.0;
										horaextra=7.52;
										printf("Introduce el numero de horas extras, si es que las ha realizado\n");
										scanf("%d",&numh);
										thx=numh*horaextra;
										px=salbase*2/12;
										dev=salbase+thx;
										bccc=dev+px;
										bccp=bccc+thx;
										aport=bccc*0.047+bccp*0.0155+bccp*0.001;
										irpf=aport*0.09;
										ded=aport+irpf;
										sal=dev-ded;
										printf("El salario aproximado que le corresponde al empleado es %.2f €\n", sal);
										break;
										
									}
								case 2://en caso de que pertenezca al departamento dos
									{
										salbase=995.21;
										horaextra=8.92;
										printf("Introduce el numero de horas extras, si es que las ha realizado\n");
										scanf("%d",&numh);
										thx=numh*horaextra;
										px=salbase*2/12;
										dev=salbase+thx;//el total devengado es el salario base mas las horas extras
										bccc=dev+px;
										bccp=bccc+thx;
										aport=bccc*0.047+bccp*0.0155+bccp*0.001;
										irpf=aport*0.09;
										ded=aport+irpf;
										sal=dev-ded;
										printf("El salario aproximado que le corresponde al empleado es %.2f €\n", sal);
										break;
									}
								case 3://en caso de que pertenezca al departamento tres
									{
										salbase=1050.0;
										horaextra=12.35;
										printf("Introduce el numero de horas extras, si es que las ha realizado\n");
										scanf("%d",&numh);
										thx=numh*horaextra;
										px=salbase*2/12;
										dev=salbase+thx;
										bccc=dev+px;
										bccp=bccc+thx;
										aport=bccc*0.047+bccp*0.0155+bccp*0.001;
										irpf=aport*0.09;
										ded=aport+irpf;
										sal=dev-ded;
										printf("El salario aproximado que le corresponde al empleado es %.2f €\n", sal);
										break;
									}
								case 4://en caso de que pertenezca al departamento cuatro
									{
										salbase=768.0;
										horaextra=7.10;
										printf("Introduce el numero de horas extras, si es que las ha realizado\n");
										scanf("%d",&numh);
										thx=numh*horaextra;
										px=salbase*2/12;
										dev=salbase+thx;
										bccc=dev+px;
										bccp=bccc+thx;
										aport=bccc*0.047+bccp*0.0155+bccp*0.001;
										irpf=aport*0.09;
										ded=aport+irpf;
										sal=dev-ded;
										printf("El salario aproximado que le corresponde al empleado es %.2f €\n", sal);
										break;
									}
								case 5://en caso de que pertenezca al departamento cinco
									{
										salbase=1568.23;
										horaextra=13.45;
										printf("Introduce el numero de horas extras, si es que las ha realizado\n");
										scanf("%d",&numh);
										thx=numh*horaextra;
										px=salbase*2/12;
										dev=salbase+thx;
										bccc=dev+px;
										bccp=bccc+thx;
										aport=bccc*0.047+bccp*0.0155+bccp*0.001;
										irpf=aport*0.09;
										ded=aport+irpf;
										sal=dev-ded;
										printf("El salario aproximado que le corresponde al empleado es %.2f €\n", sal);
										break;
									}
							}
						}
					}
				}
				while(op6!='s');
				system("cls");
			}
	}
	}
	while(opcion!=7);// si el numero marcado no corresponde a ninguna opcion sevuelve a ejecutar el menu principal
	printf("Gracias por usar nuestro software.\n");
	return 0;
}



void vaciar(char temp []){//funcion auxiliar que vacia una cadena de caracteres
	int i;
	for(i=0;i<50;i++){
		temp[i]='\0';
	}
}


void copiar (char temp[], int i, empleados *empl){/*esta funcion sirve para meter el contenido de la variable temp dentro del string dinámico nombre*/
	int N = strlen(temp)+1;//Primero reservamos espacio al string dinamico nombre. Sumamos uno para tener en cuenta el '\0'
	empl[i].nombres = (char*)malloc(N*sizeof(char));
	if (empl[i].nombres==NULL){//en caso de error se imprime el mismo por pantalla y finaliza el programa
		printf("\nNo se ha podido reservar memoria");
		exit(1);
	}
	strcpy(empl[i].nombres, temp);//se copia el contenido
}


void fichar (){//funcion dedicada a registrar las entradas de los empleados
	empleados *empl;
	int nLineas=0, l, b, var, hora, minutos, dia, mes;
	char x, aux, temp[50];
	FILE *fp;
	FILE *cp;
	fp = fopen ("auxiliar.txt","r");//se abre en modo lectura el fichero que contiene los datos no personales de los empleados
	cp = fopen ("hoja_fichar.txt","a");//se abre para añadir nuevos elementos el fichero que registra las entradas de los usuarios
	if (fp==NULL){//en caso de error
		printf("No se ha podido abrir el fichero.\n");
		exit(-1);
	}
	if (cp==NULL){//en caso de error
	printf("No se ha podido abrir el fichero.\n");
	exit(-1);
	}
	
/*Ahora,a partir de aquí estamos sacando el número de linea que hay en el fichero*/
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
	if(empl==NULL){//en caso de error
		printf("\n No se ha podido reservar la memoria\nCierre el programa");
	}
	/*Ahora vamos a leer el nombre*/
	for (l=0; !feof(fp); l++){
		vaciar(temp);//vaciamos el vector para el nuevo uso
		aux='0';//eliminamos el contenido anterior de la variable caracter aux
		for (b=0; aux!='-'; b++){//Ejecutamos en bucle el almacenamiento de cada caracter del fichero mientras este sea distinto del - que marca un nuevo empleado
			aux=fgetc(fp);//para ello nos apoyamos en la variable auxiliar
			if(aux!='-'){
				temp[b] = aux;
			}
		}
		copiar(temp, l, empl);//copiamos el contenido del vector
		fgets(temp,6,fp);	
		empl[l].numeros = atoi(temp);//convertimos el vector numero de identificacion a numero entero para facilitar su tratamiento posterior
		printf("\nNombre: %s. Numero de identificacion: %i", empl[l].nombres, empl[l].numeros);
	}
	printf("\nIntroduzca un numero de identificacion: ");//Se le pide al empleado su numero de identificacion para fichar
	scanf("%i", &var);
	for(l=0; l<nLineas; l++){//Se recorren todos los empleados dentro del fichero
		if(empl[l].numeros==var){//Cuando se encuentra a quien corresponde ese numero de identificacion se piden los datos pertinentes sobre el momento en que se dicha
		printf("\nCoincidencia: El numero de identificacion: %i corresponde al empleado con el nombre: %s\n", empl[l].numeros, empl[l].nombres);
		printf("\nBienvenido %s, introduzca la hora:\n",  empl[l].nombres);
		scanf("%i",&hora);
		printf("\nGracias, %s introduzca los minutos:\n",  empl[l].nombres);
		scanf("%i", &minutos);
		printf("\nIntroduzca el dia:\n");
		scanf("%i",&dia);
		printf("\nIntroduzca el mes:\n");
		scanf("%i",&mes);
		fprintf(cp,"%i-%i El empleado %s con numero de identificacion %i ha fichado a las %i:%i (%i/%i)\n", dia, mes, empl[l].nombres,empl[l].numeros, hora, minutos, dia, mes);
		}	//Y por ultimo se escribe dicha informacion en el fichero correspondiente
	}
	fclose(cp); // Cerramos los ficheros
	fclose(fp);	
}


void agr_emp(empleado *nuevo, int N)//funcion activada por el usuario cuando elige la opcion agregar empleado.
{
				int i;
				FILE * fp = fopen("auxiliar.txt", "r");
				FILE * pf = fopen("empleados.txt", "r");//se intenta abrir el archivo que almacena los datos de los empleados
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
				FILE *pf = fopen("empleados.txt","a");//Se abre para aÃƒÂ±adir los datos de nuevos empleados
				FILE *fp = fopen("auxiliar.txt","a");
				for(i=0;i<N;i++)
				{
					fprintf(pf,"-%s\t%s\t%s\t%d\t%d\n", nuevo[i].nombre,nuevo[i].apellido1, nuevo[i].apellido2,nuevo[i].edad,nuevo[i].identificador);//se almacenan todos los datos de ese empleado en una ÃƒÂºnica lÃƒÂ­nea
					fprintf(fp,"\n%s-%d", nuevo[i].nombre,nuevo[i].identificador);	    	
			}
				fclose(pf); // Cerramos los ficheros
				fclose(fp);			
			}
	
}
}

void list_emp()//funcion activada por el usuario cuando elige la opcion lista de empleados
{
FILE *pf = fopen("empleados.txt","r");//se abre en modo lectura el fichero que almacena todos los datos de los empleados
int  i=0;
char nombre[50], apellido1[30], apellido2[30], Apellidos[60];
int Edad[1], Identificador[1];
printf("\nNombre y Apellidos (Edad)-->N de identificacion\n\n");
while(fscanf(pf, "%s %s %s %d %d", nombre,apellido1 ,apellido2 ,Edad ,Identificador )!= EOF ){//Se ejecuta en buvle el proceso de acceder a los datos e imprimirlos en pantalla
strcpy(Apellidos, apellido1); 
strcat(Apellidos, " "); 
strcat(Apellidos, apellido2); 
printf("%s %s (%d anos)-->%d\n", nombre, Apellidos, Edad[0], Identificador[0]);
}
}

void con_dia(int dia, int mes)//funcion activada por el usuario cuando elige la opcion consultar los datos de hoy.
{
	int aux1, aux2;
	char linea [100];
	FILE *cp;
	fopen ("cp", "r");
	cp = fopen ("hoja_fichar.txt","r");//se abre en modo lectura el fichero que almacena todos los datos relativos a la accion de fichar
	fscanf(cp,"%i-%i", &aux1, &aux2);//se escaneand el dia y el mes de la primera vez que se realizo esta accion
	printf("Lista de coincidencias:\n");
	while(fgets(linea, 100, (FILE*) cp))//se imprimen por pantalla todas las coincidencias
		{
			if(aux1==dia&&aux2==mes)//en caso de coincidan se imprimen los datos
			{
			printf("%s", linea);
			}
			fscanf(cp,"%i-%i", &aux1, &aux2);//se escanea la siguiente fecha
		}
		
	fclose (cp);
}

void con_mes(int mes)//funcion activada por el usuario cuando elige la opcion consultar los datos de la semana.
{
	int aux1, aux2;
	char linea [100];
	FILE *cp;
	fopen ("cp", "r");
	cp = fopen ("hoja_fichar.txt","r");//se abre en modo lectura el fichero que almacena todos los datos relativos a la accion de fichar
	fscanf(cp,"%i-%i", &aux1, &aux2);//se escaneand el dia y el mes de la primera vez que se realizo esta accion
	printf("Lista de coincidencias:\n");
	while(fgets(linea, 100, (FILE*) cp))
		{
			
			if(aux2==mes)//en caso de que coincidan se imprimen los datos
			{
			printf("%s", linea);
			}
			fscanf(cp,"%i-%i", &aux1, &aux2);//se escanea la siguiente fecha
		}
	fclose (cp);
}

