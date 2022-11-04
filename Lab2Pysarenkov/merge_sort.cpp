#include "merge_sort.h"

Merge_sort::Merge_sort()
{
    
}

void Merge_sort::merge(int step, int ind[], std::vector<double> vec, int l, int m, int r)
{
    int highlight[2];
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    /* create temp arrays */
    double L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vec.at(l + i);
    for (j = 0; j < n2; j++)
        R[j] = vec.at(m + 1 + j);
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = ind[0]; // Initial index of first subarray
    j = ind[1]; // Initial index of second subarray
    k = ind[2]; // Initial index of merged subarray
    //k = l;
    highlight[0] = i;
    highlight[1] = j;
    while (i < n1 && j < n2) {
        vec.erase(vec.begin() + k);
        if (L[i] <= R[j]) {
            vec.insert(vec.begin() + k, L[i]);
            i++;
            ind[0] = i;
        }
        else {
            vec.insert(vec.begin() + k, R[i]);
            j++;
            ind[1] = j;
        }
        k++;
        ind[2] = k;
        this->saveStepInfo(ind, 3, highlight, 2, vec, step);
    }  
    /* Copy the remaining elements of L[], if there
    are any */
    highlight[0] = i;
    highlight[1] = -1;
    while (i < n1) {
        vec.erase(vec.begin() + k);
        vec.insert(vec.begin() + k, L[i]);
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    highlight[0] = -1;
    highlight[1] = j;
    while (j < n2) {
        vec.erase(vec.begin() + k);
        vec.insert(vec.begin() + k, R[i]);
        j++;
        k++;
    }
    highlight[0] = -1;
    highlight[1] = -1;
    this->saveStepInfo(ind, 2, highlight, 2, vec, step);
}

void Merge_sort::mergeSort(int step, int ind[], bool* finished, int l, int r, int *merge_calls, int depth, std::vector<double> vec){
    if (l < r ) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l + (r - l) / 2;
     
            // Sort first and second halves
            mergeSort(step, ind, finished, l, m, merge_calls, depth++, vec);
            mergeSort(step, ind, finished, m + 1, r, merge_calls, depth++, vec);
            if(*merge_calls == ind[3])
                merge(step, ind, vec, l, m, r);
            *merge_calls += 1;
        }
    if(depth == 0)
        *finished = true;
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
    mergeSort(step, ind, finished, 0, vec.size() - 1, &merge_calls, 0, vec);
}
