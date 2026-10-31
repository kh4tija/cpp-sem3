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

Node* kthLast(int k) {
    Node *first = head, *second = head;

    for (int i = 0; i < k; i++) {
        if (first == NULL)
            return NULL;

        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    int k = 2;

    Node* result = kthLast(k);

    if (result != NULL)
        cout << "Kth last node: " << result->data;
    else
        cout << "Invalid K";

    return 0;
}
