#include<bits/stdc++.h>
using namespace std;
#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define umap           unordered_map
#define pb             push_back
#define mpp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define ff             first
#define ss             second
#define endl           '\n'
#define dbg(x)     cerr << #x << " is " << x << endl
#define dbgg(x,y)     cerr << #x << " is " << x <<"    "<<#y<<" is "<<y<< endl
const int N=2e5+5;
int tree[N*4],lazy[N*4],arr[N];
void build_tree(int node, int start, int end)
{
    if(start==end){
        tree[start]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build_tree(node*2,start,mid);
    build_tree(node*2+1 ,mid+1, end);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void range_update(int node, int start, int end, int l, int r, int x)
{
    if(lazy[node]){
        tree[node]+=(start-end+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(end<l or r<start)return;
    if(l<=start and end<=r ){
        tree[node]+=(start-end+1)*x;
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
    }

}


