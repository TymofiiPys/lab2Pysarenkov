#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "algstruct.h"

class Merge_sort: public AlgStruct
{
public:
    Merge_sort();
    void do_sort(int step, int ind[], bool* finished);
    void mergeSort(int step, int ind[], bool* finished, int l, int r, int *merge_calls, int depth, std::vector<double> vec);
    void merge(int step, int ind[], std::vector<double> vec, int l, int m, int r);
};
#endif // MERGE_SORT_H
