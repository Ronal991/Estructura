#include <stdio.h>

void calculararea() {
    

    double radio, area, diametro;
    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &radio);
    
    area = 3.14159 * radio * radio;
    diametro = 2 * radio;
    printf("El area del circulo es: %lf\n", area);
    printf("El diametro del circulo es: %lf\n", diametro);


}
    
void calcularAreaCuadrado() {
    double lado, area;
    printf("Ingrese el lado del cuadrado: ");
    scanf("%lf", &lado);
    
    area = lado * lado; 
    printf("El area del cuadrado es: %lf\n", area);
}

void calcularvolumen() {

    double radio, altura, volumen;
    printf("Ingrese el radio del cilindro: ");
    scanf("%lf", &radio);
    printf("Ingrese la altura del cilindro: ");
    scanf("%lf", &altura);
    volumen = 3.14159 * radio * radio * altura;
    printf("El volumen del cilindro es: %lf\n", volumen);

}
void calcularVolumenCuadrado() {
    double lado, volumen;
    printf("Ingrese el lado del cubo: ");
    scanf("%lf", &lado);
    volumen = lado * lado * lado;
    printf("El volumen del cubo es: %lf\n", volumen);
}

void calculadoraBasica() {
    double a, b;
    char op;
    printf("\nCalculadora basica: no olvides usar bien los simbolos (+, -, *, /): ");
    scanf("%lf %c %lf", &a, &op, &b);
    double res;
    int valido = 1;
    switch (op) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: division por cero.\n");
                valido = 0;
            } else {
                res = a / b;
            }
            break;
        default:
            printf("Operador no valido. Usa + - * /.\n");
            valido = 0;
    }
    if (valido) {
        printf("Resultado: %lf\n", res);
    }
}
    
int main() {
    char continuar;

    do {
        printf("-------Bienvenido a mi calculadora cientifica experimental-------\n");
        
        
        printf("¿Que operacion desea realizar?\n");
        printf("1. Calcular el area de un circulo\n");
        printf("2. Calcular el area de un cuadrado\n");
        printf("3. Calcular el volumen de un cilindro\n");
        printf("4. Calcular el volumen de un cuadrado\n");
        printf("5. Calculadora basica (Suma, resta, Multiplicacion y division)\n");
        
        int operacion;
        scanf("%d", &operacion);
        
        if (operacion == 1) {
            calculararea();
        } else if (operacion == 2) {
            calcularAreaCuadrado();
        } else if (operacion == 3) {
            calcularvolumen();
        } else if (operacion == 4) {
            calcularVolumenCuadrado();
        } else if (operacion == 5) {
            calculadoraBasica();
        } else {
            printf("Operacion no valida\n");
        }
        
        printf("¿Desea continuar en el programa? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    
    printf("-------Muchas gracias por usar nuestra calculadora experimental-------\n");
    return 0;



}