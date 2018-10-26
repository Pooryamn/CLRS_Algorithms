#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
int Arr[1000];

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPalette palette = ui->lbli->palette();
     palette.setColor(ui->lbli->foregroundRole(), Qt::blue);
     ui->lbli->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnAdd_clicked()
{
    //Clicked on Add
    Add();
    ui->txtNum->setText("");
}

void Dialog::Add(){
    if(ui->txtNum->text()==""){
        return;
    }
    double dou;
    dou=ui->txtNum->text().toDouble();
    // we have to check if the input has a character delete that
    ui->listEnter->addItem(QString::number(dou));
    Arr[in]=dou;
    in++;
}


void Dialog::on_btnSort_clicked()
{
    //clicked on sort
    Sort();
}

void Dialog::Sort()
{
    while(ui->list_sort->count()>0){
        ui->list_sort->takeItem(0);
    }
     if(ui->Chbox_mode->isChecked()==false){
         //Merge_sort
     }
     else{
         //Merge_sort_dec
     }
}

vodi Dialog::Merge(int arr[], int l, int m, int r){
    int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int *L = new int[n1];
        int *R = new int[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
}



void Dialog::Merge_Dec(int arr[],int l , int m,int r){
    int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int *L = new int[n1];
        int *R = new int[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] >= R[j])//
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
}

