#include "merge_sort.h"

Merge_sort::Merge_sort()
{
    
}

void Merge_sort::merge(int step, int ind[], bool* step_finished, int l, int m, int r)
{
    std::vector<double> vec = this->get_S();
    std::string step_info;
    int highlight[2];
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    double L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = vec.at(l + i);
    for (j = 0; j < n2; j++)
        R[j] = vec.at(m + 1 + j);
 
    i = ind[0];
    j = ind[1];
    k = ind[2];
    //k = l;
    highlight[0] = l + i;
    highlight[1] = m + 1 + j;
    while (i < n1 && j < n2) {
        vec.erase(vec.begin() + k);
        if (L[i] <= R[j]) {
            vec.insert(vec.begin() + k, L[i]);
            i++;
            ind[0] = i;
        }
        else {
            vec.insert(vec.begin() + k, R[j]);
            j++;
            ind[1] = j;
        }
        k++;
        ind[2] = k;
        this->saveStepInfo(ind, 4, highlight, 2, step_info, vec, step);
        *step_finished = true;
        return;
    }  
    /* Copy the remaining elements of L[], if there
    are any */
    highlight[0] = l + i;
    highlight[1] = -1;
    while (i < n1) {
        vec.erase(vec.begin() + k);
        vec.insert(vec.begin() + k, L[i]);
        i++;
        k++;
        ind[0] = i;
        ind[2] = k;
        this->saveStepInfo(ind, 4, highlight, 2, step_info, vec, step);
        *step_finished = true;
        return;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    highlight[0] = -1;
    highlight[1] = m + 1 + j;
    while (j < n2) {
        vec.erase(vec.begin() + k);
        vec.insert(vec.begin() + k, R[j]);
        j++;
        k++;
        ind[1] = j;
        ind[2] = k;
        this->saveStepInfo(ind, 4, highlight, 2, step_info, vec, step);
        *step_finished = true;
        return;
    }
    highlight[0] = -1;
    highlight[1] = -1;
    ind[3]++;
    this->saveStepInfo(ind, 4, highlight, 2, step_info, vec, step);
    *step_finished = true;
}

void Merge_sort::mergeSort(int step, int ind[], bool* finished, bool* step_finished, int l, int r, int *merge_calls, int depth){
    if (l < r) {
            int m = l + (r - l) / 2;
            if(!(*step_finished))
                mergeSort(step, ind, finished, step_finished, l, m, merge_calls, depth++);
            if(!(*step_finished))
                mergeSort(step, ind, finished, step_finished, m + 1, r, merge_calls, depth++);
            if(*merge_calls == ind[3] && !(*step_finished))
            {
                merge(step, ind, step_finished, l, m, r);
                return;
            }
            *merge_calls += 1;
        }
    if(depth == 0 && !(*step_finished))
    {
        std::string step_info = "Завершення алгоритму";
        int highlight[2];
        highlight[0] = -1;
        highlight[1] = -1;
        this->saveStepInfo(ind, 4, highlight, 2, step_info, this->get_S(), step);
        *finished = true;
    }
}

void Merge_sort::do_sort(int step, int ind[], bool* finished){
    //highlight[0] - лівий елемент
    //highlight[1] - середній
    //highlight[2] - правий
    //ind[0] - ітератор лівого підмасиву
    //ind[1] - правого
    //ind[2] - утвореного злиттям
    //ind[3] - кількість завершених merge()
    std::vector<double> vec = this->get_S();
    int merge_calls = 0;
    bool step_finished = false; //так як сортування злиттям - рекурсивний алгоритм,
    //то по завершенню кроку потрібно буде повернутися із усіх рекурсивних викликів нагору,
    //а щоб merge_sort по поверненню із merge не почала виконувати наступні виклики, вводиться
    //цей бул
    mergeSort(step, ind, finished, &step_finished, 0, vec.size() - 1, &merge_calls, 0);
}
