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

}

void check_string(bool* q, QString s, Manual_Entry* m){
    QString sd;
    std::vector<double> vec;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
          double d = sd.toDouble();
          if(d < 0)
          {
              QMessageBox::warning(m, "Елементи", "Задайте невід'ємні елементи!");
              *q = true;
              break;
          }
          vec.push_back(sd.toDouble());
          sd = "";
      } else {
        sd+=s[i];
      }
    }
}

void Manual_Entry::on_Btn_enter_clicked()
{
    if(ui->StructEdit->toPlainText().length() > 255){
        QMessageBox::warning(this, "Кількість", "Задайте меншу кількість елементів!");
        return;
    }
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

