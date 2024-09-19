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
Para mi proyecto, decidí dado el tamaño del inventario de películas utlizar los siguientes algoritmos de ordenamiento.El objetivo fue utilizar métodos que garantizaran un buen rendimiento general en función de la cantidad de datos, independientemente de los atributos específicos.
- Shell Sort para ordenar por título y duración. La complejidad temporal de este algoritmo es   O(n log² n), lo cual es aduecuado para listas de tamaño moderado como el inventario de películas (aproximadamente 110 películas).
- Merge Sort para ordenar por año de lanzamiento. La complejidad temporal de Merge Sort es O(n log n), lo que lo hace eficiente para listas grandes, ya que nos garantiza un tiempo de ejecución estable en el peor caso.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se seleccionaron los siguientes algoritmos en función de su eficiencia y facilidad de implementación:
- Shell Sort fue elegido para ordenar por título y duración debido a sus simplicidad y buen rendimeinto en listas de tamaño medio.
- Merge Sort fue elegido para ordenar por año de lanzamiento debido a su eficiencia en listas más grandes y su estabilidad, lo cual es crucial cuando se requiere preservar el orden relativo de elementos con atributos similares.

La estructura de datos utlizada es un `std::vector`, que permite el acceso eficniete a los elementos y facilita la implementación de los algoritmos de ordenamiento.Esta decisión es adecuada para el tamaño del inventario de películas, que es de aproximadamente 110 películas.

