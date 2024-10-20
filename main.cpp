/*
 * main.cpp
 *
 *  Created on: 19/10/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

#include "pelicula.h"
#include "avl.h"
#include "inventario.h"

int main() 
{
    // Crear un árbol binario de búsqueda (AVL) para manejar películas.
    AVL<Pelicula> arbolPeliculas;
    
    // Crear un inventario para almacenar las películas en un vector.
    Inventario inventario;

    // Abrir el archivo de entrada que contiene la lista de películas.
    std::ifstream archivo_entrada("Lista.txt");
    if (!archivo_entrada.is_open()) 
    {
        std::cout << "No se pudo abrir el archivo de peliculas." << std::endl;
        // Termina el programa si no se puede abrir el archivo.
        return 1;
    }

    // Leer el archivo y agregar las películas al árbol.
    std::string line;
    // Saltar la primera línea (encabezados).
    std::getline(archivo_entrada, line); 

    // Leer cada línea del archivo y procesar sus valores.
    while (getline(archivo_entrada, line)) 
    {
        std::stringstream ss(line);
        std::string titulo, director, genero, lanzamiento_str, duracion_str;
        int lanzamiento, duracion;

        // Leer los valores de cada campo separados por comas.
        getline(ss, titulo, ',');
        getline(ss, director, ',');
        getline(ss, genero, ',');
        getline(ss, lanzamiento_str, ',');
        getline(ss, duracion_str, ',');

        // Convertir los valores a enteros.
        lanzamiento = std::stoi(lanzamiento_str);
        duracion = std::stoi(duracion_str);

        // Crear el objeto Pelicula.
        Pelicula pelicula(titulo, director, genero, lanzamiento, duracion);

        // Agregar la película al vector del inventario.
        inventario.agregarPelicula(pelicula);

        // Agregar la película al árbol AVL si no está presente.
        if (arbolPeliculas.findByTitle(titulo) == NULL) 
        {
            // Insertar en el árbol AVL.
            arbolPeliculas.add(pelicula);
        } 
    }

    // Cerrar el archivo de entrada
    archivo_entrada.close();  

    // Variable para almacenar la opción seleccionada por el usuario.
    int opcion;
    std::string volverMenuPrincipal = "si";

    // Bucle principal del menú de opciones.
    while ( volverMenuPrincipal == "si")
    {
        // Mostrar el menú principal.
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "MOVIE SELECTOR" << std::endl;
        std::cout << "Menu principal: " << std::endl;
        std::cout << "1. Mostrar inventario de peliculas." << std::endl;
        std::cout << "2. Agregar pelicula." << std::endl;
        std::cout << "3. Ordenar inventario. " << std::endl;
        std::cout << "4. Buscar pelicula. " << std::endl;
        std::cout << "5. Eliminar pelicula. " << std::endl;
        std::cout << "6. Salir. " << std::endl;
        std::cout << "Elige una opcion..." ;
        std::cin >> opcion;

        // Mostrar todas las películas del árbol AVL.
        if (opcion == 1)
        {
            std::cout << "INVENTARIO--------------------------" << std::endl;
            std::cout << arbolPeliculas.inorder() << std::endl;
        }

        // Agregar una nueva película al inventario y al árbol.
        else if (opcion == 2)
        {
            std::string titulo, director, genero;
            int lanzamiento, duracion;

            std::cout << "\nAGREGAR PELICULA--------------------";
            std::cout << "\nAgregar una nueva pelicula al inventario:\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Leer los datos de la película.
            std::cout << "Introduce el titulo de la pelicula: ";
            std::getline(std::cin, titulo);  

            std::cout << "Introduce el director de la pelicula: ";
            std::getline(std::cin, director);  

            std::cout << "Introduce el genero de la pelicula: ";
            std::getline(std::cin, genero);  

            std::cout << "Introduce el anio de lanzamiento: ";
            std::cin >> lanzamiento; 
            std::cin.ignore();

            std::cout << "Introduce la duracion en minutos: ";
            std::cin >> duracion;  
            std::cin.ignore();

            // Crear la película.
            Pelicula nuevaPelicula(titulo, director, genero, lanzamiento, duracion);

            // Agregar al vector del inventario.
            inventario.agregarPelicula(nuevaPelicula);

            // Verificar si la película ya está en el árbol.
            if (arbolPeliculas.findByTitle(titulo) == NULL) 
            {
                // Si no existe, agregar la película al árbol.
                arbolPeliculas.add(nuevaPelicula);
            } 
        }

        // Ordenar el inventario según el criterio seleccionado.
        else if (opcion == 3) 
        {
            std::string VolverAOrdenar = "si";
            int criterio;
            
            while (VolverAOrdenar == "si")
            {
                std::cout << "\nORDENAR PELICULA----------------------\n";
                std::cout << "Elige el criterio de ordenamiento:" << std::endl;
                std::cout << "1. Por titulo." << std::endl;
                std::cout << "2. Por duracion." << std::endl;
                std::cout << "3. Por anio de lanzamiento." << std::endl;
                std::cin >> criterio;

                // Ejecutar la ordenación según el criterio.
                if (criterio == 1)
                {
                    inventario.ordenarPorTitulo();
                    std::cout << "Peliculas ordenadas por Titulo:" << std::endl;
                    inventario.mostrarPeliculas();
                }
                else if(criterio == 2)
                {
                    inventario.ordenarPorDuracion();
                    std::cout << "Peliculas ordenadas por Duracion:" << std::endl;
                    inventario.mostrarPeliculas();
                }
                else if(criterio == 3)
                {
                    inventario.ordenarPorLanzamiento();
                    std::cout << "Peliculas ordenadas por Lanzamiento:" << std::endl;
                    inventario.mostrarPeliculas();
                }
                else
                {
                    std::cout << "Criterio invalido." << std::endl;
                }

                // Preguntar si desea volver al ordenar (si no eligió salir).
                if (volverMenuPrincipal != "no") 
                {
                    std::cout << "Deseas volver a ordenar? (si/no):";
                    std::cin >> VolverAOrdenar;
                    std::cin.ignore();
                }   
            } 
        }

        // Buscar una película por título.
        else if(opcion == 4)
        {
            std::string buscarTitulo;

            std::cout << "\nBUSCAR PELICULA-----------------------\n";
            std::cout << "Introduce el titulo de la pelicula a buscar: ";
            // Limpiar el buffer antes de usar getline.
            std::cin.ignore();  
            std::getline(std::cin, buscarTitulo);
    
            std::cout << "\nBuscando la pelicula \"" << buscarTitulo << "\" por titulo..." << std::endl;
            
            Pelicula* peliculaEncontrada = arbolPeliculas.findByTitle(buscarTitulo);
            
            if (peliculaEncontrada != NULL) 
            {
                std::cout << "La pelicula \"" << buscarTitulo << "\" fue encontrada." << std::endl;
                // Mostrar información de la película.
                peliculaEncontrada->mostrarInformacion();  
            } 
            else 
            {
                std::cout << "La pelicula \"" << buscarTitulo << "\" no se encontro." << std::endl;
            }
        }

        // Eliminar una película.
        else if(opcion == 5)
        {
            std::string eliminarTitulo;

            std::cout << "\nELIMINAR PELICULA-----------------------\n";

            // Limpiar buffer de entrada por cualquier residuo previo
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Introduce el titulo de la pelicula a eliminar: ";
            std::getline(std::cin, eliminarTitulo);  

            if (eliminarTitulo.empty()) 
            {
                std::cout << "Error: No se ingreso ningun titulo. Intentalo nuevamente." << std::endl;
            } 
            else 
            {
                std::cout << "\nEliminando la pelicula \"" << eliminarTitulo << "\"..." << std::endl;
                Pelicula peliculaEliminar(eliminarTitulo, "", "", 0, 0);

                try 
                {
                    // Eliminar película del árbol.
                    arbolPeliculas.remove(peliculaEliminar);
                    // Eliminar película de inevntario.
                    inventario.eliminarPelicula(eliminarTitulo);
                    std::cout << "La pelicula \"" << eliminarTitulo << "\" fue eliminada." << std::endl;
                } 
                catch (NoSuchElement& e) 
                {
                    std::cout << "No se pudo eliminar la pelicula \"" << eliminarTitulo << "\" porque no se encontro." << std::endl;
                }
            }
        }

        // Salir del programa.
        else if(opcion == 6)
        {
            // Salir del bucle y mostrar el mensaje de despedida.
            volverMenuPrincipal = "no";
        }

        // Validación de opciones inválidas.
        else 
        {
            std::cout << "Opcion invalida, intenta nuevamente." << std::endl;
        }

        // Preguntar si desea volver al menú principal (si no eligió salir).
        if (volverMenuPrincipal != "no") 
        {
            std::cout << "Deseas volver al menu? (si/no):";
            std::cin >> volverMenuPrincipal;
            std::cin.ignore();
        }
    }

    // Mensaje de despedida.
    std::cout << "Gracias por usar el Movie Selector." << std::endl;
    std::cout << "Vuelva pronto!" << std::endl;
    
    return 0;
}
