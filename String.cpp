// Colin Smith
// String Class Implementation File
// Modified May 2020

#include "String.h"

String::String()
{
    str = NULL;
    len = 0;
}

String::String(const String & toCopy) // copy constructor
{
    if(str)
    {
        delete[] str;
    }
    str = new char[toCopy.len + 1];
    strcpy(str, toCopy.str);
    len = toCopy.len;
}

String::~String() // destructor
{
    if(str)
    {
        delete[] str;
    }
    str = NULL;
    len = 0;
}

String::String(char * temp) // explicit constructor
{
    if(str)
    {
        delete[] str;
    }
    str = new char[strlen(temp) + 1];
    strcpy(str,temp);
    len = strlen(temp);
}

String & String::operator = (const String & s2)
{
    if (this == &s2)
    {
        return *this;
    }
    if(str)
    {
        delete[] str;
    }
    str = new char[s2.len + 1];
    strcpy(str, s2.str);
    len = s2.len;
    return *this;
}

String & String::operator = (const char * lit)
{
    if(str)
    {
        delete[] str;
    }
    str = new char[strlen(lit) + 1];
    strcpy(str, lit);
    len = strlen(lit);
    return *this;
}

ostream & operator << (ostream & out, const String & s2)
{
    out << s2.str;
    return out;
}

istream & operator >> (istream & in, String & s2)
{
    int size = 100;
    char temp[size];
    in >> temp;
    s2.len = strlen(temp);
    s2.str = new char[s2.len + 1];
    strcpy(s2.str, temp);
    return in;
}

String operator + (const String & s, const char * lit)
{
    char * temp = new char[s.len + strlen(lit) + 1];
    strcpy(temp, s.str);
    strcat(temp, lit);
    return String(temp);
}

String operator + (const char * lit, const String & s)
{
    char * temp = new char[s.len + strlen(lit) + 1];
    strcpy(temp, lit);
    strcat(temp, s.str);
    return String(temp);
}

String operator + (const String & s, const String & s2)
{
    char * temp = new char[s.len + s2.len];
    strcpy(temp, s.str);
    strcat(temp, s2.str);
    return String(temp);
}

String & String::operator += (const String & s2)
{
    char * temp;
    if(!str)
    {
        temp = new char[s2.len + 1];
        strcpy(temp, s2.str);
    }
    else
    {
        len += s2.len;
        temp = new char[len + 1];
        strcpy(temp, str);
        strcat(temp, s2.str);
        delete[] str;
    }
    str = temp;
    return *this;
}

String & String::operator += (const char * lit)
{
    char * temp;
    if(!str)
    {
        temp = new char[strlen(lit) + 1];
        strcpy(temp, lit);
    }
    else
    {
        len += strlen(lit);
        temp = new char[len + 1];
        strcpy(temp, str);
        strcat(temp, lit);
        delete[] str;
    }
    str = temp;
    return *this;
}

bool operator == (const String & s, const char * lit)
{
    return (strcmp(lit, s.str) == 0); 
}

bool operator == (const char * lit, const String & s)
{
    return (strcmp(s.str, lit) == 0);
}

bool operator == (const String & s, const String & s2)
{
    return (strcmp(s2.str, s.str) == 0);
}

bool operator != (const String & s, const char * lit)
{
    return (strcmp(lit, s.str) != 0);
}

bool operator != (const char * lit, const String & s)
{
    return (strcmp(s.str, lit) != 0);
}

bool operator != (const String & s, const String & s2)
{
    return (strcmp(s2.str, s.str) != 0);
}

bool operator < (const String & s, const char * lit)
{
    return (strcmp(s.str, lit) < 0);
}

bool operator < (const char * lit, const String & s)
{
    return (strcmp(lit, s.str) < 0);
}

bool operator < (const String & s, const String & s2)
{
    return (strcmp(s.str, s2.str) < 0);
}

bool operator <= (const String & s, const char * lit)
{
    return (strcmp(s.str, lit) <= 0);
}

bool operator <= (const char * lit, const String & s)
{
    return (strcmp(lit, s.str) <= 0);
}

bool operator <= (const String & s, const String & s2)
{
    return (strcmp(s.str, s2.str) <= 0);
}

bool operator > (const String & s, const char * lit)
{
    return (strcmp(s.str, lit) > 0);
}

bool operator > (const char * lit, const String & s)
{
    return (strcmp(lit, s.str) > 0);
}

bool operator > (const String & s, const String & s2)
{
    return (strcmp(s.str, s2.str) > 0);
}

bool operator >= (const String & s, const char * lit)
{
    return (strcmp(s.str, lit) >= 0);
}

bool operator >= (const char * lit, const String & s)
{
    return (strcmp(lit, s.str) >= 0);
}

bool operator >= (const String & s, const String & s2)
{
    return (strcmp(s.str, s2.str) >= 0);
}
