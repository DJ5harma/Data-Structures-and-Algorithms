#include <iostream>
using namespace std;

//Circular linked list
class Node{
public:
    int data;
    Node*next;

    Node(){}

    Node(int data){
        this->data=data;
    }
};

void print(Node* &head){cout<<endl;
    cout<<head->data<<" ";
    for(Node* temp = head->next; temp!=head; temp=temp->next){
        cout<<temp->data<<" ";
    }
cout<<endl;}

void insertAtHead(Node* &head, int value){
    Node* newNode=new Node(head->data);
    newNode->next=head->next;
    head->next=newNode;
    head->data=value;

}
void insertAtTail(Node* &tail, int value){
    Node* newNode=new Node(value);
    newNode->next=tail->next;
    tail->next=newNode;
    tail=newNode;
}

void insertAtIndex(Node* &head, int value, int index){
   
    Node* newNode=new Node(value);
    newNode->next=head;
    
    for(int i=0; i<index-1; i++){
        newNode->next=newNode->next->next;
    }
    Node*temp=new Node();
    temp->next=newNode->next->next;
    newNode->next->next=newNode;
    newNode->next=temp->next;
    temp->next=NULL;
    delete temp;

}

void deleteAtIndex(Node* &head, int index){

    Node* temp=head;
    for(int i=0; i<index-1; i++){
        temp=temp->next;
    }
    Node*temp2=new Node();
    temp2->next=temp->next->next;

    temp->next->next=NULL;
    temp->next->data=NULL;
    delete temp->next;

    temp->next=temp2->next;

    temp2->next=NULL;
    delete temp2;

}

int main(){cout<<endl;

    Node*head=new Node();
    Node*tail=new Node();
    Node* node1=new Node(100);
    Node* node2=new Node(200);
    Node* node3=new Node(300);

    node1->next=node2;
    node2->next=node3;
    node3->next=node1;

    head=node1;tail=node3;
    print(head);

    insertAtHead(head, 50);
    print(head);cout<<head->data;

    insertAtTail(tail, 350);
    print(head);cout<<tail->data;

    insertAtIndex(head, 250, 3);
    print(head);

    deleteAtIndex(head, 2);
    print(head);

cout<<endl<<endl;return 0;}
