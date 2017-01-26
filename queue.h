#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
class Customer {

private:
    long arrive;
    int processtime;
public:

    Customer() {arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}

};

typedef Customer Item;

struct Node {
    Item item;
    struct Node *next;
};


class Queue {

enum {Q_SIZE = 10};

public:
    Queue (int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item &item);


private:
    struct Node {
    Item item;
    struct Node * next;
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;

    Queue(const Queue &q) : qsize(0){}
    Queue & operator=(const Queue & q) {return *this;}


};


#endif // QUEUE_H_INCLUDED
