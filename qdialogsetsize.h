#ifndef QDIALOGSETSIZE_H
#define QDIALOGSETSIZE_H

#include <QDialog>

namespace Ui {
class QDialogSetSize;
}

class QDialogSetSize : public QDialog
{
    Q_OBJECT

public:
    void set_row_column(int ini_row, int ini_column);
    int get_row();
    int get_column();


public:
    explicit QDialogSetSize(QWidget *parent = nullptr);
    ~QDialogSetSize();

private:
    Ui::QDialogSetSize *ui;
};

#endif // QDIALOGSETSIZE_H
