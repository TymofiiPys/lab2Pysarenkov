#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "algstruct.h"

class Selection_sort : public AlgStruct
{
public:
    Selection_sort();
    void do_sort(int step, int ind[], bool* finished);
};

#endif // SELECTION_SORT_H
