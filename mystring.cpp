
#include "mystring.h"

using namespace std;


int mystring::num_strings = 0;

int mystring::HowMany(){
    return num_strings;
}

mystring::mystring(const char *s){
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    num_strings++;

}

mystring::mystring(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
mystring::mystring(const mystring & st){
    num_strings++;
    len = st.len;
    str = new char [len+1];
    std::strcpy(str, st.str);
}
mystring::~mystring(){
    --num_strings;
    delete [] str;
}
mystring & mystring::operator=(const mystring &st){
    if(this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

mystring & mystring::operator=(const char *s){
     delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & mystring::operator[](int i){

    return str[i];
}
const char & mystring::operator[](int i)const{

    return str[i];
}
bool operator <(const mystring &st1, const mystring &st2){
    return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator >(const mystring &st1, const mystring &st2){
    return st2.str < st1.str;
}
bool operator ==(const mystring &st1, const mystring &st2){
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream &os, const mystring &st){
    os << st.str;
    return os;
}
istream & operator>>(istream &is, mystring &st){

    char temp[mystring::CINLIM];
    is.get(temp, mystring::CINLIM);
    if(is)
        st= temp;
        while(is && is.get() != '\n')
            continue;
        return is;
}


mystring operator+(const mystring &st1, const mystring &st2){

    int len = (st1.len + st2.len);
    char *str = new char[len + 1];
    std::strcpy(str, st1.str);
    std::strcat(str, " ");
    std::strcat(str, st2.str);
    mystring my_str(str);
    delete str;
    return my_str;
}

mystring & mystring::stringlow(void){
    int i;
    for(i = 0; i < this->len; i++){
        str[i] =  std::tolower(this->str[i]);
    }
    return *this;

}
mystring & mystring::stringup(void){
    int i;
    for(i = 0; i < this->len; i++){
        str[i] =  std::toupper(this->str[i]);
    }

    return *this;
}

 int mystring::HowMuch(char ch){
    int i;
    int counter = 0;
    for(i = 0; i < this->len; i++){
        if(str[i] == ch)
            counter++;
    }
    return counter;
}

