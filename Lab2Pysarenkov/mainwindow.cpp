#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "manual_entry.h"
#include "algstruct.h"
#include "ASinteraction.h"
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <QTimer>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GRWIDTH = ui->graphicsView_demo->width() - 10;
    GRHEIGHT = ui->graphicsView_demo->height() - 10;
    QGraphicsScene *s = new QGraphicsScene(0, 0, GRWIDTH, GRHEIGHT, ui->graphicsView_demo);
    ui->graphicsView_demo->setScene(s);
    s->setBackgroundBrush(Qt::black);
    ui->graphicsView_demo->show();
    pen.setColor(Qt::black);
    step = 0;
    timer_auto = new QTimer(this);
    connect(timer_auto, SIGNAL(timeout()), this, SLOT(call_algorithm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::call_algorithm(){
    //виклик кроку обраного алгоритму, викликається таймером при автоматичній демонстрації
    //або кнопками попереднього/наступного кроку при ручній
    switch(alg_ind)
    {
    case 1:
        ASinter::doStep_Bubble_sort(true, step, &finished);
        break;
    }
    DrawAlg();
    step++;
    if(finished)
    {
        timer_auto->stop();
        ui->label_str_entered->setText("finished");
        ui->action_prev_step->setEnabled(false);
        ui->action_next_step->setEnabled(false);
        ui->action_pause->setEnabled(false);
    }
}

double vecmax(std::vector<double> v){
    double m = v.at(0);
    for(auto it = v.begin() + 1; it != v.end(); it++){
        if(*it > m)
            m = *it;
    }
    return m;
}

//double vecmin(std::vector<double> v){
//    double m = v.at(0);
//    for(auto it = v.begin() + 1; it != v.end(); it++){
//        if(*it < m)
//            m = *it;
//    }
//    return m;
//}

bool vec_cont(std::vector<int> vec, int i){
    for(auto it = vec.begin(); it != vec.end(); it++){
        if(*it == i)
            return true;
    }
    return false;
}

void MainWindow::DrawAlg(){
    std::vector<double> vec;
    std::vector<int> hl;
    if(step == 0)
    {
        AlgStruct as;
        as.enterS();
        vec = as.get_S();
        double max = vecmax(vec);
//        double min = vecmax(vec);
        vec.size() > 20 ? elscalew = (int)((GRWIDTH - 10) / vec.size()) : elscalew = 30;
        elscaleh = (GRHEIGHT - 10) / max;
    }
    else
    {
        ASinter::getPrevStepInfo(&vec, step, &hl);
    }
    QGraphicsScene *s = new QGraphicsScene(ui->graphicsView_demo);
    ui->graphicsView_demo->setScene(s);
    int x = 0, i = 0;
    for(auto it = vec.begin(); it != vec.end(); it++){
        QBrush br;
        if(vec_cont(hl, i))    
            br = QBrush(Qt::red);
        else
            br = QBrush(Qt::white);
        s->addRect(x, GRHEIGHT - *it*elscaleh, elscalew, *it*elscaleh, pen, br);
        x+= elscalew;
        i++;
    }
    ui->graphicsView_demo->show();
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

void MainWindow::on_pushButton_rnd_clicked()
{
    //Випадкова генерація структури (масиву) з amt елементами, в інтервалі від min до max
    //та запис до файлу
    int min = std::stoi(ui->lineEdit_min->text().toStdString());
    int max = std::stoi(ui->lineEdit_max->text().toStdString());
    int amt = std::stoi(ui->lineEdit_amt->text().toStdString());
    std::ofstream o("struct.txt");
    bool b = false;
    if(ui->comboBox->currentIndex() != 0)
        b = true;
    o << 1 << (int)b << std::endl;
    int interval = max - min;
    for(int i = 0; i < amt; i++){
        o << (rand() % interval + min);
        if(i != amt - 1)
            o << " ";
    }
    o.flush();
    o.close();
    DrawAlg();
}

void MainWindow::on_pushButton_man_clicked()
{
    //Запис структури вручну з використанням додаткового вікна
    //та файлу з булеаном, що вказує, чи обраний у цьому вікні
    //який-небудь алгоритм
    Manual_Entry *m = new Manual_Entry(this);
    bool b = false;
    if(ui->comboBox->currentIndex() != 0)
        b = true;
    FILE* f = fopen("a.dat", "wb");
    fwrite(&b, sizeof(bool), 1, f);
    fclose(f);
    m->show();
    QFont font = ui->pushButton_draw->font();
    font.setBold(true);
    ui->pushButton_draw->setEnabled(true);
    ui->pushButton_draw->setFont(font);
}

void MainWindow::on_pushButton_draw_clicked()
{
    DrawAlg();
    QFont font = ui->pushButton_draw->font();
    font.setBold(false);
    ui->pushButton_draw->setEnabled(false);
    ui->pushButton_draw->setFont(font);
}

void MainWindow::on_pushButton_file_clicked()
{
    //Читання структури з одного файлу (обирається в діалговому вікні) та запис в інший
    QString file_name = QFileDialog::getOpenFileName(this, "Відкрити файл", QDir::currentPath(), "Текстові файли (*.txt) ;; Усі файли (*.*)");
    if(file_name != "")
    {
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
        DrawAlg();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //Обираємо в comboBox якийсь пункт - 
    //ставимо у файлі (якщо він уже створений) позначку, що алгоритм обраний (index >= 1)
    //або ні (index == 0)
    char b = '1';
    if(index == 0){
        b = '0';
    }
    if (FILE *f = fopen("struct.txt", "r")) {
      fclose(f);
      std::ifstream src("struct.txt");
      std::ofstream dst("temp.txt");
      std::string row;
      std::getline(src, row);
      row[1] = b;
      dst << row << std::endl;
      while (!src.eof()) {
        std::getline(src, row);
        dst << row << std::endl;
      }
      src.close();
      dst.flush();
      dst.close();
      remove("struct.txt");
      rename("temp.txt", "struct.txt");
    }
}

void MainWindow::on_action_start_auto_triggered()
{
    //Запуск автоматичної демонстрації
    if(FILE *f = fopen("struct.txt", "r")){
    AlgStruct as;
    as.enterS();
    step = 1;
    finished = false;
    if(!as.check_ready()){//Перевіряємо, чи обрали алгоритм та задали структуру
        if(ui->comboBox->currentIndex() == 0) //Знаходимо, що саме користувач забув зробити :)
            QMessageBox::warning(this, "Увага!", "Оберіть алгоритм перед запуском демонстрації!");
        else
            QMessageBox::warning(this, "Увага!", "Введіть структуру перед запуском демонстрації!");
    }
    else{
        FILE* f = fopen("steps.txt", "w");//У цей файл записуватимуться дані про крок алгоритму
        fclose(f);
        alg_ind = ui->comboBox->currentIndex();
        timer_auto->setInterval(500); //Поки що константний інтервал
        timer_auto->start();
    }}
    else {
      if (ui->comboBox->currentIndex() == 0)
        QMessageBox::warning(this, "Увага!",
                             "Оберіть алгоритм і введіть структуру перед "
                             "запуском демонстрації!");
      else
        QMessageBox::warning(this, "Увага!",
                             "Введіть структуру перед "
                             "запуском демонстрації!");
    }
}

void MainWindow::on_action_manual_triggered()
{
    //Запуск демонстрації із ручним керуванням
    //Код аналогічний до on_action_start_auto_triggered(),
    //крім моменту, що таймер не запускається (бо він нам не потрібен),
    //а одразу викликається call_algorithm()
    if(FILE *f = fopen("struct.txt", "r")){
    AlgStruct as;
    as.enterS();
    step = 1;
    finished = false;
    if(!as.check_ready()){
        if(ui->comboBox->currentIndex() == 0)
            QMessageBox::warning(this, "Увага!", "Оберіть алгоритм перед запуском демонстрації!");
        else
            QMessageBox::warning(this, "Увага!", "Введіть структуру перед запуском демонстрації!");
    }
    else{
        FILE* f = fopen("steps.txt", "w");
        fclose(f);
        alg_ind = ui->comboBox->currentIndex();
        ui->action_prev_step->setEnabled(true);
        ui->action_next_step->setEnabled(true);
        this->call_algorithm();
    }
    }
    else {
      if (ui->comboBox->currentIndex() == 0)
        QMessageBox::warning(this, "Увага!",
                             "Оберіть алгоритм і введіть структуру перед "
                             "запуском демонстрації!");
      else
        QMessageBox::warning(this, "Увага!",
                             "Введіть структуру перед "
                             "запуском демонстрації!");
    }
}


void MainWindow::on_action_prev_step_triggered()
{
    
}


void MainWindow::on_action_next_step_triggered()
{
    //Перемикаємо крок на наступний
    this->call_algorithm();
}

