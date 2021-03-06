#ifndef DATABLOCKWRITER_H_INCLUDED
#define DATABLOCKWRITER_H_INCLUDED

#include "DataSource.h"
#include <cstring>

class DataBlockReader
{
    private:
        uint32_t block[2];
        bool pos;
        static const size_t BlockSize=8;
    public:
        uint32_t* GetBlock(DataSource* DataFrom)
        {

            memset(block, 0, sizeof(block));
            char c;
            vector<bool> b;
            uint32_t d=0;
            int cou=0;


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
        //return r;

        return block;

        }
};

#endif // DATABLOCKWRITER_H_INCLUDED
