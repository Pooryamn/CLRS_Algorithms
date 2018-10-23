#include "dialog.h"
#include "ui_dialog.h"
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);



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
    QString str;
    double dou;
    dou=ui->txtNum->text().toDouble();
    str=ui->txtNum->text();
    if(dou==0){
        return;
    }
    // we have to check if the input has a character delete that
    ui->listEnter->addItem(str);
}
