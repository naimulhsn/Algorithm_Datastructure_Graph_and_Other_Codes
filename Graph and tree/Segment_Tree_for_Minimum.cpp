#include<bits/stdc++.h>
using namespace std;
class STree{
public:
    int tree[300009];
    int a[100005];
    STree(){
        for(int i=0; i<100005; i++)a[i]=0;
        for(int i=0; i<300009; i++)tree[i]=0;
    }
    void mk_tree(int node,int b,int e){
        if(b==e){
            tree[node]=a[b];
            return;
        }
        int left=node*2;
        int right=node*2+1;
        int mid=(b+e)/2;
        mk_tree(left,b,mid);
        mk_tree(right,mid+1,e);
        tree[node]=min(tree[left],tree[right]);
    }
    int find_min(int node,int b,int e, int i,int j){
        if(j<b || e<i)return 9999999;
        if(i<=b && e<=j) return tree[node];
        int left=node*2;
        int right=node*2+1;
        int mid=(b+e)/2;
        int f1=find_min(left,b,mid,i,j);
        int f2=find_min(right,mid+1,e,i,j);
        int f=min(f1,f2);
        return f;
    }

};
int main()
{
    int tc,n,q,l,r,cs=1;
    cin>>tc;
    while(tc--){
        STree t;
        cin>>n>>q;
        for(int i=1; i<=n; i++){
            scanf("%d",&t.a[i]);
        }
        t.mk_tree(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&l,&r);
            printf("%d\n",t.find_min(1,1,n,l,r));
        }
    }
    return 0;
}
