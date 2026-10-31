#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* merge(Node* a, Node* b) {
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* a = new Node{10, new Node{30, new Node{50, NULL}}};

    Node* b = new Node{20, new Node{40, new Node{60, NULL}}};

    Node* result = merge(a, b);

    cout << "Merged List: ";
    display(result);

    return 0;
}
