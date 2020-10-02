#pragma once
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "listaenlazada.h"
#include "publicacion.h"
class Usuario
{
private:
    std::string username;
    std::string contrasena;
    std::string nombreCompleto;
    int edad;
    std::string profesion;
    int karma;
    ListaEnlazada<std::string> *misPublicaciones;
public:
    Usuario();
    Usuario(std::string un, std::string con);
    Usuario(std::string un, std::string con, std::string nc, std::string prof, int ed,int karma, ListaEnlazada<std::string> *misPublicaciones);
    Usuario(std::string un);
    std::string ObtenerUsername();
    std::string ObtenerContrasena();
    std::string ObtenerNombreCompleto();
    std::string ObtenerProfesion();
    int ObtenerEdad();
    ListaEnlazada<std::string> *ObtenerPublicaciones();
    void AgregarPublicacion(Publicacion publicacion);
    void GestionarKarma(bool sube);
    int ObtenerKarma();
    static bool ValidarSesion(Usuario *a, Usuario *b);
    static bool BuscarUsuario(Usuario *a, Usuario *b);
};

#endif // USUARIO_H
