#include "FileSource.h"

FileSource::FileSource(char* NameString)
{
    fi.open(NameString);
    CountByte=0;
    pos=0;
}

FileSource::~FileSource()
{
    fi.close();
}

bool FileSource::HasNext()
{
    char d;
    if (!fi.eof() && fi.get(d))
    {
        fi.putback(d);
        return 1;
    }
    return 0;
}

char FileSource::ReturnByte()
{
    fi.get(ch);
    ++CountByte;
    return ch;
}

vector<uint32_t> FileSource::ReadSource()
{
    vector<uint32_t> v;
    vector<bool> b;

    uint32_t d=0, p1=0;
    int cou=0, c;
    char buf=0;

    while(!fi.eof() && fi.get(buf))
    {
        c=buf;
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

    return v;
}
