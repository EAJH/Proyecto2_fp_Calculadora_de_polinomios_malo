#ifndef __POLINOMIO_H__
#define __POLINOMIO_H__
#include<stdlib.h>
#include<stdio.h>
//-----ESTRUCTURAS-----
struct _monomio{
    float coef;
    int exp;
};
typedef struct _monomio MONOMIO;

struct _polinomio{
    int grado;
    int nTerm;
    MONOMIO *term;
};
typedef struct _polinomio POLINOMIO;


//-----VARIABLES-----
POLINOMIO *memory;
POLINOMIO *mem;
POLINOMIO *dynMemory;
FILE *in_file;
FILE *out_file;
int n;
int countMemory;
POLINOMIO p;
int numeroPolFile;


//-----PROTOTIPOS-----
POLINOMIO div_binomio(POLINOMIO p1);
POLINOMIO suma(POLINOMIO p1);
POLINOMIO resta(POLINOMIO p1);
POLINOMIO mult(POLINOMIO p1);
POLINOMIO multEsc(POLINOMIO p1);
POLINOMIO divMon(POLINOMIO p1);
void burbuja(POLINOMIO pRes);

void polTeclado();
void memoryWrite();
void init_memory();

    //-----ARCHIVOS-----
    void open_in_file(char *filename);
    void open_out_file(char *filename);
    POLINOMIO fileRead(FILE *in_file);


#endif