#include "algstruct.h"
#include <fstream>

AlgStruct::AlgStruct()
{
    this->ALG_SET = false;
    this->S_SET = false;
}

std::vector<double> AlgStruct::get_S(){
    return this->S;
}

void AlgStruct::set_S(std::vector<double> v){
    this->S = v;
}

void AlgStruct::enterS(){
    std::ifstream file("struct.txt");
    double d;
    std::string sd, row;
    std::getline(file, row);
    this->S_SET = row[0];
    this->ALG_SET = row[1];
    std::getline(file, row);//Одновимірний масив записаний в одному рядку
    for (int i = 0; i < row.length(); i++) {
      if (row[i] == ' ') {
          this->S.push_back(std::stod(sd));
          sd = "";
      } else {
        sd+=row[i];
      }
    }
    this->S.push_back(std::stod(sd));
    file.close();
}

void AlgStruct::saveStepInfo(int* ind, int indamt, int* highlight, int hamt, std::vector<double> vstep, int step){
    std::ofstream o("temp.txt");
    std::ifstream i("steps.txt");
    o << step << std::endl;
    for(int i = 0; i < indamt; i++){
        o << ind[i];
        if(i != indamt - 1)
            o << " ";
    }
    o << std::endl;
    for(int i = 0; i < hamt; i++){
        o << highlight[i];
        if(i != hamt - 1)
            o << " ";
    }
    o << std::endl;
    for(auto it = vstep.begin(); it != vstep.end(); it++){
        o << *it;
        if(it != vstep.end() - 1)
            o << " ";
    }
    o << std::endl;
    std::string s;
    std::getline(i, s);
    if(step > 15)//Зберігається інформація не більше, ніж для 15 кроків
    {
        int c = 0;
        while(c < 42){
            std::getline(i, s);
            o << s << std::endl;
            c++;
        }
    }
    else
        while(!i.eof())
        {
            std::getline(i, s);
            o << s << std::endl;
        }
    i.close();
    o.flush();
    o.close();
    remove("steps.txt");
    rename("temp.txt", "steps.txt");
}

void AlgStruct::reset(){
    this->S_SET = false;
}

bool AlgStruct::check_ready(){
    return this->S_SET && this->ALG_SET;
}

//void AlgStruct::entry_rnd(double min, double max, double amount) {
//    this->S_SET = true;
//    int interval = max - min;
//    for(int i = 0; i < amount; i++){
//        this->S.push_back(rand() % interval + min);
//    }
//}

//void AlgStruct::entry_manual(std::string text) {
//    this->S_SET = true;
//    int i, j;
//    std::string snum;
//    for(i = 0; i < text.length(); i++){
//        if(text[i] == ' ')
//        {
//            snum = "";
//            this->S.push_back(std::stoi(snum));
//        }
//        else{
//            snum += text[i];
//        }
//    }
//}

