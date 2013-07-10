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
    char FileToDEncode[MaxArraySize], FileToResult[MaxArraySize], FileToDecode[MaxArraySize];
    uint32_t MyKey[4];

    char choose;
    string str;
    bool mode=0, indicator=0;

    cout<<"Enter the mode: e(to encrypt) or d(to decrypt)"<<endl;
    cin>>str;
    while(str.length()!=1 && (str[0]!='d' || str[0]!='e'))
    {
        cout<<"You can type only e or d"<<endl;
        cin>>str;
    }
    choose=str[0];

    //do{
        switch (choose)
        {
        case 'e' :

            cout<<"Enter the name of input file to encode:"<<endl;
            cin>>FileToDEncode;

            cout<<"Enter the name of output file for result of encode:"<<endl;
            cin>>FileToResult;

            mode=0;
            indicator=1;

            break;

        case 'd' :

            cout<<"Enter the name of input file to decode:"<<endl;
            cin>>FileToDEncode;

            cout<<"Enter the name of output file for result of decode:"<<endl;
            cin>>FileToResult;

            mode=1;
            indicator=1;

            break;
        default:

            cout<<"You can type only e or d"<<endl;
            indicator=0;
            //cin>>choose;

            break;
        }
        //cin>>choose;
    //}while(!indicator);

    cout<<"Enter the key to encode(should be 4 numbers):"<<endl;
    for(int i=0; i<4; i++)
    cin>>MyKey[i];


    FileSource* MySource=new FileSource(FileToDEncode);
    FileTarget* MyTarget=new FileTarget(FileToResult);

    Encrypt MyEncrypt;

    MyEncrypt.engine1(MySource, MyTarget, MyKey, mode);
    delete MySource;
    delete MyTarget;

    return 0;
}
