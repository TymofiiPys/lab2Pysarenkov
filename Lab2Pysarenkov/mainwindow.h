#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_exit_triggered();

    void on_radioButton_rnd_clicked();

    void on_radioButton_file_clicked();

    void on_radioButton_man_clicked();

    void on_pushButton_man_clicked();

    void on_pushButton_file_clicked();

    void on_action_start_auto_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
