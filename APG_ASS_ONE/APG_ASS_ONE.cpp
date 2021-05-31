#include <iostream>

#include <string.h>

#include <stdlib.h>

#include "Book.cpp"

using namespace std;

//Check Number Before Entering

double check_number(string str)
{

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return -1;

    stringstream geek(str);
    double num;

    geek >> num;

    return num;
}

int main()
{
}
