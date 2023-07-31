#include <iostream>
using namespace std;




// Doubly linked list
class Node{
public:

    Node* prev;
    int data;
    Node* next;

    Node(int data){

        this->prev=NULL;
        this->data=data;
        this->next=NULL;
    }
    Node(){}

};

void print(Node* &head){cout<<endl;

    for(Node*temp=head; temp!=NULL; temp=temp->next){
        cout<<temp->data<<" ";
    }
cout<<endl;}

int LengthOfLL(Node* &head){

    int count=0;
    for(Node*temp=head; temp!=NULL; temp=temp->next){
        count++;
    }
    return count;
}

void insertAtHead(Node* &head, int value){
    

    Node* temp = new Node(value);
    
    head->prev=temp;
    temp->next=head;
    head=temp;

}
void insertAtTail(Node* &tail, int value){
    

    Node* temp = new Node(value);
    
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void insertAtIndex(Node* &head, Node* &tail, int value, int index){
    
    if(index==0){insertAtHead(head, value);return;}
    
    Node*temp=new Node(value);
    temp->next=head;

    for(int i=0; i!=index; i++){
        temp->next=temp->next->next;
    }

    if(temp->next==NULL){insertAtTail(tail, value); return;}

    temp->prev=temp->next->prev;
    temp->prev->next=temp;
    temp->next->prev=temp;
  
}

void deleteAtIndex(Node* &head, int index){
    Node* temp = head;
    for(int i=0; i<index; i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    temp->next=NULL;
    temp->prev=NULL;
    temp->data=NULL;
    delete temp;

}

int main(){cout<<endl;

    Node*head=new Node();
    Node*tail=new Node();
    Node* node1=new Node(100);
    Node* node2=new Node(200);
    Node* node3=new Node(300);

    node1->next=node2;
    node2->prev=node1;

    node2->next=node3;
    node3->prev=node2;

    head=node1;
    tail=node3;

    print(head);
    cout<<"\nLength = "<<LengthOfLL(head)<<endl;

    insertAtHead(head, 50);
    print(head);

    insertAtTail(tail, 350);
    print(head);

    insertAtIndex(head, tail, 250, 3);
    print(head);

    deleteAtIndex(head, 2);
    print(head);

cout<<endl<<endl;return 0;}
