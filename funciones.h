float validarFloatRango(float a, float b);
void leercadena(char *cadena, int n);
void registrarLibro(int *id, char titulos[][100], char autores[][50], int *anio, int *estado, int *contL);
void mostrarLibros(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int n, int contL);
int buscarLibro(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int contL);
void cambiarEstado(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int contL);