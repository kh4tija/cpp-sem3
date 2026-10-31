#include <iostream>
using namespace std;

template <class T>
class Array {
    T a[100];
    int n;

public:
    Array() {
        n = 0;
    }

    void insert(T x) {
        a[n] = x;
        n++;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }

    void search(T x) {
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                cout << "Found";
                return;
            }
        }
        cout << "Not Found";
    }

    void deleteElement(T x) {
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                for (int j = i; j < n - 1; j++)
                    a[j] = a[j + 1];
                n--;
                cout << "Deleted";
                return;
            }
        }
        cout << "Not Found";
    }
};

int main() {
    Array<int> obj;
    int ch, x;

    do {
        cout << "\n1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                obj.insert(x);
                break;

            case 2:
                obj.display();
                break;

            case 3:
                cin >> x;
                obj.search(x);
                break;

            case 4:
                cin >> x;
                obj.deleteElement(x);
                break;
        }
    } while (ch != 5);

    return 0;
}
