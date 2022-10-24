#include "manual_entry.h"
#include "./ui_manual_entry.h"
#include "algstruct.h"

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
    ui->StructEdit->setPlainText((""));
}


void Manual_Entry::on_Btn_ex2_clicked()
{

}


void Manual_Entry::on_Btn_ex3_clicked()
{

}


void Manual_Entry::on_Btn_enter_clicked()
{
    AlgStruct s;
    s.entry_manual();
}


void Manual_Entry::on_Btn_cancel_clicked()
{
    this->close();
}

