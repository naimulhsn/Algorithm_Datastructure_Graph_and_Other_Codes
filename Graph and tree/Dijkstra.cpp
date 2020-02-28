#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int node, cost;
    NODE(int n, int c){
        node = n; cost = c;
    }
};
bool operator<(NODE a, NODE b){
    return a.cost > b.cost;
}
struct EDGE{
    int to,weight;
    EDGE(int t, int w){
        to=t; weight=w;
    }
};
vector<EDGE>adj[100005];
priority_queue<NODE> pq;
int dist[100005];
int vis[100005];
int n;

void dijkstra(int s){
    for(int i=0; i<=n; i++)dist[i]=1000000000,vis[i]=0;
    dist[s] = 0;
    pq.push(NODE(s,0));
    while(!pq.empty()){
        NODE u=pq.top();
        pq.pop();
        if(!vis[u.node]){
            vis[u.node]=1;
            for(EDGE e : adj[u.node] ){
                if(dist[e.to]>dist[u.node]+e.weight){
                    dist[e.to]=dist[u.node]+e.weight;
                    pq.push(NODE(e.to,dist[e.to]));
                }
            }
        }
    }
}
int main()
{
    int edg;
    cin>>n>>edg;
    while(edg--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(EDGE(v,w));
        adj[v].push_back(EDGE(u,w));
    }
    dijkstra(1);
    for(int i=1; i<=n; i++){
        cout<<"Dist of "<<i<<" is : "<<dist[i]<<"\n";
    }
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

