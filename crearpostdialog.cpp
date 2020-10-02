#include "crearpostdialog.h"
#include "ui_crearpostdialog.h"

CrearPostDialog::CrearPostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrearPostDialog)
{
    ui->setupUi(this);
}

CrearPostDialog::~CrearPostDialog()
{
    delete ui;
}

void CrearPostDialog::on_buttonBox_accepted()
{
    std::string titulo, profesional, contenido, txtedadMinima, txtedadMaxima;
    int edadMinima, edadMaxima;

    titulo = ui->txtTitulo->text().toUtf8().constData();
    profesional = ui->txtProfesion->text().toUtf8().constData();
    contenido = ui->txtContenido->toPlainText().toUtf8().constData();
    txtedadMinima = ui->txtMinEdad->text().toUtf8().constData();
    txtedadMaxima = ui->txtMaxEdad->text().toUtf8().constData();

    if(txtedadMinima == ""){
        edadMinima = -1;
    }else{
        edadMinima = std::stoi(txtedadMinima);
    }

    if(txtedadMaxima == ""){
        edadMaxima = -1;
    }else{
        edadMaxima = std::stoi(txtedadMaxima);
    }

    objGestion->publicaciones->Push(new Publicacion(titulo, contenido, profesional, objGestion->ObtenerUsernameActual(), edadMinima, edadMaxima));
    objGestion->AgregarPublicacionUsuarioActual(Publicacion(titulo, contenido, profesional, objGestion->ObtenerUsernameActual(), edadMinima, edadMaxima));

    QMessageBox *Msgbox = new QMessageBox();
    Msgbox->setText("Se registró exitosamente");
    Msgbox->exec();
}

void CrearPostDialog::on_buttonBox_rejected()
{
    this->close();
}
