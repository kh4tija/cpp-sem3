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

void middle() {
    Node *slow = head, *fast = head;

    if (head == NULL)
        return;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle node: " << slow->data;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    middle();

    return 0;
}
