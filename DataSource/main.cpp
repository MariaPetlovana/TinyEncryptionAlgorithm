#define MaxArraySize 256

#include "DataSource.h"
#include "DataBlockReader.h"
#include "FileSource.h"
#include "ConsoleSource.h"
#include "MemorySource.h"

#include "DataTarget.h"
#include "FileTarget.h"
#include "MemoryTarget.h"
#include "Abstract_Encrypt.h"
#include "Encrypt.h"

#include "DataBlockReader.h"

using namespace std;

int main()
{
    char FileToEncode[MaxArraySize], FileToResult[MaxArraySize], FileToDecode[MaxArraySize];
    uint32_t MyKey[4];

    cout<<"Enter the name of input file to encode:"<<endl;
    cin>>FileToEncode;

    cout<<"Enter the name of output file for result of encode:"<<endl;
    cin>>FileToResult;

    cout<<"Enter the name of input file to decode:"<<endl;
    cin>>FileToDecode;

    cout<<"Enter the key to encode(should be 4 numbers):"<<endl;
    for(int i=0; i<4; i++)
    cin>>MyKey[i];


    FileSource* MySource=new FileSource(FileToEncode);
    FileTarget* MyTarget=new FileTarget(FileToResult);

    /*
    uint32_t mas[2]={825373492, 825373492};
    uint32_t result[20];

    MemorySource<uint32_t>* MySource = new MemorySource<uint32_t>(mas);
    FileTarget* MyTarget=new FileTarget(FileToResult);
    */
    Encrypt MyEncrypt;

    MyEncrypt.engine1(MySource, MyTarget, MyKey, 0);
    delete MySource;
    delete MyTarget;

    FileSource* MySource1=new FileSource(FileToResult);
    FileTarget* MyTarget1=new FileTarget(FileToDecode);

    Encrypt MyEncrypt1;

    MyEncrypt1.engine1(MySource1, MyTarget1, MyKey, 1);
    delete MySource1;
    delete MyTarget1;

    return 0;
}
