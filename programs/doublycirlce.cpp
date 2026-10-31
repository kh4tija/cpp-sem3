#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insert(int x) {
    Node* n = new Node();
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = n;
        n->prev = n;
    }
    else {
        Node* last = head->prev;

        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
    }
}

void display() {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    return 0;
}
