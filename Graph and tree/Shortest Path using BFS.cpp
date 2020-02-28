#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+7;
int vis[N];
vector<int> adj[N];
int path[N];
int dis[N];
int path_bfs(int s, int t)
{
    if(s==t)return 0;
    vis[s]=1;
    path[s]=s;
    dis[s]=0;
              //cout<<s<<" ";
    queue<int> q;
    q.push(s);
    int v;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            v=adj[u][i];
            if(!vis[v]){
                dis[v]=dis[u]+1;
                path[v]=u;
                vis[v]=1;
                                          //cout<<v<<" ";
                q.push(v);
            }
        }
    }
    if(!vis[t]){
        return -1;
    }
    stack<int> st;
    int now=t;
    st.push(now);
    while(now!=s){
        now=path[now];
        st.push(now);
    }
    while(!st.empty()){
        cout<<st.top()<<"->";
        st.pop();
    }
    cout<<"\n Distance : ";
    return dis[t];
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
    cout<<"Path to find :";
    cin>>u>>v;
    cout<<path_bfs(u,v);


    return 0;
}
/*Data set:
10 11
4 5
4 6
5 3
5 8
5 7
6 7
7 2
7 10
6 9
9 1
10 1
*/


