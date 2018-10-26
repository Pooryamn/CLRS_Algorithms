#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
double Arr[1000];

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
         Merge_Sort(Arr,0,in-1);
     }
     else{
         //Merge_sort_dec
         Merge_Sort_Dec(Arr,0,in-1);
     }
     for(int i=0;i<in;i++){
         ui->list_sort->addItem(QString::number(Arr[i]));
     }
}

void Dialog::Merge(double arr[], int l, int m, int r){
    int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        double *L = new double[n1];
        double *R = new double[n2];

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



void Dialog::Merge_Dec(double arr[],int l , int m,int r){
    int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        double *L = new double[n1];
        double *R = new double[n2];

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

void Dialog::Merge_Sort(double arr[],int l , int r){
    if (l < r)
        {
            int m = l + (r - l) / 2;

            Merge_Sort(arr, l, m);
            Merge_Sort(arr, m + 1, r);
            Merge(arr, l, m, r);
        }
}

void Dialog::Merge_Sort_Dec(double arr[],int l,int r){
    if (l < r)
        {
            int m = l + (r - l) / 2;

            Merge_Sort_Dec(arr, l, m);
            Merge_Sort_Dec(arr, m + 1, r);
            Merge_Dec(arr, l, m, r);
        }
}

