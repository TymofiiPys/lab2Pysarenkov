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
    switch (row[0]) {
    case '0':
        this->S_SET = false;
        break;
    case '1':
        this->S_SET = true;
        break;
    }
    switch (row[1]) {
    case '0':
        this->ALG_SET = false;
        break;
    case '1':
        this->ALG_SET = true;
        break;
    }
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

void AlgStruct::saveStepInfo(int* ind, int indamt, int* highlight, int hamt, std::string step_info, std::vector<double> vstep, int step){
    std::ofstream o("temp.txt");
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
    o << step_info << std::endl;
    for(auto it = vstep.begin(); it != vstep.end(); it++){
        o << *it;
        if(it != vstep.end() - 1)
            o << " ";
    }
    std::string s;
    if(step != 1)
    {
        o << std::endl;
        std::ifstream i("steps.txt");
        std::getline(i, s);
        if(step > 16)//Зберігається інформація не більше, ніж для 15 кроків + 1 для відновлення найбільш давнього кроку
        {
            int c = 0;
            while(c < 60 && !i.eof()){
                std::getline(i, s);
                o << s;
                c++;
                if(c < 60 && !i.eof())
                    o <<std::endl;
            }
        }
        else
            while(!i.eof())
            {
                std::getline(i, s);
                o << s;
                if(!i.eof())
                    o << std::endl;
            }
        i.close();
    }
    o.flush();
    o.close();
    remove("steps.txt");
    rename("temp.txt", "steps.txt");
}

bool AlgStruct::check_ready(){
    return this->S_SET && this->ALG_SET;
}

