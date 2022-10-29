#ifndef ASINTERACTION_H
#define ASINTERACTION_H
#include <vector>

namespace ASinter{
    void setSSet(bool ss);
    void setAlgSet(bool as);
    void writeSToFile(std::vector<double> S);
    std::vector<double> readSFromFile();
    
    void doStep_Bubble_sort(bool autom, int step, bool *finished);
}
#endif // ASINTERACTION_H
