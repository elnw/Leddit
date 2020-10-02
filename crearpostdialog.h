#ifndef CREARPOSTDIALOG_H
#define CREARPOSTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "cgestion.h"
namespace Ui {
class CrearPostDialog;
}

class CrearPostDialog : public QDialog
{
    Q_OBJECT

public:
    CGestion *objGestion;
    explicit CrearPostDialog(QWidget *parent = nullptr);
    ~CrearPostDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CrearPostDialog *ui;
};

#endif // CREARPOSTDIALOG_H
