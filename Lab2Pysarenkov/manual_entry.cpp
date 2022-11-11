#include "manual_entry.h"
#include "./ui_manual_entry.h"
#include "QMessageBox"
#include <fstream>
#include <QTextStream>

Manual_Entry::Manual_Entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manual_Entry)
{
    ui->setupUi(this);
}

Manual_Entry::~Manual_Entry()
{
    delete ui;
}

void Manual_Entry::on_Btn_ex1_clicked()
{
    ui->StructEdit->setPlainText(("5 3 10 5 9 10 1 7"));
}


void Manual_Entry::on_Btn_ex2_clicked()
{
    ui->StructEdit->setPlainText(("5.8 17.8 4.8 6.6 2.6 17.3 3.1 14.2"));
}


void Manual_Entry::on_Btn_ex3_clicked()
{
     ui->StructEdit->setPlainText(("21.3 38.99 33.41 82.87 8.88 62.71 97.31 96.03 64.69 67.06 6.61 83.78 55.24 62.70 5.39 45.7 92.08 9.36 97.85 12.57 47.9 39.47 1.58 2.6 12.2 97.27 21.15 23.62 95.72 29.47 43.98 45.12 27.14 65.29 57 33.03 9.22 38.93 37.48 44.5 90.36 80.55 52.31 71.25 57.82 52.14 19.48 35.09 41.90 81.98"));
}

void check_string(bool* q, QString s, Manual_Entry* m){
    QString sd;
    std::vector<double> vec;
    int vecamount = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
          double d = sd.toDouble();
          if(d < 0)
          {
              QMessageBox::warning(m, "Елементи", "Задайте невід'ємні елементи!");
              *q = true;
              break;
          }
          if(d > INT_MAX){
              QMessageBox::warning(m, "Елементи",
                                               "Задайте елементи менші, ніж 2^31 - 1");
              *q = true;
              break;
          }
          if(vecamount > 600)
          {
              QMessageBox::warning(m, "Кількість", "Задайте меншу кількість елементів!");
              *q = true;
              break;
          }
          vec.push_back(sd.toDouble());
          sd = "";
          vecamount++;
      } else {
        sd+=s[i];
      }
    }
}

void Manual_Entry::on_Btn_enter_clicked()
{
    bool mist = false;
    check_string(&mist, ui->StructEdit->toPlainText(), this);
    if(mist)
        return;
    FILE* f = fopen("a.dat", "r");//Файл, в який записано булеан, що вказує, чи обраний який-небудь алгоритм
    QFile file("struct.txt");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    bool b;
    fread(&b, sizeof(bool), 1, f);
    fclose(f);
    remove("a.dat");
    out << 1 << b << Qt::endl;
    out << ui->StructEdit->toPlainText();
    file.flush();
    file.close();
    this->close();
}


void Manual_Entry::on_Btn_cancel_clicked()
{
    this->close();
}

