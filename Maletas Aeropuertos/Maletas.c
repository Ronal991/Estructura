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

// Estructura Pila (LIFO) - Bodega del avion
typedef struct {
    Nodo *tope;
} Pila;

// ------------ FUNCIONES DE NODO -----------------
// Crea un nodo que representa una maleta, asigna memoria dinámica
// y almacena el documento y peso del pasajero.
Nodo* crearNodo(int documento, float peso) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return NULL;
    }
    nuevoNodo->documento = documento;
    nuevoNodo->peso = peso;
    nuevoNodo->siguiente = NULL; // El nodo todavía no está enlazado
    return nuevoNodo;
}

// ------------ FUNCIONES DE COLA -----------------

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
    printf("\n Maleta registrada en cola: Documento %d, Peso: %.2f kg\n", documento, peso);
}

Nodo* desencolarMaleta(Cola *c) {
    if (colaVacia(c)) {
        printf("\n Cola vacia\n");
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
        printf("\n Cola de espera vacia\n");
        return;
    }
    printf("\n COLA DE ESPERA (Orden de llegada)\n");
    Nodo *actual = c->frente;
    int posicion = 1;
    while (actual != NULL) {
        // Imprime cada maleta en el orden en que fue registrada
        printf("%d. Documento: %d | Peso: %.2f kg\n", posicion, actual->documento, actual->peso);
        actual = actual->siguiente;
        posicion++;
    }
}

// Libera todos los nodos de la cola para evitar fugas de memoria.
// Recorre la lista desde el frente hasta el final.
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

// ------------ FUNCIONES DE PILA -----------------

void inicializarPila(Pila *p) {
    p->tope = NULL;
}

int pilaVacia(Pila *p) {
    return p->tope == NULL;
}

void apilarMaleta(Pila *p, Nodo *nodo) {
    // El nodo entrante sera el primero de la pila
    nodo->siguiente = p->tope;
    p->tope = nodo;
    printf("\n Maleta trasladada a bodega: Documento %d, Peso: %.2f kg\n", 
           nodo->documento, nodo->peso);
}

// Extrae la última maleta ingresada en la bodega (pila)
Nodo* desapilarMaleta(Pila *p) {
    if (pilaVacia(p)) {
        printf("\n Bodega vacia\n");
        return NULL;
    }
    Nodo *temp = p->tope;
    p->tope = p->tope->siguiente;
    temp->siguiente = NULL; // Desvincular el nodo antes de devolverlo
    return temp;
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("\n Bodega vacia\n");
        return;
    }
    printf("\n MALETAS EN BODEGA (Ultima en entrar, primera en salir)\n");
    Nodo *actual = p->tope;
    int posicion = 1;
    while (actual != NULL) {
        // Imprime la pila desde arriba hacia abajo
        printf("%d. Documento: %d | Peso: %.2f kg\n", posicion, actual->documento, actual->peso);
        actual = actual->siguiente;
        posicion++;
    }
}

// Libera todos los nodos almacenados en la bodega, limpiando la pila.
void liberarPila(Pila *p) {
    Nodo *actual = p->tope;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    p->tope = NULL;
}

// ------------ FUNCIONES DE MENÚ -----------------

void mostrarMenu() {
    printf("\n");
    printf("|----------------------------------------|\n");
    printf("| 1. Registrar nueva maleta              |\n");
    printf("| 2. Mostrar cola de espera              |\n");
    printf("| 3. Revisar y cargar siguiente maleta   |\n");
    printf("| 4. Visualizar maletas en bodega        |\n");
    printf("| 5. Retirar ultima maleta de bodega     |\n");
    printf("| 6. Salir y liberar memoria             |\n");
    printf("------------------------------------------\n");
    printf("Seleccione una opcion: ");
}

void revisarYCargarSiguienteMaleta(Cola *c, Pila *p) {
    Nodo *maleta;

    // Verificar si hay maletas en la cola antes de procesar
    if (colaVacia(c)) {
        printf("\n No hay maletas en la cola de espera\n");
        return;
    }

    // Mostrar la maleta que se revisara y cargara a bodega
    printf("\n SIGUIENTE MALETA EN ESPERA \n");
    printf("Documento: %d | Peso: %.2f kg\n", c->frente->documento, c->frente->peso);

    maleta = desencolarMaleta(c);
    if (maleta != NULL) {
        apilarMaleta(p, maleta);
    }
}

// ------------ FUNCIÓN PRINCIPAL -----------------

int main() {
    Cola colaEspera;
    Pila bodega;
    int opcion;
    int documento;
    float peso;
    Nodo *maleta;

    // Inicializar estructuras de datos antes de comenzar
    inicializarCola(&colaEspera);
    inicializarPila(&bodega);

    printf("|----------------------------------------|\n");
    printf("|  BIENVENIDO AL SISTEMA DE MALETAS      |\n");
    printf("|----------------------------------------|\n");

    // Bucle principal del programa que ejecuta el menú de opciones
    while (1) {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        // Seleccionar la acción según la opción del usuario
        switch (opcion) {
            case 1:
                // Registrar nueva maleta en la cola de espera
                printf("\n--- Registrar nueva maleta ---\n");
                printf("Ingrese documento del pasajero: ");
                scanf("%d", &documento);
                printf("Ingrese peso de la maleta (kg): ");
                scanf("%f", &peso);
                getchar();

                if (documento <= 0 || peso <= 0) {
                    printf("\n Documento y peso deben ser mayores a 0\n");
                } else {
                    encolarMaleta(&colaEspera, documento, peso);
                }
                break;

            case 2:
                // Mostrar todas las maletas actualmente en la cola de espera
                mostrarCola(&colaEspera);
                break;

            case 3:
                // Revisar la primera maleta en espera y trasladarla a la bodega
                revisarYCargarSiguienteMaleta(&colaEspera, &bodega);
                break;

            case 4:
                // Mostrar las maletas almacenadas en la bodega (pila)
                mostrarPila(&bodega);
                break;

            case 5:
                // Retirar la última maleta ingresada en la bodega
                maleta = desapilarMaleta(&bodega);
                if (maleta != NULL) {
                    printf("\n Maleta retirada de bodega: Documento %d, Peso: %.2f kg\n", 
                           maleta->documento, maleta->peso);
                    free(maleta);
                }
                break;

            case 6:
                // Salir del programa liberando toda la memoria dinámica usada
                printf("\n--- Liberando memoria ---\n");
                liberarCola(&colaEspera);
                liberarPila(&bodega);
                printf("✓ Memoria liberada correctamente\n");
                printf("\nGracias por usar el sistema! Hasta luego.\n");
                return 0;

            default:
                printf("\n Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}