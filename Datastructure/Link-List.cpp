#include<bits/stdc++.h>
using namespace std;
struct NODE
{
    int data;
    NODE* next;
};
struct LinkList{
private:
    NODE* head;
public:
    LinkList(){
        head=NULL;
    }
    void Front(int x){
        NODE* node=new NODE();
        node->data=x;
        node->next=head;
        head=node;
    }
    void Back(int x){
        NODE* node=new NODE();
        node->data=x;
        node->next=NULL;
        if(head==NULL) head=node;
        else{
            NODE* tmp=head;
            while(tmp->next!=NULL)
                tmp=tmp->next;
            tmp->next=node;
        }
    }
    void At(int position ,int x){
        NODE* node=new NODE();
        node->data=x;
        if(position==1){
            node->next=head;
            head=node;
        }
        else{
            int i=2;
            NODE* tmp=head;
            while(tmp!=NULL){
                if(i==position){
                    node->next=tmp->next;
                    tmp->next=node;
                    return;
                }
                tmp=tmp->next;
                i++;
            }
            printf("Invalid Position!\n");
        }
    }
    void Print(){
        NODE* tmp=head;
        while(tmp!=NULL){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
    void Delete(){
        NODE* tmp=head;
        NODE* del=tmp;
        while(tmp!=NULL){
            del=tmp;
            tmp=tmp->next;
            delete(del);
        }
        head=NULL;
    }
};

struct Stack
{
private:
    NODE* headd;
public:
    Stack()
    {
        headd =NULL;
    }
    void Push(int x)
    {
        NODE* node=new NODE();
        node->data=x;
        node->next=headd;
        headd=node;
    }
    int Top()
    {
        if(headd!=NULL) return headd->data;
        return -1;
    }
    void Pop()
    {
        NODE* tmp=headd;
        headd=headd->next;
        delete(tmp);
    }
    int IsEmpty()
    {
        if(headd!=NULL) return 0;
        return 1;
    }
};

int main()
{
    int n,x;
    cin>>n;
    Stack stk;
    LinkList l, o;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        stk.Push(x);
        cout<<"Top -> "<<stk.Top()<<endl;
        l.Back(x);
        o.Front(x);

    }
    cout<<"All link list l:\n";
    l.Print();
     cout<<"\nAll link list o:\n";
    o.Print();
    cout<<"\n\nAll the Stack:\n";
    while(!stk.IsEmpty())
    {
        cout<<stk.Top()<<" ";
        stk.Pop();
    }
    return 0;
}
