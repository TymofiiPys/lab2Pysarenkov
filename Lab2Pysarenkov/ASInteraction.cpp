#include "ASinteraction.h"
#include "algstruct.h"
#include "bubble_sort.h"
#include <fstream>
#include <QMessageBox>

void ASinter::setSSet(bool ss){ //Запис S_SET
    std::ofstream o("temp.txt");
    std::ifstream i("struct.txt");
    std::string S_BOOLS;
    std::getline(i, S_BOOLS);
    S_BOOLS[0] = ss;
}

void ASinter::setAlgSet(bool as){
    std::ofstream o("temp.txt");
    std::ifstream i("struct.txt");
    std::string S_BOOLS, foo;
    std::getline(i, S_BOOLS);
    S_BOOLS[1] = as;
    o << S_BOOLS;
    while(i.eof()){
        std::getline(i, foo);
        o << foo;
    }
    o.close();
    i.close();
    remove("struct.txt");
    rename("temp.txt", "struct.txt");
}

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

void getPrevStepInfo(int** ind, std::vector<double> *vstep, int step){
    std::ifstream i("steps.txt");
    //1-й рядок - індекс останнього кроку
    //2k-й - ітератори циклів
    //(2k+1)-й - вектор на даному кроці
    int r, laststep;
    std::string row;
    std::getline(i, row);
    laststep = std::stoi(row);
    r = laststep;
    while(r != step && !i.eof()){//Спускаємось до рядка, що містить step-й крок
        std::getline(i, row);
        std::getline(i, row);
        r--;
    }
    std::getline(i, row);
    int spaces = 0;
    for(int k = 0; k < row.length(); k++){
        if(row[k] == ' ')
            spaces++;
    }
//    int* indexes = new int[spaces - 1];
    *ind = new int[spaces + 1];
    int j = 0;
    std::string sindex = "";
    for(int k = 0; k < spaces - 1; k++){
      if (row[k] == ' ') {
        *ind[j] = std::stoi(sindex);
        sindex = "";
      }
      else
          sindex+= row[k];
    }
    /**ind = indexes*/;
    std::getline(i, row);
    std::string sd = "";
    for (int k = 0; k < row.length(); k++) {
      if (row == "") {
          (*vstep).push_back(std::stod(sd));
          sd = "";
      } else {
        sd+=row[k];
      }
    }
}

void ASinter::doStep_Bubble_sort(bool autom, int step, bool* finished){
    Bubble_sort as;
    int ind[2];
    if (step == 1) {
      as.enterS();
      ind[0] = 0;
      ind[1] = 0;
    } else {
      std::vector<double> vstep;
      int *indp;
      getPrevStepInfo(&indp, &vstep, step);
      ind[0] = indp[0];
      ind[1] = indp[1];
      delete[] indp;
      as.set_S(vstep);
    }
    *finished = false;
    as.do_sort(step, ind, finished);
}
