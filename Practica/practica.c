#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= (unsigned long long)i;
    }
    return result;
}

int main(void) {
    int n;

    printf("------Bienvenido a la factorizadora de numeros------\n");
    printf("Digite un numero entero que no negativo: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n < 0) {
        printf("No se puede calcular factorial de un numero negativo.\n");
        return 1;
    }

    unsigned long long result = factorial(n);
    printf("%d! = %llu\n", n, result);
    return 0;
}