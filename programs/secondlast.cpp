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
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }
}

void secondLast() {
    if (head == NULL || head->next == NULL) {
        cout << "Not possible";
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    cout << "Second last node: " << temp->data;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    secondLast();

    return 0;
}
