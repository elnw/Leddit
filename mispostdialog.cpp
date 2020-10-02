#include "mispostdialog.h"
#include "ui_mispostdialog.h"

MisPostDialog::MisPostDialog(ListaEnlazada<std::string> *listaPosts,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MisPostDialog)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    Nodo<std::string> *iterador = listaPosts->ObtenerIterador();
    QStringList listaStrings;
    while(iterador != nullptr){
        listaStrings << QString::fromStdString(iterador->dato);
        iterador = iterador->siguiente;
    }

    model->setStringList(listaStrings);
    ui->listaPost->setModel(model);
}

MisPostDialog::~MisPostDialog()
{
    delete ui;
}

void MisPostDialog::on_btncerrar_clicked()
{
    this->close();
}
