#ifndef ASINTERACTION_H
#define ASINTERACTION_H
#include <vector>

namespace ASinter{
    void setSSet(bool ss);
    void setAlgSet(bool as);
    void writeSToFile(std::vector<double> S);
    std::vector<double> readSFromFile();
    void getPrevStepInfo(std::vector<int> *ind, std::vector<double> *vstep, int step);//для вирішення наступного кроку алгоритму
    void getPrevStepInfo(std::vector<double> *vstep, int step, std::vector<int> *highlight);//для промальовки попереднього кроку
    
    void doStep_Bubble_sort(int step, bool *finished);
    void doStep_Merge_sort(int step, bool *finished);
    void doStep_Selection_sort(int step, bool *finished);
    void doStep_Insertion_sort(int step, bool *finished);
}
#endif // ASINTERACTION_H
