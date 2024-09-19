/*
 * inventario.h
 *
 *  Created on: 18/09/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <vector>

#include "pelicula.h"

// Función auxiliar para limpiar espacios
std::string limpiarEspacios(const std::string& str) 
{
    std::string resultado = str;

    // Eliminar espacios al inicio y al final de la cadena
    resultado.erase(0, resultado.find_first_not_of(" \t\n\r\f\v"));
    resultado.erase(resultado.find_last_not_of(" \t\n\r\f\v") + 1);

    return resultado;
}

class Inventario
{
    private:
        // Vector que contiene las películas
        std::vector<Pelicula> peliculas;

        // Métodos privados para ordenar
        void swap(std::vector<Pelicula> &v, int i, int j);
        void copyArray(std::vector<Pelicula> &A, 
                       std::vector<Pelicula> &B, int low, int high);
        void mergeSplitLanzamiento(std::vector<Pelicula>& A, 
                                   std::vector<Pelicula>& B, int low, int high);
        void mergeArrayLanzamiento(std::vector<Pelicula>& A, 
                          std::vector<Pelicula>& B, int low, int mid, int high);

    public:
        void agregarPelicula(const Pelicula& pelicula);
        void mostrarPeliculas() const;
        void ordenarPorLanzamiento();
        void ordenarPorDuracion();
        void ordenarPorTitulo();
        Pelicula* buscarPorTitulo(const std::string& tituloBuscado);
};

// Intercambiar dos películas en el vector     
void Inventario::swap(std::vector<Pelicula> &v, int i, int j)
    {
        Pelicula aux = v[i];
	    v[i] = v[j];
	    v[j] = aux;
    }

// Copiar elementos de un array a otro
void Inventario::copyArray(std::vector<Pelicula> &A, 
                           std::vector<Pelicula> &B, int low, int high)
    {
        for (int i = low; i <= high; i++) 
        {
            A[i] = B[i];
        }
    }

// Dividir el array para ordenar por año de lanzamiento (Merge Sort)
void Inventario::mergeSplitLanzamiento(std::vector<Pelicula>& A, 
                            std::vector<Pelicula>& B, int low, int high)
    {
        if(low < high)
        {
            int mid = (high + low) / 2;
		    //mergeSplit de la primera mitad
	        mergeSplitLanzamiento(A,B,low,mid);

	        //mergeSplit de la segunda mitad
	        mergeSplitLanzamiento(A,B,mid + 1, high);

	        //mergeArray de ambas mitades
	        mergeArrayLanzamiento(A,B,low, mid,high);
        }
    }

// Combinar las dos mitades ordenadas por año de lanzamiento
void Inventario::mergeArrayLanzamiento(std::vector<Pelicula>& A, 
                    std::vector<Pelicula>& B, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
	    int k = low;
	        
        while (i <= mid && j <= high) 
        {
            if (A[i].getLanzamiento() <= A[j].getLanzamiento()) 
            {
                B[k] = A[i];
                i++;
            } 

            else 
            {
                B[k] = A[j];
                j++;
            }

            k++;
        }

        // Copiar los elementos restantes de la primera mitad
        while (i <= mid) 
        {
            B[k] = A[i];
            i++;
            k++;
        } 
            
        // Copiar los elementos restantes de la segunda mitad
        while (j <= high) 
        {
            B[k] = A[j];
            j++;
            k++;
        }

        // Copiar la fusión de nuevo al array original
        copyArray(A, B, low, high);
    }

// Agregar una película al vector
void Inventario::agregarPelicula(const Pelicula& pelicula)
    {
        peliculas.push_back(pelicula);
    }

// Mostrar todas las películas en el vector
void Inventario::mostrarPeliculas() const
    {
        for (const auto& pelicula : peliculas)
        {
            pelicula.mostrarInformacion();
            std::cout << "-------------------------" << std::endl;
        }
    }

// Ordenar por año de lanzamiento usando Merge Sort
void Inventario::ordenarPorLanzamiento()
    {
        std::vector<Pelicula> tmp(peliculas.size());

        // Llama a mergeSplit para iniciar el proceso de ordenación
        mergeSplitLanzamiento(peliculas, tmp, 0, peliculas.size() - 1);
    }

// Ordenar por duracion usando Shell Sort
void Inventario::ordenarPorDuracion()
    {
        int n = (peliculas.size()/ 2);

        while( n > 0)
        {
            for (int i = peliculas.size() - 1; i > 0; i--) 
            {
                for (int j = 0; j + n <= i; j++) 
                {
                    if (peliculas[j].getDuracion() > 
                                             peliculas[j + n].getDuracion()) 
                    {
                        swap(peliculas, j, j + n);
                    }
                }
            }
            n = n / 2;
        }
    }

// Ordenar por título usando Shell Sort
void Inventario::ordenarPorTitulo()
    {
        int n = (peliculas.size()/ 2);

        while( n > 0)
        {
            for (int i = peliculas.size() - 1; i > 0; i--) 
            {
                for (int j = 0; j + n <= i; j++) 
                {
                    if (peliculas[j].getTitulo() > peliculas[j + n].getTitulo()) 
                    {
                        swap(peliculas, j, j + n);
                    }
                }
            }
            n = n / 2;
        }
    }

// Buscar una película por su título usando búsqueda binaria
Pelicula* Inventario::buscarPorTitulo(const std::string& tituloBuscado)
{
    // Ordenar el vector de películas por título con sort
    std::sort(peliculas.begin(), peliculas.end(), 
              [](const Pelicula& a, const Pelicula& b) 
    {
        std::string tituloA = limpiarEspacios(a.getTitulo());
        std::string tituloB = limpiarEspacios(b.getTitulo());

        // Convertir los títulos a minúsculas para ordenamiento 
        std::transform(tituloA.begin(), tituloA.end(), tituloA.begin(), 
                       ::tolower);
        std::transform(tituloB.begin(), tituloB.end(), tituloB.begin(), 
                       ::tolower);

        // Comparación para ordenar alfabéticamente
        return tituloA < tituloB;  
    });

    int izquierda = 0;
    int derecha = peliculas.size() - 1;

    // Limpiar espacios y convertir a minúsculas el título buscado
    std::string tituloLimpio = limpiarEspacios(tituloBuscado);
    std::transform(tituloLimpio.begin(),tituloLimpio.end(),tituloLimpio.begin(), 
                   ::tolower);

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Limpiar espacios y convertir a minúsculas el título de la película 
        std::string tituloMedio = limpiarEspacios(peliculas[medio].getTitulo());
        std::transform(tituloMedio.begin(), tituloMedio.end(), 
                       tituloMedio.begin(), ::tolower);

        if (tituloMedio == tituloLimpio)
        {
            return &peliculas[medio]; 
        }

        else if (tituloMedio < tituloLimpio)
        {
            // Continuar búsqueda a la derecha
            izquierda = medio + 1; 
        }

        else
        {
            // Continuar búsqueda a la izquierda
            derecha = medio - 1; 
        }
    }

    // No se encontró la película
    return nullptr; 
}


#endif // INVENTARIO_H