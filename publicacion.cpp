#include "publicacion.h"

Publicacion::Publicacion()
{

}

Publicacion::Publicacion(std::string titulo, std::string contenido, std::string profesionalRequerido, std::string autor, int edadMinima = -1, int edadMaxima = -1){
    this->titulo = titulo;
    this->contenido = contenido;
    this->profesionalRequerido = profesionalRequerido;
    this->edadMinima = edadMinima;
    this->edadMaxima = edadMaxima;
    this->autor = autor;

}
std::string Publicacion::ObtenerTitulo(){
    return this->titulo;
}
std::string Publicacion::ObtenerContenido(){
    return this->contenido;
}
std::string Publicacion::ObtenerProfRequerido(){
    return this->profesionalRequerido;
}
int Publicacion::ObtenerEdadMinima(){
    return this->edadMinima;
}
int Publicacion::ObtenerEdadMaxima(){
    return this->edadMaxima;
}

std::string Publicacion::ObtenerAutor(){
    return this->autor;
}
