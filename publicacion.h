#pragma once
#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include "listaenlazada.h"

class Publicacion
{
private:
    std::string titulo;
    std::string contenido;
    std::string profesionalRequerido;
    int edadMinima;
    int edadMaxima;
    std::string autor;
public:
    Publicacion();
    Publicacion(std::string titulo, std::string contenido, std::string profesionalRequerido, std::string autor, int edadMinima, int edadMaxima);
    std::string ObtenerTitulo();
    std::string ObtenerContenido();
    std::string ObtenerProfRequerido();
    int ObtenerEdadMinima();
    int ObtenerEdadMaxima();
    std::string ObtenerAutor();
};

#endif // PUBLICACION_H
