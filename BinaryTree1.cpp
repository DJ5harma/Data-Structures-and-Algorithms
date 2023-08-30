#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;
    
    node(){
        this->left=NULL;
        this->right=NULL;
    }
    node(int data){
        this->data=data;
    }
};

int idxInArray(int arr[], int value, int start, int end){
    for(int j=start; j<=end; j++){
        if(value==arr[j]){
            return j;
        }
    }
}
node* BuildBT(int preorder[], int inorder[], int startIn, int endIn){


//!!!!!!Study more about static keyword!!!!!!!, it basically conserves the value of a variable inside the current function scope. Neither in the parent scope, nor in the children scope
    static int idxPre=0;

    if(startIn>endIn){return NULL;}

    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node*temp=new node(preorder[idxPre]);
    idxPre++;

    /* If this node has no children then return */
    if(startIn==endIn){return temp;}

    /* Else find the index of this node in Inorder traversal */
    int idxIn=idxInArray(inorder,temp->data,startIn,endIn);
    
    /* Using index in Inorder traversal, construct left and
    right subtress */    
    temp->left=BuildBT(preorder,inorder,startIn,idxIn-1); 
    temp->right=BuildBT(preorder,inorder,idxIn+1,endIn); 

    return temp;
}

void printInorder(node*root){
    if(root==NULL){return;}
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    int preorder[]={1,2,4,8,5,3,6,7};
    int inorder[]={8,4,2,5,1,6,3,7};
    int size=sizeof(preorder)/sizeof(int);

    node*root=BuildBT(preorder, inorder, 0, size-1);
    printInorder(root);

    cout<<endl<<endl;return 0;
}
