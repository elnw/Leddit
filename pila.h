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
    Pila(){
        this->cantidad = 0;
        this->almacenamiento = new ListaEnlazada<T>();
    }
    void Push(T item){
        almacenamiento->Agregar(item);
        cantidad++;
    }
    void Pop(){
        if(cantidad > 0){
            almacenamiento->EliminarInicial();
             cantidad--;
        }
    }
    T Peek(){
        if(cantidad > 0){
            return almacenamiento->ObtenerInicial();
        }else{
            return nullptr;
        }
    }
    int ObtenerCantidad(){
        return cantidad;
    }
};

#endif // PILA_H
