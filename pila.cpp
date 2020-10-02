/*#include "pila.h"

template <typename T>
Pila<T>::Pila()
{
    this->cantidad = 0;
    this->almacenamiento = new ListaEnlazada<T>();
}

template <typename T>
void Pila<T>::Push(T item){
    almacenamiento->Agregar(item);
    cantidad++;
}

template <typename T>
void Pila<T>::Pop(){
    if(cantidad > 0){
        almacenamiento->EliminarInicial();
         cantidad--;
    }
}

template <typename T>
T Pila<T>::Peek(){
    if(cantidad > 0){
        return almacenamiento->ObtenerInicial();
    }else{
        return nullptr;
    }

}*/


