#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num;
    int val;
    do
    {
        val = scanf("%f",&num);
        while((getchar())!='\n');
        if (num < a || num > b || val != 1)
        {
            printf("Error: El valor ingresado es incorrecto\n");
        }
        
    } while (num < a || num > b || val != 1);
    return num;
}

void leercadena(char *cadena, int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void registrarLibro(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int *contL){
    printf("Ingrese los datos del libro %d:\n", *contL);
    id[*contL] = *contL;
    printf("Titulo: ");
    leercadena(titulos[*contL],100);
    printf("Autor: ");
    leercadena(autores[*contL],50);
    printf("Anio: ");
    anio[*contL] = validarFloatRango(1950,2026);
    estado[*contL] = 0;
    (*contL)++;
}

void mostrarLibros(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int n, int contL){
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = n; i < contL; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",id[i],
                                                titulos[i],
                                                autores[i],
                                                anio[i],
                                                (estado[i] == 0 ? "Disponible" : "Prestado"));
    }
}

void buscarLibro(int *id, char titulos[][100], 
                    char autores[][50], int *anio, int *estado, int contL){

    printf("Seleccione el metodo de busqueda 1.ID/2.Titulo: ");
    int opc = validarFloatRango(1,2);
    switch (opc)
    {
    case 1:
        printf("Ingrese un numero del 0-%d: ",contL-1);
        int iden = validarFloatRango(0,contL-1);
        mostrarLibros(id,titulos,autores,anio,estado,iden,iden+1);
        break;
    case 2:
        printf("Ingrese el titulo del libro: ");
        char titulo[100];
        leercadena(titulo,100);
        for (int i = 0; i < contL; i++)
        {
            if(strcasecmp(titulo,titulos[i])==0){
                mostrarLibros(id,titulos,autores,anio,estado,i,i+1);
            }
        }
        break;
    default:
        break;
    }

}