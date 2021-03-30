#include <iostream>
#include "HuffmanAlg.h"

int main()
{

    int sizeInStr = 500;
    char* str = new char[sizeInStr];
    int size;
    size = 0;
    char c;
    do
    {
        cin >> noskipws >> c;
        str[size] = c;
        size++;
    } while ((c!='.')&&((size+1) < sizeInStr));
    str[size] = '\n';
    cout << "Initial memory size : " << sizeof(char) * size << endl;
    HuffmanAlg ForCode(str);
    int sizeC;
    bool* code = ForCode.Code(size);
    char* decode = ForCode.Decode(sizeC);
    for (size_t i = 0; i < size; i++)
    {
        cout << code[i];
    }
    cout << endl;
    cout << "After compression : " << sizeof(bool) * size << endl;
    for (size_t i = 0; i < sizeC; i++)
    {
        cout << decode[i];
    }
}

