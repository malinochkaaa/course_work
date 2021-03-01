#ifndef CREATE_COLUMN_H
#define CREATE_COLUMN_H

#include "database.h"
#include <QDialog>

namespace Ui {
class Create_column;
}

class Create_column : public QDialog
{
    Q_OBJECT

public:
    explicit Create_column(QWidget *parent = nullptr, Database* database_=nullptr);
    ~Create_column();
    QString getName() const { return name; }
    QString getType() const { return type; }
    void setTableName(QString value) { table_name = value; }

signals:
    void nameIsEntered(QString table_name_, QString new_name, QString new_type);
    void isClosed(bool should_show_columns);

private slots:
    void on_pushButton_create_clicked();

private:
    Ui::Create_column *ui;
    Database* database;
    Create_column* create;
    QString table_name;
    QString name;
    QString type;

};

#endif // CREATE_COLUMN_H
