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
void reverseIterativelyM2(Node*&head){
    Node*previous=new Node();
    Node*current=new Node();
    Node*temp=new Node();
    
    previous->next=NULL;
    current->next=head;

    while(current->next->next!=NULL){
        temp->next=current->next->next;

        current->next->next=previous->next;

        previous->next=current->next;

        current->next=temp->next;
        
    }
    current->next->next=previous->next;
    head=current->next;

    current->next=NULL;
    previous->next=NULL;
    temp->next=NULL;
    delete temp; delete previous, delete current;
}

Node* reverseRecursively(Node*&head, Node*prev=new Node(), Node*afterHead=new Node(), bool firstTime=true){

    if(firstTime){prev=NULL;afterHead=head->next;}
    
    head->next=prev;

    if(afterHead==NULL){return head;}

    return reverseRecursively(afterHead, head, afterHead->next, false);
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
    reverseIterativelyM2(head);
    print(head);

    Node* newHead=reverseRecursively(head);
    print(newHead);
    


cout<<endl<<endl;return 0;}
