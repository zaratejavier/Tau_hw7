//
// Created by Javier Zarate on 11/12/17.
//
#include <memory>
#include "MyString.h"

/*!
 * Default constructor. Creates an object with an empty string
 */
MyString::MyString()
{}

/*!
 * Constructor with one parameter
 * count characters in cstring
 * allocate characters in ptr
 * copy string character by character
 * @param cString: characters that are in Cstring
 */
MyString::MyString(const char *cString)
{

    int counter=1, i=0;
    while(cString[i++] != (char)NULL)
    {
        counter++;
    }
    internalCString = std::make_unique<char[]>(counter);

    nlength = counter-1;

    for (i= 0; i<counter; i++)
    {
        internalCString[i] = cString[i];
    }
}
/*!
 * @return the internalCString
 */
char *MyString::getInternalCString() const
{
    return internalCString.get();
}

/*!
 * Compare each test and get the the number that it is supposed to be equal to.
 * @param lhs: the left hand side character
 * @param rhs: the right hand side characters
 * @return: the result from comparing them.
 */
int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    int result = 0;
    if (lhs.getNlength() != rhs.getNlength())
    {
        result += lhs.getNlength() - rhs.getNlength();
    }
    else
    {
        int counter = lhs.getNlength();

        for (int i = 0; i < counter; i++)
        {
            result += (int) rhs.internalCString[i] - (int) lhs.getInternalCString()[i];
        }
    }
    return result;
}
/*!
 * @return: the length of the characters
 */
int MyString::getNlength() const
{
    return nlength;
}
/*!
 * reverses the the characters so that it reads backwards.
 * it converts "Hellow123" to "321olleH"
 */
void MyString::reverseit()
{
    int counter=0, i=0, j=0;
    while(internalCString[i++] != (char)NULL)
    {
        counter++;
    }
    char temp[counter];
    for( i = counter-1, j = 0; i >= 0; i--, j++)
    {
        temp[j] = internalCString[i];
    }
    for( i= 0; i<=counter; i++)
    {
        internalCString[i] = temp[i];
    }
}

/*!
 * prints out hello123
 * @param os: output stream
 * @param myString:is the characters which is "Hello123"
 * @return: the ostream and  mystring.getInternalCString
 */
ostream &operator<<(ostream &os, const MyString &myString)
{
    return os << myString.getInternalCString();
}
