#include "selection_sort.h"

Selection_sort::Selection_sort()
{
    
}

void Selection_sort::do_sort(int step, int ind[], bool* finished){
    std::vector<double> vec = this->get_S();
    std::string step_info ;
    int i = ind[0], j = ind[1] + 1, indmin = ind[2], n;
    double x, y;
    int highlight[2];
    n = vec.size();
    while(i < n - 1){
        while(j < n){
            highlight[0] = j;
            highlight[1] = indmin;
            step_info = "Порівняння елементів " + std::to_string(j) + " та " + std::to_string(indmin);
            if (vec.at(indmin) > vec.at(j)) {
                indmin = j;
                step_info = "Новий індекс мін. ел-ту - " + std::to_string(indmin);
            }
            ind[0] = i;
            ind[1] = j;
            ind[2] = indmin;
            this->saveStepInfo(ind, 3, highlight, 2, step_info, vec, step);
            return;
        }
        if(indmin != i)
        {
            x = vec.at(indmin);
            y = vec.at(i);
            vec.erase(vec.begin() + indmin);
            vec.insert(vec.begin() + indmin, y);
            vec.erase(vec.begin() + i);
            vec.insert(vec.begin() + i, x);
        }
        i++;
        j = i + 1;
        indmin = i;
    }
    highlight[0] = -1;
    highlight[1] = -1;
    step_info = "Завершення алгоритму";
    this->saveStepInfo(ind, 3, highlight, 2, step_info, vec, step);
    *finished = true;
    this->set_S((vec));
}
