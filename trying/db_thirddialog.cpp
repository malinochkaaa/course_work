#include "db_thirddialog.h"
#include "ui_db_thirddialog.h"
#include <QDebug>

Db_thirddialog::Db_thirddialog(QWidget *parent, Database* database_) :
    QWidget(parent),
    ui(new Ui::Db_thirddialog),
    database(database_),
    empty_model(new QStringListModel())
{
    chosenTable_double_clicked = "";
    ui->setupUi(this);

    ui->list_tableNames->setModel(database->getTables());
    ui->list_tableNames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->list_columnNames->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Db_thirddialog::~Db_thirddialog()
{
    delete ui;
    ui=nullptr;
}

void Db_thirddialog::on_relogin_triggered()
{
    this->close();
    emit mainWindow();
}

void Db_thirddialog::on_exit_triggered()
{
    QApplication::quit();
}

void Db_thirddialog::on_list_tableNames_doubleClicked(const QModelIndex &index)
{
    chosenTable_double_clicked = ui->list_tableNames->model()->data(index).toString();
    ui->list_columnNames->setModel(database->getColumns(chosenTable_double_clicked));
}

/*void Db_thirddialog::on_pushButton_AddTable_clicked()
{
    table_creator = new EntityCreator(this, database);
    table_creator->setAttribute(Qt::WA_DeleteOnClose);
    connect(table_creator, &EntityCreator::nameIsEntered, database, &Database::addTable);
    connect(table_creator, &EntityCreator::isClosed, this, &Db_thirddialog::update);
    table_creator->exec();
}*/

void Db_thirddialog::on_update_triggered()
{
    this->update(false);
}

void Db_thirddialog::on_list_tableNames_clicked(const QModelIndex &index)
{
    chosenTable = ui->list_tableNames->model()->data(index).toString();
}


void Db_thirddialog::on_pushButton_DeleteTable_clicked()
{
    if(chosenTable == "sqlite_sequence" || chosenTable == "TestTable"){
        QMessageBox::warning(this, "Ошибка!", "Данная таблица необходима для корректной работы базы данных и не может быть удалена!");
        return;
    }
    database->deleteTable(chosenTable);
    chosenTable = "";
    this->update(false);
}

void Db_thirddialog::update(bool should_show_columns)
{
    if(ui == nullptr)
        return;
    ui->list_tableNames->setModel(database->getTables());
    if(!should_show_columns){
        ui->list_columnNames->setModel(empty_model);
    } else{
        ui->list_columnNames->setModel(database->getColumns(chosenTable_double_clicked));
    }
}

/*void Db_thirddialog::on_pushButton_AddCol_clicked()
{
    create = new Create_column(this, database);
    create->setAttribute(Qt::WA_DeleteOnClose);
    if(chosenTable_double_clicked == ""){
        return;
    }
    create->setTableName(chosenTable_double_clicked);
    connect(create, &Create_column::nameIsEntered, database, &DBManager::addColumn);
    connect(create, &Create_column::isClosed, this, &Db_thirddialog::update);
    //create->exec();
}*/

void Db_thirddialog::on_list_columnNames_clicked(const QModelIndex &index)
{
    QString chosenColumn_ = ui->list_columnNames->model()->data(index).toString();
    QTextStream ss(&chosenColumn_);
    ss >> chosenColumn;
}

void Db_thirddialog::on_pushButton_DeleteCol_clicked()
{
    //qDebug() << chosenColumn << " " << chosenTable_double_clicked;
    if(chosenColumn == "" || chosenTable_double_clicked == "sqlite_sequence"){
        return;
    }
    if(chosenColumn == "ID"){
        QMessageBox::warning(this, "Ошибка!", "ID не может быть удален!");
        return;
    }
    database->deleteColumn(chosenTable_double_clicked, chosenColumn);
    chosenColumn = "";
    this->update(true);
}

void Db_thirddialog::changeChosenColumn(QString new_name)
{
    chosenColumn = new_name;
}

/*void void AdminWindow::on_pushButton_RenameCol_clicked()
{
    column_renamer = new ColumnRenamer(this, db_manager);
    column_renamer->setAttribute(Qt::WA_DeleteOnClose);
    if(chosenColumn == "" || chosenTable_double_clicked == "sqlite_sequence"){
        return;
    }
    if(chosenColumn == "ID"){
        QMessageBox::warning(this, "Ошибка!", "ID не может быть переименован!");
        return;
    }
    column_renamer->setTableName(chosenTable_double_clicked);
    column_renamer->setOldName(chosenColumn);
    connect(column_renamer, &ColumnRenamer::nameIsEntered, db_manager, &DBManager::renameColumn);
    connect(column_renamer, &ColumnRenamer::changeChosenColumn, this, &AdminWindow::changeChosenColumn);
    connect(column_renamer, &ColumnRenamer::isClosed, this, &AdminWindow::update);
    column_renamer->exec();
}::on_renameCol_clicked()
{
    column_renamer = new ColumnRenamer(this, db_manager);
    column_renamer->setAttribute(Qt::WA_DeleteOnClose);
    if(chosenColumn == "" || chosenTable_double_clicked == "sqlite_sequence"){
        return;
    }
    if(chosenColumn == "ID"){
        QMessageBox::warning(this, "Ошибка!", "ID не может быть переименован!");
        return;
    }
    column_renamer->setTableName(chosenTable_double_clicked);
    column_renamer->setOldName(chosenColumn);
    connect(column_renamer, &ColumnRenamer::nameIsEntered, db_manager, &DBManager::renameColumn);
    connect(column_renamer, &ColumnRenamer::changeChosenColumn, this, &AdminWindow::changeChosenColumn);
    connect(column_renamer, &ColumnRenamer::isClosed, this, &AdminWindow::update);
    column_renamer->exec();
}*/

void Db_thirddialog::on_pushButton_makeFK_clicked()
{
    fk_create = new FK_create(this, database);
    fk_create->setAttribute(Qt::WA_DeleteOnClose);
    fk_create->setFKTable(chosenTable_double_clicked);
    connect(fk_create, &FK_create::tableWasChosen, database, &Database::makeForeignKey);
    connect(fk_create, &FK_create::isClosed, this, &Db_thirddialog::update);
    //fk_create->exec();
}
