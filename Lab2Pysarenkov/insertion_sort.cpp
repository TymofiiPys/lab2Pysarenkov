#include "insertion_sort.h"

Insertion_sort::Insertion_sort()
{
    
}

void Insertion_sort::do_sort(int step, int ind[], bool* finished){
    std::vector<double> vec = this->get_S();
    std::string step_info;
    int i = ind[0], j = ind[1] - 1, key = ind[2], n;
    double x, y;
    int highlight[2];
    n = vec.size();
    while(i < n){
        while(j >= 0 && vec.at(j)>key){
            highlight[0] = i;
            highlight[1] = j;
            x = vec.at(j);
            vec.erase(vec.begin() + j + 1);
            vec.insert(vec.begin() + j + 1, x);
            step_info = "Переміщення ел-ту " + std::to_string(j) + " на місце " + std::to_string(j+1);
            ind[0] = i;
            ind[1] = j;
            ind[2] = key;
            this->saveStepInfo(ind, 3, highlight, 2, step_info, vec, step);
            return;
        }
        vec.erase(vec.begin() + j + 1);
        vec.insert(vec.begin() + j + 1, key);
        i++;
        j = i - 1;
        if(i < n)
            key = vec.at(i);
    }
    highlight[0] = -1;
    highlight[1] = -1;
    step_info = "Завершення алгоритму";
    this->saveStepInfo(ind, 3, highlight, 2, step_info, vec, step);
    *finished = true;
    this->set_S((vec));
}
