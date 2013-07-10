#include "DataBlockReader.h"

uint32_t* DataBlockReader::GetBlock(DataSource* DataFrom)
{
    memset(block, 0, sizeof(block));
    char c;
    vector<bool> b;
    uint32_t d=0;
    int cou=0;
    pos=0;

    for (size_t i = 0; i < BlockSize; ++i)
    {
        if (DataFrom->HasNext())
        {
            c=DataFrom->ReturnByte();
            b.clear();

            for(int j=0; j<8; j++)
            {
                if(c & 1) b.push_back(1);
                else b.push_back(0);
                c>>=1;
            }

            reverse(b.begin(), b.end());

            for(int i=0; i<8; i++)
            {
                d |= (b[i]<<(31-cou));
                cou++;
            }

            if(cou==32)
            {
                cou=0;
                block[pos]=d;
                ++pos;
                d=0;
            }

        }
        else break;
    }

    if(cou)
    {
        d>>=(32-cou);
        block[pos]=d;
        ++pos;
        cou=0;
        d=0;
    }

    if(block[0] && !block[1])
    {
        block[1]=block[0];
        block[0]=0;
    }

    return block;
}

size_t DataBlockReader::GetBlock1(DataSource* DataFrom, uint32_t* res)
{
    memset(res, 0, sizeof(res));
    char c;
    vector<bool> b;
    uint32_t d=0;
    int cou=0;
    pos=0;
    bytes=0;

    for (size_t i = 0; i < BlockSize; ++i)
    {
        if (DataFrom->HasNext())
        {
            c=DataFrom->ReturnByte();
            ++bytes;
            b.clear();

            for(int j=0; j<8; j++)
            {
                if(c & 1) b.push_back(1);
                else b.push_back(0);
                c>>=1;
            }

            reverse(b.begin(), b.end());

            for(int i=0; i<8; i++)
            {
                d |= (b[i]<<(31-cou));
                cou++;
            }

            if(cou==32)
            {
                cou=0;
                res[pos]=d;
                ++pos;
                d=0;
            }

        }
        else break;
    }

    if(cou)
    {
        d>>=(32-cou);
        res[pos]=d;
        ++pos;
        cou=0;
        d=0;
    }

    if(res[0] && !res[1])
    {
        res[1]=res[0];
        res[0]=0;
    }

    return bytes;
}

