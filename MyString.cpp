//
// Created by Javier Zarate on 11/12/17.
//
#include <memory>
#include "MyString.h"


MyString::MyString()
{
    //unique_ptr<char[]> temp = new unique_ptr<char[]>();
    //internalCString = std::make_unique<char[]>(0);
}

MyString::MyString(const char *cString)
{
    //count chars in cString.
    int counter=1, i=0;
    while(cString[i++] != (char)NULL)
    {
        counter++;
    }
    internalCString = std::make_unique<char[]>(counter); //allocate that many chars in ptr.

    //copy string char by char.
    for (i= 0; i<counter; i++)
    {
        internalCString[i] = cString[i];
    }
}

char *MyString::getInternalCString() const
{
    return internalCString.get();
}
