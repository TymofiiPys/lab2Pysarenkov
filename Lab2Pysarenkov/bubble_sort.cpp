#include "bubble_sort.h"

Bubble_sort::Bubble_sort()
{
    
}

void Bubble_sort::do_sort(int step, int ind[], bool* finished){
    std::vector<double> vec = this->get_S();
    int i = ind[0], j = ind[1] + 1, n;
    double x, y;
    int highlight[2];
    n = vec.size();
    while(i < n - 1){
        while(j < n - i - 1){
            x = vec.at(j);
            y = vec.at(j + 1);
            highlight[0] = j;
            highlight[1] = j + 1;
            if (vec[j] > vec[j + 1]) {
              vec.erase(vec.begin() + j);
              vec.insert(vec.begin() + j, y);
              vec.erase(vec.begin() + j + 1);
              vec.insert(vec.begin() + j + 1, x);
            }
            ind[0] = i;
            ind[1] = j;
            this->saveStepInfo(ind, 2, highlight, 2, vec, step);
            return;
        }
        i++;
        j = 0;
    }
    highlight[0] = -1;
    highlight[1] = -1;
    this->saveStepInfo(ind, 2, highlight, 2, vec, step);
    *finished = true;
    this->set_S((vec));
}
