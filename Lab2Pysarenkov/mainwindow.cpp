#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "manual_entry.h"
#include "algstruct.h"
#include "ASinteraction.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <cmath>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_amt->setValidator(new QIntValidator(0, 600, this));
    ui->lineEdit_min->setValidator(new QDoubleValidator(0, INT_MAX, 6, this));
    ui->lineEdit_max->setValidator(new QDoubleValidator(0, INT_MAX, 6, this));
    ui->lineEdit_tim->setValidator(new QIntValidator(10, INT_MAX, this));
    GRWIDTH = ui->graphicsView_demo->width() - 10;
    GRHEIGHT = ui->graphicsView_demo->height() - 10;
    QGraphicsScene *s_demo = new QGraphicsScene(0, 0, GRWIDTH, GRHEIGHT, ui->graphicsView_demo);
    QGraphicsScene *s_str = new QGraphicsScene(0,0, 610, 120, ui->graphicsView_struct);
    ui->graphicsView_demo->setScene(s_demo);
    ui->graphicsView_struct->setScene(s_str);
    s_demo->setBackgroundBrush(Qt::black);
    s_str->setBackgroundBrush(Qt::black);
    ui->graphicsView_demo->show();
    ui->graphicsView_struct->show();
    pen.setColor(Qt::black);
    step = 0;
    timer_auto = new QTimer(this);
    timer_stopped = true;
    custom_interval_set = false;
    connect(timer_auto, SIGNAL(timeout()), this, SLOT(call_algorithm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::call_algorithm(){
    //виклик кроку обраного алгоритму, викликається таймером при автоматичній демонстрації
    //або кнопками попереднього/наступного кроку при ручній
    finished = false;
    switch(alg_ind)
    {
    case 1:
        ASinter::doStep_Bubble_sort(step, &finished);
        break;
    case 2:
        ASinter::doStep_Selection_sort(step, &finished);
        break;
    case 3:
        ASinter::doStep_Insertion_sort(step, &finished);
        break;
    case 4:
        ASinter::doStep_Merge_sort(step, &finished);
        break;
    }
    DrawAlg();
    editActionH();
    step++;
    if(finished)
    {
        timer_auto->stop();
        ui->action_pause->setIcon(QIcon(":/img/img/pause.png"));
        timer_stopped = true;  
        ui->label_str_entered->setText("Демонстрацію завершено.");
        ui->action_next_step->setEnabled(false);
        ui->action_pause->setEnabled(false);
        ui->action_manual->setEnabled(true);
        ui->action_start_auto->setEnabled(true);
    }
}

void MainWindow::editActionH(){
    std::ifstream i("steps.txt");
    std::string s;
    QString steps_info[16];
    int amount_of_steps = 0, laststep, earlieststep;
    std::getline(i, s);
    laststep = std::stoi(s);
    while(!i.eof()){
        std::getline(i, s);
        std::getline(i, s);
        std::getline(i, s);
        steps_info[amount_of_steps] = QString::fromStdString(s);
        std::getline(i, s);
        amount_of_steps++;
        if(i.eof())
            earlieststep = laststep-amount_of_steps;
    }
    if(earlieststep > 1)//Якщо найдавніший крок не перший - то відновити його не вдасться
        amount_of_steps--;
    i.seekg(0, i.beg);
    std::getline(i, s);
    bool Visible[16];
    QString actionText[16];
    int it = 0;
    for(int j = 0; j < 16; j++)
        Visible[j] = false;
    for(int j = amount_of_steps - 1; j >= 0; j--){
        Visible[j] = true;
        actionText[it] = steps_info[j];
        it++;
    }
    ui->action_h1->setVisible(Visible[0]);
    ui->action_h2->setVisible(Visible[1]);
    ui->action_h3->setVisible(Visible[2]);
    ui->action_h4->setVisible(Visible[3]);
    ui->action_h5->setVisible(Visible[4]);
    ui->action_h6->setVisible(Visible[5]);
    ui->action_h7->setVisible(Visible[6]);
    ui->action_h8->setVisible(Visible[7]);
    ui->action_h9->setVisible(Visible[8]);
    ui->action_h10->setVisible(Visible[9]);
    ui->action_h11->setVisible(Visible[10]);
    ui->action_h12->setVisible(Visible[11]);
    ui->action_h13->setVisible(Visible[12]);
    ui->action_h14->setVisible(Visible[13]);
    ui->action_h15->setVisible(Visible[14]);
    
    ui->action_h1->setText("1. " + actionText[0]);
    ui->action_h2->setText("2. " +actionText[1]);
    ui->action_h3->setText("3. " +actionText[2]);
    ui->action_h4->setText("4. " +actionText[3]);
    ui->action_h5->setText("5. " +actionText[4]);
    ui->action_h6->setText("6. " +actionText[5]);
    ui->action_h7->setText("7. " +actionText[6]);
    ui->action_h8->setText("8. " +actionText[7]);
    ui->action_h9->setText("9. " +actionText[8]);
    ui->action_h10->setText("10. " +actionText[9]);
    ui->action_h11->setText("11. " +actionText[10]);
    ui->action_h12->setText("12. " +actionText[11]);
    ui->action_h13->setText("13. " +actionText[12]);
    ui->action_h14->setText("14. " +actionText[13]);
    ui->action_h15->setText("15. " +actionText[14]);
    
    i.close();
}

double vecmax(std::vector<double> v){
    double m = v.at(0);
    for(auto it = v.begin() + 1; it != v.end(); it++){
        if(*it > m)
            m = *it;
    }
    return m;
}

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
        vec.size() > 20 ? elscalew = (int)((GRWIDTH - 10) / vec.size()) : elscalew = 30;
        ui->graphicsView_struct->setSceneRect(10,5, vec.size()*75, ui->graphicsView_struct->height() - 30);
        elscaleh = (GRHEIGHT - 10) / max;
        ui->action_prev_step->setEnabled(false);
        ui->action_next_step->setEnabled(false);
        ui->action_pause->setEnabled(false);
    }
    else
    {
        ASinter::getPrevStepInfo(&vec, step, &hl);
    }
    QGraphicsScene *s = new QGraphicsScene(ui->graphicsView_demo);
    QGraphicsScene* s_str = new QGraphicsScene(ui->graphicsView_struct);
    ui->graphicsView_demo->setScene(s);
    ui->graphicsView_struct->setScene(s_str);
    int x = 0, i = 0, x1 = 20;
    for(auto it = vec.begin(); it != vec.end(); it++){
        QBrush br;
        if(vec_cont(hl, i))    
            br = QBrush(Qt::red);
        else
            br = QBrush(Qt::white);
        s->addRect(x, GRHEIGHT - *it*elscaleh, elscalew, *it*elscaleh, pen, br);
        s_str->addRect(x1, 25, 75,75, pen, br);
        QGraphicsTextItem *text = s_str->addText(QString::number(round(*it * 10)/10));
        QFont textfont;
        QString qs = QString::number(round(*it * 10)/10);
        if(qs.length() > 3)
            textfont.setPointSize((int)(48/qs.length()));
        else
            textfont.setPointSize(15);
        text->setFont(textfont);
        text->setPos(x1 + 5, 35);
        x+= elscalew;
        x1+=70;
        i++;
    }
    ui->graphicsView_struct->show();
    ui->graphicsView_demo->show();
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
    bool everything_is_int;
    double min = ui->lineEdit_min->text().toDouble(&everything_is_int);
    double max = ui->lineEdit_max->text().toDouble(&everything_is_int);
    double amt = ui->lineEdit_amt->text().toDouble(&everything_is_int);
    if(ui->lineEdit_min->text().isEmpty() || ui->lineEdit_max->text().isEmpty() || ui->lineEdit_amt->text().isEmpty()){
        QMessageBox::warning(this, "Пусті поля",
                             "Будь ласка, введіть УСІ параметри.");
        return;
    }
//    if(!everything_is_int)
//    {
//        QMessageBox::warning(this, "Введіть ЧИСЛА",
//                             "Ви маєте вводити у поля \"Кількість елементів\", \"Мін.\" і \"Макс.\" ЧИСЛА!");
//        return;
//    }
    //Перевірка коректності введення параметрів
//    if (min < 0 || max < 0) {
//      QMessageBox::warning(this, "Ліміт",
//                           "Будь ласка, задайте невід'ємний ліміт.");
//      return;
//    }
    if(min > max)
    {
        QMessageBox::warning(this, "Максимальне значення",
                             "Макс. значення не може бути меншим за мінімальне!");
        return;
    }
    if(min == max){
        QMessageBox::warning(this, "Максимальне значення",
                             "Макс. значення не може дорівнювати мінімальному!");
        return;
    }
//    if(max >= INT_MAX){
//        if(min >= INT_MAX)
//        {QMessageBox::warning(this, "Мінімальне значення",
//                                 "Задайте ліміти менші, ніж 2^31 - 1");
//            return;
//        }
//        else
//            max = INT_MAX;
//    }
//    if(amt <= 0)
//    {
//        QMessageBox::warning(this, "Кількість",
//                             "Задайте додатню кількість елементів!");
//        return;
//    }
    if(amt >= 600){//Таке обмеження накладається, тому що ширина виділеного для демонстрації graphicsView - 600 пкс.,
        //тобто при демонстрації при більших значеннях кількості деякі елементи можуть бути непроілюстровані
        QMessageBox::warning(this, "Кількість",
                             "Будь ласка, задайте кількість елементів, меншу за 600!");
        return;
    }
    std::ofstream o("struct.txt");
    bool b = false;
    if(ui->comboBox_alg->currentIndex() != 0)
        b = true;
    o << 1 << (int)b << std::endl;
    int interval = max - min, randmult = 1;
    if(interval > RAND_MAX){
        while(RAND_MAX * randmult < interval)
            randmult *= 10; //Даний множник потрібен для випадків, коли вводяться значення більші за 
        //RAND_MAX, тобто усього лише 32767
    }
    for(int i = 0; i < amt; i++){
        o << ((rand() * randmult) % interval + min);
        if(i != amt - 1)
            o << " ";
    }
    o.flush();
    o.close();
    step = 0;
    DrawAlg();
}

void MainWindow::on_pushButton_man_clicked()
{
    //Запис структури вручну з використанням додаткового вікна
    //та файлу з булеаном, що вказує, чи обраний у цьому вікні
    //який-небудь алгоритм
    Manual_Entry *m = new Manual_Entry(this);
    bool b = false;
    if(ui->comboBox_alg->currentIndex() != 0)
        b = true;
    FILE* f = fopen("a.dat", "wb");
    fwrite(&b, sizeof(bool), 1, f);
    fclose(f);
    m->show();
    QFont font = ui->pushButton_draw->font();
    font.setBold(true);
    ui->pushButton_draw->setEnabled(true);
    ui->pushButton_draw->setFont(font);
    step = 0;
}

void MainWindow::on_pushButton_draw_clicked()
{
    DrawAlg();
    QFont font = ui->pushButton_draw->font();
    font.setBold(false);
    ui->pushButton_draw->setEnabled(false);
    ui->pushButton_draw->setFont(font);
}

void check_string(bool* q, MainWindow* m, std::string file_name){
    std::ifstream i(file_name);
    std::string s, sd;
    std::getline(i, s);
    std::getline(i, s);
    std::vector<double> vec;
    int vecamount = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
          double d = std::stoi(sd);
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
          vec.push_back(std::stoi(sd));
          sd = "";
          vecamount++;
      } else {
        sd+=s[i];
      }
    }
}

void MainWindow::on_pushButton_file_clicked()
{
    //Читання структури з одного файлу (обирається в діалговому вікні) та запис в інший
    QString file_name = QFileDialog::getOpenFileName(this, "Відкрити файл", QDir::currentPath(), "Текстові файли (*.txt) ;; Усі файли (*.*)");
    if(file_name != "")
    {
        bool mist;
        check_string(&mist, this, file_name.toStdString());
        if(mist)
            return;
        std::ifstream  src(file_name.toStdString());
        std::ofstream  dst("struct.txt");
        bool b = false;
        if(ui->comboBox_alg->currentIndex() != 0)
            b = true;
        dst << 1 << (int)b << std::endl;
        dst << src.rdbuf();
        src.close();
        dst.flush();
        dst.close();
        step = 0;
        DrawAlg();
    }
}

void MainWindow::on_action_start_auto_triggered()
{
    //Запуск автоматичної демонстрації
    if(FILE *f = fopen("struct.txt", "r")){
        fclose(f);
        AlgStruct as;
        as.enterS();
        finished = false;
        if(!as.check_ready()){//Перевіряємо, чи обрали алгоритм та задали структуру
            if(ui->comboBox_alg->currentIndex() == 0) //Знаходимо, що саме користувач забув зробити :)
                QMessageBox::warning(this, "Увага!", "Оберіть алгоритм перед запуском демонстрації!");
            else
                QMessageBox::warning(this, "Увага!", "Введіть структуру перед запуском демонстрації!");
        }
        else{
            FILE* f1 = fopen("steps.txt", "w");//У цей файл записуватимуться дані про крок алгоритму
            fclose(f1);
            step = 1;
            alg_ind = ui->comboBox_alg->currentIndex();
            ui->action_pause->setEnabled(true);
            ui->action_prev_step->setEnabled(false);
            ui->action_next_step->setEnabled(false);
            if(!custom_interval_set)
                timer_auto->setInterval(500);
            timer_auto->start();
            timer_stopped = false;
            ui->label_str_entered->setText("");
        }
    }
    else {
      if (ui->comboBox_alg->currentIndex() == 0)
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
        fclose(f);
        AlgStruct as;
        as.enterS();
        finished = false;
        if(!as.check_ready()){
            if(ui->comboBox_alg->currentIndex() == 0)
                QMessageBox::warning(this, "Увага!", "Оберіть алгоритм перед запуском демонстрації!");
            else
                QMessageBox::warning(this, "Увага!", "Введіть структуру перед запуском демонстрації!");
        }
        else{
            FILE* f1 = fopen("steps.txt", "w");
            fclose(f1);
            step = 1;
            alg_ind = ui->comboBox_alg->currentIndex();
            timer_stopped = true;
            ui->action_pause->setIcon(QIcon(":/img/img/cont.png"));
            ui->action_pause->setEnabled(true);
            ui->action_prev_step->setEnabled(false);
            ui->action_next_step->setEnabled(true);
            ui->label_str_entered->setText("");
            this->call_algorithm();
        }
    }
    else {
      if (ui->comboBox_alg->currentIndex() == 0)
        QMessageBox::warning(this, "Увага!",
                             "Оберіть алгоритм і введіть структуру перед "
                             "запуском демонстрації!");
      else
        QMessageBox::warning(this, "Увага!",
                             "Введіть структуру перед "
                             "запуском демонстрації!");
    }
}

bool nowhere_to_go(int step){
    std::ifstream i("steps.txt");
    std::string s;
    std::getline(i, s);
    int r = std::stoi(s);
    while(!i.eof()){
        std::getline(i,s);
        std::getline(i,s);
        std::getline(i,s);
        std::getline(i,s);
        r--;
    }
    i.close();
    if(r >= step)
        return true;
    return false;
}

void MainWindow::on_action_prev_step_triggered()
{
    step-=2;
    ui->action_pause->setIcon(QIcon(":/img/img/cont.png"));
    ui->action_pause->setEnabled(true);
    if(step < 2 || nowhere_to_go(step - 2))
        ui->action_prev_step->setEnabled(false);
    this->call_algorithm();
}

void MainWindow::on_action_next_step_triggered()
{
    //Перемикаємо крок на наступний
    if(step >= 2)
        ui->action_prev_step->setEnabled(true);
    this->call_algorithm();
}

void MainWindow::on_action_pause_triggered()
{
    if(timer_stopped)
    {
        ui->action_pause->setIcon(QIcon(":/img/img/pause.png"));
        if(!custom_interval_set)
            timer_auto->setInterval(500);
        timer_auto->start();
        ui->action_prev_step->setEnabled(false);
        ui->action_next_step->setEnabled(false);
        timer_stopped = false;
    }
    else
    {
        ui->action_pause->setIcon(QIcon(":/img/img/cont.png"));
        timer_auto->stop();
        ui->action_prev_step->setEnabled(true);
        ui->action_next_step->setEnabled(true);
        timer_stopped = true;
    }
}

void MainWindow::on_action_stop_triggered()
{
    ui->action_prev_step->setEnabled(false);
    ui->action_next_step->setEnabled(false);
    ui->action_pause->setEnabled(false);
    ui->action_pause->setIcon(QIcon(":/img/img/pause.png"));
    step = 0;
    timer_auto->stop();
    QGraphicsScene *s_demo = new QGraphicsScene(0, 0, GRWIDTH, GRHEIGHT, ui->graphicsView_demo);
    QGraphicsScene *s_str = new QGraphicsScene(0,0, 610, 130, ui->graphicsView_struct);
    ui->graphicsView_demo->setScene(s_demo);
    ui->graphicsView_struct->setScene(s_str);
    s_demo->setBackgroundBrush(Qt::black);
    s_str->setBackgroundBrush(Qt::black);
    ui->graphicsView_demo->show();
    ui->graphicsView_struct->show();
}

void MainWindow::on_action_reset_triggered()
{
    ui->action_prev_step->setEnabled(false);
    ui->action_next_step->setEnabled(false);
    ui->action_pause->setEnabled(false);
    step = 0;
    timer_auto->stop();
    ui->comboBox_alg->setCurrentIndex(0);
    remove("struct.txt");
    QGraphicsScene *s_demo = new QGraphicsScene(0, 0, GRWIDTH, GRHEIGHT, ui->graphicsView_demo);
    QGraphicsScene *s_str = new QGraphicsScene(0,0, 610, 130, ui->graphicsView_struct);
    ui->graphicsView_demo->setScene(s_demo);
    ui->graphicsView_struct->setScene(s_str);
    s_demo->setBackgroundBrush(Qt::black);
    s_str->setBackgroundBrush(Qt::black);
    ui->graphicsView_demo->show();
    ui->graphicsView_struct->show();
}

void MainWindow::on_pushButton_1_clicked()
{
    //Задання інтервалу таймера
    int new_interval = ui->lineEdit_tim->text().toInt();
    if(new_interval < 10)
        QMessageBox::warning(this, "Замалий інтервал", "Встановіть інтервал більше 10 мс, інакше графіка буде страшною!");
    else
    {
        timer_auto->setInterval(ui->lineEdit_tim->text().toInt());
        custom_interval_set = true;
        if(new_interval > 10000)
            QMessageBox::warning(this, "Завеликий інтервал", "З таким інтервалом демонстрація завершиться не скоро...");
    }
}

void MainWindow::on_action_exit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_comboBox_alg_currentIndexChanged(int index)
{
    //Обираємо в comboBox якийсь пункт - 
    //ставимо у файлі (якщо він уже створений) позначку, що алгоритм обраний (index >= 1)
    //або ні (index == 0)
    char b = '1';
    if(index == 0){
        b = '0';
    }
    if (QFile::exists("struct.txt")) {
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
      QFile::remove("struct.txt");
      QFile::rename("temp.txt", "struct.txt");
    }
}

int amtsteps(){
    std::ifstream i("steps.txt");
    std::string s;
    int amount_of_steps = 0, laststep, earlieststep;
    std::getline(i, s);
    laststep = std::stoi(s);
    while(!i.eof()){
        std::getline(i, s);
        std::getline(i, s);
        std::getline(i, s);
        std::getline(i, s);
        amount_of_steps++;
        if(i.eof())
            earlieststep = laststep-amount_of_steps;
    }
    i.close();
    if(earlieststep > 1)
        amount_of_steps--;
    return amount_of_steps;
}

void MainWindow::on_action_h1_triggered()
{
    if(amtsteps() == 15)
        step-=15;
    else
        step-=amtsteps();
    this->call_algorithm();   
}


void MainWindow::on_action_h2_triggered()
{
    if(amtsteps() == 15)
        step-=14;
    else
        step-=amtsteps() - 1;
    this->call_algorithm();  
}


void MainWindow::on_action_h3_triggered()
{
    if(amtsteps() == 15)
        step-=13;
    else
        step-=amtsteps() - 2;
    this->call_algorithm();  
}


void MainWindow::on_action_h4_triggered()
{
    if(amtsteps() == 15)
        step-=12;
    else
        step-= amtsteps() - 3;
    this->call_algorithm();  
}


void MainWindow::on_action_h5_triggered()
{
    if(amtsteps() == 15)
        step-=11;
    else
        step-=amtsteps() - 4;
    this->call_algorithm();  
}


void MainWindow::on_action_h6_triggered()
{
    if(amtsteps() == 15)
        step-=10;
    else
        step-=amtsteps() - 5;
    this->call_algorithm();  
}


void MainWindow::on_action_h7_triggered()
{
    if(amtsteps() == 15)
        step-=9;
    else
        step-=amtsteps() - 6;
    this->call_algorithm();  
}


void MainWindow::on_action_h8_triggered()
{
    if(amtsteps() == 15)
        step-=8;
    else
        step-=amtsteps() -7;
    this->call_algorithm();  
}


void MainWindow::on_action_h9_triggered()
{
    if(amtsteps() == 15)
        step-=7;
    else
        step-=amtsteps() - 8;
    this->call_algorithm();  
}


void MainWindow::on_action_h10_triggered()
{
    if(amtsteps() == 15)
        step-=6;
    else
        step-=amtsteps() - 9;
    this->call_algorithm();  
}


void MainWindow::on_action_h11_triggered()
{
    if(amtsteps() == 15)
        step-=5;
    else
        step-=amtsteps() - 10;
    this->call_algorithm();  
}


void MainWindow::on_action_h12_triggered()
{
    if(amtsteps() == 15)
        step-=4;
    else
        step-=amtsteps() - 11;
    this->call_algorithm();  
}


void MainWindow::on_action_h13_triggered()
{
    if(amtsteps() == 15)
        step-=3;
    else
        step-=amtsteps() - 12;
    this->call_algorithm();  
}


void MainWindow::on_action_h14_triggered()
{
    if(amtsteps() == 15)
        step-=2;
    else
        step-=amtsteps() - 13;
    this->call_algorithm();  
}


void MainWindow::on_action_h15_triggered()
{
    if(amtsteps() == 15)
        step-=1;
    else
        step-=amtsteps() - 14;
    this->call_algorithm();  
}

