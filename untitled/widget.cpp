#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 300);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}
void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-300);
}


void Widget::on_pushButton_clicked()
{
    int n_500 = 0, n_100 = 0, n_50 = 0, n_10 = 0;
    char s[1000];
    while (money >= 500)
    {
        money -= 500;
        n_500 += 1;
    }

    while(money >= 100)
    {
        money -= 100;
        n_100 += 1;
    }

    while(money >= 50)
    {
        money -= 50;
        n_50 += 1;
    }

    while(money >= 10)
    {
        money -= 10;
        n_10 += 1;
    }

    changeMoney(0);
    sprintf(s, "500\t(%d)\n100\t(%d)\n50\t(%d)\n10\t(%d)\n", n_500, n_100, n_50, n_10);
    QMessageBox::information(this, "Excuse me your change!", s);
    ui->lcdNumber->display(money);
}
