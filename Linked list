#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    Node(){}

};


void print(Node* head){cout<<endl;
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
    return;
}

void insertAtHead(Node* &head, int value){
    Node* newNode = new Node(value);
    newNode->next=head;
    head=newNode;
}
void insertAtTail(Node* &tail, int value){
    Node* newNode= new Node(value);
    tail->next=newNode;
    tail=newNode;
}
void insertAtIndex(Node* &head, Node* &tail, int value, int index){

    if(index==0){insertAtHead(head, value);return;}

    Node* newNode = new Node(value);

    Node* temp = new Node();
    temp->next=head;

    for(int i=0; i<index; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    if(newNode->next==NULL){tail=newNode;}
}
void deleteAtIndex(Node* &head, int index){

    if(index==0){
        Node* temp = head;
        head=head->next;

        temp->next=NULL;
        delete temp;
        return;}


    Node* current = head;
    Node* previous = NULL;

    for(int i=0; i<index; i++){
        previous=current;
        current=current->next;
    }
    
    previous->next=current->next;

    current->next=NULL;//Before freeing up from the memory space, it should not point to a node, 
    delete current;
}


int main(){cout<<endl;

    Node* node1=new Node(10);
    Node* node2=new Node(20);
    Node* node3=new Node(30);

    node1->next=node2;
    node2->next=node3;

    Node* head=node1;
    Node* tail=node3;

    print(head);cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl;

// Insert at head
    insertAtHead(head, 5);
    print(head);cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl;

// Insert at tail
    insertAtTail(tail, 35);
    print(head);cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl;

// Insert at index
    insertAtIndex(head, tail, 25, 3);
    print(head);cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl;

// Delete at index
    deleteAtIndex(head, 3);
    print(head);cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl;


cout<<endl<<endl;return 0;}
