#ifndef DB_THIRDDIALOG_H
#define DB_THIRDDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include <QMainWindow>

#include "database.h"

namespace Ui {
class Db_thirddialog;
}

class Db_thirddialog : public QWidget
{
    Q_OBJECT

public:
    explicit Db_thirddialog(QWidget *parent = nullptr, Database* database_=nullptr);
    ~Db_thirddialog();

signals:
    void loginWindow();

private:
    Ui::Db_thirddialog *ui;
    Database* database;
};

#endif // DB_THIRDDIALOG_H
