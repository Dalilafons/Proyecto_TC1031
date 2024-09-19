/*
 * main.cpp
 *
 *  Created on: 18/09/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <limits>

#include "pelicula.h"
#include "inventario.h"
using namespace std;

int main() {
    // Crear un objeto Inventario
    Inventario inventario;

    // Abrir el archivo de entrada
    ifstream archivo_entrada("Lista.txt");

    // Abrir el archivo de entrada que contiene la lista de películas
    if (archivo_entrada.is_open()) 
    {
        string line;
        
        // Saltar la primera línea que contiene los encabezados
        getline(archivo_entrada, line);

        // Leer cada línea del archivo
        while (getline(archivo_entrada, line)) {
            stringstream ss(line);
            string titulo, director, genero, lanzamiento_str, duracion_str;
            int lanzamiento, duracion;

            // Extraer los valores de cada campo separados por comas
            getline(ss, titulo, ',');
            getline(ss, director, ',');
            getline(ss, genero, ',');
            getline(ss, lanzamiento_str, ',');
            getline(ss, duracion_str, ',');

            // Convertir los valores de lanzamiento y duracion a enteros
            lanzamiento = stoi(lanzamiento_str);
            duracion = stoi(duracion_str);

            // Crear un objeto Pelicula con los valores leídos
            Pelicula pelicula(titulo, director, genero, lanzamiento, duracion);

            // Agregar la película al inventario
            inventario.agregarPelicula(pelicula);
        }

        // Cerrar el archivo
        archivo_entrada.close();
    }

    else 
    {
        // Mensaje de error si el archivo no se pudo abrir
        cout << "No se pudo abrir el archivo de películas." << endl;
        return 1;
    }

    // Variable para almacenar la opción seleccionada por el usuario
    int opcion;
    std::string volverMenuPrincipal = "si";

    // Bucle principal del menú
    while( volverMenuPrincipal == "si")
    {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "MOVIE SELECTOR" << std::endl;
        std::cout << "Menu principal: " << std::endl;
        std::cout << "1. Mostrar inventario de peliculas." << std::endl;
        std::cout << "2. Agregar pelicula." << std::endl;
        std::cout << "3. Ordenar inventario. " << std::endl;
        std::cout << "4. Buscar pelicula. " << std::endl;
        std::cout << "5. Salir. " << std::endl;
        std::cout << "Elige una opcion..." ;
        std::cin >> opcion;
        
        // Opción para mostrar todas las películas en el inventario
        if (opcion == 1)
        {
            std::cout << "INVENTARIO--------------------------" << std::endl;
            inventario.mostrarPeliculas();
        }

        // Opción para agregar nuevas películas al inventario
        else if (opcion == 2)
        {
            std::string agregar = "si";
            std::string peli_titulo;
            std::string peli_director;
            std::string peli_genero;
            int peli_lanzamiento;
            int peli_duracion;
            
            // Bucle para agregar varias películas
            while ( agregar == "si" )
            {
                // Limpiar el buffer de entrada
                std::cin.ignore(std::numeric_limits
                <std::streamsize>::max(),'\n');  

                // Capturar los datos de la película
                std::cout << "AGREGAR PELICULAS------------------" << std::endl;
                std::cout << "Ingresa el titulo (ej:El Rey): " << std::endl;
                std::getline(std::cin, peli_titulo); 

                std::cout << "Ingresa el director (ej:Roger): " << std::endl;
                std::getline(std::cin, peli_director);  

                std::cout << "Ingresa el genero (ej:Comedia): " << std::endl;
                std::getline(std::cin, peli_genero);  

                std::cout << "Ingresa el anio de lanzamiento: " << std::endl;
                std::cin >> peli_lanzamiento;

                std::cout << "Ingresa la duracion (min.totales): " << std::endl;
                std::cin >> peli_duracion;

                // Agregar la película al inventario
                inventario.agregarPelicula(Pelicula(peli_titulo,peli_director,
                peli_genero,peli_lanzamiento,peli_duracion));
                
                // Preguntar si desea agregar otra película
                std::cout << "Deseas seguir agregando peliculas? (si/no): ";
                std::cin >> agregar;
            }
        }

        // Opción para ordenar las películas en el inventario
        else if (opcion == 3)
        {
            std::string ordenar = "si";
            int opcion_ordenar;

            // Bucle para ordenar según diferentes criterios
            while( ordenar == "si")
            {
                std::cout << "ORDENAR PELICULA------------------" << std::endl;
                std::cout << "1. Ordenar por titulo. " << std::endl;
                std::cout << "2. Ordenar por anio de lanzamiento." << std::endl;
                std::cout << "3. Ordenar por duracion." << std::endl;
                std::cout << "Elige una opcion..." ;
                std::cin >> opcion_ordenar;

                // Ordenar por título
                if (opcion_ordenar == 1)
                {
                    std::cout << "ORDENAR POR TITULO-------------" << std::endl;
                    inventario.ordenarPorTitulo();
                    inventario.mostrarPeliculas();
                }

                // Ordenar por año de lanzamiento
                else if (opcion_ordenar == 2)
                {
                    std::cout << "ORDENAR POR LANZAMIENTO--------" << std::endl;
                    inventario.ordenarPorLanzamiento();
                    inventario.mostrarPeliculas();
                }

                // Ordenar por duración
                else if (opcion_ordenar == 3)
                {
                    std::cout << "ORDENAR POR DURACION-----------" << std::endl;
                    inventario.ordenarPorDuracion();
                    inventario.mostrarPeliculas();
                }

                // Opción inválida
                else 
                {
                    std::cout << "Opcion invalida...." << std::endl;
                    std::cout << "Intenta nuevamente." << std::endl;
                }

                // Preguntar si desea seguir ordenando
                std::cout << "Deseas seguir ordenando? (si/no): ";
                std::cin >> ordenar;
            }
        }

        // Opción para buscar una película por título
        else if (opcion == 4)
        {
            std::string buscar = "si";

            // Bucle para realizar varias búsquedas
            while (buscar == "si")
            {
                std::string T_Buscado;

                std::cout << "BUSCAR PELICULA ------------------" << std::endl;
                std::cout << "Introduce el titulo de la pelicula: ";

                // Limpiar el buffer de entrada
                std::cin.ignore(std::numeric_limits
                <std::streamsize>::max(), '\n');
          
                // Obtener el título de la película a buscar
                std::getline(std::cin, T_Buscado);  

                // Buscar la película por título usando búsqueda binaria
                Pelicula* encontrada = inventario.buscarPorTitulo(T_Buscado);

                // Comprobar si se encontró la película
                if (encontrada != nullptr) 
                {
                    std::cout << "Pelicula encontrada:" << std::endl;
                    encontrada->mostrarInformacion();
                }
                
                else
                {
                    std::cout << "No se encontro la pelicula: " 
                    << T_Buscado << std::endl;
                }
                
                // Preguntar si desea seguir buscando
                std::cout << "Deseas seguir buscando? (si/no): ";
                std::cin >> buscar;
            }
        }


        else if (opcion == 5)
        {
            // Salir del bucle y mostrar el mensaje de despedida
            volverMenuPrincipal = "no";
        }

        // Opción inválida en el menú principal
        else 
        {
            std::cout << "Opcion invalida, intenta nuevamente." << std::endl;
        }

        // Preguntar si desea volver al menú principal (si no eligió salir)
        if (volverMenuPrincipal != "no") {
            std::cout << "Deseas volver al menu? (si/no):";
            std::cin >> volverMenuPrincipal;
        }
    }

    // Mensaje de despedida
    std::cout << "Gracias por usar el Movie Selector." << std::endl;
    std::cout << "Vuelva pronto!" << std::endl;

    return 0;
}

