#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include "algstruct.h"

class Insertion_sort : public AlgStruct
{
public:
    Insertion_sort();
    void do_sort(int step, int ind[], bool* finished);
};

#endif // INSERTION_SORT_H
