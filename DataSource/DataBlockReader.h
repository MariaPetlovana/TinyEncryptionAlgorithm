#ifndef DATABLOCKREADER_H_INCLUDED
#define DATABLOCKREADER_H_INCLUDED

#include "DataSource.h"
#include <cstring>

class DataBlockReader
{
    private:
        uint32_t block[2];
        size_t pos;
        static const size_t BlockSize=8;
    public:
        uint32_t* GetBlock(DataSource* DataFrom);
};

#endif // DATABLOCKREADER_H_INCLUDED
