#ifndef ABSTRACT_ENCRYPT_H_INCLUDED
#define ABSTRACT_ENCRYPT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>

#include "DataSource.h"
#include "DataTarget.h"

using namespace std;

class Abstract_Encrypt
{
  protected:
    static const uint32_t delta=0x9e3779b9;
    uint32_t sum, i;
    uint32_t key[4], vec[2];

 public:
    virtual void engine (DataSource* MyDataSource, DataTarget* MyTarget, uint32_t* pswd, bool CryptMode) = 0;
    virtual void engine1 (DataSource* MyDataSource, DataTarget* MyTarget, uint32_t* pswd, bool CryptMode) = 0; //with DataBlockReader
};

#endif // ABSTRACT_ENCRYPT_H_INCLUDED
