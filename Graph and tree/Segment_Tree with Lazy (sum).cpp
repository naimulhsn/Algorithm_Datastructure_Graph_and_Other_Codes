#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int tree[N*4],lazy[N*4],arr[N];

void range_update(int node, int start, int end, int l, int r, int x)
{
    if(lazy[node]){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(end<l or r<start)return;
    if(l<=start and end<=r ){
        tree[node]+=(end-start+1)*x;
        if(start!=end){
            lazy[node*2]+= x;
            lazy[node*2+1]+= x;
        }
        return ;
    }
    int mid=(start+end)/2;
    range_update(node*2,start,mid,l,r,x);
    range_update(node*2+1, mid+1, end, l,r, x);
    tree[node] = tree[node*2]+tree[node*2+1];

}
long long query(int node, int start, int end, int l, int r)
{
    if(end<l or r<start)return 0;
    if(lazy[node]){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=start and end<=r)return tree[node];
    int mid=(start+end)/2;
    long long q1 = query(node*2,start,mid,l,r);
    long long q2 = query(node*2+1,mid+1,end,l,r);
    return (q1+q2);
}

void build_tree(int node, int start, int e)
{
    if(start==e){
        tree[node] = arr[start];
        return;
    }
    int mid=(start+e)/2;
    build_tree(node*2,start,mid);
    build_tree(node*2+1 ,mid+1, e);
    tree[node] = tree[node*2]+tree[node*2+1];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    build_tree(1,1,n);
    int q,op,l,r,x;
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            range_update(1,1,n,l,r,x);
        }
        else {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }

}


