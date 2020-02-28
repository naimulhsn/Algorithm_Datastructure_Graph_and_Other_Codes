#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int par[N+7];
int findroot(int u)
{
    if(par[u]==u)return u;
    return par[u]=findroot(par[u]);
}
void Union(int u, int v)
{
    u=findroot(u);
    v=findroot(v);
    if(u!=v)
        par[u]=v;
}
int main()
{
    for(int i=1; i<=N; i++)par[i]=i;
    int n, edge,u,v;
    cin>>n>>edge;
    while(edge--){
        cin>>u>>v;
        Union(u,v);
    }
    return 0;
}
