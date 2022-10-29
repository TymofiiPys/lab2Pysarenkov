#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "manual_entry.h"
#include "algstruct.h"
#include "ASinteraction.h"
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <QTimer>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    step = 0;
    timer_auto = new QTimer;
    connect(timer_auto, SIGNAL(timeout), this, SLOT(call_algorithm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_exit_triggered()
{
    remove("struct.txt");
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
    Manual_Entry *m = new Manual_Entry(this);
    bool b = false;
    if(ui->comboBox->currentIndex() != 0)
        b = true;
    FILE* f = fopen("a.dat", "wb");
    fwrite(&b, sizeof(bool), 1, f);
    fclose(f);
    m->show();
}


void MainWindow::on_pushButton_file_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Відкрити файл", QDir::currentPath(), "Текстові файли (*.txt) ;; Усі файли (*.*)");
    std::ifstream  src(file_name.toStdString());
    std::ofstream  dst("struct.txt");
    bool b = false;
    if(ui->comboBox->currentIndex() != 0)
        b = true;
    dst << 1 << (int)b << std::endl;
    dst << src.rdbuf();
    src.close();
    dst.flush();
    dst.close();
}

void MainWindow::on_pushButton_rnd_clicked()
{
    int min = std::stoi(ui->lineEdit_min->text().toStdString());
    int max = std::stoi(ui->lineEdit_max->text().toStdString());
    int amt = std::stoi(ui->lineEdit_amt->text().toStdString());
    std::ofstream o("struct.txt");
    bool b = false;
    if(ui->comboBox->currentIndex() != 0)
        b = true;
    o << 1 << b << std::endl;
    int interval = max - min;
    for(int i = 0; i < amt; i++){
        o << (rand() % interval + min);
        if(i != amt - 1)
            o << " ";
    }
    o.flush();
    o.close();
}

void MainWindow::call_algorithm(){
    switch(alg_ind)
    {
    case 1:
        ASinter::doStep_Bubble_sort(true, step, &finished);
        break;
    }
    if(finished)
    {
        timer_auto->stop();
        ui->label_str_entered->setText("finished");
    }
}

void MainWindow::on_action_start_auto_triggered()
{
    AlgStruct as;
    as.enterS();
    step = 1;
    finished = false;
    if(!as.check_ready())
        QMessageBox::warning(this, "Увага!", "Оберіть алгоритм і введіть структуру перед запуском демонстрації!");
    else{
        FILE* f = fopen("steps.txt", "w");//У цей файл записуватимуться дані про крок алгоритму
        fclose(f);
        alg_ind = ui->comboBox->currentIndex();
        timer_auto->setInterval(2000);
        timer_auto->start();
    }
//    bool ready;
//    ast.check_ready(&ready);
//    if(!ready){
//        if(ui->comboBox->currentIndex() == 0)
//            QMessageBox::critical(this, "Помилка", "Ви не обрали алгоритм!");
//        else
//            QMessageBox::critical(this, "Помилка", "Ви не ввели структуру!");
//    }
}


void MainWindow::on_pushButton_print_clicked()
{
//    std::vector<double> s = ast.get_S();
//    std::string text;
//    for (auto it = s.begin(); it != s.end(); it++) {
//        text += std::to_string(*it) + " ";
//    }
//    ui->plainTextEdit->setPlainText(QString::fromStdString(text));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int b = 1;
    if(index == 0){
        b = 0;
    }
    std::ifstream src("struct.txt");
    std::ofstream dst("temp.txt");
    std::string row;
    std::getline(src, row);
    row[1] = (int)b;
    dst << row << std::endl;
    while(!src.eof()){
        std::getline(src, row);
        dst << row << std::endl;
    }
    src.close();
    dst.flush();
    dst.close();
    remove("struct.txt");
    rename("temp.txt", "struct.txt");
}

