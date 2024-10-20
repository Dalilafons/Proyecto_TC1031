# Proyecto: Movie Selector
Este proyecto consiste en un sistema de inventario de películas que permite agregar, ordenar , buscar y eliminar películas en base a atributos clave, como título, director, género, año de lanzamiento y duración. El sistema utiliza un vector para gestionar las películas, y emplea el algoritmo Merge Sort como método principal para ordenar el inventario de manera eficiente.

Además, se implementa un Árbol AVL como estructura de datos avanzada para asegurar una gestión balanceada del inventario. El Árbol AVL permite optimizar las operaciones de búsqueda, inserción y eliminación, garantizando un rendimiento óptimo en cada operación.

Este enfoque combina la eficiencia de algoritmos avanzados de ordenamiento con estructuras de datos balanceadas, proporcionando una experiencia fluida al gestionar el inventario de películas.

## Descripción del avance 1
En este primer avance, se ha implementado lo siguiente:
- Clases `Pelicula` y `Inventario` para gestionar la información de las películas y el inventario de las mismas.
- Lectura de una lista de películas desde un archivo de texto `Lista.txt` que contiene información sobre cada película.
- Funcionalidad para agregar nuevas películas al inventario.
- Funcionalidad para ordenar el inventario por título, año de lanzamiento o duración.
- Implementación de búsqueda binaria para encontrar una película por su título.

## Descripción del avance 2
En este segundo avance, se ha implementado lo siguiente:
- Clases `Pelicula` e `Inventario`:
La clase `Pelicula` representa cada película del inventario, almacenando atributos como título, director, género, año de lanzamiento y duración. Por su parte, la clase `Inventario` organiza y gestiona un vector de películas, permitiendo operaciones de ordenamiento y manejo de las mismas.

- Lectura desde el archivo de texto `Lista.txt`:
Al iniciar el programa, se carga la lista de películas desde el archivo `Lista.txt`, que contiene información detallada de cada película. Esta lista se procesa línea por línea y las películas se almacenan tanto en el inventario como en el Árbol AVL para las diferentes funcionalidades del proyecto, además de evitar duplicados.

- Árbol AVL para gestión eficiente:
Se ha implementado un Árbol AVL, una estructura de datos balanceada que permite realizar búsquedas, inserciones y eliminaciones de películas en O(log n), asegurando una alta eficiencia incluso para grandes volúmenes de datos.

- Ordenamiento del inventario utilizando Merge Sort:
El inventario de películas se puede ordenar por diferentes criterios: título, año de lanzamiento o duración, utilizando el algoritmo Merge Sort, que garantiza un rendimiento óptimo con complejidad O(n log n).

- Menú interactivo:
El programa ofrece un menú dinámico donde los usuarios pueden:
    - Mostrar el inventario completo de películas.
    - Agregar nuevas películas al inventario y al árbol AVL.
    - Ordenar el inventario según el criterio seleccionado.
    - Buscar una película por título utilizando el Árbol AVL.
    - Eliminar películas del inventario y del árbol AVL.
    - Salir del programa con un mensaje de despedida.

- Sin duplicidad de películas:
Al agregar películas, se verifica que no estén previamente en el árbol AVL para evitar duplicados en el inventario.

### Cambios sobre el primer avance
1. Eliminación del Algoritmo Shell Sort:
    En la primera versión del proyecto, se utilizaba Shell Sort como uno de los algoritmos de ordenamiento. En este avance, se ha decidido eliminarlo y consolidar el ordenamiento exclusivamente con Merge Sort.
    La razón de cambio es porque Merge Sort ofrece un mejor rendimiento garantizando con complejidad O(n log n) y es más adecuado para manejar grandes volúmenes de datos como en mi proyecto de alrededor 100 películas, es por eso que se eliminó Shell Sort porque no era un método de ordenamiento eficiente por su complejidad en el peor de los casos de O(n^2) y en el mejor O(n log^2 n), entonces no es constante como Merge Sort, además de que este funciona bien para conjuntos pequeños, pero su rendimiento se desagrada por su complejidad en volúmenes más grandes y esta inconsistencia en su desempeño podría afectar negativamente la experiencia del usuario.
2. Implementación de la estructura de datos Árbol AVL:
    Se agregó la estructura de datos Árbol AVL para manejar el inventario de películas junto al uso de un vector. El Árbol AVL permite realizar operaciones como búsqueda, inserción y eliminación de manera eficiente y se complementa con el vector para otras operaciones de gestión.
    La estructura de Árbol AVL fue incluida porque es una de las mejores opciones para garantizar que las operaciones de búsqueda y eliminación tengan una complejidad de O(log n). Además, su inclusión fue necesaria para cumplir con los requerimientos del avance. Esto mejora el rendimiento del sistema, especialmente cuando se trabaja con conjuntos de datos más grandes, manteniendo las películas en un estado balanceado y organizado.
3. Sustitución de la función `sort()` por Merge Sort:
    Se eliminó el uso de la función sort() estándar de C++ y se implementó Merge Sort como el algoritmo principal para ordenar las películas.
    La función `sort()` estándar de C proporcionaba una implementación que no era muy eficaz para mi proyecto, primero por la estabilidad, ya que Merge Sort es un algoritmo muy estable, lo que significa que preserva el orden relativo de los elementos iguales. Esto es útil si necesitas mantener un orden preexistente en otros atributos al ordenar por uno específico, como el título de la película, `sort()` no garantiza estabilidad en todos los casos.
    Por último, aunque `sort()` utiliza Introsort, que combina varios algoritmos, en casos particulares, puede presentar ciertas ineficiencias debido a la variación de estrategias. Merge Sort es consistente en cuanto a su O(n log n) en el mejor, promedio y peor casos.

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

Además del archivo de entrada, el programa permite al usuario agregar nuevas películas durante la ejecución, ingresando los datos directamente desde la consola. Se validan las entradas para asegurarse de que el título no esté duplicado en el Árbol AVL, evitando así la duplicidad en el inventario.

## Descripción de las salidas del avance de proyecto
El programa proporciona las siguientes salidas:
- Mostrar Inventario de Películas:
    Al seleccionar esta opción, se listan todas las películas almacenadas en el inventario, mostrando los siguientes atributos para cada una:
        - Título
        - Director
        - Género
        - Año de lanzamiento
        - Duración (en minutos)
- Ordenar Inventario:
    Al ordenar el inventario, se muestra la lista completa de películas organizadas de acuerdo con el atributo seleccionado:
        - Título: Orden alfabético.
        - Año de lanzamiento: Orden cronológico.
        - Duración: Orden por tiempo de reproducción en minutos.
- Buscar una Película:
    Al realizar una búsqueda por título, el programa proporciona dos posibles salidas:
        - Película encontrada: Se muestra toda la información detallada de la película.
        - Película no encontrada: Se notifica al usuario que no se encontró ninguna coincidencia para el título ingresado.
- Mensajes de confirmación y errores:
    El programa también proporciona retroalimentación al usuario mediante mensajes, como:
        - Confirmación de operaciones exitosas: (e.g., "Película agregada exitosamente.")
        - Mensajes de error: (e.g., "Película no encontrada", "No se pudo abrir el archivo Lista.txt.")

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En mi proyecto, he implementado el algoritmo de ordenamiento Merge Sort en las funciones `ordenarPorTitulo`, `ordenarPorDuracion` y `ordenarPorLanzamiento`. El análisis de complejidad del algoritmo es el siguiente:
- Complejidad temporal en el peor de los casos: O(n log n), ya que Merge Sort siempre requiere dividir el conjunto de datos y luego combinar las sublistas. Esto implica que, sin importar el estado inicial de la lista, el número de pasos sigue siendo constante.
- Complejidad temporal en el mejor de los casos: O(n log n), dado que el algoritmo sigue dividiendo y combinando incluso cuando la lista está parcialmente o completamente ordenada.
  
Comparado con otros algoritmos, como Bubble Sort, Selection Sort, Insertion Sort, y Quick Sort, que en el peor de los casos tienen una complejidad de O(n²), Merge Sort es más eficiente para grandes volúmenes de datos. El algoritmo también es estable, lo que significa que mantiene el orden relativo de los elementos iguales después del proceso de ordenamiento, a diferencia de Quick Sort, que no lo garantiza.

Esta estabilidad es importante en mi proyecto, ya que se manejan vectores de películas con múltiples atributos. Por ejemplo, al ordenar por duración, si varias películas tienen la misma duración, Merge Sort mantendrá el orden original relativo entre ellas.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
1. Vector:
En mi proyecto, utilicé un vector para almacenar y gestionar el inventario de películas. A continuación, explicaré dónde se reflejan las diferentes operaciones del vector, junto con su complejidad en los distintos casos.
    - Acceso por Índice:
        - Complejidad en el mejor y peor caso: O(1), el acceso a los elementos del vector por su índice es constante.
        Esto lo podemos observar cuando accedemos a un elemento del inventario para mostrar la lista de películas ordenada o no ordenada: `mostrarPeliculas()`.
    - Inserción al Final del Vector:
        - Complejidad en el mejor de los casos: O(1), si el vector tiene espacio, la inserción es inmediata.
        - Complejidad en el peor de los casos: O(n), si el vector necesita redimensionarse, copia todos los elementos a una nueva ubicación.
        Esto lo podemos observar cuando se agrega una nueva película al inventario: `inventario.agregarPelicula(nuevaPelicula)`.
        Si el vector ya está lleno, el programa asignará más memoria y copiará los elementos existentes.
    - Eliminación de un Elemento del Vector:
        - Complejidad en el mejor de los casos: O(1), eliminar el último elemento es inmediato.
        - Complejidad en el peor de los casos: O(n), eliminar un elemento del principio o del medio requiere desplazar los elementos restantes hacia la izquierda.
        Esto esta reflejado en el proyecto, cuando eliminamos una película del inventario: `inventario.eliminarPelicula("Nombre de la pelicula")`.
2. Árbol AVL:
El Árbol AVL es una estructura de datos balanceada que garantiza un rendimiento eficiente en las operaciones de búsqueda, inserción y eliminación, asegurando que el árbol se mantenga equilibrado mediante rotaciones cuando sea necesario.
    - Búsqueda `findByTitle()`:
        - Complejidad en el mejor de los casos: O(log n), el árbol está perfectamente balanceado, lo que minimiza la altura.
        - Complejidad en el peor de los casos: O(log n), incluso en el peor caso, el AVL garantiza que esté balanceado.
    - Inserción `add()`:
        - Complejidad en el mejor de los casos: O(log n), la inserción no requiere rotaciones porque el árbol permanece balanceado.
        - Complejidad en el peor de los casos: O(log n), se realizan rotaciones simples o dobles para restaurar el balance.
    - Eliminación `remove()`:
        - Complejidad en el mejor de los casos: O(log n), el nodo eliminado no requiere rotaciones para mantener el balance.
        - Complejidad en el peor de los casos: O(log n), se realizan rotaciones simples o dobles para reequilibrar el árbol.
    - Recorrido en orden `inorder()`:
        - Complejidad en el mejor de los casos: O(n), siempre recorre todos los nodos del árbol en orden ascendente.
        - Complejidad en el peor de los casos: O(n), no importa la estructura del árbol, todos los nodos deben visitarse.

En mi proyecto, he implementado tanto el vector como el Árbol AVL, y he realizado un análisis detallado de su complejidad en el mejor y peor caso. Esta competencia se puede observar en la selección de estructuras adecuadas para cada tarea:

Utilicé el `vector` para almacenar las películas, lo cual es eficiente para el acceso directo y recorridos secuenciales. Sin embargo, sus operaciones de inserción y eliminación presentan O(n) en el peor caso, lo que motivó la incorporación del Árbol AVL.

Implementé el `Árbol AVL` para operaciones como búsqueda, inserción y eliminación, ya que garantiza un rendimiento eficiente de O(log n) en ambos casos, lo que lo hace más adecuado para gestionar un inventario dinámico.

Este análisis me permitió diseñar un sistema eficiente y escalable, optimizando las operaciones críticas del inventario. Además, la implementación de estructuras balanceadas como el Árbol AVL asegura un rendimiento constante y predecible incluso con un número creciente de películas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para mi proyecto, decidí utilizar Merge Sort debido a sus características específicas que lo hacen el más adecuado para mi proyecto:

- Tiene una complejidad temporal constante de O(n log n) en el mejor y el peor de los casos, lo que lo hace ideal para listas grandes y desordenadas de peliculas.
- Su estabilidad garantiza que los elementos con valores iguales mantengan su orden relativo original, algo fundamental al manejar conjuntos de datos complejos , como mi proyecto cuenta con un arreglo de varios objetos en este caso películas con múltiples atributos,  al elegir ciertas funciones , por ejemplo `ordenarporDuracion`, algunas películas pueden tener el mismo valor de duración, entonces Merge Sort mantiene el mismo orden relativo que tenían en la lista original después de ordenarlas, a comparación de por ejemplo Quick Sort que cuando tiene elementos iguales, no garantiza el orden relativo de estos elementos después del ordenamiento. 
- Al comparar con otros algoritmos como Quick Sort, que aunque eficiente,  tiene un peor caso de O(n²) e Insertion Sort o Bubble Sort, que tienen un mejor rendimiento sólo en listas parcialmente ordenadas, Merge Sort se destaca como la mejor opción para manejar datos desordenados y en grandes volúmenes, por tener la complejidad en el peor caso O(n log n), como ya lo mencioné.
  
En conclusión, el algoritmo de ordenamiento que elegí Mergesort fue el mejor para mi proyecto, por su rendimiento constante, por la mejor complejidad temporal a comparacion de otros algoritmos, en el peor y en el mejor de los casos, también por su adaptabilidad sin importar el estado inicial de la lista a ordenar y por último por su capacidad de manejar grandes conjuntos de datos de manera eficiente. 

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para mi proyecto, seleccioné dos estructuras de datos fundamentales: vector y Árbol AVL. La decisión de utilizar ambas estructuras se tomó cuidadosamente para abordar diferentes necesidades específicas del inventario de películas y optimizar tanto la eficiencia como la funcionalidad.

- Selección y uso del `Vector`:
    - Utilicé un vector porque es una estructura dinámica y eficiente para almacenar colecciones de datos, en este caso, películas. Los vectores permiten realizar accesos directos a los elementos mediante índices en O(1), lo que es ideal para recorrer y mostrar todas las películas del inventario de manera secuencial.
    - El vector se utiliza principalmente en las funciones `mostrarPeliculas()` y para almacenar las películas añadidas por el usuario.
    - Permite recorrer los elementos rápidamente para visualizarlos en la consola.
    - Es fácil de gestionar y redimensionar dinámicamente según el tamaño del inventario.
    - Una limitación, es que debido a que las operaciones de inserción y eliminación en posiciones específicas tienen una complejidad de O(n), decidí complementar el uso del vector con un Árbol AVL.

- Selección y uso del `Árbol AVL`:
    - Incorporé un Árbol AVL para manejar las operaciones de búsqueda, inserción y eliminación de películas de manera eficiente, ya que estas operaciones en un vector no escalan bien. El Árbol AVL es ideal para problemas en los que se requiere mantener un conjunto de datos ordenado y acceder a ellos de manera rápida y eficiente. En este proyecto, la búsqueda de películas por título es una operación clave, lo que justificó la selección del AVL.
    - Podemos ver su uso:
        Búsqueda: `arbolPeliculas.findByTitle(titulo)`.
        Inserción: `arbolPeliculas.add(nuevaPelicula)`.
        Eliminación: `arbolPeliculas.remove(peliculaEliminar)`.
        Recorrido inorder: `arbolPeliculas.inorder()`.
    - Sus ventajas son:
        -Búsqueda rápida: O(log n), incluso con un inventario grande.
        -Inserción y eliminación balanceadas: El árbol se mantiene equilibrado, garantizando que las operaciones críticas no se degraden.
        -Recorrido ordenado: Con el recorrido inorder, las películas se muestran en orden alfabético.

La combinación de `vector` y `Árbol AVL` fue la solución más adecuada para mi proyecto. El vector permite gestionar y recorrer fácilmente la lista de películas, mientras que el Árbol AVL garantiza un rendimiento eficiente en operaciones de búsqueda, inserción y eliminación, con una complejidad de O(log n).

Este desarrollo de la competencia se observa claramente en la forma en que seleccioné cada estructura de datos para aprovechar sus puntos fuertes y compensar sus limitaciones. El vector es ideal para operaciones de acceso y recorrido secuencial, mientras que el Árbol AVL es fundamental para mantener un inventario dinámico y eficiente. Esta combinación optimiza tanto la funcionalidad como el rendimiento del sistema, asegurando que el proyecto sea escalable y eficiente en la gestión del inventario de películas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En mi proyecto, he implementado mecanismos eficientes y correctos para consultar información de las estructuras de datos utilizadas: el vector y el Árbol AVL. A continuación, explicaré cómo se aplican estos mecanismos y se garantiza la precisión de las consultas:

1. Mecanismos de consulta en el Vector:
    El vector almacena todas las películas del inventario. La consulta de información se realiza mediante el acceso secuencial a sus elementos, aprovechando su eficiencia en recorridos.
    `inventario.mostrarPeliculas()`, esta función permite listar todas las películas almacenadas en el vector, proporcionando una salida clara al usuario.
    La complejidad O(1) del acceso a un elemento por índice permite recorridos eficientes, asegurando que la visualización completa del inventario sea rápida, sin importar el número de elementos.

2. Mecanismos de consulta en el Árbol AVL:
    El Árbol AVL se utiliza para realizar búsquedas rápidas y precisas por título, asegurando que cada consulta se resuelva en tiempo O(log n).
    `Pelicula* peliculaEncontrada = arbolPeliculas.findByTitle(titulo)`,esta función busca una película por su título y devuelve su información si es encontrada. Además, el recorrido inorder se utiliza para mostrar todas las películas en orden alfabético: `std::cout << arbolPeliculas.inorder() << std::endl`.
    El AVL garantiza un tiempo de consulta eficiente mediante su estructura balanceada. La búsqueda en tiempo O(log n) es posible gracias a la reestructuración del árbol con rotaciones, asegurando que ninguna operación degrade el rendimiento del sistema.

3. Validación de las consultas:
    En mi proyecto, las consultas no solo se ejecutan correctamente, sino que también se validan para manejar errores:
        - Búsqueda fallida: Si una película no se encuentra en el árbol, se muestra un mensaje claro al usuario: `if (peliculaEncontrada == NULL) {std::cout << "La pelicula no se encontro." << std::endl;}`
        - Visualización ordenada: El recorrido inorder garantiza que el inventario siempre se muestre en orden alfabético por título.
        - Además esta elección está basada en la complejidad computacional:
            - O(1) para accesos en el vector.
            - O(log n) para búsquedas en el AVL.
            - O(n) para el recorrido inorder del árbol.

He desarrollado esta competencia al implementar mecanismos científicos y correctos para consultar información de las estructuras de datos utilizadas. El vector permite realizar consultas eficientes para recorrer y mostrar el inventario completo, mientras que el Árbol AVL garantiza búsquedas rápidas por título y recorridos ordenados mediante el recorrido inorder.

Este desarrollo se observa en las funciones que realizan búsquedas, muestran películas y manejan situaciones donde las consultas fallan. Además, el uso de estructuras eficientes y sus mecanismos de consulta aseguran que el proyecto sea preciso, funcional y escalable.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En mi proyecto, he implementado un mecanismo eficiente y funcional para leer los datos desde un archivo de texto llamado `Lista.txt` y cargarlos tanto en el vector como en el Árbol AVL. A continuación, detallo cómo se aplica este mecanismo y cómo garantiza que los datos se gestionen correctamente en cada estructura de datos.

1. Lectura del archivo de entrada y procesamiento de datos:
    El archivo `Lista.txt` contiene una lista de películas, con sus atributos separados por comas, como título, director, género, año de lanzamiento y duración. Este archivo es leído línea por línea y procesado para cargar los datos tanto en el vector como en el Árbol AVL.
    - Uso del vector y del  Árbol AVL:
        - Vector: Almacena todas las películas de forma secuencial, permitiendo recorrerlas y ordenarlas fácilmente.
        - Árbol AVL: Permite gestionar las películas mediante operaciones eficientes como búsqueda, inserción y eliminación, manteniendo un acceso rápido y evitando duplicados.

2.  Ciencia y correctitud del mecanismo de lectura:
    - Manejo de errores en la apertura del archivo:
    En el código implementado: `if (!archivo_entrada.is_open()) {std::cout << "No se pudo abrir el archivo de peliculas." << std::endl; return 1;}`.
    Antes de procesar los datos, el programa verifica si el archivo se abrió correctamente utilizando `is_open()`. Esto previene posibles errores futuros si el archivo no está disponible, y se notifica al usuario si ocurre algún problema. Manejar correctamente los errores de apertura es una buena práctica para evitar interrupciones inesperadas en la ejecución del programa.
    
    - Lectura de datos línea por línea:
    En el código implementado:
    `std::getline(archivo_entrada, line);`
    `while (getline(archivo_entrada, line)) {`
        `std::stringstream ss(line); }`
    Se lee cada línea del archivo y se procesa utilizando `std::stringstream` para separar los campos por comas. Este mecanismo permite extraer los atributos de cada película de manera precisa, independientemente del tamaño del archivo o la cantidad de líneas.
    
    - Conversión de tipos y validación de datos:
    En el código implementado:
    `lanzamiento = std::stoi(lanzamiento_str);`
    `duracion = std::stoi(duracion_str);`
    Los valores de año de lanzamiento y duración se convierten a enteros mediante `std::stoi()` para asegurarse de que los datos se almacenen en el formato correcto. Esta validación es fundamental para garantizar que los datos sean coherentes y se puedan manipular correctamente en las estructuras de datos posteriores.

    - Carga a múltiples estructuras (Vector y Árbol AVL):
    En el código implementado:
    `inventario.agregarPelicula(pelicula);`
    `if (arbolPeliculas.findByTitle(titulo) == NULL)`
    `{arbolPeliculas.add(pelicula);}`
    Una vez que los datos son procesados y validados, se agregan al vector y al Árbol AVL:
        -El vector permite almacenar las películas en secuencia, facilitando el recorrido y ordenamiento.
        -El Árbol AVL asegura que no haya duplicados en la estructura mediante la verificación `findByTitle()`, lo que optimiza las futuras búsquedas, inserciones y eliminaciones con una complejidad de O(log n).
    
    - Cierre del archivo:
    En el código implementado:
    `archivo_entrada.close()`
    Cerrar el archivo explícitamente es esencial para liberar los recursos del sistema una vez que la lectura ha finalizado. Este es un paso importante para evitar fugas de recursos y asegurar un manejo adecuado del sistema de archivos.

He desarrollado esta competencia al implementar un mecanismo robusto y eficiente de lectura de archivos, que permite cargar los datos correctamente en las estructuras de datos de mi proyecto. Este mecanismo incluye:
    - La verificación correcta de la apertura del archivo.
    - La lectura precisa de los datos línea por línea.
    - La conversión de tipos adecuada para asegurar que los atributos se almacenen en el formato correcto.
    - La carga simultánea en el vector y en el Árbol AVL, optimizando tanto el acceso secuencial como las operaciones de búsqueda y manejo de duplicados.
El desarrollo de este mecanismo se observa en cómo los datos del archivo Lista.txt se procesan de manera eficiente y se almacenan en las estructuras de datos, asegurando un inventario bien organizado, sin duplicados y listo para ser manipulado correctamente.
