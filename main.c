#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    int id[10];
    char titulos[10][100];
    char autores[10][50];
    int anio[10];
    int estado[10];
    int contL = 0, opc, opc2;

    do
    {
        printf("Seleccione una opcion:\n");
        printf("1.Registrar libro\n");
        printf("2.Mostrar libros\n");
        printf("3.Buscar libro\n");
        printf("4.Prestar/Devolver libro\n");
        printf("5.Eliminar Libro\n");
        printf(">> ");
        opc = validarFloatRango(1,5);
        switch (opc)
        {
        case 1:
            registrarLibro(id,titulos,autores,anio,estado,&contL);
            break;
        case 2:
            mostrarLibros(id,titulos,autores,anio,estado,0,contL);
            break;
        case 3:
            buscarLibro(id,titulos,autores,anio,estado,contL);
            break;
        case 4:
            cambiarEstado(id,titulos,autores,anio,estado,contL);
            break;
        default:
            break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        opc2 = validarFloatRango(1,2);
    } while (opc2==1);
    

    return 0;
}