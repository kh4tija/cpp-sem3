#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T x) {
        data = x;
        next = NULL;
    }
};

template <class T>
class LinkedList {
    Node<T>* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(T x) {
        Node<T>* newNode = new Node<T>(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    void display() {
        Node<T>* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void search(T x) {
        Node<T>* temp = head;

        while (temp != NULL) {
            if (temp->data == x) {
                cout << "Found";
                return;
            }
            temp = temp->next;
        }

        cout << "Not Found";
    }
};

int main() {
    LinkedList<int> l;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        l.insert(x);
    }

    l.display();

    cout << "\nEnter search element: ";
    cin >> x;

    l.search(x);

    return 0;
}
