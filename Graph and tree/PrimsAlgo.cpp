#include<bits/stdc++.h>
using namespace std;
struct EDGE{
    int to,weight;
    EDGE(int t, int w){
        to=t; weight=w;
    }
};
struct EDGEE{
    int from,to,weight;
    EDGEE(int f, int t, int w){
        from=f; to=t; weight=w;
    }
};

bool operator<(EDGEE a, EDGEE b){
    return a.weight > b.weight;
}

vector<EDGE>adj[100005];
vector<EDGE>mst[100005];
priority_queue<EDGEE> pq;
int vis[100005];
int n;
int ans;

void Prim(int s){
    for(int i=0; i<=n; i++)vis[i]=0;
    vis[s]=1;
    pq.push(EDGEE(s,s,0));
    while(!pq.empty()){
        EDGEE u=pq.top();
        vis[u.to]=1;
        pq.pop();
        for(EDGE e : adj[u.to] ){
            if(!vis[e.to]){
                pq.push(EDGEE(u.to, e.to, e.weight));
            }
        }
        while(!pq.empty()&& (vis[pq.top().from] && vis[pq.top().to] )  )pq.pop();

        if(pq.empty())break;
        else{
            EDGEE tree=pq.top();
            mst[tree.from].push_back(EDGE(tree.to,tree.weight));
            mst[tree.to].push_back(EDGE(tree.from,tree.weight));
            ans+=tree.weight;
        }
    }
    cout<<ans<<"\n\n\n\n\n";
}


void bfs(int s)
{
    for(int i=0; i<100000; i++)vis[i]=0;
    vis[s]=1;
    cout<<s<<" \n";
    queue<EDGE> q;
    q.push(EDGE(s,0));
    while(!q.empty()){
        EDGE u=q.front();
        q.pop();
        for(EDGE e : mst[u.to] ){
            int v=e.to;
            if(!vis[v]){
                vis[v]=1;
                cout<<"form "<<u.to<<" to "<<v<<" & weight: "<<e.weight<<"\n";
                q.push(EDGE(v,e.weight));
            }
        }
        cout<<"\n";
    }
    return ;
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
    Prim(1);
    bfs(1);
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

