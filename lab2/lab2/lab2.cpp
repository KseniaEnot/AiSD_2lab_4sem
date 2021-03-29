#include <iostream>
#include "HuffmanAlg.h"

int main()
{
    char str[] = { 'H','e','l','l','o',' ','W','o','r','l','d','!','\n' };
    HuffmanAlg ForCode(str);
    int size;
    int sizeC;
    bool* code = ForCode.Code(size);
    char* decode = ForCode.Decode(sizeC);
    for (size_t i = 0; i < size; i++)
    {
        cout << code[i];
    }
    cout << endl;
    for (size_t i = 0; i < sizeC; i++)
    {
        cout << decode[i];
    }
}

