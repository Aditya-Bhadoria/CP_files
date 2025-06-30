#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* next;
    Node* prev;
    //constructor
    Node (int data){
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }
    //destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        if(prev != NULL){
            delete prev;
            prev = NULL;
        }
        cout << "Memory free of node with data " << val << '\n';
    }
}; 

void insertAtHead(Node* &tail, Node* &head, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp; tail = temp;
    }
    else{
        temp->next = head; head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node* &tail, Node* &head, int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp; head = temp;
    }
    else{
        tail->next = temp; temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position == 1){ insertAtHead(tail, head, d); return;} // updates head
    Node* temp = head;
    Node* nodeToInsert = new Node(d);
    for(int i=0; i<position-2; i++){
        temp = temp->next;
    }

    if(temp->next == NULL){ insertAtTail(tail, head, d); return; } // updates tail
    nodeToInsert -> next = temp -> next; temp->next->prev = nodeToInsert;
    temp -> next = nodeToInsert; nodeToInsert->prev = temp;
}
void deleteNode(Node* &tail, Node* &head, int position){
    if(position == 1){ 
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next; temp->next = NULL;
        delete temp; return; 
    }
    Node* curr = head;
    Node* prev = NULL;
    for(int i=1; i<position; i++){
        prev = curr; 
        curr = curr->next;
    }
    if(curr->next == NULL){
        tail->prev = NULL;
        tail = prev;
        tail->next = NULL; delete curr;
        return;
    }
    prev->next = curr->next; curr->next->prev = prev;
    curr->next = NULL; curr->prev = NULL; delete curr; 
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << '\n';
}
int getLen(Node* head){ //gives length of linked list
    int ans = 0;
    Node* temp = head;
    while(temp != NULL){
        ans++;
        temp = temp->next;
    }
    return ans;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    Node* node1 = new Node(8);
    Node* head = NULL;
    Node* tail = NULL; print(head);
    // cout << getLen(head) << '\n';
    insertAtHead(tail, head, 11); print(head);
    insertAtHead(tail, head, 13); print(head);
    insertAtHead(tail, head, 8); print(head);
    insertAtTail(tail, head, 25); print(head);
    insertAtPosition(tail, head, 2, 100); print(head);
    insertAtPosition(tail, head, 1, 101); print(head);
    insertAtPosition(tail, head, 7, 102); print(head);
    deleteNode(tail, head, 1); print(head);
    deleteNode(tail, head, 6); print(head);
    // cout << head->data << ' ' << tail->data << '\n';
    return 0;
}