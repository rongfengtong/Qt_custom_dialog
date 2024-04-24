#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qdialogsetsize.h"


void MainWindow::set_model_size(int row, int column)
{
    the_model->setRowCount(row);
    the_model->setColumnCount(column);
}


void MainWindow::set_model_text(int row, int column, QString str_text)
{
    QModelIndex cur_index = the_model->index(row, column);
    the_model->setData(cur_index, str_text, Qt::DisplayRole);
    the_selection->clearSelection();
    the_selection->setCurrentIndex(cur_index, QItemSelectionModel::Select);
}

void MainWindow::act_tab_locate_enable()
{
    ui->actTab_Locate->setEnabled(true);
    dlg_locate = NULL;
    qDebug()<<"利用槽 初始化完成";
}

void MainWindow::set_btn_init()
{
    ui->actTab_Locate->setEnabled(true);
    dlg_locate = NULL;
    qDebug()<<"初始化完成";
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    the_model = new QStandardItemModel(this);
    the_selection = new QItemSelectionModel(the_model);
    ui->tableView->setModel(the_model);
    ui->tableView->setSelectionModel(the_selection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//设置model大小
void MainWindow::on_actTab_SetSize_triggered()
{
    //初始化
    QDialogSetSize *dlg = new QDialogSetSize(this);
    dlg->set_row_column(the_model->rowCount(), the_model->columnCount());

    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        int row = dlg->get_row();
        int column = dlg->get_column();

        set_model_size(row, column);
    }


    delete dlg;
}

//设置the_model title
void MainWindow::on_actTab_SetHeader_triggered()
{
    if(dlg_setHeaders == NULL)
        dlg_setHeaders = new QDialogSetHeaders(this);
    //初始化
    if(dlg_setHeaders->get_string_list().count() != the_model->columnCount()){
        QStringList str;
        for(int i=0; i<the_model->columnCount(); ++i)
            str<<the_model->headerData(i, Qt::Horizontal).toString();

        dlg_setHeaders->set_string_list(str);
    }

    //设置写
    int ret = dlg_setHeaders->exec();
    if(ret == QDialog::Accepted){
        QStringList head_list = dlg_setHeaders->get_string_list();
        the_model->setHorizontalHeaderLabels(head_list);
    }
}

// 非模态写法，两窗口同时显示并作用，不抑制底层窗口的点击使用。这个dlg理应写为非模态型
// void MainWindow::on_actTab_Locate_triggered()
// {
//     ui->actTab_Locate->setEnabled(false);
//     dlg_locate = new QDialogLocate(this);
//     dlg_locate->setAttribute(Qt::WA_DeleteOnClose);

//     //初始化
//     dlg_locate->set_minmax_range(the_model->rowCount(), the_model->columnCount());
//     QModelIndex cur_index = the_selection->currentIndex();
//     if(cur_index.isValid())
//         dlg_locate->set_spin_value(cur_index.row(), cur_index.column());


//     //实时动作
//     connect(dlg_locate, SIGNAL(set_text_signal(int,int,QString)),
//             this, SLOT(set_model_text(int,int,QString)));



//     dlg_locate->show();

//     connect(dlg_locate, SIGNAL(act_tab_locate_enable_signal()),
//             this, SLOT(act_tab_locate_enable()));
// }

//改写为模态型 success
void MainWindow::on_actTab_Locate_triggered()
{
    // ui->actTab_Locate->setEnabled(false);
    dlg_locate = new QDialogLocate(this);
    // dlg_locate->setAttribute(Qt::WA_DeleteOnClose);

    //初始化
    dlg_locate->set_minmax_range(the_model->rowCount(), the_model->columnCount());
    QModelIndex cur_index = the_selection->currentIndex();
    if(cur_index.isValid())
        dlg_locate->set_spin_value(cur_index.row(), cur_index.column());


    //实时动作
    connect(dlg_locate, SIGNAL(set_text_signal(int,int,QString)),
            this, SLOT(set_model_text(int,int,QString)));

    connect(dlg_locate, SIGNAL(act_tab_locate_enable_signal()),
            this, SLOT(act_tab_locate_enable()));

    dlg_locate->exec();     //模态显示
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(dlg_locate != NULL)
        dlg_locate->set_spin_value(index.row(), index.column());

}







