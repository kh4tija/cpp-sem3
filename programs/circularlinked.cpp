#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* n = new Node();
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
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
