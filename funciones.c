#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funciones.h"

//--------FUNCION BURBUJA---------
/**
 * @brief Función que representa el algoritmo burbuja
 * @param pRes polinomio resultante a ordenar
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void burbuja(POLINOMIO pRes)
{
    MONOMIO aux;
    for (int i = 0; i < sizeof(pRes.nTerm); i++)
    {
        // Con -i ya no evaluamos números que ya están acomodados
        // El -1 es para que, a la hora de hacer las comparaciones, no llegue al ultimo y compare con el siguiente y se de cuenta que no hay siguiente
        for (int j = 0; j < sizeof(pRes.nTerm) - i - 1; j++)
        {
            if (pRes.term[j].exp < pRes.term[j + 1].exp)
            {
                // Intercambio de exponentes para ordenar el polinomio drecientemente
                aux = pRes.term[j];
                pRes.term[j] = pRes.term[j + 1];
                pRes.term[j + 1] = aux;
            }
        }
    }
}

//--------FUNCIONES RELACIONADAS CON OPERACIONES ENTRE POLINOMIOS---------

/**
 * @brief Función que realiza la división de un polinomio entre un binomio mediante el método de división sintética
 * @param p1 polinomio ingresado
 * @param bino binomio ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Juárez Herrera Erick Adrián
 */


POLINOMIO div_binomio(POLINOMIO p1)
{
    POLINOMIO bino;
    POLINOMIO pRes;
    int k,n1;
    int i = 0;
    

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees dividir:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    k=p1.nTerm;

    //Reserva de memoria
    pRes.term = (MONOMIO *)malloc(sizeof(MONOMIO) * p.nTerm);
    bino.term = (MONOMIO *)malloc(2 * sizeof(MONOMIO));

    //Lectura del binomio
    for(int j=0; j<2; j++)
    {
        printf("Ingrese el termino %d del binomio divisor: \n", j+1);
        scanf("%f\t%d", &bino.term[j].coef, &bino.term[j].exp);
    }

    //EN DIV SINTÉTICA UTILIZAMOS SOLAMENTE LOS COEFICIENTES

    bino.term[1].coef = bino.term[1].coef * -1;
    pRes.term[0].coef = p.term[0].coef;       // Primer valor del polinomio resultante
    pRes.term[0].exp = p.term[0].exp - 1; // Exponente del primer valor del polinomio resultante

    // División sintética
    for (i=1; i < p1.nTerm; i++)
    {
        pRes.term[i].coef = (bino.term[1].coef * pRes.term[i - 1].coef) + p.term[i].coef;
        pRes.term[i].exp = p.term[i].exp - 1;
    }
    pRes.grado = p.term[0].exp - bino.term[0].exp;
    pRes.nTerm = i;
    pRes.term = (MONOMIO *)realloc(pRes.term, (i) * (sizeof(MONOMIO)));

    
    printf("El grado del polinomio resultante es: %d\n",pRes.grado);

    //Imprimimos el polinomio
    for(int g=0; g<(k-1);g++)
    {
        printf("%.3f\t%d\t", pRes.term[g].coef, pRes.term[g].exp);
    }

    //Residuo
    printf("\nEl residuo del polinomio es: %f\t0", pRes.term[k-1].coef);

    if(pRes.term[k-1].coef == 0)
    {
        printf("\nAdemás, x = %f\t%d es una raiz del polinomio.\n",bino.term[1].coef , bino.term[1].exp);
        //bin.term[1].coef no se multiplica por -1 porque eso ya se hizo desde antes
    }
    return pRes;
}

/**
 * @brief Función que realiza la suma entre dos polinomios
 * @param p1 primer polinomio ingresado
 * @param p2 segundo polinomio ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Jasso Vázquez Sara, Juárez Herrera Erick Adrián, Pérez Ortiz Sofia
 */
POLINOMIO suma(POLINOMIO p1)
{
    POLINOMIO pRes;
    POLINOMIO p2;
    MONOMIO t, t2;
    int i = 0, j = 0, k = 0, h = 0;
    int n1;

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees sumar:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    printf("Ingrese el grado del polinomio 2:\n");
    scanf("%d", &p2.grado);
    printf("Ingrese el numero de terminos del polinomio 2:\n");
    scanf("%d", &p2.nTerm);

    p2.term = (MONOMIO *)malloc(p2.nTerm * sizeof(MONOMIO));
    pRes.term = (MONOMIO *)malloc((p1.nTerm + p2.nTerm) * sizeof(MONOMIO));

    for (int o = 0; o < p2.nTerm; o++)
    {
        printf("Ingrese el termino %d del polinomio 2:\n", o+1);
        scanf("%f\t%d", &p2.term[o].coef, &p2.term[o].exp);
    }

    while (i < p1.nTerm)
    {
        while (j < p2.nTerm)
        {
            t = p1.term[i];
            t2 = p2.term[j];
            if (t.exp == t2.exp)
            {
                pRes.term[k].coef = t.coef + t2.coef;
                pRes.term[k].exp = t.exp;
                k++;
                i++;
                j++;
            }
            else if (t.exp > t2.exp)
            {
                pRes.term[k].coef = t.coef;
                pRes.term[k].exp = t.exp;
                k++;
                i++;
            }
            else if (t.exp < t2.exp)
            {
                pRes.term[k].coef = t2.coef;
                pRes.term[k].exp = t2.exp;
                k++;
                j++;
            }
        }
    }

    pRes.nTerm = k;
    pRes.term = (MONOMIO*)realloc(pRes.term, (k)*sizeof(MONOMIO));
    
    printf("Resultados:\n");
    if (p1.grado > p2.grado)
    {
        pRes.grado = p1.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    }
    else if(p1.grado < p2.grado)
    {
        pRes.grado = p2.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    } else{
        pRes.grado = p1.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    }

    //Imprimir resultado
    for(; h<k; h++)
    {
        printf("%.3f\t%d\t", pRes.term[h].coef, pRes.term[h].exp);
    }
    return pRes;
}

/**
 * @brief Función que realiza la resta entre dos polinomios
 * @param p1 primer polinomio ingresado
 * @param p2 segundo polinomio ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Jasso Vázquez Sara, Juárez Herrera Erick Adrián, Pérez Ortiz Sofia
 */
POLINOMIO resta(POLINOMIO p1)
{
    POLINOMIO pRes;
    POLINOMIO p2;
    MONOMIO t, t2;
    int i = 0, j = 0, k = 0, h = 0;
    int n1;

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees restar:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    printf("Ingrese el grado del polinomio 2:\n");
    scanf("%d", &p2.grado);
    printf("Ingrese el numero de terminos del polinomio 2:\n");
    scanf("%d", &p2.nTerm);

    p2.term = (MONOMIO *)malloc(p2.nTerm * sizeof(MONOMIO));
    pRes.term = (MONOMIO *)malloc((p1.nTerm + p2.nTerm) * sizeof(MONOMIO));

    for (int o = 0; o < p2.nTerm; o++)
    {
        printf("Ingrese el termino %d del polinomio 2:\n", o+1);
        scanf("%f\t%d", &p2.term[o].coef, &p2.term[o].exp);
    }

    while (i < p1.nTerm)
    {
        while (j < p2.nTerm)
        {
            t = p1.term[i];
            t2 = p2.term[j];
            if (t.exp == t2.exp)
            {
                pRes.term[k].coef = t.coef - t2.coef;
                pRes.term[k].exp = t.exp;
                k++;
                i++;
                j++;
            }
            else if (t.exp > t2.exp)
            {
                pRes.term[k].coef = t.coef;
                pRes.term[k].exp = t.exp;
                k++;
                i++;
            }
            else if (t.exp < t2.exp)
            {
                pRes.term[k].coef = t2.coef;
                pRes.term[k].exp = t2.exp;
                k++;
                j++;
            }
        }
    }

    pRes.nTerm = k;
    pRes.term = (MONOMIO*)realloc(pRes.term, (k)*sizeof(MONOMIO));
    
    printf("Resultados:\n");
    if (p1.grado > p2.grado)
    {
        pRes.grado = p1.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    }
    else if(p1.grado < p2.grado)
    {
        pRes.grado = p2.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    } else{
        pRes.grado = p1.grado;
        printf("Grado del polinomio resultante: %d\n", pRes.grado);
    }

    //Imprimir resultado
    for(; h<k; h++)
    {
        printf("%.3f\t%d\t", pRes.term[h].coef, pRes.term[h].exp);
    }
    return pRes;
}

/**
 * @brief Función que realiza la multiplicación entre un polinomio ingresado y un escalar ingresado
 * @param p1 polinomio ingresado
 * @param n escalar ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Juárez Herrera Erick Adrián
 */
POLINOMIO multEsc(POLINOMIO p1)
{
    POLINOMIO pRes;
    int k,n1;
    float escalar=0;

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees multiplicar:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    k = p1.nTerm;
    pRes.term =  (MONOMIO*)malloc(k*sizeof(MONOMIO));//Tiene el mismo tamaño que el polinomio ingresado

    printf("Ingresa el escalar a multiplicar:\n");
    scanf("%f",&escalar);

    for (int i = 0; i < p.nTerm; i++)
    {
        pRes.term[i].coef = p1.term[i].coef * escalar;
        pRes.term[i].exp = p1.term[i].exp;
    }
    
    pRes.grado = p1.grado;
    pRes.nTerm = k;
    pRes.term = (MONOMIO*)realloc(pRes.term, (k)*sizeof(MONOMIO));
    printf("Grado del polinomio resultante: %d\n", pRes.grado);
    //Imprimir resultado
    for(int j=0;j<k;j++)
    {
        printf("%.3f\t%d\t", pRes.term[j].coef, pRes.term[j].exp);
    }
    return pRes;
}

/**
 * @brief Función que realiza la multiplicación entre dos polinomios ingresados
 * @param p1 primer polinomio ingresado
 * @param p2 segundo polinomio ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Juárez Herrera Erick Adrián
 */
POLINOMIO mult(POLINOMIO p1)
{
    POLINOMIO pRes, p2;
    int n1;
    int h=0;

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees multiplicar:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    printf("Ingrese el grado del polinomio 2:\n");
    scanf("%d", &p2.grado);
    printf("Ingrese el numero de terminos del polinomio 2:\n");
    scanf("%d", &p2.nTerm);

    p2.term = (MONOMIO *)malloc(p2.nTerm * sizeof(MONOMIO));
    pRes.term =  (MONOMIO*)malloc((p1.nTerm + p2.nTerm)*sizeof(MONOMIO));

    for (int o = 0; o < p2.nTerm; o++)
    {
        printf("Ingrese el termino %d del polinomio 2:\n", o+1);
        scanf("%f\t%d", &p2.term[o].coef, &p2.term[o].exp);
    }

    if (p1.nTerm > p2.nTerm)
    {
        for (int i = 0; i < p1.nTerm; i++)
        {
            for (int j = 0; j < p2.nTerm; j++)
            {
                pRes.term[i].coef = p1.term[i].coef * p2.term[j].coef;
                pRes.term[i].exp = p1.term[i].exp + p2.term[j].exp;
            }
        }
    }
    else
    {
        if (p1.nTerm < p2.nTerm)
        {
            for (int i = 0; i < p1.nTerm; i++)
            {
                for (int j = 0; j < p2.nTerm; j++)
                {
                    pRes.term[i].coef = p2.term[i].coef * p1.term[j].coef;
                    pRes.term[i].exp = p2.term[i].exp + p1.term[j].exp;
                }
            }
        }
        else
        {
            for (int i = 0; i < p1.nTerm || i < p2.nTerm; i++)
            {
                pRes.term[i].coef = p1.term[i].coef * p2.term[i].coef;
                pRes.term[i].exp = p1.term[i].exp + p2.term[i].exp;
            }
        }
    }
    pRes.nTerm = p1.nTerm + p2.nTerm;
    pRes.term = (MONOMIO*)realloc(pRes.term, (pRes.nTerm)*sizeof(MONOMIO));
    
    printf("Resultados:\n");

    //Imprime el grado 
    pRes.grado = p1.term[0].exp + p2.term[0].exp;
    printf("Grado del polinomio resultante: %d\n", pRes.grado);

    //Imprimir resultado
    for(; h<pRes.nTerm; h++)
    {
        printf("%.3f\t%d\t", pRes.term[h].coef, pRes.term[h].exp);
    }
    return pRes;
}

/**
 * @brief Función que elabora la división de un polinomio entre un monomio
 * @param p1 polinomio ingresado
 * @param p2 monomio ingresado
 * @return POLINOMIO lo que retorna es un apuntador de tipo POLINOMIO con el polinomio resultante
 * @programador: Juárez Herrera Erick Adrián
 */

POLINOMIO divMon(POLINOMIO p1)
{
    POLINOMIO pRes;
    int i = 0;
    MONOMIO aux;
    MONOMIO p2;
    int  k,n1;

    printf("Existen en memoria %d polinomios\n", countMemory);
    printf("Selecciona el polinomio que desees dividir:\n");
    scanf("%d",&n1);
    p1 = dynMemory[n1];

    k = p1.nTerm;

    pRes.term =  (MONOMIO*)malloc(k*sizeof(MONOMIO));//Tiene el mismo tamaño que el polinomio ingresado
    
    printf("Ingresa el monomio divisor: \n");
    scanf("%f\t%d", &p2.coef, &p2.exp);

    for (int j=0; j < k; j++)
    {
        pRes.term[j].coef = p1.term[j].coef / p2.coef;
        pRes.term[j].exp = p1.term[j].exp - p2.exp;
    }
    
    pRes.nTerm = k;
    pRes.term = (MONOMIO*)realloc(pRes.term, (k)*sizeof(MONOMIO));
    pRes.grado = p1.term[0].exp-p2.exp;
    printf("El grado del polinomioo resultante es: %d\n",pRes.grado);
    //Tiene el mismo numero de terminos que p1 el pRes
    //Imprimir resultado
    for(int g=0; g<k;g++)
    {
        printf("%.3f\t%d\t", pRes.term[g].coef, pRes.term[g].exp);
    }
    return pRes;
}

//--------FUNCIONES RELACIONADAS CON LOS ARCHIVOS---------

/**
 * @brief Función que abre el contenido de un archivo en modo lectura (r)
 * @param filename Nombre del archivo
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void open_in_file(char *filename)
{
    in_file = fopen(filename, "r");
    if (!in_file)
    {
        printf("No tienes permisos suficientes para abrir %s\n", filename);
    }
}

/**
 * @brief Función que abre el contenido de un archivo en modo lectura/escritura (r+)
 * @param filename Nombre del archivo
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void open_out_file(char *filename)
{
    out_file = fopen(filename, "r+");
    if (!out_file)
    {
        printf("No tienes permisos para abrir %s\n", filename);
    }
}

/**
 * @brief Función que lee polinomios desde un archivo
 * @param in_file Recibe un archivo
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
POLINOMIO fileRead(FILE *in_file)//Porbar que reciba el nombre del archivo
{
    char *filename;
    char c[2];
    c[1]='\0';
    char *str = (char*)malloc(sizeof(char));
    POLINOMIO salida;

    
    in_file = fopen(filename, "r");
    if (!in_file)
    {
        printf("No tienes permisos suficientes para abrir %s\n", filename);
    }

    c[0] = fgetc(in_file);
    do
    {
        strcat(str,c);
        c[0] = fgetc(in_file);
    } while (c[0] != '\t');

    salida.nTerm = atoi(str);
    salida.term = (MONOMIO*)malloc(salida.nTerm*sizeof(MONOMIO));

    c[0] = fgetc(in_file);
    do
    {
        //Lectura del coeficiente y exponente
        strcpy(str, "");
        c[0] = fgetc(in_file);
        for(int i=0; i<salida.nTerm; i++)
        {
            fscanf(in_file,"%f\t%d", &salida.term[i].coef, &salida.term[i].exp);
        }
    }while(c[0] != '\n');
    fclose(filename);
    return salida;
}


//--------FUNCIONES RELACIONADAS CON LA MEMORIA---------

/**
 * @brief Función que reserva la memoria del programa tras iniciarlo (mínimo para 10 polinomios)
 * @return nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void init_memory()
{
    dynMemory = NULL;
    dynMemory = (POLINOMIO *)malloc(10 * sizeof(POLINOMIO));
}

/**
 * @brief Función que lee polinomios desde teclado
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void polTeclado()//void polTeclado()
{
    printf("Ingrese el grado del polinomio:\n");
    scanf("%d", &p.grado);
    printf("Ingrese el numero de terminos del polinomio:\n");
    scanf("%d", &p.nTerm);
    p.term = (MONOMIO *)malloc(p.nTerm * sizeof(MONOMIO));
    for (int i = 0; i < p.nTerm; i++)
    {
        printf("Ingrese el termino %d del polinomio:\n", i+1);
        scanf("%f\t%d", &p.term[i].coef, &p.term[i].exp);
    }
}

/**
 * @brief Función que va almacenando los polinomios ingresados en la memoria
 * @param p Polinomio ingresado
 * @return Nada, debido a que es una función de tipo void
 * @programador: Juárez Herrera Erick Adrián
 */
void memoryWrite()//void memoryWrite(POLINOMIO p) SI TIENE QUE LEER UN POLINOMIO
{
    countMemory++;
    dynMemory = (POLINOMIO*)realloc(dynMemory, (countMemory+1)*sizeof(POLINOMIO));
    dynMemory[countMemory - 1] = p;
}