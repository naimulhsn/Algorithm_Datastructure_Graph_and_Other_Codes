#include<bits/stdc++.h>
using namespace std;
vector<int> v[10000];
int vis[100000];

int dfs(int s){
    vis[s]=1;
    int cnt=0;
    for(int i=0; i<v[s].size(); i++){
        if(vis[v[s][i]]==1)cnt++;
        else if(vis[v[s][i]]==0){
            cnt+=dfs(v[s][i]);
        }
    }
    vis[s]=2;
    return cnt;
}

int main()
{
    int node,e;
    cin>>node>>e;
    for(int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    int cnt=0;
    for(int i=1; i<=node; i++){
        if(!vis[i])cnt+=dfs(i);
    }
    cout<<"\n\nTotal cycles : "<<cnt;
}
