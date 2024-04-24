#ifndef QDIALOGLOCATE_H
#define QDIALOGLOCATE_H

#include <QDialog>

namespace Ui {
class QDialogLocate;
}

class QDialogLocate : public QDialog
{
    Q_OBJECT

public:
    void set_minmax_range(int max_row, int max_column);
    void set_spin_value(int row, int column);
    void closeEvent(QCloseEvent * event);
signals:
    void set_text_signal(int,int,QString);
    void act_tab_locate_enable_signal();
    // void init_dlg_locate_signal();


public:
    explicit QDialogLocate(QWidget *parent = nullptr);
    ~QDialogLocate();

private slots:
    void on_btnSetText_clicked();

private:
    Ui::QDialogLocate *ui;
};

#endif // QDIALOGLOCATE_H
