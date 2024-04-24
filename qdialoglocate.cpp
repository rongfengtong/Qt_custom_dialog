#include "qdialoglocate.h"
#include "ui_qdialoglocate.h"

#include "mainwindow.h"
void QDialogLocate::closeEvent(QCloseEvent * event){
    //每次关闭dlg_locate后，the_model可能发生了变换，所以重新打开时，需要重新设置spinBox_range
    emit act_tab_locate_enable_signal();
    // emit init_dlg_locate_signal();

    // MainWindow * parentW = (MainWindow *)parentWidget();
    // parentW->set_btn_init();
}

void QDialogLocate::set_minmax_range(int max_row, int max_column)
{
    ui->spinBoxRow->setRange(0, max_row);
    ui->spinBoxColumn->setRange(0, max_column);
}

void QDialogLocate::set_spin_value(int row, int column)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(column);
}

QDialogLocate::QDialogLocate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QDialogLocate)
{
    ui->setupUi(this);
}

QDialogLocate::~QDialogLocate()
{
    delete ui;
}

void QDialogLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRow->value();
    int column = ui->spinBoxColumn->value();
    QString str_text = ui->edtCaption->text();
    emit set_text_signal(row, column, str_text);

    if(ui->chkBoxRow->isChecked())
        ui->spinBoxRow->setValue(ui->spinBoxRow->value() + 1);
    if(ui->chkBoxColumn->isChecked())
        ui->spinBoxColumn->setValue(ui->spinBoxColumn->value() + 1);
}






