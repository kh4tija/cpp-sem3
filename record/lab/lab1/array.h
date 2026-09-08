#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <ostream>

template <class T>
class Array {
    int lb,ub;
    T a[100];

    public:
    array();
    void setLB(int x);
    void setUB(int x);
    void create(); 
    void insert_at_end(T key);
    void insert_at_begining(T key);
    void insert_at_position(int , T key);
    void delete_at_end();
    void delete_at_begining();
    void delete_at_position(int);
    template <class U>friend ostream& operator<<(ostream& , Array<U>&);

};