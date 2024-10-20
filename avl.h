/*
 * avl.h
 *
 *  Created on: 19/10/2024
 *      Author: Dalila Fonseca Maya A01711722
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include "pelicula.h"

// Excepción OutOfMemory
class OutOfMemory : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "No se pudo asignar memoria.";
    }
};

// Excepción NoSuchElement
class NoSuchElement : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "No se encontró el elemento en el árbol.";
    }
};

template <class T>
class Node {
private:
    T value;
    Node* left;
    Node* right;
    int level, balance;

    // Método privado para encontrar el predecesor.
    Node<T>* predecesor();  

    template <class U>
    friend class AVL;

public:
    Node(T val);
    void add(T val);
    T* findByTitle(const std::string& title);
    void remove(T val);
    void removeChilds();
    void inorder(std::stringstream& aux) const;
};

template <class T>
Node<T>::Node(T val) : value(val), left(nullptr), right(nullptr), level(0), balance(0) {}

template <class T>
Node<T>* Node<T>::predecesor() 
{
    Node<T>* le = left;
    Node<T>* ri = right;

    if (left == NULL) 
    {
        right = NULL;
        return ri;
    }

    if (left->right == NULL) 
    {
        left = left->left;
        le->left = NULL;
        return le;
    }

    Node<T>* parent = left;
    Node<T>* child = left->right;

    while (child->right != NULL) 
    {
        parent = child;
        child = child->right;
    }

    parent->right = child->left;
    child->left = NULL;
    return child;
}

template <class T>
void Node<T>::add(T val) 
{
    if (val.getTitulo() < value.getTitulo()) 
    {
        if (left != NULL) 
        {
            left->add(val);
        } 
        else 
        {
            left = new Node<T>(val);
        }
    } 
    else 
    {
        if (right != NULL) 
        {
            right->add(val);
        } 
        else 
        {
            right = new Node<T>(val);
        }
    }
}

template <class T>
T* Node<T>::findByTitle(const std::string& title) 
{
    if (title == value.getTitulo()) 
    {
        return &value;
    } 
    else if (title < value.getTitulo()) 
    {
        return (left != NULL) ? left->findByTitle(title) : NULL;
    } 
    else 
    {
        return (right != NULL) ? right->findByTitle(title) : NULL;
    }
}

template <class T>
void Node<T>::remove(T val) 
{
    if (val.getTitulo() < value.getTitulo()) 
    {
        if (left != NULL) 
        {
            if (left->value.getTitulo() == val.getTitulo()) 
            {
                Node<T>* old = left;
                Node<T>* succ = left->predecesor();

                if (succ != NULL) 
                {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                left = succ;
                delete old;
            } 
            else 
            {
                left->remove(val);
            }
        }
    } 
    else if (val.getTitulo() > value.getTitulo()) 
    {
        if (right != NULL) 
        {
            if (right->value.getTitulo() == val.getTitulo()) 
            {
                Node<T>* old = right;
                Node<T>* succ = right->predecesor();

                if (succ != NULL) 
                {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                right = succ;
                delete old;
            } 
            else 
            {
                right->remove(val);
            }
        }
    }
}

template <class T>
void Node<T>::removeChilds() 
{
    if (left != NULL) 
    {
        left->removeChilds();
        delete left;
        left = NULL;
    }
    if (right != NULL) 
    {
        right->removeChilds();
        delete right;
        right = NULL;
    }
}

template <class T>
void Node<T>::inorder(std::stringstream& aux) const 
{
    if (left != NULL) 
    {
        left->inorder(aux);
    }

    aux << "Titulo: " << value.getTitulo() << "\n"
        << "Director: " << value.getDirector() << "\n"
        << "Genero: " << value.getGenero() << "\n"
        << "Año de lanzamiento: " << value.getLanzamiento() << "\n"
        << "Duración: " << value.getDuracion() << " minutos\n\n";

    if (right != NULL) 
    {
        right->inorder(aux);
    }
}

template <class T>
class AVL {
private:
    Node<T>* root;

public:
    AVL();
    ~AVL();
    bool empty() const;
    void add(T val);
    T* findByTitle(const std::string& title) const;
    void remove(T val);
    void removeAll();
    std::string inorder() const;
};

template <class T>
AVL<T>::AVL() : root(NULL) {}

template <class T>
AVL<T>::~AVL() {
    removeAll();
}

template <class T>
bool AVL<T>::empty() const 
{
    return root == NULL;
}

template <class T>
void AVL<T>::add(T val) 
{
    if (root != nullptr) 
    {
        if (findByTitle(val.getTitulo()) == NULL) 
        {
            root->add(val);
        }
    } 
    else 
    {
        root = new Node<T>(val);
    }
}

template <class T>
T* AVL<T>::findByTitle(const std::string& title) const 
{
    return (root != NULL) ? root->findByTitle(title) : NULL;
}

template <class T>
void AVL<T>::remove(T val) 
{
    if (root != NULL) 
    {
        if (val.getTitulo() == root->value.getTitulo()) 
        {
            Node<T>* succ = root->predecesor();

            if (succ != NULL) 
            {
                succ->left = root->left;
                succ->right = root->right;
            }
            delete root;
            root = succ;
        } 
        else 
        {
            root->remove(val);
        }
    }
}

template <class T>
void AVL<T>::removeAll() 
{
    if (root != NULL) 
    {
        root->removeChilds();
        delete root;
        root = NULL;
    }
}

template <class T>
std::string AVL<T>::inorder() const 
{
    std::stringstream aux;

    if (!empty()) 
    {
        root->inorder(aux);
    }
    return aux.str();
}

#endif // AVL_H 
