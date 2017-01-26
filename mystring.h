
#include <iostream>
#include <cstring>
#include <cctype>



using namespace std;

class mystring {



public:

  static const int CINLIM = 80;


    mystring(const char *s);
    mystring();
    mystring(const mystring &);
    ~mystring();
    int length () const {return len;}

    mystring &operator=(const mystring &);
    mystring &operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;

    mystring & stringlow(void);
    mystring & stringup(void);


    friend bool operator <(const mystring &st, const mystring &st2);
    friend bool operator >(const mystring &st1, const mystring &st2);
    friend bool operator ==(const mystring &st1, const mystring &st2);

    friend mystring operator+(const mystring &st1, const mystring &st2);
    friend ostream & operator <<(ostream &os, const mystring &st);
    friend istream & operator >>(istream &is, mystring &st);
    static int HowMany();

     int HowMuch(char ch);

private:
    char * str;
    int len;
    static int num_strings;


};




