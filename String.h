// Colin Smith
// String Class Header File
// Modified May 2020

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstring>

using namespace std;

class String
{
    public:
        String(); // constructor
        String(const String &); // copy constructor
        ~String(); // destructor

        String & operator = (const String &); // assignment operator
        String & operator = (const char *);

        friend ostream & operator << (ostream &, const String &);
        friend istream & operator >> (istream &, String &);

        friend String operator + (const String &, const char *);
        friend String operator + (const char *, const String &);
        friend String operator + (const String &, const String &);

        String & operator += (const String &);
        String & operator += (const char *);

        friend bool operator == (const String &, const char *);
        friend bool operator == (const char *, const String &);
        friend bool operator == (const String &, const String &);

        friend bool operator != (const String &, const char *);
        friend bool operator != (const char *, const String &);
        friend bool operator != (const String &, const String &);
        
        friend bool operator < (const String &, const char *);
        friend bool operator < (const char *, const String &);
        friend bool operator < (const String &, const String &);

        friend bool operator <= (const String &, const char *);
        friend bool operator <= (const char *, const String &);
        friend bool operator <= (const String &, const String &);

        friend bool operator > (const String &, const char *);
        friend bool operator > (const char *, const String &);
        friend bool operator > (const String &, const String &);

        friend bool operator >= (const String &, const char *);
        friend bool operator >= (const char *, const String &);
        friend bool operator >= (const String &, const String &);

        // char & operator [] (int) const;

    private:
        explicit String(char *);
        char * str;
        int len;
};
