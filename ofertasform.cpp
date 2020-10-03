#include "ofertasform.h"
#include "ui_ofertasform.h"

OfertasForm::OfertasForm(CGestion *og, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OfertasForm)
{
    ui->setupUi(this);
    this->objGestion = og;
    CargarOferta();
    ui->lblTitulo->setText("Hola, " + QString::fromStdString(objGestion->ObtenerNombreActual()) + ", mira los post de hoy");
}

OfertasForm::~OfertasForm()
{
    delete ui;
}

void OfertasForm::on_btnSalir_clicked()
{
    objGestion->GuardarInformacion();
    QCoreApplication::quit();
}

void OfertasForm::CargarOferta(){
    if(objGestion->publicaciones->ObtenerCantidad() > 0){
        Publicacion *objPublicacion;

        objPublicacion = objGestion->publicaciones->Peek();
        ui->lblEdades->show();
        ui->lblContenido->show();
        ui->lblProfesional->show();

        ui->lblTitulo_2->setText(QString::fromStdString(objPublicacion->ObtenerTitulo()));
        ui->lblProfesional->setText(QString::fromStdString(objPublicacion->ObtenerProfRequerido()));
        if(objPublicacion->ObtenerEdadMinima() != -1 && objPublicacion->ObtenerEdadMaxima() != -1){
            ui->lblEdades->setText("Entre " + QString::fromStdString(std::to_string(objPublicacion->ObtenerEdadMinima())) + " años y " + QString::fromStdString(std::to_string(objPublicacion->ObtenerEdadMaxima())) + " años");
        }else{
            if(objPublicacion->ObtenerEdadMinima() != -1){
                ui->lblEdades->setText("A partir de los " + QString::fromStdString(std::to_string(objPublicacion->ObtenerEdadMinima())) + " años");
            }else{
                if(objPublicacion->ObtenerEdadMaxima() != -1){
                     ui->lblEdades->setText("Hasta los " + QString::fromStdString(std::to_string(objPublicacion->ObtenerEdadMaxima())) + " años");
                }else{
                    ui->lblEdades->setText("Sin requerimiento de edad");
                }
            }
        }
        ui->lblContenido->setText(QString::fromStdString(objPublicacion->ObtenerContenido()));

    }else{
        ui->lblTitulo_2->setText("No hay mas publicaciones :(");
        ui->lblEdades->hide();
        ui->lblContenido->hide();
        ui->lblProfesional->hide();
    }

}

void OfertasForm::on_btnInteresa_clicked()
{
    Publicacion *objPublicacion = objGestion->publicaciones->Peek();
    if(objPublicacion != nullptr){
        objGestion->IncrementarKarmaUsuario(objPublicacion->ObtenerAutor());
        objGestion->publicaciones->Pop();
        CargarOferta();
    }

}

void OfertasForm::on_btnNoInteresa_clicked()
{
    Publicacion *objPublicacion = objGestion->publicaciones->Peek();
    if(objPublicacion != nullptr){
        objGestion->ReducirKarmaUsuario(objGestion->publicaciones->Peek()->ObtenerAutor());
        objGestion->publicaciones->Pop();
        CargarOferta();
    }

}

void OfertasForm::on_btnActualizar_clicked()
{
     CargarOferta();
}

void OfertasForm::on_btnCrearPost_clicked()
{
    CrearPostDialog *crearPostDialog = new CrearPostDialog();
    crearPostDialog->objGestion = this->objGestion;
    crearPostDialog->show();
}

void OfertasForm::on_btnMisPost_clicked()
{
    MisPostDialog *misPostsDialog = new MisPostDialog(objGestion->ObtenerListaPostUsuarioActual());
    misPostsDialog->show();
}

void OfertasForm::on_btnKarma_clicked()
{
    Usuario *reyKarma = this->objGestion->ObtenerReyDelKarma();
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setText("El rey del karma es: " + QString::fromStdString(reyKarma->ObtenerUsername()) + " con " + QString::fromStdString(std::to_string(reyKarma->ObtenerKarma())) + " puntos");
    msgBox->exec();
}
