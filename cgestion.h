#pragma once
#ifndef CGESTION_H
#define CGESTION_H

#include "pila.h"
#include "usuario.h"
#include "publicacion.h"
#include <fstream>
#include <sstream>
#include <vector>

class CGestion
{
private:
    std::string archivoUsuarios;
    std::string archivoPost;
    Usuario *sesionActual;
    void CargarUsuarios();
    void CargarPublicaciones();
    void GuardarUsuarios();
    void GuardarPublicaciones();

public:
    CGestion();
    ListaEnlazada<Usuario*> *listaUsuarios;
    Pila<Publicacion*> *publicaciones;
    Usuario *IniciarSesion(std::string usuario, std::string contrasena);
    Usuario *ObtenerUsuario(std::string usuario);
    std::string ObtenerUsernameActual();
    std::string ObtenerNombreActual();
    void AgregarPublicacionUsuarioActual(Publicacion publicacion);
    void RegistrarUsuario(Usuario *usuario);
    void CrearPublicacion(Publicacion *publicacion);
    void DescartarPost();
    Publicacion *ObtenerUltimoPost();
    ListaEnlazada<std::string> *ObtenerListaPostUsuarioActual();
    std::vector<std::string> SplitString(std::string cadena, char delimitador = ';');
    void IncrementarKarmaUsuario(std::string autor);
    void ReducirKarmaUsuario(std::string autor);
    Usuario* ObtenerReyDelKarma();
    void GuardarInformacion();

};

#endif // CGESTION_H
