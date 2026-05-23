#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    printf("Bubble Sort:\n");
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Intercambio en posiciones %d y %d: ", j, j + 1);
                printArray(arr, n);
            }
        }
        printf("Ciclo %d completado: ", i + 1);
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n) {
    printf("Selection Sort:\n");
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            printf("Intercambio en posiciones %d y %d: ", i, minIndex);
            printArray(arr, n);
        }
        printf("Ciclo %d completado: ", i + 1);
        printArray(arr, n);
    }
}

void insertionSort(int arr[], int n) {
    printf("Insertion Sort:\n");
    printArray(arr, n);
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
            printf("Desplazamiento en posicion %d: ", j + 1);
            printArray(arr, n);
        }
        arr[j + 1] = clave;
        printf("Insercion en posicion %d: ", j + 1);
        printArray(arr, n);
        printf("Ciclo %d completado: ", i);
        printArray(arr, n);
    }
}

int main() {
    char continuar;

    do {
        printf("-----------Bienvenido al programa de ordenamiento-----------\n");
        printf("Ingrese la cantidad de elementos: ");

        int n;
        scanf("%d", &n);

        if (n <= 0) {
            printf("Cantidad no valida. Intenta de nuevo.\n");
            return 1;
        }

        int original[n];
        printf("Ingrese los elementos: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &original[i]);
        }

        printf("Seleccione el tipo de ordenamiento:\n");
        printf("1. Burbuja\n");
        printf("2. Seleccion\n");
        printf("3. Insercion\n");

        int opcion;
        scanf("%d", &opcion);

        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = original[i];
        }

        switch (opcion) {
            case 1:
                bubbleSort(arr, n);
                printf("Elementos ordenados con burbuja: ");
                printArray(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                printf("Elementos ordenados con seleccion: ");
                printArray(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                printf("Elementos ordenados con insercion: ");
                printArray(arr, n);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }

        printf("¿Deseas continuar organizando archivos? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
