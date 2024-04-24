#include "qdialogsetsize.h"
#include "ui_qdialogsetsize.h"

void QDialogSetSize::set_row_column(int ini_row, int ini_column)
{
    ui->spinBoxRow->setValue(ini_row);
    ui->spinBoxColumn->setValue(ini_column);
}

int QDialogSetSize::get_row()
{
    return ui->spinBoxRow->value();
}

int QDialogSetSize::get_column()
{
    return ui->spinBoxColumn->value();
}

QDialogSetSize::QDialogSetSize(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QDialogSetSize)
{
    ui->setupUi(this);
}

QDialogSetSize::~QDialogSetSize()
{
    delete ui;
}
