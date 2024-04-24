#ifndef QDIALOGSETHEADERS_H
#define QDIALOGSETHEADERS_H

#include <QDialog>
#include <QStringListModel>


namespace Ui {
class QDialogSetHeaders;
}

class QDialogSetHeaders : public QDialog
{
    Q_OBJECT

private:
    QStringListModel *list_model;
public:
    QStringList get_string_list();
    void set_string_list(QStringList str);


public:
    explicit QDialogSetHeaders(QWidget *parent = nullptr);
    ~QDialogSetHeaders();

private:
    Ui::QDialogSetHeaders *ui;
};

#endif // QDIALOGSETHEADERS_H
