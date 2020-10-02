#pragma once
#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <QIntValidator>
#include <QMessageBox>
#include "cgestion.h"

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    CGestion *gestion;
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void on_btnRegistrar_clicked();

private:
    Ui::RegisterForm *ui;
    QMessageBox *Msgbox;

};

#endif // REGISTERFORM_H
