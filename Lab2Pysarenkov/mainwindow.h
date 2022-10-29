#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void call_algorithm();    
private slots:
    void on_action_exit_triggered();

    void on_radioButton_rnd_clicked();

    void on_radioButton_file_clicked();

    void on_radioButton_man_clicked();

    void on_pushButton_man_clicked();

    void on_pushButton_file_clicked();

    void on_action_start_auto_triggered();

    void on_pushButton_rnd_clicked();
    
    void on_pushButton_print_clicked();
    
    void on_comboBox_currentIndexChanged(int index);
    
private:
    Ui::MainWindow *ui;
    QTimer* timer_auto; /*Таймер, який запускається по запуску автоматичної демонстрації алгоритму 
(перехід на новий крок через певний проміжок часу)*/
    int step; //Крок алгоритму
    int alg_ind; //Індекс алгоритму, що доменструється
    bool finished; //Чи завершене виконання алгоритму (якщо так - таймер зупиняється або рух на крок уперед унеможливлюється)
};
#endif // MAINWINDOW_H
