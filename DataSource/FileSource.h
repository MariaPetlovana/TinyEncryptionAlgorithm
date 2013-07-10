#ifndef FILESOURCE_H_INCLUDED
#define FILESOURCE_H_INCLUDED

#include "DataSource.h"

using namespace std;

class FileSource : public DataSource
{
public:
    FileSource (char* NameString);
    ~FileSource ();
    virtual bool HasNext();
    virtual char ReturnByte();

protected:
    ifstream fi;
    virtual vector<uint32_t> ReadSource();
};

#endif // FILESOURCE_H_INCLUDED
