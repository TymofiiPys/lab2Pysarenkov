#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
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
    void DrawAlg();
    void editActionH();
private slots:
    void on_action_exit_triggered();

    void on_radioButton_rnd_clicked();

    void on_radioButton_file_clicked();

    void on_radioButton_man_clicked();

    void on_pushButton_man_clicked();

    void on_pushButton_file_clicked();

    void on_action_start_auto_triggered();

    void on_pushButton_rnd_clicked();
    
    void on_action_manual_triggered();
    
    void on_action_prev_step_triggered();
    
    void on_action_next_step_triggered();
    
    void on_pushButton_draw_clicked();
    
    void on_action_pause_triggered();
    
    void on_action_stop_triggered();
    
    void on_pushButton_1_clicked();
    
    void on_action_reset_triggered();
    
    void on_comboBox_alg_currentIndexChanged(int index);
    
    void on_action_h1_triggered();
    
    void on_action_h2_triggered();
    
    void on_action_h3_triggered();
    
    void on_action_h4_triggered();
    
    void on_action_h5_triggered();
    
    void on_action_h6_triggered();
    
    void on_action_h7_triggered();
    
    void on_action_h8_triggered();
    
    void on_action_h9_triggered();
    
    void on_action_h10_triggered();
    
    void on_action_h11_triggered();
    
    void on_action_h12_triggered();
    
    void on_action_h13_triggered();
    
    void on_action_h14_triggered();
    
    void on_action_h15_triggered();
    
private:
    Ui::MainWindow *ui;
    QTimer* timer_auto; /*Таймер, який запускається по запуску автоматичної демонстрації алгоритму 
(перехід на новий крок через певний проміжок часу)*/
    bool timer_stopped;
    bool custom_interval_set;
    int step; //Крок алгоритму
    int alg_ind; //Індекс алгоритму, що доменструється
    bool finished; //Чи завершене виконання алгоритму (якщо так - таймер зупиняється або рух на крок уперед унеможливлюється)
    int GRHEIGHT; //Висота graphicsview_demo
    int GRWIDTH; //Ширина graphicsview_demo
    int elscalew;//Ширина стовпчика, що представляє елемент
    double elscaleh; //Скільки пікселів займатиме стовпчик, що представляє елемент величиною 1
    QPen pen;
};
#endif // MAINWINDOW_H
