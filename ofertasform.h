#ifndef OFERTASFORM_H
#define OFERTASFORM_H

#include <QWidget>
#include <QMessageBox>
#include "cgestion.h"
#include "crearpostdialog.h"
#include "mispostdialog.h"

namespace Ui {
class OfertasForm;
}

class OfertasForm : public QWidget
{
    Q_OBJECT

public:
    CGestion *objGestion;
    explicit OfertasForm(CGestion *og, QWidget *parent = nullptr);
    ~OfertasForm();

private slots:
    void on_btnSalir_clicked();

    void on_btnInteresa_clicked();

    void on_btnNoInteresa_clicked();

    void on_btnActualizar_clicked();

    void on_btnCrearPost_clicked();

    void on_btnMisPost_clicked();

    void on_btnKarma_clicked();

private:
    Ui::OfertasForm *ui;
    void CargarOferta();
};

#endif // OFERTASFORM_H
