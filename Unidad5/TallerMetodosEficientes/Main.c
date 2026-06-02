/*
Autores:
Ronald Smith Angulo Arboleda

Taller Unidad 5
Métodos de Ordenamiento Eficientes y Búsqueda Binaria
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30
#define PESO_MIN 100
#define PESO_MAX 1000


int pesos[MAX_CONTENEDORES];
int ordenado = 0;

void limpiarBuffer(void);
void mostrarMenu(void);
int registrarPesos(int *cantidad);
int generarPesosAleatorios(int *cantidad);
void mostrarContenedores(int cantidad);
void hundir(int i, int cantidad);
void ordenarMetodo1(int cantidad);
void fusionar(int izq, int mid, int der);
void ordenarMerge(int izq, int der);
void ordenarMetodo2(int cantidad);
int particion(int bajo, int alto);
void ordenarMetodo3(int bajo, int alto);
int busquedaBinaria(int cantidad, int objetivo);

int main(void)
{
    int cantidad = 0;
    int opcion;

    srand((unsigned int)time(NULL));

    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) {
            limpiarBuffer();
            opcion = 0;
        } else {
            limpiarBuffer();
        }

        switch (opcion) {
        case 1:
            if (registrarPesos(&cantidad)) {
                ordenado = 0;
            }
            break;
        case 2:
            if (generarPesosAleatorios(&cantidad)) {
                ordenado = 0;
            }
            break;
        case 3:
            mostrarContenedores(cantidad);
            break;
        case 4:
            if (cantidad > 0) {
                ordenarMetodo1(cantidad);
                ordenado = 1;
                printf("Contenedores ordenados con Metodo 1.\n");
            } else {
                printf("No hay contenedores para ordenar.\n");
            }
            break;
        case 5:
            if (cantidad > 0) {
                ordenarMetodo2(cantidad);
                ordenado = 1;
                printf("Contenedores ordenados con Metodo 2.\n");
            } else {
                printf("No hay contenedores para ordenar.\n");
            }
            break;
        case 6:
            if (cantidad > 0) {
                ordenarMetodo3(0, cantidad - 1);
                ordenado = 1;
                printf("Contenedores ordenados con Metodo 3.\n");
            } else {
                printf("No hay contenedores para ordenar.\n");
            }
            break;
        case 7:
            if (cantidad == 0) {
                printf("No hay contenedores registrados para buscar.\n");
            } else if (!ordenado) {
                printf("Debe ordenar los contenedores antes de usar la busqueda binaria.\n");
            } else {
                int objetivo;
                printf("Ingrese el peso a buscar: ");
                if (scanf("%d", &objetivo) != 1) {
                    limpiarBuffer();
                    printf("Entrada invalida. Busqueda cancelada.\n");
                } else {
                    limpiarBuffer();
                    int indice = busquedaBinaria(cantidad, objetivo);
                    if (indice >= 0) {
                        printf("Contenedor encontrado en la posicion %d con peso %d.\n", indice + 1, pesos[indice]);
                    } else {
                        printf("No se encontro un contenedor con ese peso.\n");
                    }
                }
            }
            break;
        case 8:
            printf("Saliendo del sistema.\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
            break;
        }

        if (opcion != 8) {
            printf("\n");
        }
    } while (opcion != 8);

    return 0;
}

void mostrarMenu(void)
{
    printf("=========SISTEMA DE ORGANIZACION DE CONTENEDORES MUELLE DE CARGA=======\n");
    printf("1. Registrar peso de contenedores manualmente\n");
    printf("2. Generar pesos aleatorios de contenedores\n");
    printf("3. Mostrar contenedores registrados\n");
    printf("4. Ordenar contenedores Metodo 1 (Quick sort)\n");
    printf("5. Ordenar contenedores Metodo 2 (Merge sort)\n");
    printf("6. Ordenar contenedores Metodo 3 (Heap sort)\n");
    printf("7. Buscar contenedor\n");
    printf("8. Salir\n");
    printf("========================================\n");
    printf("Seleccione una opcion: ");
}

int registrarPesos(int *cantidad)
{
    int n;
    printf("Cuantos contenedores desea registrar (maximo %d)? ", MAX_CONTENEDORES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CONTENEDORES) {
        limpiarBuffer();
        printf("Cantidad invalida. Operacion cancelada.\n");
        return 0;
    }
    limpiarBuffer();

    for (int i = 0; i < n; i++) {
        printf("Peso del contenedor %d: ", i + 1);
        if (scanf("%d", &pesos[i]) != 1) {
            limpiarBuffer();
            printf("Entrada invalida. Operacion cancelada.\n");
            return 0;
        }
        limpiarBuffer();
    }
    *cantidad = n;
    return 1;
}

int generarPesosAleatorios(int *cantidad)
{
    int n;
    printf("Cuantos contenedores desea generar (maximo %d)? ", MAX_CONTENEDORES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CONTENEDORES) {
        limpiarBuffer();
        printf("Cantidad invalida. Operacion cancelada.\n");
        return 0;
    }
    limpiarBuffer();

    for (int i = 0; i < n; i++) {
        pesos[i] = rand() % (PESO_MAX - PESO_MIN + 1) + PESO_MIN;
    }
    *cantidad = n;
    printf("%d pesos aleatorios generados.\n", n);
    return 1;
}

void mostrarContenedores(int cantidad)
{
    if (cantidad == 0) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("Contenedores registrados:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Contenedor %2d: %d\n", i + 1, pesos[i]);
    }
}

void hundir(int i, int cantidad)
{
    int mayor = i;
    int izquierdo = 2 * i + 1;
    int derecho = 2 * i + 2;

    if (izquierdo < cantidad && pesos[izquierdo] > pesos[mayor]) {
        mayor = izquierdo;
    }

    if (derecho < cantidad && pesos[derecho] > pesos[mayor]) {
        mayor = derecho;
    }

    if (mayor != i) {
        int temp = pesos[i];
        pesos[i] = pesos[mayor];
        pesos[mayor] = temp;
        hundir(mayor, cantidad);
    }
}

void ordenarMetodo1(int cantidad)
{
    for (int i = cantidad / 2 - 1; i >= 0; i--) {
        hundir(i, cantidad);
    }

    for (int i = cantidad - 1; i > 0; i--) {
        int temp = pesos[0];
        pesos[0] = pesos[i];
        pesos[i] = temp;
        hundir(0, i);
    }
}

void fusionar(int izq, int mid, int der)
{
    int temp[MAX_CONTENEDORES];
    int i = izq, j = mid + 1, k = 0;

    while (i <= mid && j <= der) {
        if (pesos[i] <= pesos[j]) {
            temp[k++] = pesos[i++];
        } else {
            temp[k++] = pesos[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = pesos[i++];
    }

    while (j <= der) {
        temp[k++] = pesos[j++];
    }

    for (i = izq, k = 0; i <= der; i++, k++) {
        pesos[i] = temp[k];
    }
}

void ordenarMerge(int izq, int der)
{
    if (izq < der) {
        int mid = izq + (der - izq) / 2;
        ordenarMerge(izq, mid);
        ordenarMerge(mid + 1, der);
        fusionar(izq, mid, der);
    }
}

void ordenarMetodo2(int cantidad)
{
    if (cantidad > 1) {
        ordenarMerge(0, cantidad - 1);
    }
}

int particion(int bajo, int alto)
{
    int pivote = pesos[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (pesos[j] <= pivote) {
            i++;
            int temp = pesos[i];
            pesos[i] = pesos[j];
            pesos[j] = temp;
        }
    }
    int temp = pesos[i + 1];
    pesos[i + 1] = pesos[alto];
    pesos[alto] = temp;
    return i + 1;
}

void ordenarMetodo3(int bajo, int alto)
{
    if (bajo < alto) {
        int indicePivote = particion(bajo, alto);
        ordenarMetodo3(bajo, indicePivote - 1);
        ordenarMetodo3(indicePivote + 1, alto);
    }
}

int busquedaBinaria(int cantidad, int objetivo)
{
    int izquierda = 0;
    int derecha = cantidad - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (pesos[medio] == objetivo) {
            return medio;
        }
        if (pesos[medio] < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

void limpiarBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}
