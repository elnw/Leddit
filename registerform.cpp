#include "registerform.h"
#include "ui_registerform.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    Msgbox = new QMessageBox(this);
    ui->txtEdad->setValidator(new QIntValidator(0, 100, this) );
    //gestion = new CGestion();
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_btnRegistrar_clicked()
{
   std::string username = ui->txtuSuario->text().toUtf8().constData();
   std::string contrasena = ui->txtContrasena->text().toUtf8().constData();
   std::string nombreCompleto = ui->txtNombre->text().toUtf8().constData();
   std::string edadTexto = ui->txtEdad->text().toUtf8().constData();
   std::string profesion= ui->txtProfesion->text().toUtf8().constData();

    if(username.length() == 0 || contrasena.length() == 0 || nombreCompleto.length() == 0 || edadTexto.length() == 0 || profesion.length() == 0){
        Msgbox->setText("Debe completar todos los campos para poder registrarse");
        Msgbox->exec();
    }else{
        gestion->RegistrarUsuario(new Usuario(username, contrasena, nombreCompleto, profesion, stoi(edadTexto), 0, new ListaEnlazada<std::string>()));
        Msgbox->setText("Se registró al usuario correctamente");
        Msgbox->exec();
        this->close();
    }


}
