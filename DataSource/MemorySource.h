#ifndef MEMORYSOURCE_H_INCLUDED
#define MEMORYSOURCE_H_INCLUDED

#include "DataSource.h"
#include "Range.h"

using namespace std;

template<typename T>
class MemorySource : public DataSource
{
public:
    virtual bool HasNext()
    {
        if(MyRange.BeginByte != MyRange.EndByte)
        return 1;
        return 0;
    }
    virtual char ReturnByte()
    {
        char ret = *MyRange.BeginByte;
        ++MyRange.BeginByte;
        return ret;
    }
    MemorySource(T* array, size_t n)
    {
        MyRange.MakeRange(array, n);
    }

protected:
    //T* MemoryArray;
    //size_t SizeOfArray;
    //size_t SizeOfElement;

    Range<T, char> MyRange;

    //virtual vector<uint32_t> ReadSource();
};
/*
template<typename T>
MemorySource<T>::MemorySource(T* InputMemoryArray)
{
    SizeOfArray=0;
    SizeOfElement=0;
    if(InputMemoryArray!=NULL)
    {
        SizeOfElement = sizeof(T);
        SizeOfArray = sizeof(InputMemoryArray)/SizeOfElement;
        MemoryArray = InputMemoryArray;
    }
}
*/

/*
template<typename T>
vector<uint32_t> MemorySource<T>::ReadSource()
{
    vector<uint32_t> v;
    vector<bool> b;

    uint32_t d=0, p1=0;
    int cou=0;
    char buf=0;

    for(int i=0; i<SizeOfArray; i++)
    {
        T c = MemoryArray[i];
        b.clear();

        for(int j=0; j<8*SizeOfElement; j++)
        {
            if(c & 1) b.push_back(1);
            else b.push_back(0);
            c>>=1;
        }
        reverse(b.begin(), b.end());

        for(int i=0; i<8*SizeOfElement; i++)
        {
            d |= (b[i]<<(31-cou));
            cou++;

            if(cou==32)
            {
                cou=0;
                v.push_back(d);
                d=0;
            }
        }
        if(cou==32)
        {
            cou=0;
            v.push_back(d);
            d=0;
        }
    }
    if(cou)
    {
        d>>=(32-cou);
        v.push_back(d);
        cou=0;
        d=0;
    }
    /*
    for(int j=0; j<v.size(); j++)
    cout<<v[j]<<endl;

    cout<<endl;

    return v;
}
*/
#endif // MEMORYSOURCE_H_INCLUDED
