#ifndef MEMORYTARGET_H_INCLUDED
#define MEMORYTARGET_H_INCLUDED

#include "DataSource.h"

using namespace std;

template<typename T>
class MemoryTarget : public DataTarget
{
public:
    MemoryTarget (T* OutputMemoryArray);

protected:
    T* MemoryArray;
    size_t SizeOfArray;
    size_t SizeOfElement;

    virtual void PutTarget (vector<uint32_t> v);
};



template<typename T>
MemoryTarget<T>::MemoryTarget(T* OutputMemoryArray)
{
    SizeOfArray=0;
    SizeOfElement=0;
    if(OutputMemoryArray!=NULL)
    {
        SizeOfElement = sizeof(T);
        SizeOfArray = sizeof(OutputMemoryArray)/SizeOfElement;
        MemoryArray = OutputMemoryArray;
    }
}


template<typename T>
void MemoryTarget<T>::PutTarget(vector<uint32_t> v)
{
    size_t size = (4/SizeOfElement) ? 4/SizeOfElement : 1;
    T mybuf[size], cha=0;
    int cou1=0;
    uint32_t p1;

    for(int k=0; k<v.size(); k++)
    {
        p1=v[k];
        memset(mybuf, 0, sizeof(mybuf));

        for(int i=0; i<size; i++)
        {
            cha=0;
            cou1=0;

            for(int j=0; j<8*SizeOfElement; j++)
            {
                cha |= (p1 & 1)<<cou1;
                cou1++;
                p1>>=1;
            }

            if(cha) mybuf[size-i-1]=cha;
        }

        for(int i=0; i<size; i++)
        {
            if(mybuf[i])
            {
                *MemoryArray = mybuf[i];
                //cout<<mybuf[i]<<endl;
                ++MemoryArray;
            }
        }
    }

    return;
}

#endif // MEMORYTARGET_H_INCLUDED
