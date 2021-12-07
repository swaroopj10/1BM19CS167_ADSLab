#include <bits/stdc++.h>

using namespace std;

class Node {
    public : int data;
    Node* next;
};

Node* Xor(Node* x, Node* y) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;

    new_node->next = *head_ref;

    if(*head_ref != NULL) {
        (*head_ref)->next = Xor(new_node, (*head_ref)->next);
    }
    *head_ref = new_node;
}

void printList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt;

    cout<<"The nodes of Linked List are: \n";

    while(curr != NULL) {
        cout<<curr->data<<" ";
        nxt = Xor(prev, curr->next);
        prev = curr;
        curr = nxt;
    }
    cout<<"\n";
}

void deleteElement(Node** head_ref) {
    if(*head_ref == NULL)
        cout<<"The Linked List is empty\n";
    else {
        Node* curr = *head_ref;
        Node* prev = NULL;
        Node* nxt;

        while(Xor(curr->next, prev) != NULL) {
            nxt = Xor(prev, curr->next);
            prev = curr;
            curr = nxt;
        }

        if(prev != NULL)
            prev->next = Xor(Xor(prev->next, curr), NULL);
        else
            *head_ref = NULL;

        delete curr;
        cout<<"Element is successfully deleted\n";
    }
}

int main() {
    Node* head = NULL;
    int ch, value;
    cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\n";
    do {
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch) {
        case 1:
            cout<<"Enter the element to be inserted\n";
            cin>>value;
            insert(&head, value);
            break;
        case 2:
            deleteElement(&head);
            break;
        case 3:
            printList(head);
            break;
        default:
            cout<<"Enter a valid choice\n";
            break;
        }
    }while(ch != 4);
    return 0;
}