//#include "listaenlazada.h"

/*template <typename T>
ListaEnlazada<T>::ListaEnlazada()
{
    this->cabeza = nullptr;
}

template <typename T>
void ListaEnlazada<T>::Agregar(T valorAgregar){
    Nodo<T>* nuevoNodo = new Nodo<T>();
    nuevoNodo->dato = valorAgregar;
    nuevoNodo->siguiente = this->cabeza;
    cabeza = nuevoNodo;
}

template <typename T>
bool ListaEnlazada<T>::Existe(T item){
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

template <typename T>
T ListaEnlazada<T>::Existe(T item, std::function<bool(T,T)> comp){
    Nodo<T>* iterador = this->cabeza;

    while(iterador != nullptr){
        if(comp(iterador->dato, item)){
            return iterador;
        }
        iterador = iterador->siguiente;
    }

    return nullptr;
}

template <typename T>
T ListaEnlazada<T>::ObtenerInicial(){
    return this->cabeza;
}

template <typename T>
void ListaEnlazada<T>::EliminarInicial(){
    Nodo<T>* prim = this->cabeza->siguiente;
    this->cabeza = nullptr;
    cabeza = prim;
}*/
