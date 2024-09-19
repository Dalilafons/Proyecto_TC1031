/*
 * pelicula.h
 *
 *  Created on: 18/09/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include <algorithm> 

class Pelicula
{
    // Variables de instancia (atributos de la película)
    protected:
        std::string titulo;
        std::string director;
        std::string genero;
        int lanzamiento;
        int duracion;

    // Métodos de Pelicula (funciones)
    public:
        Pelicula();
        Pelicula(std::string titulo_1, std::string director_1, 
                 std::string genero_1, int lanzamiento_1, int duracion_1);
        std::string getGenero() const;
        std::string getTitulo() const;
        int getLanzamiento() const;
        int getDuracion() const;
        void mostrarInformacion() const;
};  

// Implementación del constructor por defecto
Pelicula::Pelicula() 
    : titulo(""), director(""), genero(""), lanzamiento(0), duracion(0) {}

// Implementación del constructor parametrizado
Pelicula::Pelicula(std::string titulo_1, std::string director_1, 
                   std::string genero_1, int lanzamiento_1, int duracion_1)
    : titulo(titulo_1), director(director_1), genero(genero_1), 
      lanzamiento(lanzamiento_1), duracion(duracion_1) {}

// Implementación de los métodos "getters"
std::string Pelicula::getGenero() const 
    {
        return genero;
    }

std::string Pelicula::getTitulo() const
    {
        return titulo;
    }
        
int Pelicula::getLanzamiento() const
    {
        return lanzamiento;
    }
        
int Pelicula::getDuracion() const
    {
        return duracion;
    }

// Implementación del método para mostrar la información de la película
void Pelicula::mostrarInformacion() const
    {
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Director: " << director << std::endl;
        std::cout << "Genero: " << genero << std::endl;
        std::cout << "Anio de lanzamiento: " << lanzamiento << std::endl;
        std::cout << "Duracion: " << duracion << std::endl;
    }

#endif //PELICULA_H
