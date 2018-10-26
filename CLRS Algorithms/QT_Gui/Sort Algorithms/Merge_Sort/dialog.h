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
    void on_btnSort_clicked();


private:
    Ui::Dialog *ui;
public slots:
    void Add();
    void Sort();
    void Merge_Sort(int arr[], int l, int r);
    void Merge_Sort_Dec(int arr[], int l, int r);
    void Merge(int arr[], int l, int m, int r);
    void Merge_Dec(int arr[], int l, int m, int r);
};

#endif // DIALOG_H
