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

void LLsIntersectionNodeM1(node*&head1, node*&head2){

    node*temp1=head1;
    node*temp2=head2;

    int count1=1;
    while(temp1!=NULL){

        int count2=1;   
        while(temp2!=NULL){
            
            if(temp1->data == temp2->data){
                cout<<temp1->data<<", longL: "<<count1<<"th, shortL: "<<count2<<"th";
                return;
            }
            temp2=temp2->next;  
            count2++;
        }
        temp2=head2;
        temp1=temp1->next;
        count1++;
    }
    return ;

}
void LLsIntersectionNodeM2(node*&head1, node*&head2){
    // We know that the intersection pt. will always be/after the first node of the smaller list. So, we will start looking in the bigger list from the (length1-length2 +1)th node
    node*temp1=head1;
    node*temp2=head2;

    int length1=1;
    int length2=1;

    while(temp1!=NULL){
        temp1=temp1->next;
        length1++;
    }
    while(temp2!=NULL){
        temp2=temp2->next;
        length2++;
    }
    temp1=head1;
    temp2=head2;

    int diff;
    if(length1>length2){
        diff=length1-length2;
        for(int i=0; i<diff; i++){
            temp1=temp1->next;
        }
    }
    else{
        diff=length2-length1;
        for(int i=0; i<diff; i++){
            temp2=temp2->next;
        }
    }

    int count=1;
    while(temp1!=NULL){
        if(temp1->data==temp2->data){
            cout<<temp1->data<<" longL: "<<count+diff<<" shortL: "<<count<<endl;
            return;
        }
        count++;
        temp1=temp1->next;
        temp2=temp2->next;
    }

    
}

int main(){

    node*n1=new node(1);
    node*n2=new node(2);
    node*n3=new node(3);
    node*n4=new node(4);
    node*n5=new node(5);
    node*n6=new node(6);
    
    node*m1=new node(9);
    node*m2=new node(10);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;

    n4->next=n5;
    n5->next=n6;

    m1->next=m2;
    m2->next=n5;

    node*head1=n1;
    node*head2=m1;

    // LLsIntersectionNodeM1(head1, head2);
    // LLsIntersectionNodeM2(head1, head2);

    return 0;
}
