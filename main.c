#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Libros.h"
#define MAXCHAR 1000

#define READ_ONLY "r"

//contratos de procedimientos
void showTitles(void);
void showMenu(void);
void agregarLibro();
void quitarLibro(void);
void agregarSede(void);
void quitarSede(void);
void agregarSecciones(void);
void quitarSecciones(void);
void agregarPisos(void);
void quitarPisos(void);

enum OPTIONS { AGREGARLIBRO = 1, QUITARLIBRO = 2, AGREGARSEDE = 3, QUITARSEDE = 4, AGREGARSECCIONES = 5, QUITRARSECCIONES =6, AGREGARPISOS= 7, QUITARPISOS=8};

void showContentsAsStruct(FILE *pFile);

FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,READ_ONLY);
    return fp;
}

//Aca empieza el codigo de funciones

void showTitles(){
    // presentacion de las opciones
    printf("\n1) Agregar Libro\n");
    printf("2) Quitar libro\n");
    printf("3) Agregar Sede\n");
    printf("4) Quitar Sede\n");
    printf("5) Agregar Seccion\n");
    printf("6) Quitar Seccion\n");
    printf("7) Agregar Piso\n");
    printf("7) Quitar Piso\n");
    printf("\n");
    printf("Seleccione una opcion:  \n");
}

void showMenu() {
    int option = 0;
    showTitles();
    scanf("%d", &option);
//esto hace que el menu vuelva a mostrarse hasta que me ingrese una opcion valida
    while (option <= 0 || option >= 8) {
        printf("Opción Invalida! \n");
        showTitles();
        scanf("%d", &option);
    };
//Solo salgo con una opcion valida
    switch (option) {
        case AGREGARLIBRO:
            agregarLibro();
            break;

        case QUITARLIBRO:
            quitarLibro();
            break;

        case AGREGARSEDE:
            agregarSede();
            break;

        case QUITARSEDE:
            quitarSede();
            break;

        case AGREGARSECCIONES:
            agregarSecciones();
            break;

        case QUITRARSECCIONES:
            quitarSecciones();
            break;

        case AGREGARPISOS:
            agregarPisos();
            break;

        case QUITARPISOS:
            quitarPisos();
            break;
    }
}


//hasta aqui showMenu codigo

//Códigos de funciones **************************************************************************************************
void agregarLibro(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char titulo[100], edificio[50], autor[100], seccion[100], estantesec[100], sede[100];

    int year, estantenum, piso;

    printf("Bienvenido/a, a continuacion le solicitaremos informacion para agregar el libro de su eleccion.\nIngrese el titulo deseado: ");
    scanf("%s", titulo);
    printf("Quien es el autor? ");
    scanf("%s", autor);
    printf("En que sede se encuentra? ");
    scanf("%s", sede);
    printf("Cual anio corresponde?: ");
    scanf("%d", &year);
    printf("En que seccion de estante esta?: ");
    scanf("%s", estantesec);
    printf("En que numero de estante esta?: ");
    scanf("%d", &estantenum);
    printf("En que edificio esta?: ");
    scanf("%s", edificio);
    printf("En que piso? ");
    scanf("%d", &piso);
    fclose(guardar);

}

void quitarLibro(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char titulo[100];

    printf("Inserte el titulo del libro que desea quitar:");
    scanf("%s", &titulo);

    fclose(guardar);

}

void agregarSede(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char sede[100];
    printf("Ingrese el nombre de la sede que desea agregar: ");
    scanf("%s", &sede);
    fclose(guardar);
}

void quitarSede(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char sede[100];
    printf("Ingrese el nombre de la sede que desea quitar: ");
    scanf("%s", &sede);
    if ((sede)>0){ //suma(sede)>0    *La suma de veces que se repite sede debe ser igual a 0 para que no tenga libros asignados
        printf("La sede que desea quitar no se puede eliminar porque tiene libros asignados");
    }else{printf("La sede se ha eliminado");
    }
    fclose(guardar);
}

void agregarSecciones(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char seccion[100];
    printf("Ingrese el nombre de la seccion que desea agregar: ");
    scanf("%s", &seccion);
    fclose(guardar);
}

void quitarSecciones(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char seccion[100];
    printf("Ingrese el nombre de la seccion que desea quitar: ");
    scanf("%s", &seccion);
    if ((seccion)>0){ //suma(seccion)>0    *La suma de veces que se repite seccion debe ser igual a 0 para que no tenga libros asignados
        printf("La seccion que desea quitar no se puede eliminar porque tiene libros asignados");
    }else{printf("La seccion se ha eliminado");
    }
    fclose(guardar);
}

void agregarPisos(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char seccion[100];
    printf("Ingrese el nombre de la seccion que desea agregar: ");
    scanf("%s", &seccion);
    fclose(guardar);
}

void quitarPisos(){
    FILE *guardar;
    guardar=fopen("inventario.csv","a");
    char seccion[100];
    printf("Ingrese el nombre del piso que desea quitar: ");
    scanf("%s", &seccion);
    if ((seccion)>0){ //suma(seccion)>0    *La suma de veces que se repite seccion debe ser igual a 0 para que no tenga libros asignados
        printf("El piso que desea quitar no se puede eliminar porque tiene libros asignados");
    }else{printf("El piso se ha eliminado");
    }
    fclose(guardar);
}

void showContentsAsStruct(FILE *pFile) {
    Libro *libros;
    //paso el contenido del file a un array de personas
    libros = getLibros(pFile);

    //accedo a la cantidad de registro que lei
    for (int i = 0; i < registryCount; ++i) {
        //puedo solo imprimir su mail por ejemplo
        printf("titulo: %s \nautor: %s \nanio: %s \nestante_numero: %s\nestante_seccion: %s \npiso: %s \nedificio: %s \nsede: %s \n", libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estante_numero, libros[i].estante_seccion, libros[i].piso, libros[i].edificio, libros[i].sede);
    }
}

int main(int argc, char *argv[] ){

    FILE *fp = openingFile(argv[1]);

    showContentsAsStruct(fp);
    showTitles();
    showMenu();

    return 0;

}
