#include<bits/stdc++.h>
using namespace std;
int vertex,edge,u,v,w;
vector<int,pair<int,int> > adj[10005];
int sparse[10005][18];
int par[10005],dis[10005],lv[10005],root;
void dfs(int s,int dist,int lvl){
    dis[s]=dist;
    lv[s]=lvl;
    for(int i=0; i<adj[s].size(); i++){
        dfs(adj[s][i].first, adj[s][i].second + dist, lvl+1);
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        cin>>vertex;
        for(int i=0; i<=vertex; i++)par[i]=-1;

        for(int i=1; i<vertex; i++){
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            //adj[v].push_back({u,w});
            par[v]=u;
        }
        for(int i=1; i<=vertex; i++){
            if(par[i]==-1)root=i;
            adj[i][0]=par[i];
        }
        dfs(root,0,0);
    }


}
