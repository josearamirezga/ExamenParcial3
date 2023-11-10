//INTENTO 2:
	
	//REALIZAR UN PROGRAMA QUE TOME LOS DATOS DE UNA LISTA CSV, LOS IMPRIMA Y BASADO EN EL ID DEL ESTUDIANTE, REALIZE UNA SUMA DE ESTOS VALORES.

#include <stdio.h>
#include <stdlib.h>

#define MAX_COLUMNS 3200
#define MAX_ROWS 50
#define MAX_STRING_LENGTH 50
#define BUFFER_SIZE 10240

void DUPLICAR_ARRAY(char LUGAR[], const char ORIGEN[]){
	int i;
	
	for (i = 0; ORIGEN[i] !=  '\0' && i < MAX_STRING_LENGTH - 1; i++){
		
		LUGAR[i] = ORIGEN[i];
		
	}
}

int main(){
	int ID = 963; // Ultimos 3 numeros
	printf("El ID del estudiante es: %d \n", ID);
	
	
	FILE * DATABASE = fopen("emails.csv", "r");
	char TEMP[BUFFER_SIZE];
	char NOMBRES[MAX_COLUMNS][MAX_STRING_LENGTH]; // Nombres de las columnas
	
	
	if (DATABASE == NULL){
		
		perror("El archivo no puede ser leido \n");
		return 1;
		
	}
	printf("El archivo fue abierto \n");
	
	int COLUMN[MAX_COLUMNS];
	
	if (fgets(TEMP, sizeof(TEMP), DATABASE)) {
		
		int COLUMNA = 0;
		char *Comienzo = TEMP;
		while (*Comienzo != '\0' && COLUMNA < MAX_COLUMNS){
			
			char *FIN = Comienzo;
			
			while (*FIN != ',' && *FIN != '\0'){
				
				FIN ++;
				
			}
			DUPLICAR_ARRAY(NOMBRES[COLUMNA], Comienzo);
			
			Comienzo = (*FIN == ',') ? FIN + 1: FIN;
			
			COLUMNA ++;
		}
		
	}
	
	for (int i = 0; i < MAX_COLUMNS; i++) {
        COLUMN[i] = 0;
    }
    
    for (int filanueva = 0; filanueva <= ID && fgets(TEMP, sizeof(TEMP), DATABASE); ++filanueva) {
    }
    
    for (int filanueva = 0; filanueva <= MAX_ROWS && fgets(TEMP, sizeof(TEMP), DATABASE); ++filanueva){
    	int columna = 0;
    	char *start = TEMP;
    	while (*start != '\0' && columna < MAX_COLUMNS){
    		
    		char *end = start;
    		
    		while (*end != ',' && *end != '\0') {
    			
    			end ++;
    		}
    		COLUMN[columna] += atoi(start);
    		
    		start = (*end == ',') ? end + 1: end;
    		
    		columna ++;
    	}
    	
    }
	fclose(DATABASE);
	
	FILE *ARCHIVO = fopen("180963.txt","w");
	if (ARCHIVO == NULL){
		
		perror("Error al abrir el archivo");
		return 1;
		
	}
	
	
	for (int i = 1; i < MAX_COLUMNS && NOMBRES[i][0] != '\0'; i++){
		
		fprintf(ARCHIVO, "%s, %d\n", NOMBRES[i],COLUMN[i]);
		
	}
	
	fclose(ARCHIVO);
	return 0;
	
}

// INTENTO 1:

/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
	
	FILE * DATABASE = fopen("emails.csv", "r");
	
	if (DATABASE == NULL){
		perror("Error al crear el archivo\n");
		return 1;
	}
	
	printf("El archivo fue abierto.\n");
	
	int COLUMN_I = 0;
	int ROW_I = 0;
	
	char Caracter;
	bool CONDITION = false;
	while (feof(DATABASE) == 0){
		
		Caracter = fgetc(DATABASE);
		
		if (Caracter == '\n'){
			
			ROW_I++;
			CONDITION = true;
		} else if (!CONDITION && Caracter == ','){
			
			COLUMN_I++;
		}
	}
	
	printf("Renglones de matriz = %d\n Columnas de la matriz: %d\n", ROW_I, COLUMN_I);
	
	int Matrix[ROW_I][COLUMN_I];
	
	fseek(DATABASE,0, SEEK_SET);
	
	int i = 0;
	
	int TEMP[ROW_I * COLUMN_I];
	
	while (feof(DATABASE) == 0){
		
		int NUM = -1;
		Caracter = fgetc(DATABASE);
		
		if (Caracter == ','){
			
			fscanf(DATABASE,"%d", &NUM);
			
			if (NUM != -1){
				
				TEMP[i] = NUM;
				
				i++;
			}	
		}

	}
	
	char NOMBRES[ROW_I][20];
	int j = 0;
	 i = -1;
	CONDITION = false;
	fseek(DATABASE, 0, SEEK_SET);
	
	
	while (feof(DATABASE) == 0){
		
		Caracter = fgetc(DATABASE);
		
		
		if (Caracter == ','){
			j = 0;
			i++;
			CONDITION = true;
		} else if (CONDITION && i < ROW_I - 1){
	
			NOMBRES[i][j] = Caracter;
			
			j++;
		}
	} 
	
	for (int i = 0; i < ROW_I - 2; i++){
		printf("%s, %d", NOMBRES[i]);
		
		printf("\n");
	} 
	
	int TEMPSUM = 0;
	for (i = 0; i < ROW_I; i++){
		
		for (int j = 0; j < COLUMN_I; j++){
			
			Matrix[i][j] = TEMP[TEMPSUM];
			TEMPSUM++;
			
		}
		
	}
	
	for ( i = 0; i < ROW_I - 1 ; i++){
		
		for (int j = 0; j < COLUMN_I; j++){
			
			printf("%d  ", Matrix[i][j]);
			
		}
		printf("\n");
	} 
	
	
	
	fclose(DATABASE);
	
	FILE * Archivo = fopen("MatrizNueva.txt","w");
	
	if (Archivo == NULL){
		
		perror("El archivo no fue encontrado.");
		return 1;
	}
	
	printf("El archivo fue abierto."); 
	
	fclose(Archivo);
	
	return 0; 
	
} */
