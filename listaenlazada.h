#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"
#include <functional>


template <class T>
class ListaEnlazada
{
private:
    Nodo<T> *cabeza;
public:
    ListaEnlazada(){
        this->cabeza = nullptr;
    }
    void Agregar(T item){ //O(1) - 4
        Nodo<T>* nuevoNodo = new Nodo<T>();
        nuevoNodo->dato = item;
        if(this->cabeza != nullptr)nuevoNodo->siguiente = this->cabeza;
        cabeza = nuevoNodo;
    }
    bool Existe(T item){ // O(N) - 4 + 5N
        bool existeItem = false;
        Nodo<T>* iterador = this->cabeza;

        while(iterador != nullptr){
            if(iterador->dato == item){
                existeItem = true;
                break;
            }
            iterador = iterador->siguiente;
        }

        return existeItem;
    }
    T Existe(T item, std::function<bool(T,T)> comp){ // O(N) - 3 + 6N
        Nodo<T>* iterador = this->cabeza;

        while(iterador != nullptr){
            if(comp(iterador->dato, item)){
                return iterador->dato;
            }
            iterador = iterador->siguiente;
        }

        return nullptr;
    }

    T Obtener(int n){ // O(N) - 4 + 7N
        int contador = 0;
        Nodo<T>* iterador = this->cabeza;

        while(iterador != nullptr){
            if(contador == n){
                return iterador->dato;
            }
            iterador = iterador->siguiente;
            contador++;
        }

        return nullptr;
    }

    T ObtenerInicial(){
         return this->cabeza->dato;
    }
    void EliminarInicial(){
        Nodo<T>* prim = this->cabeza->siguiente;
        this->cabeza = nullptr;
        cabeza = prim;
    }

    Nodo<T> *ObtenerIterador(){
        return this->cabeza;
    }
};

#endif // LISTAENLAZADA_H
