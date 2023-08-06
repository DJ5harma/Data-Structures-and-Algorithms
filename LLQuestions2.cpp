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

void reverseHT(node*&h, node*&t){
    node*x=h;
    node*y=x->next;
    node*z=y->next;
    x->next=NULL;
    while(z!=t){
        y->next=x;
        x=y;
        y=z;
        z=z->next;
    }z->next=y; y->next=x;

    t=h;
    h=z;


    return;
}

void reverseKNodes(node*&head, int k){

    node*futureHead=new node();
    futureHead->next=head;
    for(int i=0; i<k; i++){
        futureHead=futureHead->next;
    }    

    node*temp1=head;
    node*temp2=new node();
    node*h=new node();
    node*t=new node();
    temp2=futureHead;

    bool stop=false;

    while(!stop){
        h=temp1;
        t=temp2;
        temp1=temp2=t->next;
        for(int i=1; (i<k)&&(temp2->next!=NULL); i++){
            temp2=temp2->next;
        }
        reverseHT(h,t);
        t->next=temp2;
        if(temp2->next == NULL){stop=true;}
    }

    head=futureHead;
}


void lastKNodesAtStart(node*&head, int k){
    node*temp=head;
    int length=1;

    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    temp->next=head;


    temp=head;
    int i=1;

    while(i<length-k){
        temp=temp->next;
        i++;
    }
    node*newHead=temp->next;
    temp->next=NULL;
    
    head=newHead;
}

void evenNodesAfterOddNodes(node*&head){
    // node*oddHead=head;
    node*evenHead=head->next;
    node*oddTemp=head;
    node*evenTemp=head->next;

    while(true){
        if((evenTemp==NULL)||(evenTemp->next==NULL)){
            oddTemp->next=evenHead;
            return;
        }

        oddTemp->next=oddTemp->next->next;
        oddTemp=oddTemp->next;
        evenTemp->next=evenTemp->next->next;
        evenTemp=evenTemp->next;
        }
}

int main(){cout<<endl;

    node*n1=new node(101);
    node*n2=new node(102);
    node*n3=new node(103);
    node*n4=new node(104);
    node*n5=new node(105);
    node*n6=new node(106);
    node*n7=new node(107);
    node*n8=new node(108);
    node*n9=new node(109);
    node*n10=new node(1010);
    
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    n7->next=n8;
    n8->next=n9;
    n9->next=n10;

    node*head=n1;

    // reverseKNodes(head, 3);
    // printLL(head);
    
    // lastKNodesAtStart(head, 4);
    // printLL(head);

    // evenNodesAfterOddNodes(head);
    // printLL(head);



    cout<<endl;
    return 0;}
