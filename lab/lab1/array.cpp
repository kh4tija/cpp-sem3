#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class T>
class array {
private:
    int lb, ub;
    T a[100]; // Adjust size as needed

public:
    array();
    void setLB(int x);
    void setUB(int x);
    int getLB();
    int getUB();
    void create();
    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_at_position(int p, T key);
    void delete_at_end();
    void delete_at_beginning();
    void delete_at_position(int p);

    template <class U>
    friend ostream& operator<<(ostream& os, const array<U>& m);
};

#endif