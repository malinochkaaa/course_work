#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <algorithm>
#include <QtSql>

class Database : public QObject{
    Q_OBJECT

public:
    explicit Database(QObject *parent = nullptr);
    ~Database();
    QString checkPassword(bool admin_chosen, QString username, QString password);
    bool connectToDataBase(QString path);
    const QSqlDatabase* getDatabase() const { return &database; }
    QSqlRelationalTableModel* printTable(QString table_name);
    QStringListModel* getTables();
    QStringListModel* getColumns(QString table_name);
    int getLastID(QString table_name);
    bool insertLineInto(QString table_name);
    bool deleteLineFrom(QString table_name, int id);
    int getID(QString table_name, int row);
    QString getColumnName(QString table_name, int col);
    bool updateField(QString table_name, int col, int ID, QString value);

public slots:
    bool addColumn(QString table_name, QString column_name, QString column_type);
    bool deleteColumn(QString table_name, QString column_name);
    bool addTable(QString table_name);
    bool deleteTable(QString table_name);
    bool renameColumn(QString table_name, QString old_name, QString new_name);
    bool makeForeignKey(QString FK_table_name, QString PK_table_name);

private:
    QSqlDatabase database;
    QSqlRelationalTableModel* model{nullptr};
    QStringListModel* table_names_model{nullptr};
    QStringListModel* column_names_model{nullptr};
    QStringList admin_logins;
    QStringList admin_passwords;
    QStringList operator_logins;
    QStringList operator_passwords;
    bool openDataBase(QString path);
    void closeDataBase();

};

#endif // DATABASE_H
