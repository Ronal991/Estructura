#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para cada nodo (maleta)
typedef struct Nodo {
    int documento;           // Documento del pasajero
    float peso;              // Peso de la maleta
    struct Nodo *siguiente;  // Puntero al siguiente nodo
} Nodo;

// Estructura Cola (FIFO) - Maletas en espera
typedef struct {
    Nodo *frente;
    Nodo *final;
} Cola;

// Estructura Pila (LIFO) - Bodega del avión
typedef struct {
    Nodo *tope;
} Pila;

// ==================== FUNCIONES DE NODO ====================

Nodo* crearNodo(int documento, float peso) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return NULL;
    }
    nuevoNodo->documento = documento;
    nuevoNodo->peso = peso;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// ==================== FUNCIONES DE COLA ====================

void inicializarCola(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
}

int colaVacia(Cola *c) {
    return c->frente == NULL;
}

void encolarMaleta(Cola *c, int documento, float peso) {
    Nodo *nuevoNodo = crearNodo(documento, peso);
    if (nuevoNodo == NULL) return;

    if (colaVacia(c)) {
        c->frente = nuevoNodo;
    } else {
        c->final->siguiente = nuevoNodo;
    }
    c->final = nuevoNodo;
    printf("\n✓ Maleta registrada en cola: Documento %d, Peso: %.2f kg\n", documento, peso);
}

Nodo* desencolarMaleta(Cola *c) {
    if (colaVacia(c)) {
        printf("\n✗ Cola vacía\n");
        return NULL;
    }
    Nodo *temp = c->frente;
    c->frente = c->frente->siguiente;
    if (c->frente == NULL) {
        c->final = NULL;
    }
    temp->siguiente = NULL;
    return temp;
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("\n✗ Cola de espera vacía\n");
        return;
    }
    printf("\n=== COLA DE ESPERA (Orden de llegada) ===\n");
    Nodo *actual = c->frente;
    int posicion = 1;
    while (actual != NULL) {
        printf("%d. Documento: %d | Peso: %.2f kg\n", posicion, actual->documento, actual->peso);
        actual = actual->siguiente;
        posicion++;
    }
}

void liberarCola(Cola *c) {
    Nodo *actual = c->frente;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    c->frente = NULL;
    c->final = NULL;
}

// ==================== FUNCIONES DE PILA ====================

void inicializarPila(Pila *p) {
    p->tope = NULL;
}

int pilaVacia(Pila *p) {
    return p->tope == NULL;
}

void apilarMaleta(Pila *p, Nodo *nodo) {
    nodo->siguiente = p->tope;
    p->tope = nodo;
    printf("\n✓ Maleta trasladada a bodega: Documento %d, Peso: %.2f kg\n", 
           nodo->documento, nodo->peso);
}

Nodo* desapilarMaleta(Pila *p) {
    if (pilaVacia(p)) {
        printf("\n✗ Bodega vacía\n");
        return NULL;
    }
    Nodo *temp = p->tope;
    p->tope = p->tope->siguiente;
    temp->siguiente = NULL;
    return temp;
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("\n✗ Bodega vacía\n");
        return;
    }
    printf("\n=== MALETAS EN BODEGA (Última en entrar, primera en salir) ===\n");
    Nodo *actual = p->tope;
    int posicion = 1;
    while (actual != NULL) {
        printf("%d. Documento: %d | Peso: %.2f kg\n", posicion, actual->documento, actual->peso);
        actual = actual->siguiente;
        posicion++;
    }
}

void liberarPila(Pila *p) {
    Nodo *actual = p->tope;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    p->tope = NULL;
}

// ==================== FUNCIONES DE MENÚ ====================

void mostrarMenu() {
    printf("\n");
    printf("|----------------------------------------|\n");
    printf("|   SISTEMA DE MANEJO DE MALETAS         |\n");
    printf("|----------------------------------------|\n");
    printf("| 1. Registrar nueva maleta              |\n");
    printf("| 2. Mostrar cola de espera              |\n");
    printf("| 3. Revisar siguiente maleta            |\n");
    printf("| 4. Trasladar maleta a bodega           |\n");
    printf("| 5. Visualizar maletas en bodega        |\n");
    printf("| 6. Retirar última maleta de bodega     |\n");
    printf("| 7. Salir y liberar memoria             |\n");
    printf("------------------------------------------\n");
    printf("Seleccione una opción: ");
}

void revisarSiguienteMaleta(Cola *c) {
    if (colaVacia(c)) {
        printf("\n✗ No hay maletas en la cola de espera\n");
        return;
    }
    printf("\n=== SIGUIENTE MALETA EN ESPERA ===\n");
    printf("Documento: %d | Peso: %.2f kg\n", c->frente->documento, c->frente->peso);
}

// ==================== FUNCIÓN PRINCIPAL ====================

int main() {
    Cola colaEspera;
    Pila bodega;
    int opcion;
    int documento;
    float peso;
    Nodo *maleta;

    inicializarCola(&colaEspera);
    inicializarPila(&bodega);

    printf("|----------------------------------------|\n");
    printf("|  BIENVENIDO AL SISTEMA DE MALETAS      |\n");
    printf("|----------------------------------------|\n");

    while (1) {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch (opcion) {
            case 1:
                printf("\n--- Registrar nueva maleta ---\n");
                printf("Ingrese documento del pasajero: ");
                scanf("%d", &documento);
                printf("Ingrese peso de la maleta (kg): ");
                scanf("%f", &peso);
                getchar();

                if (documento <= 0 || peso <= 0) {
                    printf("\n✗ Documento y peso deben ser mayores a 0\n");
                } else {
                    encolarMaleta(&colaEspera, documento, peso);
                }
                break;

            case 2:
                mostrarCola(&colaEspera);
                break;

            case 3:
                revisarSiguienteMaleta(&colaEspera);
                break;

            case 4:
                maleta = desencolarMaleta(&colaEspera);
                if (maleta != NULL) {
                    apilarMaleta(&bodega, maleta);
                }
                break;

            case 5:
                mostrarPila(&bodega);
                break;

            case 6:
                maleta = desapilarMaleta(&bodega);
                if (maleta != NULL) {
                    printf("\n✓ Maleta retirada de bodega: Documento %d, Peso: %.2f kg\n", 
                           maleta->documento, maleta->peso);
                    free(maleta);
                }
                break;

            case 7:
                printf("\n--- Liberando memoria ---\n");
                liberarCola(&colaEspera);
                liberarPila(&bodega);
                printf("✓ Memoria liberada correctamente\n");
                printf("\n¡Gracias por usar el sistema! Hasta luego.\n");
                return 0;

            default:
                printf("\n✗ Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}