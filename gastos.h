#ifndef GASTOS_H
#define GASTOS_H

#define MAX_GASTOS 100
#define MAX_TEXTO 50

// Estructura que representa un gasto
typedef struct {
    char categoria[MAX_TEXTO];
    float monto;
    char descripcion[MAX_TEXTO];
} Gasto;

// Prototipos de funciones
void mostrarMenu();
void agregarGasto(Gasto gastos[], int *numGastos);
void mostrarGastos(Gasto gastos[], int numGastos);
void buscarPorCategoria(Gasto gastos[], int numGastos);
void ordenarPorMonto(Gasto gastos[], int numGastos);
void totalPorCategoria(Gasto gastos[], int numGastos);

#endif
