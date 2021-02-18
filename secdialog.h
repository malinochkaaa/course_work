#ifndef SECDIALOG_H
#define SECDIALOG_H

#include "database.h"
#include "mainwindow.h"

#include <QDialog>
#include <QWidget>
#include <QFileDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr, Database* database_=nullptr);
    ~SecDialog();


private slots:
    void on_toolButton_dots_clicked();
    void on_pushButton_openBD_clicked();
    void on_pushButton_createDB_clicked();
private:
    Ui::SecDialog *ui;
    Database* database;
    bool path_was_chosen;
};

#endif // SECDIALOG_H
