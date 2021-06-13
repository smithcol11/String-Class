# String-Class
For my Data Strucures course at Portland State University, we were not allowed to use 'string', and instead had to use cstrings. So, I wrote my own string class that would have similar functionality to the the traditionally imported string using operator overloading. 

## Code Snippets
> This is the .h file
```c++
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
```
