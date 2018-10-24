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
    // clicked on add
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

void Dialog::Sort(){
    while(ui->list_sort->count()>0){
        ui->list_sort->takeItem(0);
    }
    Insertion_Sort(Arr,in);
    for(int i=0;i<in;i++){
        ui->list_sort->addItem(QString::number(Arr[i]));
    }
}

void Dialog::Insertion_Sort(double *A,int n){
    double key;
    int i;
    for(int j=1;j<n;j++){
        key = A[j];
             i = j-1;
        while(i>=0 && A[i] > key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}


