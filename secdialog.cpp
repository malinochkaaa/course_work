#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


SecDialog::SecDialog(QWidget *parent, Database* database_) :
    QDialog(parent),
    ui(new Ui::SecDialog),
    database(database_),
    path_was_chosen(false)
{
    ui->setupUi(this);
    ui->lineEdit_path->setReadOnly(true);
}

SecDialog::~SecDialog()
{
    delete ui;
}



void SecDialog::on_toolButton_dots_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Выберите базу данных", "", "Databases (*.db)");
    ui->lineEdit_path->setText(file_path);
    path_was_chosen = true;
}


void SecDialog::on_pushButton_openBD_clicked()
{
    if(!path_was_chosen){
            QMessageBox::warning(this, "Ошибка!", "Выберите путь!");
            return;
        }
        if(!database->connectToDataBase(ui->lineEdit_path->text())){
            QMessageBox::warning(this, "Ошибка!", "База данных недоступна!");
            return;
        }
        //this->show_login();
        ui->lineEdit_path->clear();
        path_was_chosen = false;
}

void SecDialog::on_pushButton_createDB_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(this, "Выберите базу данных", "", "Databases (*.db)");
        ui->lineEdit_path->setText(file_path);
        if(!file_path.isEmpty())
            path_was_chosen = true;
}
