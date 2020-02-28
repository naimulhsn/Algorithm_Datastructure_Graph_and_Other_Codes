#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
int vis[N];
int t, discover[N];
struct Edge
{
    int u,v;
    Edge(int _u, int _v)
    {
        u=_u;
        v=_v;
    }
};
vector<Edge> backedge,treedge,forwardedge,crossedge;
void dfs(int u)
{
    discover[u]=++t;
    vis[u]=1;
    cout<<u<<" ";
    for(int i=0; i<adj[u].size(); i++)
    {
        if(vis[adj[u][i]]==0)
        {
            treedge.push_back(Edge(u,adj[u][i]));
            dfs(adj[u][i]);
        }
        else if(vis[adj[u][i]]==1)
        {
            backedge.push_back(Edge(u,adj[u][i]));
        }
        else if(vis[adj[u][i]]==2)
        {
            if(discover[u]<discover[adj[u][i]])
                forwardedge.push_back(Edge(u,adj[u][i]));
            else
                crossedge.push_back(Edge(u,adj[u][i]));
        }

    }

    vis[u]=2;
    return ;
}
int main()
{
    int ver,edge,u,v;
    cin>>ver>>edge;
    while(edge--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=ver; i++){
        if(!vis[i])dfs(i);
    }
    cout<<"\nTree Edge : \n";
    for(Edge e: treedge){
        cout<<e.u<<" -> "<<e.v<<"\n";
    }
    cout<<"\nBack Edge : \n";
    for(Edge e: backedge){
        cout<<e.u<<" -> "<<e.v<<"\n";
    }
    cout<<"\nForward Edge : \n";
    for(Edge e: forwardedge){
        cout<<e.u<<" -> "<<e.v<<"\n";
    }
    cout<<"\nCross Edge : \n";
    for(Edge e: crossedge){
        cout<<e.u<<" -> "<<e.v<<"\n";
    }
    return 0;
}
/*

7 8

1 2
2 3
2 4
4 1
1 5
3 5
6 3
6 7

*/

