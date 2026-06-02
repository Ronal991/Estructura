Sistema de Organización de Contenedores - Muelle de Carga

Descripción

Este proyecto fue desarrollado en lenguaje C como parte de la Unidad 5: Métodos de Ordenamiento Eficiente y Búsqueda Binaria.

El sistema permite gestionar el peso de hasta 30 contenedores ubicados en un patio de carga portuario. Los usuarios pueden registrar pesos manualmente, generar datos aleatorios, visualizar los contenedores almacenados, aplicar diferentes algoritmos de ordenamiento eficiente y realizar búsquedas binarias sobre los datos ordenados.

Objetivo

Implementar una solución basada en arreglos y funciones que permita aplicar técnicas de organización eficiente de datos mediante algoritmos de ordenamiento y búsqueda estudiados en la asignatura de Estructuras de Datos.

Características del Sistema

* Registro manual de pesos de contenedores.
* Generación automática de pesos aleatorios.
* Visualización de los contenedores registrados.
* Ordenamiento mediante algoritmos eficientes.
* Búsqueda binaria de contenedores por peso.
* Validación de entradas del usuario.
* Control del estado de ordenamiento mediante una bandera lógica.

Especificaciones

* Capacidad máxima: 30 contenedores.
* Los pesos se almacenan como números enteros.
* El sistema utiliza un arreglo unidimensional para almacenar los datos.
* La variable `ordenado` indica si el arreglo se encuentra organizado o no.

Algoritmos Implementados

Método 1: Quick Sort

Algoritmo de ordenamiento basado en la estrategia de división y conquista. Selecciona un pivote y reorganiza los elementos alrededor de él hasta obtener el arreglo ordenado.

Método 2: Heap Sort

Método de ordenamiento eficiente que utiliza una estructura tipo montículo (heap) para organizar y ordenar los elementos del arreglo.

Método 3: Merge Sort

Algoritmo de división y conquista que divide el arreglo en subarreglos más pequeños, los ordena y posteriormente los fusiona para obtener el resultado final.

Búsqueda Binaria

Permite localizar un peso específico dentro del arreglo de forma eficiente. Solo puede ejecutarse cuando los datos se encuentran previamente ordenados.

Estructuras y Conceptos Utilizados

* Arreglos unidimensionales.
* Funciones.
* Variables globales.
* Recursividad.
* Ordenamiento eficiente.
* Búsqueda binaria.
* Generación de números aleatorios.
* Validación de entradas.

Menú del Programa

1. Registrar peso de contenedores manualmente.
2. Generar pesos aleatorios de contenedores.
3. Mostrar contenedores registrados.
4. Ordenar contenedores Método 1 (Quick Sort).
5. Ordenar contenedores Método 2 (Heap Sort).
6. Ordenar contenedores Método 3 (Merge Sort).
7. Buscar contenedor mediante búsqueda binaria.
8. Salir.

Compilación

Para compilar el programa utilizando GCC:

cd Unidad5
gcc main.c


Ejecución en Windows

a.exe


Estructura del Proyecto

unidad5/
└── tallerMetodosEficientes/
    ├── main.c
    ├── README.md
    └── evidencias/
        ├── evidencia_codigo.png
        ├── evidencia_compilacion.png
        ├── evidencia_ejecucion.png
        └── evidencia_repositorio.png

Autor

Ronald Smith Angulo Arboleda

Jefferson Montaño

Ingeniería de Sistemas

Universidad del Pacífico

Conclusión

El proyecto permitió aplicar estructuras de datos basadas en arreglos, implementar algoritmos de ordenamiento eficiente (Quick Sort, Heap Sort y Merge Sort) y utilizar búsqueda binaria para optimizar la localización de información dentro de un conjunto de datos previamente ordenado.