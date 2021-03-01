#ifndef FK_CREATE_H
#define FK_CREATE_H

#include "database.h"
#include <QDialog>

namespace Ui {
class FK_create;
}

class FK_create : public QDialog
{
    Q_OBJECT

public:
    explicit FK_create(QWidget *parent = nullptr, Database* database_=nullptr);
    ~FK_create();
    void setFKTable(QString value) { FK_table = value; }

signals:
    void tableWasChosen(QString FK_table_name, QString PK_table_name);
    void isClosed(bool should_show_columns);

private slots:
   void on_listView_clicked(const QModelIndex &index);
   void on_pushButton_choose_clicked();

private:
    Ui::FK_create *ui;
    Database* database;
    QString FK_table;
    QString chosenTable;
};

#endif // FK_CREATE_H
