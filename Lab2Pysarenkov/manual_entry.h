#ifndef MANUAL_ENTRY_H
#define MANUAL_ENTRY_H

#include <QDialog>

namespace Ui {
class Manual_Entry;
}

class Manual_Entry : public QDialog
{
    Q_OBJECT

public:
    explicit Manual_Entry(QWidget *parent = nullptr);
    ~Manual_Entry();

private slots:
    void on_Btn_ex1_clicked();

    void on_Btn_ex2_clicked();

    void on_Btn_ex3_clicked();

    void on_Btn_enter_clicked();

    void on_Btn_cancel_clicked();

private:
    Ui::Manual_Entry *ui;
};

#endif // MANUAL_ENTRY_H
