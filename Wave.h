//
// Created by Alice Santilli on 2017-11-08.
//

#ifndef MADAWASKA_WAVE_H
#define MADAWASKA_WAVE_H

#include <string>
#include <vector>

using namespace std;


class Wave {

    // Wave elements
private :
    vector<int> wave1 = {1,10,1};
    vector<int> wave2 = {2, 20, 2};
    vector<int> wave3 = {3, 30 ,3};

public:
    vector<int> getWaveElements(const int);
    
};


#endif //MADAWASKA_WAVE_H
