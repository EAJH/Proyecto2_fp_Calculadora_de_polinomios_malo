#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "funciones.h"

//--------PROTOTIPOS--------
void menu();

int main(int argc, char **argv)
{
    //ARGV0   ARGV1   ARGV2    ARGV3   ARGV4
// ./polinomio -in entrada.txt -out salida.txt
// ./polinomio -out salida.txt -in entrada.txt
// ./polinomio -in entrada.txt
// ./polinomio -out salida.txt
// ./polinomio
    if(argc==3)
    {
        if(strcmp(argv[1], "-in")==0)
        {
            open_in_file(argv[2]);
        }else if(strcmp(argv[1], "-out")==0){
            open_out_file(argv[2]);
        }
    }else if(argc==5){
        if(strcmp(argv[1], "-in")==0){
            open_in_file(argv[2]);
        }else if(strcmp(argv[1], "-out")==0){
            open_out_file(argv[2]);
        }
    }else if(strcmp(argv[3], "-in")==0){
        open_in_file(argv[4]);
    }else if(strcmp(argv[3], "-out")==0){
        open_out_file(argv[4]);
    } 

    int op;
    int n1;
    int n2;
    float escalar;
    POLINOMIO p, p1, p2;
    MONOMIO m;
    POLINOMIO bino;
    //Los términos se deben de ingresar en orden decreciente respecto al exponente
    init_memory();
    while(true)
    {
        printf("\n---------------PROYECTO 2. CALCULADORA DE POLINOMIOS---------------\n");
        printf("\t\t\tUniversidad Nacional Autonoma de Mexico (UNAM)\n");
        printf("\t\t\tFacultad de Ingenieria\n");
        printf("\t\t\tMateria: Fundamentos de programacion (1122)\n");
        printf("\t\t\tProfesor: Mercado Martinez Adrian Ulises\n");
        printf("\t\t\tGrupo: 07\n");
        printf("\t\tBrigada 11\n");
        printf("Integrantes de la brigada:\n");
        printf("\t-Jasso Vazquez Sara.\n");
        printf("\t*Numero de lista: 28.\n");
        printf("\t-Juarez Herrera Erick Adrian.\n");
        printf("\t*Numero de lista: 30.\n");
        printf("\t-Perez Ortiz Sofia.\n");
        printf("\t*Numero de lista: 38.\n");
        printf("\t\t\tSemestre 2022-1\n");
        menu();
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                polTeclado();
                memoryWrite();
            break;
            case 2:
                fileRead(argv[2]);
                memoryWrite();
            break;
            case 3:
                p = suma(p1);
                memoryWrite();
            break;
            case 4:
                p = resta(p1);
                memoryWrite();
            break;
            case 5:
                p = multEsc(p1);
                memoryWrite();
            break;
            case 6:
                p = mult(p1);
                memoryWrite();
            break;
            case 7:
                p = divMon(p1);
                memoryWrite();
            break;
            case 8:
                p = div_binomio(p1);
                memoryWrite();  
            break;
            case 9:
                printf("Existen en memoria %d polinomios\n", countMemory);
                printf("Los polinomios son: \n");
                for(int i = 0; i<=countMemory; i++)
                {
                    printf("%.3f\t%d\t", dynMemory->term[i].coef, dynMemory->term[i].exp);
                }
            break;
            case 10:
            break;
            case 11:
                printf("Para poder consultar el manual de usuario, consulte el siguiente link: \n");
                printf("https://drive.google.com/file/d/1ZcxIm1vRak05WfPz-FXs8ATEn3fql5SM/view?usp=sharing");
            break;
            case 12:
                exit(EXIT_SUCCESS);
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("\t\nCALCULADORA DE POLINOMIOS\t\n");
    printf("Selecciona una opcion a ejecutar: \n");
    printf("1. Leer polinomio de teclado.\n");
    printf("2. Leer polinomio(s) desde un archivo.\n");
    printf("3. Suma de polinomios.\n");
    printf("4. Resta de polinomios.\n");
    printf("5. Multiplicacion de un polinomio por un escalar.\n");
    printf("6. Multiplicacion de polinomios\n");
    printf("7. Division de un polinomio entre un monomio.\n");
    printf("8. Division de polinomio entre un binomio.\n");
    printf("9. Escribir en pantalla.\n");
    printf("10. Escribir a un archivo.\n");
    printf("11. Manual de usuario.\n");
    printf("12. Salir.\n");
}