#ifndef ENCRYPT_H_INCLUDED
#define ENCRYPT_H_INCLUDED

#include "Abstract_Encrypt.h"

using namespace std;

class Encrypt: public Abstract_Encrypt
{
  public:
    virtual void engine (DataSource* MyDataSource, DataTarget* MyTarget, uint32_t* pswd, const bool CryptMode);
    virtual void engine1 (DataSource* MyDataSource, DataTarget* MyTarget, uint32_t* pswd, const bool CryptMode);
};

#endif // ENCRYPT_H_INCLUDED
