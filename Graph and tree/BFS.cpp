#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+7;
int vis[N];
vector<int> adj[N];

void bfs(int s)
{
    if(vis[s])return ;
    vis[s]=1;
              //cout<<s<<" ";
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            if(!vis[v]){
                vis[v]=1;
                                          //cout<<v<<" ";
                q.push(v);
            }
        }
    }
    return ;
}

int main()
{
    int ver, edge,u,v;
    cin>>ver>>edge;
    while(edge--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(v);
    return 0;
}
