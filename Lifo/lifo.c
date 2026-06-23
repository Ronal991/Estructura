#include <stdio.h>
#include <malloc.h>
int semilla = 500;
typedef struct nodo {
 int dato;
 struct nodo *sig;
} nodo;

nodo *top = NULL;
void push() {
 nodo *nuevo = (nodo*) malloc(sizeof(nodo));
 nuevo->dato = semilla;
 semilla++;
 nuevo->sig = top;
 top = nuevo;
 nuevo = NULL;
 free(nuevo); 
}

void pop() {
 if (top != NULL){
     nodo* temp = top;
     top = top->sig;
     free(temp);     
 }
}

void peek() {
 if (top != NULL){
     printf("Top Valor: %d\n", top->dato);     
 }
}
void mostrar(){
    printf("Esto es un Gazapo\n");
    for(nodo* temp = top; temp!=NULL; temp=temp->sig){
        printf("Nodo Valor: %d\n", temp->dato);     
    }
}

int main(){
    int opc;
    do{
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Mostrar\n");//Como se haria esto
        printf("5. Salir\n");
        scanf("%d", &opc);
        switch(opc){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: mostrar(); break;
        }

    }while(opc!=5);
}