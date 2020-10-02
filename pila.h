#pragma once
#ifndef PILA_H
#define PILA_H

#include "listaenlazada.h"

template <class T>
class Pila
{
private:
    ListaEnlazada<T> *almacenamiento;
    int cantidad;
public:
    Pila(){ //=O(n) - 2
        this->cantidad = 0;
        this->almacenamiento = new ListaEnlazada<T>();
    }
    void Push(T item){// O(1) - 4
        almacenamiento->Agregar(item);
        cantidad++;
    }
    void Pop(){ //O(1) - 5
        if(cantidad > 0){
            almacenamiento->EliminarInicial();
             cantidad--;
        }
    }
    T Peek(){ // O(1) - 2
        if(cantidad > 0){
            return almacenamiento->ObtenerInicial();
        }else{
            return nullptr;
        }
    }
    int ObtenerCantidad(){ //O(1) - 1
        return cantidad;
    }
};

#endif // PILA_H
