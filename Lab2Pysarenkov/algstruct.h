#ifndef ALGSTRUCT_H
#define ALGSTRUCT_H
#include <vector>
#include <string>

class AlgStruct
{
private:
    std::vector<double> S; //Структура, що виступає вхідними даними для алгоритмів
    bool S_SET; //вказує, чи задана структура
    bool ALG_SET; //вказує, чи обраний алгоритм
//    int step; //Номер кроку
//    int i, j; //Ітератори циклів, що лежать в основі алгоритмів
public:
    AlgStruct();
//    void entry_rnd(double min, double max, double amount);
    void enterS(); //Зчитування вектора у 
//    void entry_manual(std::string text);
    bool check_ready();
    void reset();
    std::vector<double> get_S();
    void set_S(std::vector<double> v);
    void get_set_Step(int* x, bool get_or_set);
    void saveStepInfo(int* ind, int indamt, int* highlight, int hamt, std::string step_info, std::vector<double> vstep, int step);
};

#endif // ALGSTRUCT_H
