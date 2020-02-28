#include<bits/stdc++.h>
using namespace std;
int a[100001],tree[300003];

int query(int node,int b,int e,int l,int r){
    if(r<b || e<l)return 0;
    if(l<=b && e<=r)return tree[node];
    int left=node*2;
    int right=node*2 +1;
    int mid=(b+e)/2;
    return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}
void update(int node,int b, int e, int i,int val){
    if(i<b || i>e)return;
    if(i<=b && e<=i){
        tree[node]=val;
        return ;
    }
    int left=node*2;
    int right=node*2 +1;
    int mid= (b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=tree[left]+tree[right];
}
void make_tree(int node,int b, int e){
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2 +1;
    int mid=(b+e)/2;
    make_tree(left,b,mid);
    make_tree(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    make_tree(1,1,n);
    for(int i=1; i<=13; i++)cout<<tree[i]<<" ";
    cout<<endl;
    update(1,1,n,1,3);
    for(int i=1; i<=13; i++)cout<<tree[i]<<" ";
    cout<<endl;
    cout<<query(1,1,n,2,n);
    return 0;
}
