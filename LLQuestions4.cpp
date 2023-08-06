#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next; 
    node(){}
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void printLL(node*head){cout<<endl<<endl;
    node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }    
    cout<<endl;
}

node* mergeSortedLLs(node*&head1, node*&head2){
    node*temp1=head1;
    node*temp2=head2;

    node*helper=new node();

    while((temp1!=NULL)&&(temp2!=NULL)){

        if((temp2->data>temp1->data) && (temp2->data<temp1->next->data)){
            
            helper=temp2->next;
            temp2->next=temp1->next;
            temp1->next=temp2;

            temp2=helper;

        }
        temp1=temp1->next;
    }
    return head1;
}



int main(){

    node*n1=new node(1);
    node*n2=new node(4);
    node*n3=new node(5);
    node*n4=new node(7);

    node*m1=new node(2);
    node*m2=new node(3);
    node*m3=new node(6);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    
    m1->next=m2;
    m2->next=m3;

    node*head1=n1;
    node*head2=m1;

    node*head=mergeSortedLLs(head1, head2);

    printLL(head);

    return 0;
}
