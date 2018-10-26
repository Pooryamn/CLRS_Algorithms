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
  //  double Arr[1000];
    int in=0;
    ~Dialog();

private slots:
    void on_btnAdd_clicked();

    void on_btnSort_clicked();

private:
    Ui::Dialog *ui;

public slots:
    void Add();
    void Sort();
    void Insertion_Sort(double *A,int n);
    void Insertion_Sort_dec(double *A,int n);
};

#endif // DIALOG_H
