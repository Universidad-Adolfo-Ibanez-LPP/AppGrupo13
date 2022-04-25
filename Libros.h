struct Libros {
    int id;
    char *titulo;
    char *autor;
    char *anio;
    char *estante_numero;
    char *estante_seccion;
    char *piso;
    char *edificio;
    char *sede;

};


typedef struct Libros Libro;
Libro* getLibros(FILE *fp);
extern int registryCount;