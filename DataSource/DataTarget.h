#ifndef DATATARGET_H_INCLUDED
#define DATATARGET_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class DataTarget
{
protected:
    virtual void PutTarget(vector<uint32_t>) = 0;
    static const size_t BlockSize = 2;

public:
    void PutData(vector<uint32_t> v)
    {
        PutTarget(v);
        return;
    }

    virtual void PutBlock(uint32_t* v) = 0;
};

#endif // DATATARGET_H_INCLUDED
