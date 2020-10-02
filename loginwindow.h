#pragma once
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "cgestion.h"
#include "registerform.h"
#include "ofertasform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnIniciarSesion_clicked();

private:
    Ui::LoginWindow *ui;
    CGestion *objGestion;
    QMessageBox *Msgbox;
    RegisterForm *registerForm;


};
#endif // LOGINWINDOW_H
