#include<iostream>
using namespace std;
// Binary tree

class node{
public:
    int data;
    node*left;
    node*right;

    node(){}
    node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};

// PreOrder traversal  : Root -> Left -> Right
void preOrder(node*&temp){

    if(temp==NULL){return;}

    cout<<temp->data<<" ";
    
    preOrder(temp->left);
    
    preOrder(temp->right);
    
}

// InOrder traversal   : Left -> Root -> Right
void InOrder(node*&temp){

    if(temp==NULL){return;}

    InOrder(temp->left);

    cout<<temp->data<<" ";

    InOrder(temp->right);

}

// PostOrder traversal : Left -> Right-> Root
void postOrder(node*&temp){

    if(temp==NULL){return;}

    postOrder(temp->left);

    postOrder(temp->right);

    cout<<temp->data<<" ";

}


int main(){

    node* root=new node(0);

    node* n1=new node(1);
    node* n2=new node(2);
    node* n3=new node(3);
    node* n4=new node(4);
    node* n5=new node(5);
    node* n6=new node(6);

    root->left=n1;
    root->right=n2;

    n1->left=n3;
    n1->right=n4;

    n2->left=n5;
    n2->right=n6;

    cout<<"PreOrder : ";preOrder(root);
    cout<<endl;

    cout<<"PostOrder : ";postOrder(root);
    cout<<endl;
    
    cout<<"InOrder : ";InOrder(root);
    cout<<endl;
    
    
    

cout<<endl;
return 0;}
