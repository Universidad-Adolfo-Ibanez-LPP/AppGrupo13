#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "Libros.h"

#define MAXCHAR 9000

int registryCount = 0;

Libro* getLibros(FILE *fp) {
    //genero un array dinamico de personas
    Libro* libros = (Libro*)malloc(9000*sizeof(Libro*));

    char row[MAXCHAR];
    char *token;
    int cont = 0;

    char* titulo;
    char* autor;
    char* anio;
    char* estante_numero;
    char* estante_seccion;
    char* piso;
    char* edificio;
    char* sede;
    //saco la primer linea
    fgets(row, MAXCHAR, fp);
    while (fgets(row,MAXCHAR,fp)){
        //obtiene la linea siguiente
        //fgets(row, MAXCHAR, fp);
        titulo = strtok(row,",");
        autor = strtok(NULL,",");
        anio = strtok(NULL,",");
        estante_numero = strtok(NULL,",");
        estante_seccion = strtok(NULL,",");
        piso = strtok(NULL,",");
        edificio = strtok(NULL,",");
        sede = strtok(NULL,",");
        //token = strtok(row, ",");
        //print id first
        Libro  *libro = (Libro *) malloc(sizeof(Libro));
        //convierto el id en entero
        /* int id = atoi(token);
        //lo paso a la persona
        libro->id = id; */

        //obtengo el primer campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->titulo = (char*)malloc(strlen(titulo) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy(libro->titulo, titulo);


        //obtengo el siguiente campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->autor = (char*)malloc(strlen(autor) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->autor, autor);

        //obtengo el primer campo
        //token = strtok(NULL, ",");

        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro ->anio = (char*)malloc( strlen(anio) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy(libro->anio, anio);

        //obtengo el primer campo
        //token = strtok(NULL, ",");

        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro ->estante_numero = (char*)malloc( strlen(estante_numero) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->estante_numero, estante_numero);

        //obtengo el siguiente campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->estante_seccion = (char*)malloc( strlen(estante_seccion) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->estante_seccion, estante_seccion);

        //obtengo el siguiente campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->piso = (char*)malloc( strlen(piso) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->piso, piso);

        //obtengo el siguiente campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->edificio = (char*)malloc( strlen(edificio) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->edificio, edificio);

        //obtengo el siguiente campo
        //token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->sede = (char*)malloc( strlen(sede) * sizeof(char*));
        //finalmente lo copio en el campo de persona
        strcpy( libro->sede, sede);  

        libros[cont] = *libro;
        cont++;
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return libros;
}