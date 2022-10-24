#include "algstruct.h"

AlgStruct::AlgStruct()
{
    this->SOLVE_READY = false;
    this->S_SET = false;
}

void AlgStruct::entry_rnd(double min, double max, double amount) {
    this->S_SET = true;
}

void AlgStruct::entry_manual() {
    this->S_SET = true;
}

void AlgStruct::check_ready(bool* b){
    *b = this->SOLVE_READY;
}
