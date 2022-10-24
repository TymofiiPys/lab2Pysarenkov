#ifndef ALGSTRUCT_H
#define ALGSTRUCT_H
#include <vector>

class AlgStruct
{
private:
    std::vector<double> S;
    bool S_SET;
    bool SOLVE_READY;
public:
    AlgStruct();
    void entry_rnd(double min, double max, double amount);
    void entry_file();
    void entry_manual();
    void check_ready(bool* b);
};

#endif // ALGSTRUCT_H
