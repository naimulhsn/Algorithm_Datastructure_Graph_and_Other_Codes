#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int dis[1000000];
int parent[1000000];
struct EDGE{
    int u,v,w;
    EDGE(int uu, int vv, int ww){
        u=uu; v=vv; w=ww;
    }
};
vector<EDGE> edg;
bool bellmanFord(int vertex,int source){
    for(int i=1; i<=vertex; i++)dis[i]=parent[i]=INF;
    dis[source]=0;
    for(int i=1; i<vertex; i++){
        int f=0;
        for(EDGE e : edg){
            if(dis[e.u]+e.w<dis[e.v]){
                dis[e.v]=dis[e.u]+e.w;
                parent[e.v]=e.u;
                f=1;
            }
        }
        if(!f)return true;
    }
    for(EDGE e: edg){
        if(dis[e.u]+e.w<dis[e.v])
            return false;
    }
}

int main()
{
    int vertex, edge,u,v,g;
    cin>>vertex>>edge;
    while(edge--){
        cin>>u>>v>>g;
        edg.push_back(EDGE(u,v,g));
    }
    cout<<"Enter Source: ";
    int source;
    cin>>source;
    if(!bellmanFord(vertex,source)){
        cout<<"Negative cycle detected!!!";
        return 0;
    }
    cout<<"Enter target : ";
    int target;
    cin>>target;
    stack<int> s;
    s.push(target);
    while(parent[target]!=INF){
        s.push(parent[target]);
        target=parent[target];
    }
    while(!s.empty()){
        cout<<s.top()<<" -> ";
        s.pop();
    }
    return 0;
}
/*

5 7
1 2 2
2 5 5
2 4 3
4 5 2
3 4 -2
1 3 3
1 4 7

*/


