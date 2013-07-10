#ifndef CONSOLETARGET_H_INCLUDED
#define CONSOLETARGET_H_INCLUDED

#include "DataTarget.h"

using namespace std;

class ConsoleTarget : public DataTarget
{
public:
    virtual void PutBlock(uint32_t* v);

protected:
    virtual void PutTarget (vector<uint32_t> v);
};

#endif // CONSOLETARGET_H_INCLUDED
