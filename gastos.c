#include <stdio.h>
#include <string.h>
#include "gastos.h"

// Muestra el menú principal
void mostrarMenu() {
    printf("=====================================\n");
    printf("   CONTROL DE GASTOS PERSONALES\n");
    printf("=====================================\n");
    printf("1. Agregar gasto\n");
    printf("2. Mostrar todos los gastos\n");
    printf("3. Buscar gastos por categoría\n");
    printf("4. Ordenar gastos por monto y mostrar\n");
    printf("5. Mostrar total gastado por categoría\n");
    printf("6. Salir\n");
    printf("=====================================\n");
}

// Añade un gasto al array
void agregarGasto(Gasto gastos[], int *numGastos) {
    if (*numGastos >= MAX_GASTOS) {
        printf("No se pueden agregar más gastos (límite alcanzado).\n");
        return;
    }

    Gasto nuevo;
    
    printf("Introduce la categoría del gasto (ej: comida, transporte): ");
    fgets(nuevo.categoria, MAX_TEXTO, stdin);
    nuevo.categoria[strcspn(nuevo.categoria, "\n")] = '\0'; // quitar salto

    printf("Introduce el monto del gasto: ");
    scanf("%f", &nuevo.monto);
    getchar(); // limpiar buffer

    // Validación simple de monto
    if (nuevo.monto <= 0) {
        printf("El monto debe ser mayor que 0. Gasto no agregado.\n");
        return;
    }

    printf("Introduce una breve descripción del gasto: ");
    fgets(nuevo.descripcion, MAX_TEXTO, stdin);
    nuevo.descripcion[strcspn(nuevo.descripcion, "\n")] = '\0';

    gastos[*numGastos] = nuevo;
    (*numGastos)++;

    printf("Gasto agregado correctamente.\n");
}

// Muestra todos los gastos
void mostrarGastos(Gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        printf("No hay gastos registrados.\n");
        return;
    }

    printf("Listado de gastos:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < numGastos; i++) {
        printf("Gasto %d:\n", i + 1);
        printf("  Categoría   : %s\n", gastos[i].categoria);
        printf("  Monto       : %.2f\n", gastos[i].monto);
        printf("  Descripción : %s\n", gastos[i].descripcion);
        printf("-------------------------------------\n");
    }
}

// Busca gastos por categoría (búsqueda lineal)
void buscarPorCategoria(Gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        printf("No hay gastos registrados.\n");
        return;
    }

    char categoriaBuscada[MAX_TEXTO];
    int encontrado = 0;

    printf("Introduce la categoría a buscar: ");
    fgets(categoriaBuscada, MAX_TEXTO, stdin);
    categoriaBuscada[strcspn(categoriaBuscada, "\n")] = '\0';

    printf("Resultados de la búsqueda para la categoría '%s':\n", categoriaBuscada);
    printf("-------------------------------------\n");
    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].categoria, categoriaBuscada) == 0) {
            printf("Gasto %d:\n", i + 1);
            printf("  Categoría   : %s\n", gastos[i].categoria);
            printf("  Monto       : %.2f\n", gastos[i].monto);
            printf("  Descripción : %s\n", gastos[i].descripcion);
            printf("-------------------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron gastos en esa categoría.\n");
    }
}

// Ordena los gastos por monto usando burbuja (algoritmo de ordenación)
// y muestra el resultado
void ordenarPorMonto(Gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        printf("No hay gastos registrados para ordenar.\n");
        return;
    }
    if (numGastos == 1) {
        printf("Solo hay un gasto. No es necesario ordenar.\n");
        mostrarGastos(gastos, numGastos);
        return;
    }

    int i, j;
    for (i = 0; i < numGastos - 1; i++) {
        for (j = 0; j < numGastos - 1 - i; j++) {
            if (gastos[j].monto > gastos[j + 1].monto) {
                Gasto temp = gastos[j];
                gastos[j] = gastos[j + 1];
                gastos[j + 1] = temp;
            }
        }
    }

    printf("Gastos ordenados por monto (ascendente):\n");
    printf("-------------------------------------\n");
    mostrarGastos(gastos, numGastos);
}

// Muestra el total gastado en una categoría concreta
void totalPorCategoria(Gasto gastos[], int numGastos) {
    if (numGastos == 0) {
        printf("No hay gastos registrados.\n");
        return;
    }

    char categoriaBuscada[MAX_TEXTO];
    float total = 0.0;
    int encontrado = 0;

    printf("Introduce la categoría para calcular el total: ");
    fgets(categoriaBuscada, MAX_TEXTO, stdin);
    categoriaBuscada[strcspn(categoriaBuscada, "\n")] = '\0';

    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].categoria, categoriaBuscada) == 0) {
            total += gastos[i].monto;
            encontrado = 1;
        }
    }

    if (encontrado) {
        printf("Total gastado en la categoría '%s': %.2f\n", categoriaBuscada, total);
    } else {
        printf("No se encontraron gastos en esa categoría.\n");
    }
}
