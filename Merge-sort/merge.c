#include <stdio.h>
// Función para fusionar dos mitades ordenadas del arreglo
void merge(int arr[], int left, int mid, int right) {
 int n1 = mid - left + 1;
 int n2 = right - mid;
 int L[n1], R[n2];
 for (int i = 0; i < n1; i++) L[i] = arr[left + i];
 for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
 int i = 0, j = 0, k = left;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k++] = L[i++];
 } else {
 arr[k++] = R[j++];
 }
 }
 while (i < n1) arr[k++] = L[i++];
 while (j < n2) arr[k++] = R[j++];
}
// Función recursiva de Merge Sort
void mergeSort(int arr[], int left, int right) {
if (left < right)
{
 int mid = (left + right) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, left, mid, right);
 }
}
int main() {
 char continuar = 's';

 while (continuar == 's' || continuar == 'S') {
 printf("---------Bienvenido a la organizadora de datos--------\n");
 printf("Que datos quieres organizar?\n");

 int n;
 int valid = 0;
 while (!valid) {
 printf("Ingrese la cantidad de valores a ordenar: ");
 if (scanf("%d", &n) != 1 || n <= 0) {
 int c;
 while ((c = getchar()) != '\n' && c != EOF);
 printf("Cantidad no valida. Intente de nuevo.\n");
 } else {
 valid = 1;
 }
 }

 int data[n];
 for (int i = 0; i < n; i++) {
 printf("Valor %d: ", i + 1);
 scanf("%d", &data[i]);
 }

 mergeSort(data, 0, n - 1);
 printf("\nDatos ordenados:\n");
 for (int i = 0; i < n; i++) {
 printf("%d ", data[i]);
 }
 printf("\n");

 printf("Deseas continuar organizando datos? (s/n): ");
 int c;
 while ((c = getchar()) != '\n' && c != EOF);
 continuar = getchar();
 while (continuar == '\n') {
 continuar = getchar();
 }
 if (continuar == 'S' || continuar == 's') {
 while ((c = getchar()) != '\n' && c != EOF);
 }
 }
 return 0;
}