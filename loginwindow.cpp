#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    objGestion = new CGestion();
    Msgbox = new QMessageBox(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//registrar usuario
void LoginWindow::on_pushButton_clicked()
{
    registerForm = new RegisterForm();
    registerForm->gestion = objGestion;
    registerForm->showNormal();
}

void LoginWindow::on_btnIniciarSesion_clicked()
{
    std::string usuarioIngresado = ui->txtUsuario->text().toUtf8().constData();
    std::string contrasenaIngresada = ui->txtClave->text().toUtf8().constData();

    if(usuarioIngresado.size() == 0 || contrasenaIngresada.size() == 0){
        Msgbox->setText("Debe ingresar todos los datos");
        Msgbox->exec();
    }else{
        Usuario *usuarioLogueado = objGestion->IniciarSesion(usuarioIngresado, contrasenaIngresada);

        if(usuarioLogueado == nullptr){
            Msgbox->setText("Usuario y/o contraseña incorrecta");
            Msgbox->exec();
        }else{
            OfertasForm *ofertasForm = new OfertasForm(this->objGestion);
            ofertasForm->show();
            this->close();
        }

    }

}
