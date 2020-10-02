#include "usuario.h"

Usuario::Usuario()
{

}

Usuario::Usuario(std::string un, std::string con)
{
    this->username = un;
    this->contrasena = con;
}
Usuario::Usuario(std::string un){
    this->username = un;
}

Usuario::Usuario(std::string un, std::string con, std::string nc, std::string prof, int ed, int karma, ListaEnlazada<std::string> *misPublicaciones)
{
    this->username = un;
    this->contrasena = con;
    this->nombreCompleto = nc;
    this->profesion = prof;
    this->edad = ed;
    this->misPublicaciones = misPublicaciones;
    this->karma = karma;
}

std::string Usuario::ObtenerUsername(){
    return this->username;
}
std::string Usuario::ObtenerContrasena(){
    return this->contrasena;
}
std::string Usuario::ObtenerNombreCompleto(){
    return this->nombreCompleto;
}
std::string Usuario::ObtenerProfesion(){
    return this->profesion;
}
int Usuario::ObtenerEdad(){
    return this->edad;
}

bool Usuario::ValidarSesion(Usuario *a, Usuario *b){
    return ((a->username == b->username) && (a->contrasena == b->contrasena));
}

bool Usuario::BuscarUsuario(Usuario *a, Usuario *b){
    return (a->username == b->username);
}

ListaEnlazada<std::string> *Usuario::ObtenerPublicaciones(){
    return this->misPublicaciones;
}

void Usuario::AgregarPublicacion(Publicacion publicacion){
    misPublicaciones->Agregar(publicacion.ObtenerTitulo());
}

void Usuario::GestionarKarma(bool sube){
    this->karma = this->karma + (sube ==false)*(-1) + (sube);
}

int Usuario::ObtenerKarma(){
    return this->karma;
}

