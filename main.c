#include <stdio.h>
#include "gastos.h"

int main() {
    Gasto gastos[MAX_GASTOS];
    int numGastos = 0;
    int opcion;
    int salir = 0;

    // Bucle principal del programa
    while (!salir) {
        mostrarMenu();
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                agregarGasto(gastos, &numGastos);
                break;
            case 2:
                mostrarGastos(gastos, numGastos);
                break;
            case 3:
                buscarPorCategoria(gastos, numGastos);
                break;
            case 4:
                ordenarPorMonto(gastos, numGastos);
                break;
            case 5:
                totalPorCategoria(gastos, numGastos);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                salir = 1;
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
