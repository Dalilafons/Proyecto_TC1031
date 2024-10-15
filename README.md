# Proyecto: Movie Selector
Este proyecto consiste en un sistema de inventario de películas, que permite agregar, ordenar y buscar películas en base a diferentes atributos, como título, director, género, año de lanzamiento y duración. Además utiliza estructuras de datos como vectores y algoritmos de ordenamiento (Merge Sort y Shell Sort) para gestionar la lista de películas de manera eficiente. También incluye la funcionalidad de búsqueda binaria para encontrar películas por título.

## Descripción del avance 1
En este primer avance, se ha implementado lo siguiente:
- Clases `Pelicula` y `Inventario` para gestionar la información de las películas y el inventario de las mismas.
- Lectura de una lista de películas desde un archivo de texto `Lista.txt` que contiene información sobre cada película.
- Funcionalidad para agregar nuevas películas al inventario.
- Funcionalidad para ordenar el inventario por título, año de lanzamiento o duración.
- Implementación de búsqueda binaria para encontrar una película por su título.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto
El programa requiere un archivo de entrada llamado `Lista.txt`, que contiene la lista de películas en el siguiente formato:

```plaintext
titulo, director, genero, lanzamiento, duracion
El Origen, Christopher Nolan, Ciencia ficcion, 2010, 148
El Padrino, Francis Ford Coppola, Drama, 1972, 175
El Caballero Oscuro, Christopher Nolan, Accion, 2008, 152
```

Cada línea contiene los datos de una película separados por comas:
- titulo: Título de la película.
- director: Nombre del director de la película.
- genero: Género de la película.
- lanzamiento: Año de lanzamiento de la película.
- duracion: Duración en minutos.

El programa también permite ingresar nuevas películas a través de la consola durante la ejecución.

## Descripción de las salidas del avance de proyecto
El programa proporciona las siguientes salidas:
- Al elegir la opción mostrar inventario de películas, se listan todas las películas con sus respectivos atributos.
- La opción ordenar, muestra el inventario ordenado de acuerdo con el atributo seleccionado (título,lanzamiento o duración).
- La opción buscar una película, realiza una búsqueda por título, donde el programa indica si la película fue encontrada y muestra su información, o indica que no se encontró.

## Desarrollo de competencias
### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En mi proyecto, he implementado el algoritmo de ordenamiento Merge Sort en las funciones `ordenarPorTitulo`, `ordenarPorDuracion` y `ordenarPorLanzamiento`. El análisis de complejidad del algoritmo es el siguiente:
- Complejidad temporal en el peor de los casos: O(n log n), ya que Merge Sort siempre requiere dividir el conjunto de datos y luego combinar las sublistas. Esto implica que, sin importar el estado inicial de la lista, el número de pasos sigue siendo constante.
- Complejidad temporal en el mejor de los casos: O(n log n), dado que el algoritmo sigue dividiendo y combinando incluso cuando la lista está parcialmente o completamente ordenada.
  
Comparado con otros algoritmos, como Bubble Sort, Selection Sort, Insertion Sort, y Quick Sort, que en el peor de los casos tienen una complejidad de O(n²), Merge Sort es más eficiente para grandes volúmenes de datos. El algoritmo también es estable, lo que significa que mantiene el orden relativo de los elementos iguales después del proceso de ordenamiento, a diferencia de Quick Sort, que no lo garantiza.

Esta estabilidad es importante en mi proyecto, ya que se manejan arreglos de películas con múltiples atributos. Por ejemplo, al ordenar por duración, si varias películas tienen la misma duración, Merge Sort mantendrá el orden original relativo entre ellas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para mi proyecto, decidí utilizar Merge Sort debido a sus características específicas que lo hacen el más adecuado para mi proyecto:

- Tiene una complejidad temporal constante de O(n log n) en el mejor y el peor de los casos, lo que lo hace ideal para listas grandes y desordenadas de peliculas.
- Su estabilidad garantiza que los elementos con valores iguales mantengan su orden relativo original, algo fundamental al manejar conjuntos de datos complejos , como mi proyecto cuenta con un arreglo de varios objetos en este caso películas con múltiples atributos,  al elegir ciertas funciones , por ejemplo `ordenarporDuracion`, algunas películas pueden tener el mismo valor de duración, entonces Merge Sort mantiene el mismo orden relativo que tenían en la lista original después de ordenarlas, a comparación de por ejemplo Quick Sort que cuando tiene elementos iguales, no garantiza el orden relativo de estos elementos después del ordenamiento. 
- Al comparar con otros algoritmos como Quick Sort, que aunque eficiente,  tiene un peor caso de O(n²) e Insertion Sort o Bubble Sort, que tienen un mejor rendimiento sólo en listas parcialmente ordenadas, Merge Sort se destaca como la mejor opción para manejar datos desordenados y en grandes volúmenes, por tener la complejidad en el peor caso O(n log n), como ya lo mencioné.
  
En conclusión, el algoritmo de ordenamiento que elegí Mergesort fue el mejor para mi proyecto, por su rendimiento constante, por la mejor complejidad temporal a comparacion de otros algoritmos, en el peor y en el mejor de los casos, también por su adaptabilidad sin importar el estado inicial de la lista a ordenar y por último por su capacidad de manejar grandes conjuntos de datos de manera eficiente. 





