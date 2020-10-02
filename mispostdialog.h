#ifndef MISPOSTDIALOG_H
#define MISPOSTDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include "listaenlazada.h"

namespace Ui {
class MisPostDialog;
}

class MisPostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MisPostDialog(ListaEnlazada<std::string> *listaPosts, QWidget *parent = nullptr);
    ~MisPostDialog();

private slots:
    void on_btncerrar_clicked();

private:
    Ui::MisPostDialog *ui;
    QStringListModel *model;
};

#endif // MISPOSTDIALOG_H
