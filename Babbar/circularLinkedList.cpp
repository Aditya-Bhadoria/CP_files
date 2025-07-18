#include<bits/stdc++.h>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node* curr = tail;
        while(curr->data != element) {
            curr = curr -> next;
        }
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}    

void print(Node* tail) {
    Node* temp = tail;
    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp); cout << '\n';
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = curr->next;
        }

        curr -> next = NULL;
        delete curr;

    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    Node* tail = NULL;

	insertNode(tail, 5, 3); print(tail);
	insertNode(tail, 3, 5); print(tail);
    insertNode(tail, 5, 7); print(tail);
    insertNode(tail, 7, 9); print(tail);
    insertNode(tail, 5, 6); print(tail);
	insertNode(tail, 3, 4); print(tail);
	deleteNode(tail, 3); print(tail);
	deleteNode(tail, 9); print(tail);
	// deleteNode(tail, 5); print(tail);
	// deleteNode(tail, 6); print(tail);
	// deleteNode(tail, 7); print(tail);
	// deleteNode(tail, 9); print(tail);
    return 0;
}