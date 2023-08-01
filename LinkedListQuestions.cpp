#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node*next;

    Node(){}
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node*&head){cout<<endl;
    for(Node*temp=head; temp!=NULL; temp=temp->next){
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

void reverseIteratively(Node*&head){
    Node*a=head;
    Node*b=a->next;
    Node*c=b->next;
    a->next=NULL;

    while(c!=NULL){
        b->next=a;
        a=b;b=c;c=c->next;
    }b->next=a;
    head=b;
}


Node* middleNode(Node*&head){
    int count=0;
    Node*temp=head;
    
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    int mid=count/2;
    cout<<"index of mid = "<<mid<<endl ;

    count=0;temp=head;
    while(count<mid){
        count++;
        temp=temp->next;
    }

    return temp;

}

    

int main(){cout<<endl;

    Node* n1=new Node(100);
    Node* n2=new Node(200);
    Node* n3=new Node(300);
    Node* n4=new Node(400);
    Node* n5=new Node(500);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

    Node*head=n1;

    print(head);

    cout<<middleNode(head)->data;

           
    reverseIteratively(head);
    print(head);
    


cout<<endl<<endl;return 0;}
