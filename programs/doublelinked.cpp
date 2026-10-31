#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();

    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverseDisplay() {
    Node* temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main() {
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }

    cout << "Forward: ";
    display();

    cout << "\nBackward: ";
    reverseDisplay();

    return 0;
}
