#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "algstruct.h"

class Bubble_sort: public AlgStruct
{
public:
    Bubble_sort();
    void do_sort(int step, int ind[], bool* finished);
};

#endif // BUBBLE_SORT_H
