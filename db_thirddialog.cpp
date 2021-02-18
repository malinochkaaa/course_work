#include "db_thirddialog.h"
#include "ui_db_thirddialog.h"
#include <QDebug>

Db_thirddialog::Db_thirddialog(QWidget *parent, Database* database_) :
    QWidget(parent),
    ui(new Ui::Db_thirddialog),
    database(database_)
{
    ui->setupUi(this);
}

Db_thirddialog::~Db_thirddialog()
{
    delete ui;
    ui=nullptr;
}
