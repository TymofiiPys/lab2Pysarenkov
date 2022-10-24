#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "manual_entry.h"
#include "algstruct.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_exit_triggered()
{
     QApplication::exit();
}


void MainWindow::on_radioButton_rnd_clicked()
{
    ui->groupBox_rnd->setEnabled(true);
    ui->pushButton_file->setEnabled(false);
    ui->pushButton_man->setEnabled(false);
}


void MainWindow::on_radioButton_file_clicked()
{
    ui->groupBox_rnd->setEnabled(false);
    ui->pushButton_file->setEnabled(true);
    ui->pushButton_man->setEnabled(false);
}


void MainWindow::on_radioButton_man_clicked()
{
    ui->groupBox_rnd->setEnabled(false);
    ui->pushButton_file->setEnabled(false);
    ui->pushButton_man->setEnabled(true);
}


void MainWindow::on_pushButton_man_clicked()
{
    Manual_Entry m;
    m.show();
}


void MainWindow::on_pushButton_file_clicked()
{

}


void MainWindow::on_action_start_auto_triggered()
{
    AlgStruct h;
    bool ready;
    h.check_ready(&ready);
    if(!ready){
        if(ui->comboBox->currentIndex() == 0)
            QMessageBox::critical(this, "Помилка", "Ви не обрали алгоритм!");
        else
            QMessageBox::critical(this, "Помилка", "Ви не ввели структуру!");
    }
}

