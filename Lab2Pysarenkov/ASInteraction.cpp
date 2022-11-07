#include "ASinteraction.h"
#include "algstruct.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include <fstream>
#include <QMessageBox>

void ASinter::writeSToFile(std::vector<double> S){//Запис вектора у файл для подальшого використання в процесі виконання програми
    std::ofstream o("struct.txt");
    o << 0 << 0 << std::endl; //S_SET = false, ALG_SET = false
    for(auto it = S.begin(); it != S.end(); it++){
        o << *it;
        if(it != S.end() - 1)
            o << " ";
    }
    o.close();
}

std::vector<double> ASinter::readSFromFile(){//Читання вектора з файлу для запису в об'єкт класу
    std::vector<double> v;
    std::ifstream i("struct.txt");
    std::string row, sd;
    std::getline(i, row);
    for (int i = 0; i < row.length(); i++) {
      if (row == "") {
          v.push_back(std::stod(sd));
          sd = "";
      } else {
        sd+=row[i];
      }
    }
    i.close();
    return v;
}

void ASinter::getPrevStepInfo(std::vector<int> *ind, std::vector<double> *vstep, int step){
    //Ця процедура отримує ДЛЯ ЗДІЙСНЕННЯ НАСТУПНОГО КРОКУ АЛГОРИТМУ
    //вектор на певному кроці та масив ind, у якому записані ітератори циклів, ключі тощо
    std::ifstream i("steps.txt");
    //1-й рядок - індекс останнього кроку
    //2k-й - ітератори циклів
    //(2k+1)-й - елементи, між якими відбувалося порівняння
    //(2k+2)-й - вектор на даному кроці
    int r, laststep;
    std::string row;
    std::getline(i, row);
    laststep = std::stoi(row);
    r = laststep;
    if(r != step){//Якщо відбувається рух на певну кількість кроків назад
        if(r - step >= 15){//Перевіряємо, чи знайдеться інформація про шуканий крок,
            //оскільки файл зберігає записи про <= 15 кроків
            QWidget *w = new QWidget;
            QMessageBox::warning(w, "Увага", "Досягнено максимально допустимого кроку назад");
            return;
        }
        std::ofstream o("temp1.txt");//переписуємо зі steps.txt всю наявну інформацію про попередні 
        //до шуканого кроки, а про наступні - не записуємо
        while(r!=step && !i.eof()){//Спускаємось до рядка, що містить step-й крок
            std::getline(i, row);
            std::getline(i, row);
            std::getline(i, row);
            r--;
        }
        o << step << std::endl; //записуємо номер кроку, на який ми повернулися - надалі
        //відштовхуємось від нього як від останнього
        while(!i.eof())
        {
            std::getline(i, row);
            o << row;
            if(!i.eof())
               o << std::endl;
        }
        i.close();
        o.flush();
        o.close();
        remove("steps.txt");
        rename("temp1.txt", "steps.txt");
        i.open("steps.txt");
        std::getline(i, row);
    }
    std::getline(i, row);
    int j = 0;
    std::string sindex = "";
    for(int k = 0; k < row.length(); k++){
      if (row[k] == ' ') {
         (*ind).push_back(std::stoi(sindex));
        sindex = "";
        j++;
      }
      else
          sindex+= row[k];
    }
    (*ind).push_back(std::stoi(sindex));
    /**ind = indexes*/;
    std::getline(i, row);//рядок з виділеними на минулому кроці елементами
    std::getline(i, row);
    std::string sd = "";
    for (int k = 0; k < row.length(); k++) {
      if (row[k] == ' ') {
          (*vstep).push_back(std::stod(sd));
          sd = "";
      } else {
        sd+=row[k];
      }
    }
    (*vstep).push_back(std::stod(sd));
    i.close();
}

void ASinter::getPrevStepInfo(std::vector<double> *vstep, int step, std::vector<int> *highlight){
    //Ця процедура отримує ДЛЯ ПРОМАЛЬОВКИ У GRAPHICSVIEW
    //вектор на певному кроці та елементи цього вектора, які потрібно виділити
    std::ifstream i("steps.txt");
    int r, laststep;
    std::string row;
    std::getline(i, row);
    laststep = std::stoi(row);
    r = laststep;
    if(r - step >= 15){
        QWidget *w = new QWidget;
        QMessageBox::warning(w, "Увага", "Досягнено максимально допустимого кроку назад");
        return;
    }
    while(r != step && !i.eof()){//Спускаємось до рядка, що містить step-й крок
        std::getline(i, row);
        std::getline(i, row);
        std::getline(i, row);
        r--;
    }
    std::getline(i, row);//рядок з індексами циклів
    std::getline(i, row);
    int j = 0;
    std::string sindex = "";
    for(int k = 0; k < row.length(); k++){
      if (row[k] == ' ') {
          if(std::stoi(sindex) != -1)
              (*highlight).push_back(std::stoi(sindex));
          sindex = "";
          j++;
      }
      else
          sindex+= row[k];
    }
    (*highlight).push_back(std::stoi(sindex));
    /**ind = indexes*/;
    std::getline(i, row);
    std::string sd = "";
    for (int k = 0; k < row.length(); k++) {
      if (row[k] == ' ') {
          (*vstep).push_back(std::stod(sd));
          sd = "";
      } else {
        sd+=row[k];
      }
    }
    (*vstep).push_back(std::stod(sd));
    i.close();
}

void ASinter::doStep_Bubble_sort(int step, bool* finished){
    Bubble_sort as;
    int ind[2];
    if (step == 1) {
      as.enterS();
      ind[0] = 0; //ітератор зовнішнього циклу
      ind[1] = -1; //ітератор внутрішнього циклу
    } else {
      std::vector<double> vstep;
      std::vector<int> indv;
      getPrevStepInfo(&indv, &vstep, step - 1);
      ind[0] = indv[0];
      ind[1] = indv[1];
      as.set_S(vstep);
    }
    *finished = false;
    as.do_sort(step, ind, finished);
}

void ASinter::doStep_Insertion_sort(int step, bool *finished){
    Insertion_sort as;
    int ind[3];
    if (step == 1) {
      as.enterS();
      ind[0] = 1;//ітератор зовнішнього циклу
      ind[1] = 1;//ітератор внутрішнього циклу
      ind[2] = as.get_S().at(1); //ключ
    } else {
      std::vector<double> vstep;
      std::vector<int> indv;
      getPrevStepInfo(&indv, &vstep, step - 1);
      ind[0] = indv[0];
      ind[1] = indv[1];
      ind[2] = indv[2];
      as.set_S(vstep);
    }
    *finished = false;
    as.do_sort(step, ind, finished);
}

void ASinter::doStep_Merge_sort(int step, bool *finished){
    Merge_sort as;
    int ind[3];
    if (step == 1) {
      as.enterS();
      ind[0] = 0; //ітератор лівого підмасиву
      std::vector<double> v = as.get_S();
      ind[1] = v.size() - 1; //ітератор правого підмасиву
      ind[2] = -1; //
    } 
}

void ASinter::doStep_Selection_sort(int step, bool *finished){
    Selection_sort as;
    int ind[3];
    if (step == 1) {
      as.enterS();
      ind[0] = 0;//ітератор зовнішнього циклу
      ind[1] = -1;//ітератор внутрішнього циклу
      ind[2] = 0; //індекс найменшого елементу
    } else {
      std::vector<double> vstep;
      std::vector<int> indv;
      getPrevStepInfo(&indv, &vstep, step - 1);
      ind[0] = indv[0];
      ind[1] = indv[1];
      ind[2] = indv[2];
      as.set_S(vstep);
    }
    *finished = false;
    as.do_sort(step, ind, finished);
}
