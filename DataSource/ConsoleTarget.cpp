#include "ConsoleTarget.h"

void ConsoleTarget::PutTarget(vector<uint32_t> v)
{
    char mybuf[4], cha=0;
    int cou1=0;
    uint32_t p1;

    for(int k=0; k<v.size(); k++)
    {
        p1=v[k];
        memset(mybuf, 0, sizeof(mybuf));

        for(int i=0; i<4; i++)
        {
            cha=0;
            cou1=0;

            for(int j=0; j<8; j++)
            {
                cha |= (p1 & 1)<<cou1;
                cou1++;
                p1>>=1;
            }

            if(cha) mybuf[3-i]=cha;
        }

        for(int i=0; i<4; i++)
        if(mybuf[i]) cout<<mybuf[i];
    }

    return;
}

void ConsoleTarget::PutBlock(uint32_t* v)
{
    char mybuf[4], cha=0;
    int cou1=0;
    uint32_t p1;

    for(int k=0; k<BlockSize; k++)
    {
        p1=v[k];
        memset(mybuf, 0, sizeof(mybuf));

        for(int i=0; i<4; i++)
        {
            cha=0;
            cou1=0;

            for(int j=0; j<8; j++)
            {
                cha |= (p1 & 1)<<cou1;
                cou1++;
                p1>>=1;
            }

            if(cha) mybuf[3-i]=cha;
        }

        for(int i=0; i<4; i++)
        {
            if(mybuf[i])
            {
                cout<<mybuf[i];
            }
        }
    }

    return;
}

