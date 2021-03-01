#ifndef DB_THIRDDIALOG_H
#define DB_THIRDDIALOG_H

#include <QWidget>
#include <QObject>
#include <QDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QDebug>

#include "create_column.h"
#include "database.h"
#include "fk_create.h"

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
    void mainWindow();

private slots:
       void on_relogin_triggered();
       void on_exit_triggered();
       void on_list_tableNames_doubleClicked(const QModelIndex &index);
       //void on_pushButton_AddTable_clicked();
       void on_update_triggered();
       void on_list_tableNames_clicked(const QModelIndex &index);
       void on_pushButton_DeleteTable_clicked();
       void update(bool should_show_columns);
       //void on_pushButton_AddCol_clicked();
       void on_list_columnNames_clicked(const QModelIndex &index);
       void on_pushButton_DeleteCol_clicked();
       void changeChosenColumn(QString new_name);
       //void on_pushButton_RenameCol_clicked();
       void on_pushButton_makeFK_clicked();

private:
    Ui::Db_thirddialog *ui;
    Database* database;
    Db_thirddialog *adm_win;
    FK_create* fk_create;
    Create_column* create;
    QString chosenTable;
    QString chosenTable_double_clicked;
    QString chosenColumn;
    QStringListModel* empty_model;
};

#endif // DB_THIRDDIALOG_H
