#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <QComboBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reply = QMessageBox::question(this, "", "If you will work with int, tap yes, with strings - tap no.",
                          QMessageBox::Yes|QMessageBox::No);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{



    QString first = ui->lineEdit->text();

    QString second = ui->lineEdit_2->text();



    if (first == "" || second == ""){
        QMessageBox::critical(this, "Error", "You must pass numbers");
        return;
    }

    if (reply == QMessageBox::Yes){

    int f1= first.toInt();
    int s1 = second.toInt();
    ch1.push_back(f1);
    ch2.push_back(s1);


    QString str = "";
    foreach (auto i, ch1){
    str += QString::number(i);
    str += "\n";
    }
    ui->f_set ->setText(str);


    QString str2 = "";
    foreach (auto i, ch2){
    str2 += QString::number(i);
    str2 += "\n";
    }
    ui->s_set ->setText(str2);

    }

    else{
        str1.push_back(first.toStdString());
        str2.push_back(second.toStdString());
        QString s1 = "";
        foreach (auto i, str1){
        s1 += QString::fromStdString(i);
        s1 += "\n";
        }
        ui->f_set ->setText(s1);


        QString s2 = "";
        foreach (auto i, str2){
        s2 += QString::fromStdString(i);
        s2 += "\n";
        }
        ui->s_set ->setText(s2);



    }


}

void MainWindow::on_pushButton_clicked()
{

    if (reply == QMessageBox::Yes){
    chisla set1(ch1);
    chisla set2(ch2);

        mnozhestvo res = set1.mult(set2);

        QString s = "";
        foreach (auto i, res.ch){
        s += QString::number(i);
        s += "\n";
        }
        ui->l_set ->setText(s);
        }
    else{
        stroki first_set(str1);
        stroki second_set(str2);

        mnozhestvo res = first_set.mult(second_set);
                if (res.str.size()== 1 && res.str[0] == ""){
                    QMessageBox::critical(this, "error", "Unable to intersect");
                }
                QString s = "";
                foreach (auto i, res.str){
                s += QString::fromStdString(i);
                s += "\n";
                }
                ui->l_set ->setText(s);
                }


}



void MainWindow::on_pushButton_2_clicked()
{
     if (reply == QMessageBox::Yes){
         chisla set1(ch1);
         chisla set2(ch2);
    mnozhestvo res = set1.add(set2);
    QString s = "";
    foreach (auto i, res.ch){
    s += QString::number(i);
    s += "\n";
    }
    ui->l_set ->setText(s);
    }
    else{
        stroki first_set(str1);
        stroki second_set(str2);

        mnozhestvo res = first_set.add(second_set);
        QString s = "";
        foreach (auto i, res.str){
        s += QString::fromStdString(i);
        s += "\n";
        }
        ui->l_set ->setText(s);
        }



}



void MainWindow::on_pushButton_3_clicked()
{
    if (reply == QMessageBox::Yes){

    chisla set1(ch1);
    chisla set2(ch2);

    mnozhestvo res = set1.sim_sub(set2);
    QString s = "";
    foreach (auto i, res.ch){
    s += QString::number(i);
    s += "\n";
    }
    ui->l_set ->setText(s);
    }
    else{

        stroki first_set(str1);
        stroki second_set(str2);

        mnozhestvo res = first_set.sim_sub(second_set);
        QString s = "";
        foreach (auto i, res.str){
        s += QString::fromStdString(i);
        s += "\n";
        }
        ui->l_set ->setText(s);

    }
}
void MainWindow::on_pushButton_5_clicked()
{
    if (reply == QMessageBox::Yes){
    ch1.clear();
    }
    else{
        str1.clear();
    }
    ui->f_set->setText("");

}

void MainWindow::on_pushButton_6_clicked()
{
    if (reply == QMessageBox::Yes){
    ch2.clear();
    }
    else{
        str2.clear();
    }
    ui->s_set->setText("");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->l_set->setText("");
}
