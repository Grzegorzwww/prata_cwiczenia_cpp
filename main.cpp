#include <iostream>
#include <ctime>
#include <cstdlib>
#include "complex0.h" 		// to avoid confusion with complex.h
#include "mystring.h"
#include "queue.h"
#include "valarray"
#include "string"

using namespace std;



template <class T1, class T2>

class Pair
{
    private:
    T1 a;
    T2 b;
    public:

    void addFirst(const  T1 &aval) { a = aval;}
    void addSecond(const  T2 &bval) { b = bval;}
    T1 & first();
    T2 & second();
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 & aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;



class Wine: private std::string, private PairArray
{
    private:
    enum {MAX_BOTTLE = 5};
    //char  *nazwa;
   // PairArray dane[5];
    int liczba_rocznikow;


    public:

    Wine();
    Wine(const char *l, int y,const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottels();
   // char & Label() const {return *nazwa;}
    int sum() ;
    void show();

};



Wine::Wine() : liczba_rocznikow(1), std::string("brak nazwy"), PairArray()
{

}

Wine::Wine(const char *l, int y,const int yr[], const int bot[]) : liczba_rocznikow(y),  std::string(l), PairArray(ArrayInt(yr,y), ArrayInt(bot, y))
{

}

Wine::Wine(const char *l, int y) : std::string(l), liczba_rocznikow(y), PairArray(ArrayInt(0,y), ArrayInt(0, y))
{


}
void Wine::GetBottels(){
    int bottels_counter = 0;
    int temp_val = 0;;
    while(bottels_counter < liczba_rocznikow){
        cout << "Wino: "<< (const string &) *this <<",  prosze podac rocznik: ";
        cin >> temp_val;

       PairArray::first()[bottels_counter ] = temp_val;

        cout << "Wino: "<< (const string &) *this<<",  prosze podac ilosc butelek: ";
        cin >> temp_val;
        PairArray::second()[bottels_counter ]  = temp_val;

        bottels_counter++;
        }
}

void Wine::show(){

    for(int i = 0; i < liczba_rocznikow; i++){
        cout << "Wino: "<< (const string &) *this <<": ";
        cout << ", rocznik  - " << PairArray::first()[i];
        cout << ", ilosc - " << PairArray::second()[i]<<endl;

    }

}





int main()
{

    cout <<"Podaj nazwe wina: ";
    char lab[50];
    cin.getline(lab, 50);

    cout <<"Podaj liczbe rocznikow: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);

    holding.GetBottels();
    holding.show();
}


/*






typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;



class Wine
{
    private:
    enum {MAX_BOTTLE = 5};
    char  *nazwa;
    PairArray dane[5];
    int liczba_rocznikow;


    public:

    Wine();
    Wine(const char *l, int y,const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottels();
    char & Label() const {return *nazwa;}
    int sum() ;

};


Wine::Wine() : liczba_rocznikow(1)
{
    nazwa = new char[sizeof("brak nazwy")+1];
    strcpy(nazwa, "brak nazwy");
    int i;
    for(i = 0; i < MAX_BOTTLE; i++)
    {
        dane[i].first() = 0;
        dane[i].second() = 0;
    }
}
Wine::Wine(const char *l, int y,const int yr[], const int bot[]) : liczba_rocznikow(y)
{
    nazwa = new char[sizeof(l)+1];
    strcpy(nazwa, l);

    int i;
    for(i = 0; i < y; i++)
    {
        dane[i].first() = yr[i];
        dane[i].second() = bot[i];
    }

}
Wine::Wine(const char *l, int y) : liczba_rocznikow(y)
{
    nazwa = new char[sizeof(l)+1];
    strcpy(nazwa, l);
    int i;
    for(i = 0; i < MAX_BOTTLE; i++)
    {
        dane[i].first() = 0;
        dane[i].second() = 0;
    }

}

void Wine::GetBottels(){
    int bottels_counter = 0;
    int temp_val = 0;;
    while(bottels_counter < liczba_rocznikow){
        cout << "Wino: "<< nazwa<<",  prosze podac rocznik: ";
        cin >> temp_val;
        dane[bottels_counter].first() = temp_val;

        cout << "Wino: "<< nazwa<<",  prosze podac ilosc butelek: ";
        cin >> temp_val;
        dane[bottels_counter].second() = temp_val;

        bottels_counter++;
        }
}

int Wine::sum()  {
    return 1;
}



int main()
{

    cout <<"Podaj nazwe wina: ";
    char lab[50];
    cin.getline(lab, 50);

    cout <<"Podaj liczbe rocznikow: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);

    holding.GetBottels();






    return 0;
}





/*

template <typename T>
class ManyFriend
{
private:
    T item;
public:
    ManyFriend(const T & i) : item(i) {}
    template <typename C, typename D> friend void show2(C &, D&);
};

template <typename C, typename D> void show2(C & c, D & d)
{
    cout << c.item << ", "<<d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout <<"hfi1, hfi2: ";
    show2(hfi1, hfi2);
    cout <<"hfdb, dfi2: ";
    show2(hfdb, hfi2);

    return 0;
}


*/

/*
template <typename T>
class HasFriend
{
    private:
    T item;
    static int ct;
    public:
    HasFriend(const T & i) : item(i) {ct++;}
    ~HasFriend() {ct--;}
    friend void counts();
    friend void reports(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

void counts()
{
    cout <<"Konkretzacja int: "<< HasFriend<int>::ct <<"; ";
    cout <<"Konkretyzacja double: " << HasFriend<double>::ct <<endl;
}
void reports(HasFriend<int> & hf)
{
    cout <<"HasFriend<int>: "<<hf.item << endl;
}
void reports(HasFriend<double> & hf)
{
    cout <<"HasFirnd<double>: "<<hf.item << endl;
}

int main(){

    cout << "Brak zadeklarowanych obiektow: ";
    counts();
    HasFriend<int> hfi1(10);
    cout <<"Po deklaracji hfi1: ";
    counts();
    HasFriend<int> hfi2(20);
    counts();
    cout <<"Po deklaracji hfi2: ";
    HasFriend<double> hfdb(10.5);
    cout <<"Po deklaracji hfdb: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}
*/

/****************************************************/

/*
template <typename T>
class beta
{
private:
    template <typename V>
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const
        {
            cout << val << endl;
        }
        V Value() const
        {
            return val;
        }
    };
    hold<T> q;
    hold<int >n;
public :

    beta(T t, int i) : q(t), n(i) {}
    template <typename U>
    U blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }
    void Show() const
    {
        q.show();
        n.show();
    }
};

int main()
{
    beta <double> guy(3.5, 3);
    guy.Show();
    cout << guy.blab(10, 2.3) << endl;
    cout << "Koniec\n";


    return 0;
}


*/


/****************************************************/

/*
template <class T1, class T2>
class Pair
{
    private:
    T1 a;
    T2 b;
    public:
    T1 & first();
    T2 & second();
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 & aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}

};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}


int main()
{
    Pair<string, int> ratings[4] = {
    Pair<string, int> ("Pod czerwonym baronem", 5),
    Pair<string, int> ("Szybko i tanio", 4),
    Pair<string, int> ("Suflety Magdy", 5),
    Pair<string, int> ("U Gerda", 3),
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);
    cout <<"Ocena: \t Restaturacja:\n";
    for(int i = 0;i < joints; i++)
    cout << ratings[i].second() << ":\t"
    << ratings[i].first() << endl;
    cout << "Uwaga ! Zmiana oceny:\n";
    ratings[3].first() = "U Gerda";
    ratings[3].second() = 6;

    cout << ratings[3].second() << ":\t"
    << ratings[3].first() << endl;


return 0;
}

*/
/****************************************************/
/*
template <class T, int n>
class ArrayTP
{
private:
    T ar[n];
public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T  operator[](int i) const;
};



int main(void )
{


    ArrayTP <int, 10> sums;
    ArrayTP <double, 10> aves;
    ArrayTP <ArrayTP<int, 5>, 10 > twodee;


    int i, j;

    for(i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for(j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double) sums[i] / 5;
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout <<": sum = ";
        cout.width(3);
        cout << sums[i] << ", średnia = " << aves[i] << endl;
    }
    cout << "Koniec";


    return 0;
}





template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
    for(int i = 0; i < n;i++){
        ar[i] = v;
    }
}

template <class T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
    if(i < 0 || i >= n)
    {
        cerr << "Blad zakresu tablicy: " << i <<" jet poza zakresem\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T  ArrayTP<T, n>::operator[](int i) const
{
    if(i < 0 || i >= n){
        cerr << "Blad zakresu tablicy: "<< i << " jest poza zakresem\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}


*/


/****************************************************/
/*
template  <class Type>

class Stack
{
private:

    int stacksize;
    Type *items;
    int top;

public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack & st);
    ~Stack() {  delete [] items; }
    bool isempty(){  return top == 0; }
    bool isfull() {return top == stacksize; }
    bool push(const Type & item);
    bool pop(Type & item);

    Stack & operator=(const Stack &st);


};


template <class Type>
Stack<Type>::Stack(int ss): stacksize(ss), top(0)
{
    items = new Type[stacksize];
}
template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];

}


template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top < stacksize)
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }

}
template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if(this = &st)
        return *this;

    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.itemsp[i];
    return *this;



}
const int Num = 10;

int main()
{
   srand(time(0));
   cout <<"Podaj romiar stosu: ";
   int stacksize;
   cin>>stacksize;

   Stack<const char *> st(stacksize);

   const char * in[Num] = {
    " 1: Henryk Gilgamesz", " 2. Kinga Isztar",
    " 3: Beata Roker", " 4: Jan Flagranti",
    " 5: Wolfgang Mocny", " 6: Patrycja Kup",
    " 7: Jacek Almond", " 8: Ksawery Papryka ",
    " 9: Julian Mor", " 10: marian Macher"
   };

   const char * out[Num];

   int processed = 0;
   int nextin = 0;


   while(processed < Num)
   {
    if(st.isempty())
        st.push(in[nextin++]);
    else if(st.isfull())
        st.pop(out[processed++]);
    else if((rand() % 2) && (nextin < Num))
        st.push(in[nextin++]);
    else
        st.pop(out[processed++]);
   }

   for(int i = 0; i < Num; i++){
        cout << out[i] <<endl;
   }
   cout << "Koniec\n";

    return 0;
}












*/






/****************************************************/

/*
class Worker
{
private:
    string fullname;
    long id;
    protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname("brak"), id(0L) {}
    Worker(const string & s, long n) :fullname(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set();
    virtual void Show() const = 0;



};


class Waiter : virtual public Worker
{
private:
    int panache;
    protected:
    virtual void Data() const;
    virtual void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;



};

class Singer : virtual public Worker
{
protected:
    enum {inny, alt, kontalt, sopran, bas, baryon, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char *pv[Vtypes];
    int voice;
public :
    Singer(): Worker(), voice(inny) {}
    Singer(const string & s, long n, int v = inny) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = inny) : Worker(wk), voice(v) {}
    void Set();
    void Show() const ;

};

class SingingWaiter : public Singer, public Waiter
{
    protected:
    void Data( ) const;
    void Get();
    public:
    SingingWaiter() {}
    SingingWaiter(const string &s, long n, int p = 0, int v = inny) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & kw, int p = 0, int v = inny) : Worker(kw), Waiter(kw, p), Singer(kw, v) {}
    SingingWaiter(const Waiter & wt, int v = inny) : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & wt, int p = 0) : Worker(wt), Waiter(wt), Singer(wt) {}
    void Set();
    void Show() const;


};

const int LIM = 4;
const int SIZE = 5;


int main()
{

    Worker * lolas[SIZE];
    int ct;
    for(ct = 0; ct < SIZE; ct++)
    {
    char choice;
    cout << "Podaj kategorie pracownika: \n"
        <<"k: kelner    p: piosenkarz "
        <<"s: śpiewajacy kelner     w: wyjscie\n";
        cin>> choice;
        while(strchr("kpsw", choice) == NULL)
        {
            cout << "Wpisz k, p, s lub w: ";
            cin >> choice;
        }
        if(choice == 'w')
            break;
        switch(choice)
        {
            case 'k' : lolas[ct] = new Waiter;
            break;
            case 'p' : lolas[ct] = new Singer;
            break;
            case 's' : lolas[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    cout << "\nLista pracownikow:\n";
    int i;
    for(i = 0; i < ct; i++)
    {
    cout << endl;
    lolas[i]->Show();

    }
    for(i = 0; i < ct; i++){
        delete lolas[i];
    }
    cout<< "Koniec\n";
    return 0;

}



Worker::~Worker() {}


void Worker::Data() const
{
    cout <<"Imie i naziwsko: "<<fullname<<"\n";
    cout <<"Numer identyfikacyjny: "<<id<<"\n";

}

void Worker::Get() {

    getline(cin, fullname);
    cout << "Podaj numer identyfikacyjny pracownika: ";
    cin >> id;
    while(cin.get() != '\n')
        continue;

}
void Worker::Set()
{
    cout << "Podaj imie i nazwisko pracownika: ";
    getline(cin, fullname);
    cout << "Podaj numer identyfikacyjny pracownika: ";
    cin >> id;
    while(cin.get() != '\n')
        continue;

}

void Worker::Show() const
{
    cout <<"Imie i naziwsko: "<<fullname<<"\n";
    cout <<"Numer identyfikacyjny: "<<id<<"\n";

}


void Waiter::Set()
{

    cout <<"Imie i nazwisko kelnera: ";
    Worker::Get();
    Get();


}
void Waiter::Show() const
{
    cout <<"Kategoria : kelner\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout<< "Elegancja: "<<panache << endl;
}

void Waiter::Get()
{
cout <<"Podaj poziom elegancji kolnera: ";
cin>>panache;
while(cin.get() != '\n')
    continue;
}


char * Singer::pv[Singer::Vtypes] = {"inny", "alt", "kontralt", "sopran", "bas", "baryton", "tenor"};

void Singer::Set()
{
    Worker::Set();
    cout << "Podaj imie i nazwisko piosenkarza: ";
    Worker::Get();
    Get();

}

void Singer::Show() const
{
    cout <<"Kategoria: piosenkarz\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Skala glosu: "<< pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Podaje numer dla sklali glosu piosenarza\n";
    int i;
    for(i = 0; i < Vtypes; i++)
    {
        cout << i <<": "<<pv[i] << "   ";
        if(i % 4 == 3){
            cout << endl;
        }
    }
    if(i % 4 != 0)
    cout << '\n';
    cin >> voice;
    while(cin.get() != '\n')
        continue;
}

void SingingWaiter ::Data() const
{
    Singer::Data();
    Waiter::Data();

}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}
void SingingWaiter::Set()
{
    cout <<" Podaj imie i naziwsko spiewajacego kelnera: ";
    Worker::Get();
    Get();
}
void SingingWaiter::Show() const
{
    cout << "Kategoria: spiewajacy kelner\n";
    Worker::Data();
    Data();
}





/****************************************************/
/*s Student
{

private:

    typedef std::valarray<double> ArrayDb;
    string name;
    ArrayDb scores;
    ostream & arr_out(ostream & os) const;

public:

    Student() : name ("brak"), scores() {}
    Student(const string &s) : name(s), scores() {}
    explicit Student(int n): name("Brak"), scores(n) {}
    Student(const string &s, int n) : name(s), scores(n) {}
    Student (const char * str, const double *pd, int n) : name(str), scores(pd, n) {}
    ~Student() {}
    double Average() const;
    const string & Name() const;
    double & operator[] (int i);
    double operator[] (int i) const;


    friend istream & operator>>(istream & is, Student & stu);
    friend istream & getline(istream & is, Student &stu);
    friend ostream & operator<<(ostream & os, const Student & stu);
};


double Student::Average() const
{
    if(scores.size() > 0){
        return (scores.sum() / scores.size());
    }
    else {
        return 0;
    }
}

const string & Student::Name() const
{
return name;
}

double & Student::operator[](int i)
{
    return scores[i];
}
double Student::operator[](int i) const
{
    return scores[i];
}

ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if(lim > 0)
    {
    for(i = 0; i < lim; i++){
        os << scores[i] << " ";
        if(i % 5 == 4){
            os << endl;
        }
    }
    if(i % 5 != 0)
        os <<endl;

    }
    else
        os << " tablica jest pusta ";
    return os;
}
istream & operator>>(istream & is, Student & stu){
    is >> stu.name;
    return is;
}
istream & getline(istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}
ostream & operator<<(ostream & os, const Student & stu){
    os << "Wyniki "<<stu.name <<":\n";
    stu.arr_out(os);
    return os;
}
void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main(){
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;



    for(i = 0; i < pupils; ++i) {
        set(ada[i], quizzes);
    }
    cout <<"Lista studentow: \n";
    for(i = 0; i < pupils; ++i){
        cout << ada[i].Name() << endl;
    }
    cout << "\nWykini:";
    for(i = 0; i < pupils; ++i){
        cout <<endl << ada[i];
        cout <<"srednia: " <<ada[i].Average() << endl;
    }
    cout <<"Gotowe";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Podaj imie i nazwisko studenta: ";
    getline(cin, sa);
    cout << "Podaj "<< n << "wynikow testow: \n";
    for(int i = 0; i < n; i++)
        cin >> sa[i];
    while(cin.get() != '\n')
        continue;
}


/*
class base
{

private :

protected:

    char *label;
    int rating;


public :
    virtual void View() const = 0;
    char *getLabel() const {return label;}
    int getRating() const {return rating;}
    base(const char *l = "brak", int r = 0);
    base(const base &rs);
    ~base();

};



class baseDMA : public base
{
private:

public:

    baseDMA(const char *l = "brak", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    virtual void View() const;
    baseDMA &operator=(const baseDMA &rs);
    friend ostream & operator<<(ostream  &os, const baseDMA &rs);


};

class lacksDMA : public base
{
private:

    enum {COL_LEN = 40};
    char color[COL_LEN];

public:

    lacksDMA(const char *c = "brak", const char * l = "brak", int r = 0);
    lacksDMA(const char *c, const base & rs);
    virtual void View() const;
    friend ostream & operator<<(ostream &os,  const lacksDMA &rs);

};

class hasDMA : public base
{
private:
    char *style;

public:
    hasDMA(const char *s = "brak", const char * l = "brak", int r = 0);
    hasDMA(const char *s, const base &rs);
    hasDMA(const hasDMA &rs);
    virtual ~hasDMA();
    virtual void View() const;
    hasDMA & operator=(const hasDMA & rs);
    friend ostream & operator<<(ostream &os, const hasDMA &rs);
};


int main()
{
    base *main_obj_ptr[6];

    baseDMA shirt("Portabelly", 8);
    baseDMA shirt2;
    shirt2 = shirt;

    lacksDMA ballon("czerwony", "Blimpo", 4);
    lacksDMA ballon2(ballon);


    hasDMA map("Merkator", "buffalo keys", 5);
    hasDMA map2 = map;

    main_obj_ptr[0] = &shirt;
    main_obj_ptr[1] = &shirt2;
    main_obj_ptr[2] = &ballon;
    main_obj_ptr[3] = &ballon2;
    main_obj_ptr[4] = &map;
    main_obj_ptr[5] = &map2;


    for(int i = 0; i < 6; i++){
        cout << "objekt = "<<i<<" -----------------"<<endl;
        main_obj_ptr[i]->View();
    }

    cout << shirt << endl;
    cout << shirt2 << endl;

    cout << ballon << endl;
    cout << ballon2 << endl;

    cout << map << endl;
    cout << map2 << endl;

    return 0;
}



base::base(const char *l, int r)
{
    label = new char[strlen(l)+1];
    strcpy(label, l);
    rating = r;
}

base::base(const base &rs)
{
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
}
 base::~base(){
 }

ostream & operator<<(ostream & os, const base & rs)
{
    os <<"Etykieta: "<<rs.getLabel() << endl;
    os <<"Klasa: "<<rs.getRating()<<endl;
    return os;
}

baseDMA::baseDMA(const char *l, int r) :base(l, r)
{

}

baseDMA::baseDMA(const baseDMA &rs)
{
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;

}

 void baseDMA::View() const {
    cout <<"Etykieta: "<<label << endl;
    cout <<"Klasa: "<<rating<<endl;
 }

ostream & operator<<(ostream & os, const baseDMA & rs)
{
    os <<"Etykieta: "<<rs.label << endl;
    os <<"Klasa: "<<rs.rating<<endl;
    return os;
}

lacksDMA::lacksDMA(const char * c, const char *l, int r) : base(l, r)
{
    strncpy(color, c, 39);
    color[39] = 2/02;
}
lacksDMA::lacksDMA(const char * c, const base & rs) : base(rs)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN -1 ] = 2/02;
}

ostream & operator<<(ostream & os, const lacksDMA & ls)
{
    os << (const base &) ls;
    os <<"Kolor: "<<ls.color << endl;
    return os;
}

 void lacksDMA::View() const {

    cout <<"Etykieta: "<<label << endl;
    cout <<"Klasa: "<<rating<<endl;
    cout <<"Kolor: "<< color << endl;
 }

hasDMA::hasDMA(const char *s, const char *l, int r) : base(l, r)
{
    style = new char[strlen(s)+1];
    strcpy(style,s);
}
hasDMA::hasDMA(const char *s, const base & rs) : base(rs)
{
    style = new char[strlen(s)+1];
    strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hs) : base(hs)
{
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if(this == & hs)
        return *this;
    base::operator=(hs);
    style = new char [strlen(hs.style)+1];
    strcpy(style, hs.style);
    return * this;
}
 void hasDMA::View() const {

    cout <<"Etykieta: "<<label << endl;
    cout <<"Klasa: "<<rating<<endl;
    cout <<"Styl: "<< style << endl;
 }

ostream & operator<<(ostream & os, const hasDMA & hs)
{
    os << (const base & ) hs;
    os << "Styl: "<< hs. style << endl;
    return os;
}
*/

