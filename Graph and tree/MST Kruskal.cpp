#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//vector<pii> adj[1000];
vector<pii> mst[1000];
int par[10000];
struct EDGE
{
    int from, to, weight;
    EDGE(int f, int t, int w){
        from=f; to=t; weight=w;
    }
};
bool operator<(EDGE A, EDGE B){
    return A.weight< B.weight;
}
int findroot(int u){
    if(par[u]==u)return u;
    return par[u]=findroot(par[u]);
}
bool Union(int u, int v){
    u=findroot(u);
    v=findroot(v);
    if(u!=v){
        par[u]=v;
        return true;
    }
    return false;
}

vector<EDGE> edg;


void Kruskal(){
    for(int i=0; i<=1000; i++)par[i]=i;
    sort(edg.begin(),edg.end());
    int len=edg.size();
    int totalWeight=0;
    for(EDGE e : edg) {
        if(Union(e.from,e.to)){
            totalWeight+=e.weight;
            //mst[e.from].push_back(make_pair(e.to,e.weight));
            //mst[e.to].push_back(make_pair(e.from, e.weight));
            cout<<"form "<<e.to<<" -> "<<e.from<<" : "<< e.weight<<"\n";
        }
    }
    cout<<"Total weight : "<<totalWeight<<"\n";
}
int main()
{
    int vertex,edge,u,v,w;
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++){
        cin>>u>>v>>w;
        //adg[u].push_back(make_pair(v,w));
        //adg[v].push_back(make_pair(u,w));
        edg.push_back(EDGE(u,v,w));
    }
    Kruskal();
    return 0;
}
/*

5
5
1 2 6
1 3 2
3 2 1
2 5 5
3 4 4

*/

