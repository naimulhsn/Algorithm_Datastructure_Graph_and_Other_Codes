#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
int vis[N];

void dfs(int v)
{
    if(vis[v])return ;
    vis[v]=1;
    cout<<v<<" ";
    for(int i=0; i<adj[v].size(); i++){
        dfs(adj[v][i]);
    }
    return ;
}
int main()
{
    int ver,edge,u,v;
    cin>>ver>>edge;
    while(edge--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(v);
    return 0;
}
