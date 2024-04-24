#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "qdialogsetheaders.h"
#include "qdialoglocate.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QStandardItemModel * the_model;
    QItemSelectionModel * the_selection;
    void set_model_size(int row, int column);

    QDialogSetHeaders * dlg_setHeaders = NULL;
    QDialogLocate * dlg_locate = NULL;
private slots:
    void set_model_text(int row, int column, QString str_text);
    void act_tab_locate_enable();
public:
    void set_btn_init();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actTab_SetSize_triggered();

    void on_actTab_SetHeader_triggered();

    void on_actTab_Locate_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
