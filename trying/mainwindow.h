#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <QLineEdit>

#include <secdialog.h>
#include <database.h>
#include <db_thirddialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Database* database_=nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();
    void on_radioButton_Admin_clicked();
    void on_radioButton_Operator_clicked();
    void hide_login();
    void show_login();

private:
    Ui::MainWindow *ui;
    QDialog *secDialog;
    Database* database;
    Create_column* create;
    Db_thirddialog *adm_win;
    bool admin_chosen;
};
#endif // MAINWINDOW_H
