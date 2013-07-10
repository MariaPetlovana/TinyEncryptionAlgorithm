#ifndef DATASOURCE_H_INCLUDED
#define DATASOURCE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class DataSource
{
protected:
    virtual vector<uint32_t> ReadSource() = 0;
    char ch;
    size_t pos;
    size_t CountByte;

public:
    vector<uint32_t> GetData()
    {
        vector<uint32_t> data = ReadSource();
        return data;
    }

    virtual bool HasNext() = 0;
    virtual char ReturnByte() = 0;

};

#endif // DATASOURCE_H_INCLUDED
