/*
 * inventario.h
 *
 *  Created on: 19/10/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <vector>

#include "pelicula.h"

// Función auxiliar para limpiar espacios.
std::string limpiarEspacios(const std::string& str) 
{
    std::string resultado = str;

    // Eliminar espacios al inicio y al final de la cadena.
    resultado.erase(0, resultado.find_first_not_of(" \t\n\r\f\v"));
    resultado.erase(resultado.find_last_not_of(" \t\n\r\f\v") + 1);

    return resultado;
}

class Inventario
{
    private:
        // Vector que contiene las películas.
        std::vector<Pelicula> peliculas;

        // Métodos privados para ordenar.
        void copyArray(std::vector<Pelicula> &A, 
                       std::vector<Pelicula> &B, int low, int high);
        void mergeSplitLanzamiento(std::vector<Pelicula>& A, 
                                   std::vector<Pelicula>& B, int low, int high);
        void mergeSplitDuracion(std::vector<Pelicula>& A, 
                                   std::vector<Pelicula>& B, int low, int high); 
        void mergeSplitTitulo(std::vector<Pelicula>& A, 
                                   std::vector<Pelicula>& B, int low, int high);                       
        void mergeArrayLanzamiento(std::vector<Pelicula>& A, 
                          std::vector<Pelicula>& B, int low, int mid, int high);
        void mergeArrayDuracion(std::vector<Pelicula>& A, 
                          std::vector<Pelicula>& B, int low, int mid, int high);
        void mergeArrayTitulo(std::vector<Pelicula>& A, 
                          std::vector<Pelicula>& B, int low, int mid, int high);

    public:
        void agregarPelicula(const Pelicula& pelicula);
        void mostrarPeliculas() const;
        void ordenarPorLanzamiento();
        void ordenarPorDuracion();
        void ordenarPorTitulo();
        void eliminarPelicula(const std::string& titulo );
};

// Copiar elementos de un array a otro.
void Inventario::copyArray(std::vector<Pelicula> &A, 
                           std::vector<Pelicula> &B, int low, int high)
    {
        for (int i = low; i <= high; i++) 
        {
            A[i] = B[i];
        }
    }

// Dividir el array para ordenar por año de lanzamiento (Merge Sort).
void Inventario::mergeSplitLanzamiento(std::vector<Pelicula>& A, 
                            std::vector<Pelicula>& B, int low, int high)
    {
        if(low < high)
        {
            int mid = (high + low) / 2;
		    //mergeSplit de la primera mitad.
	        mergeSplitLanzamiento(A,B,low,mid);

	        //mergeSplit de la segunda mitad.
	        mergeSplitLanzamiento(A,B,mid + 1, high);

	        //mergeArray de ambas mitades.
	        mergeArrayLanzamiento(A,B,low, mid,high);
        }
    }

// Dividir el array para ordenar por Duración (Merge Sort).
void Inventario::mergeSplitDuracion(std::vector<Pelicula>& A, 
                            std::vector<Pelicula>& B, int low, int high)
    {
        if(low < high)
        {
            int mid = (high + low) / 2;
		    //mergeSplit de la primera mitad.
	        mergeSplitDuracion(A,B,low,mid);

	        //mergeSplit de la segunda mitad.
	        mergeSplitDuracion(A,B,mid + 1, high);

	        //mergeArray de ambas mitades.
	        mergeArrayDuracion(A,B,low, mid,high);
        }
    }

// Dividir el array para ordenar por Titulo (Merge Sort).
void Inventario::mergeSplitTitulo(std::vector<Pelicula>& A, 
                            std::vector<Pelicula>& B, int low, int high)
    {
        if(low < high)
        {
            int mid = (high + low) / 2;
		    //mergeSplit de la primera mitad.
	        mergeSplitTitulo(A,B,low,mid);

	        //mergeSplit de la segunda mitad.
	        mergeSplitTitulo(A,B,mid + 1, high);

	        //mergeArray de ambas mitades.
	        mergeArrayTitulo(A,B,low, mid,high);
        }
    }

// Combinar las dos mitades ordenadas por año de lanzamiento.
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

        // Copiar los elementos restantes de la primera mitad.
        while (i <= mid) 
        {
            B[k] = A[i];
            i++;
            k++;
        } 
            
        // Copiar los elementos restantes de la segunda mitad.
        while (j <= high) 
        {
            B[k] = A[j];
            j++;
            k++;
        }

        // Copiar la fusión de nuevo al array original.
        copyArray(A, B, low, high);
    }

// Combinar las dos mitades ordenadas por duración.
void Inventario::mergeArrayDuracion(std::vector<Pelicula>& A, 
                    std::vector<Pelicula>& B, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
	    int k = low;
	        
        while (i <= mid && j <= high) 
        {
            if (A[i].getDuracion() <= A[j].getDuracion()) 
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

        // Copiar los elementos restantes de la primera mitad.
        while (i <= mid) 
        {
            B[k] = A[i];
            i++;
            k++;
        } 
            
        // Copiar los elementos restantes de la segunda mitad.
        while (j <= high) 
        {
            B[k] = A[j];
            j++;
            k++;
        }

        // Copiar la fusión de nuevo al array original.
        copyArray(A, B, low, high);
    }

// Combinar las dos mitades ordenadas por titulo.
void Inventario::mergeArrayTitulo(std::vector<Pelicula>& A, 
                    std::vector<Pelicula>& B, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
	    int k = low;
	        
        while (i <= mid && j <= high) 
        {
            if (A[i].getTitulo() <= A[j].getTitulo()) 
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

        // Copiar los elementos restantes de la primera mitad.
        while (i <= mid) 
        {
            B[k] = A[i];
            i++;
            k++;
        } 
            
        // Copiar los elementos restantes de la segunda mitad.
        while (j <= high) 
        {
            B[k] = A[j];
            j++;
            k++;
        }

        // Copiar la fusión de nuevo al array original.
        copyArray(A, B, low, high);
    }

// Agregar una película al vector.
void Inventario::agregarPelicula(const Pelicula& pelicula)
    {
        peliculas.push_back(pelicula);
    }

// Mostrar todas las películas en el vector.
void Inventario::mostrarPeliculas() const
    {
        for (const auto& pelicula : peliculas)
        {
            pelicula.mostrarInformacion();
            std::cout << "-------------------------" << std::endl;
        }
    }

// Ordenar por año de lanzamiento usando Merge Sort.
void Inventario::ordenarPorLanzamiento()
    {
        std::vector<Pelicula> tmp(peliculas.size());

        // Llama a mergeSplit para iniciar el proceso de ordenación.
        mergeSplitLanzamiento(peliculas, tmp, 0, peliculas.size() - 1);
    }

// Ordenar por duración usando Merge Sort.
void Inventario::ordenarPorDuracion()
    {
        std::vector<Pelicula> tmp(peliculas.size());

        // Llama a mergeSplit para iniciar el proceso de ordenación.
        mergeSplitDuracion(peliculas, tmp, 0, peliculas.size() - 1);
    }

// Ordenar por titulo usando Merge Sort.
void Inventario::ordenarPorTitulo()
    {
        std::vector<Pelicula> tmp(peliculas.size());

        // Llama a mergeSplit para iniciar el proceso de ordenación.
        mergeSplitTitulo(peliculas, tmp, 0, peliculas.size() - 1);
    }

void Inventario::eliminarPelicula(const std::string& titulo) 
{
    peliculas.erase(std::remove_if(peliculas.begin(), peliculas.end(),
                                   [&titulo](const Pelicula& p) 
                                   {
                                       return p.getTitulo() == titulo;
                                   }),
                    peliculas.end());
}
#endif // INVENTARIO_H
