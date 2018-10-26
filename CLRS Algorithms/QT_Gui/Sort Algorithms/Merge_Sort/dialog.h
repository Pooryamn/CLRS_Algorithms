#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    int in=0;
    ~Dialog();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::Dialog *ui;
public slots:
    void Add();
};

#endif // DIALOG_H
