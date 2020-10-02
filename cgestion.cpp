#include "cgestion.h"

CGestion::CGestion()
{
    this->listaUsuarios = new ListaEnlazada<Usuario*>();
    this->publicaciones = new Pila<Publicacion*>();

    archivoUsuarios  = "../RedSocial/archivo_usuarios.txt";
    archivoPost = "../RedSocial/archivo_post.txt";

    CargarUsuarios();
    CargarPublicaciones();
}


Usuario *CGestion::IniciarSesion(std::string usuario, std::string contrasena){
    sesionActual = listaUsuarios->Existe(new Usuario(usuario,contrasena), [](Usuario *a, Usuario *b) -> bool{ return Usuario::ValidarSesion(a,b);});
    return sesionActual;
}
Usuario *CGestion::ObtenerUsuario(std::string un){
    return listaUsuarios->Existe(new Usuario(un), [](Usuario *a, Usuario *b) ->bool{ return Usuario::BuscarUsuario(a,b);});
}
void CGestion::RegistrarUsuario(Usuario *usuario){
    listaUsuarios->Agregar(usuario);
}
void CGestion::CrearPublicacion(Publicacion *publicacion){
    publicaciones->Push(publicacion);
}
void CGestion::DescartarPost(){
    publicaciones->Pop();
}

Publicacion *CGestion::ObtenerUltimoPost(){
    return publicaciones->Peek();
}

void CGestion::CargarUsuarios(){
    std::ifstream archivo;
    std::string usuario, clave, nombre, prof, karmaTexto, linea="";
    int edad;

    archivo.open(archivoUsuarios);
    if(archivo){
        while(std::getline(archivo, linea)){
            std::vector<std::string> lineaDesparseada = SplitString(linea);
            if(lineaDesparseada.size() < 6){
                throw;
            }else{
                usuario = lineaDesparseada[0];
                clave = lineaDesparseada[1];
                nombre = lineaDesparseada[2];
                edad = std::stoi(lineaDesparseada[3]);
                prof = lineaDesparseada[4];
                karmaTexto = lineaDesparseada[5];
                ListaEnlazada<std::string> *listaPublicaciones = new ListaEnlazada<std::string>();
                if(lineaDesparseada.size() > 6){
                    for(unsigned long i=6;i<lineaDesparseada.size();i++){
                        listaPublicaciones->Agregar(lineaDesparseada[i]);
                    }
                }
                listaUsuarios->Agregar(new Usuario(usuario, clave, nombre, prof, edad, std::stoi(karmaTexto),listaPublicaciones));
            }
        }
    }

    archivo.close();
}
void CGestion::CargarPublicaciones(){
     std::ifstream archivo(archivoPost);
     std::string titulo, contenido, profRequerido,autor, linea;
     int edadMinima, edadMaxima;

     while(std::getline(archivo, linea)){
        std::vector<std::string> lineaDesparseada = SplitString(linea);
        if(lineaDesparseada.size() < 6){
            throw;
        }else{
            titulo = lineaDesparseada[0];
            contenido = lineaDesparseada[1];
            profRequerido = lineaDesparseada[2];
            edadMinima = std::stoi(lineaDesparseada[3]);
            edadMaxima = std::stoi(lineaDesparseada[4]);
            autor = lineaDesparseada[5];
            publicaciones->Push(new Publicacion(titulo, contenido, profRequerido,autor, edadMinima, edadMaxima));

        }
     }
    archivo.close();
}

std::vector<std::string> CGestion::SplitString(std::string cadena, char delimitador){
    std::vector<std::string> strings;
    std::string temp = "";
    for(unsigned long i=0;i<cadena.length();i++){
        if(cadena[i] != delimitador){
            temp += cadena[i];
        }else{
            strings.push_back(temp);
            temp = "";
        }
    }

    if(temp != ""){
        strings.push_back(temp);
    }

    return strings;
}

std::string CGestion::ObtenerUsernameActual(){
    return this->sesionActual->ObtenerUsername();
}

void CGestion::AgregarPublicacionUsuarioActual(Publicacion publicacion){
    this->sesionActual->AgregarPublicacion(publicacion);
}

void CGestion::IncrementarKarmaUsuario(std::string autor){
    Usuario *usuarioEncontrado = this->listaUsuarios->Existe(new Usuario(autor), [](Usuario *a, Usuario *b) ->bool{ return Usuario::BuscarUsuario(a,b); });

    if(usuarioEncontrado != nullptr){
        usuarioEncontrado->GestionarKarma(true);
    }

}
void CGestion::ReducirKarmaUsuario(std::string autor){
    Usuario *usuarioEncontrado = this->listaUsuarios->Existe(new Usuario(autor), [](Usuario *a, Usuario *b) ->bool{ return Usuario::BuscarUsuario(a,b); });

    if(usuarioEncontrado != nullptr){
        usuarioEncontrado->GestionarKarma(false);
    }
}

ListaEnlazada<std::string> *CGestion::ObtenerListaPostUsuarioActual(){
    return sesionActual->ObtenerPublicaciones();
}

Usuario *CGestion::ObtenerReyDelKarma(){
    Nodo<Usuario*> *iterador = listaUsuarios->ObtenerIterador();
    Usuario *reyKarma;
    int temp=-10000;
    while(iterador != nullptr){

        if(iterador->dato->ObtenerKarma() > temp){
            temp = iterador->dato->ObtenerKarma();
            reyKarma = iterador->dato;
        }

        iterador = iterador->siguiente;
    }

    return reyKarma;
}

void CGestion::GuardarUsuarios(){
    std::ofstream archivo;

    archivo.open(archivoUsuarios, std::ofstream::out | std::ofstream::trunc);

    if(archivo){
         Nodo<Usuario*> *iterador = listaUsuarios->ObtenerIterador();
        while(iterador != nullptr){
            Usuario *usActual = iterador->dato;
            archivo << usActual->ObtenerUsername() << ";" << usActual->ObtenerContrasena() << ";" << usActual->ObtenerNombreCompleto() << ";" << usActual->ObtenerEdad() << ";" << usActual->ObtenerProfesion() << ";" << usActual->ObtenerKarma();

            Nodo<std::string> *iteradorPosts = usActual->ObtenerPublicaciones()->ObtenerIterador();

            while(iteradorPosts != nullptr){
                archivo << ";" << iteradorPosts->dato;

                iteradorPosts = iteradorPosts->siguiente;
            }
            archivo << std::endl;

            iterador = iterador->siguiente;
        }
    }
    archivo.close();
}

void CGestion::GuardarPublicaciones(){
    std::ofstream archivo;

    archivo.open(archivoPost, std::ofstream::out | std::ofstream::trunc);

    if(archivo){
        Publicacion *actual = publicaciones->Peek();
        archivo << actual->ObtenerTitulo() << ";" << actual->ObtenerContenido() << ";" << actual->ObtenerProfRequerido() << ";" << actual ->ObtenerEdadMinima() << ";" << actual ->ObtenerEdadMaxima() << ";" << actual->ObtenerAutor() << std::endl;
        publicaciones->Pop();
    }
    archivo.close();
}

void CGestion::GuardarInformacion(){
    GuardarUsuarios();
    GuardarPublicaciones();
}

