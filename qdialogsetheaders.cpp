#include "qdialogsetheaders.h"
#include "ui_qdialogsetheaders.h"



QStringList QDialogSetHeaders::get_string_list()
{
    return list_model->stringList();
}

void QDialogSetHeaders::set_string_list(QStringList str)
{
    list_model->setStringList(str);
}

QDialogSetHeaders::QDialogSetHeaders(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QDialogSetHeaders)
{
    ui->setupUi(this);

    list_model = new QStringListModel(this);
    ui->listView->setModel(list_model);
}

QDialogSetHeaders::~QDialogSetHeaders()
{
    delete ui;
}
