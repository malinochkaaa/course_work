#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Database* database_) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    database(database_),
    admin_chosen(true)
{
    ui->setupUi(this);
    ui->radioButton_Admin->click();
  //  ui->lineEdit_password->setEchoMode(QLineEdit::Password);
   // this->hide_login();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString role;
    QString res = database->checkPassword(admin_chosen, username, password);

  if(admin_chosen) {
        if(username == "test" && password == "test"){
            secDialog = new SecDialog(this);
            secDialog->show();
        }
        if(username == "test" && password != "test")
            QMessageBox::warning(this, "Login", "Password is not correct");
        if(username != "test" && password == "test")
            QMessageBox::warning(this, "Login", "Username is not correct");
        if(username != "test" && password != "test")
            QMessageBox::warning(this, "Login", "Login and Password are not correct");
   }
    /*if(!res.isEmpty()){
            QMessageBox::warning(this, "Ошибка!", res);
            return;
        }
        if(admin_chosen){
            this->close();
            adm_win = new Db_thirddialog(this, database);
           adm_win->setAttribute(Qt::WA_DeleteOnClose);
           connect(adm_win, &Db_thirddialog::mainWindow, this, &MainWindow::show);
           connect(adm_win, &Db_thirddialog::mainWindow, this, &MainWindow::hide_login);
           // connect(adm_win, SIGNAL(mainWindow()), this, SIGNAL(show()));
            //connect(adm_win, SIGNAL(mainWindow()), this, SIGNAL(hide_login()));
            adm_win->show();
        }*/ /* else{
            this->close();
            oper_win = new MainWindow(this, database);
            oper_win->setAttribute(Qt::WA_DeleteOnClose);
            connect(oper_win, &MainWindow::loginWindow, this, &LoginWindow::show);
            connect(oper_win, &MainWindow::loginWindow, this, &LoginWindow::hide_login);
            oper_win->show();
        }*/

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}

void MainWindow::on_radioButton_Admin_clicked()
{
    admin_chosen = true;
}

void MainWindow::on_radioButton_Operator_clicked()
{
    admin_chosen = false;
}
void MainWindow::hide_login(){
    ui->lineEdit_username->hide();
    ui->lineEdit_password->hide();
    ui->radioButton_Admin->hide();
    ui->radioButton_Operator->hide();
    ui->pushButton_login->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
}
void MainWindow::show_login(){
    ui->lineEdit_username->show();
    ui->lineEdit_password->show();
    ui->radioButton_Admin->show();
    ui->radioButton_Operator->show();
    ui->pushButton_login->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
}
