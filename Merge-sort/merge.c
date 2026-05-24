#include <stdio.h>
#include <stdlib.h>

// Función para fusionar dos mitades ordenadas del arreglo
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Función recursiva de Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        printf("Cuantos numeros desea ordenar?: ");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Entrada invalida. Ingrese un numero entero positivo.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        int *data = malloc(n * sizeof(int));
        if (data == NULL) {
            printf("Error de memoria. Saliendo.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            printf("Ingrese el numero %d: ", i + 1);
            scanf("%d", &data[i]);
        }

        mergeSort(data, 0, n - 1);

        printf("Arreglo ordenado: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");

        free(data);

        printf("Desea continuar organizando numeros? (s/n): ");
        scanf(" %c", &continuar);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return 0;
}
