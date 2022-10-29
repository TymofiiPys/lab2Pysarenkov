#include "manual_entry.h"
#include "./ui_manual_entry.h"
#include "ASinteraction.h"
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
    ui->StructEdit->setPlainText(("-5.8 17.8 -4.8 6.6 -2.6 17.3 -3.1 14.2"));
}


void Manual_Entry::on_Btn_ex3_clicked()
{

}


void Manual_Entry::on_Btn_enter_clicked()
{
    if(FILE* f = fopen("struct.txt", "r")){
            fclose(f);
            std::ifstream src("struct.txt");
            std::ofstream dst("temp.txt");
            std::string row;
            std::getline(src, row);
            dst << row << std::endl;
            dst << ui->StructEdit->toPlainText().toStdString();
            src.close();
            dst.flush();
            src.close();
            remove("struct.txt");
            rename("temp.txt", "struct.txt");
    }
    else{
            QFile file("struct.txt");
            file.open(QFile::WriteOnly | QFile::Text);
            QTextStream out(&file);
            out << 1 << 0 << Qt::endl;
            out << ui->StructEdit->toPlainText();
            file.flush();
            file.close();
            this->close();
    }
}


void Manual_Entry::on_Btn_cancel_clicked()
{
    this->close();
}

