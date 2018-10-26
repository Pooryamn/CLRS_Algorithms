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
