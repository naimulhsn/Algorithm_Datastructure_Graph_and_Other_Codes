#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
int edge_id[N];
int vis[N];

void dfs(int v)
{
    if(vis[v])return ;
    vis[v]=1;
    cout<<v<<" "; //jkyfufufyyu
    stack<int> stk;
    stk.push(v);
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        while(edge_id[u]<adj[u].size()){
            int v=adj[u][edge_id[u]];
            edge_id[u]++;
            if(!vis[v]){
                vis[v]=1;
                cout<<v<<" "; //jkyfufufyyu
                stk.push(u);
                stk.push(v);
                break;
            }
        }
    }
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

