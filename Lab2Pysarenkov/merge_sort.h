#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "algstruct.h"

class Merge_sort: public AlgStruct
{
public:
    Merge_sort();
    void do_sort(int step, int ind[], bool* finished);
    void mergeSort(int step, int ind[], bool* finished, bool* step_finished, int l, int r, int *merge_calls, int depth);
    void merge(int step, int ind[], bool* step_finished, int l, int m, int r);
};
#endif // MERGE_SORT_H
