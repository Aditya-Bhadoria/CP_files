#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* next;
    //constructor
    Node (int data){
        this-> data = data;
        this-> next = NULL;
    }
    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
}; 

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position == 1){ insertAtHead(head, d); return;} // updates head
    Node* temp = head;
    Node* nodeToInsert = new Node(d);
    for(int i=0; i<position-2; i++){
        temp = temp->next;
    }

    if(temp->next == NULL){ insertAtTail(tail, d); return; } // updates tail
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
void deleteNode(Node* &tail, Node* &head, int position){
    if(position == 1){ 
        Node* temp = head;
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
        tail = prev;
        tail->next = NULL; delete curr;
        return;
    }
    prev->next = curr->next;
    curr->next = NULL; delete curr; 
}

bool detectLoop(Node* head){
    if(head == NULL)
    return false;

    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            cout << "Loop found.";
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    cout << "Loop not found.";
    return false;
}

bool floydCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            cout << "Found.";
            return true;
        }
    }
    cout << "Not found.";
    return false;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    Node* head = new Node(4);
    Node* tail = head;
    
    print(head);
    // insertAtHead(head, 10);
    // print(head);
    // insertAtHead(head, 11);
    // print(head);
    // insertAtHead(head, 12);
    // print(head);
    insertAtTail(tail, 2); print(head);
    insertAtTail(tail, 3); print(head);
    insertAtPosition(tail,head, 4, 22);
    print(head);
    //tail->next = head->next;
    bool ok = floydCycle(head);
    // cout << tail->data;
    //deleteNode(tail, head, 4); print(head);
    //cout << tail->data;
    return 0;
}