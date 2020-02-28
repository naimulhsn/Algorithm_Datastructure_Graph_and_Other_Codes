#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int data;
    NODE *left, *right;
    NODE(){
        left=NULL;
        right=NULL;
    }
};
NODE* root=NULL;
void Insert(int x)
{
    NODE* node=new NODE();
    node->data=x;
    if(root==NULL){
        root=node;
    }
    else{
        NODE* tmp=root;
        NODE* parent;
        while(tmp!=NULL){
            if(x<=tmp->data){
                parent=tmp;
                tmp=tmp->left;
            }
            else {
                parent=tmp;
                tmp=tmp->right;
            }
        }
        if(x<=parent->data)parent->left=node;
        else parent->right=node;
    }
}
void PreOrder(NODE* tmp)
{
    if(tmp==NULL)return ;
    cout<< tmp->data<<" ";
    PreOrder(tmp->left);
    PreOrder(tmp->right);
}
 void PostOrder(NODE* tmp)
{
    if(tmp==NULL)return ;
    PostOrder(tmp->left);
    PostOrder(tmp->right);
    cout<< tmp->data<<" ";
}
 void InOrder(NODE* tmp)
{
    if(tmp==NULL)return ;
    InOrder(tmp->left);
    cout<< tmp->data<<" ";
    InOrder(tmp->right);
}


int main()
{
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        Insert(x);
    }
    cout<<"Printing PreOrder :"<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Printing PostOrder :"<<endl;
    PostOrder(root);
    cout<<endl;
    cout<<"Printing InOrder :"<<endl;
    InOrder(root);
    cout<<endl;
    return 0;
}
