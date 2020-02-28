#include<bits/stdc++.h>
using namespace std;
const int N= 1e3+7;
int vis[N][N];
int dis[N][N];
int ara[N][N];
int dr[4]={0,1,0,-1};
int dc[4]={-1,0,1,0};
bool valid(int x, int y){
    if(x>0 && y>0 && x<N &&y<N && vis[x][y]==0)return true;
    return false;
}
int grid_bfs(int ux,int uy, int vx,int vy)
{
    if(ux==vx &&uy==vy)return 0;
    vis[ux][uy]=1;
    dis[ux][uy]=0;
    pair<int ,int > p;
    queue<pair<int ,int> > q;
    q.push(make_pair(ux,uy));

    while(!q.empty()){
        p =q.front();
        q.pop();
        ux=p.first;
        uy=p.second;
        for(int i=0; i<4; i++){
            int x=ux+dc[i];
            int y=uy+dr[i];
            if(valid(x,y)){
                vis[x][y]=1 ;
                dis[x][y]=dis[ux][uy]+1 ;
                if(x==vx &&y==vy){
                    cout<<"Found "<<endl;
                    return dis[x][y];
                }
                q.push(make_pair(x,y));
            }
        }
    }
    return -1;
}

int main()
{
    int n,m,ux,uy,vx,vy;
    cout<<"Enter start point and end point:";
    cin>>ux>>uy>>vx>>vy;
    int f=grid_bfs(ux,uy,vx,vy);
    if(f==-1)cout<<"Not found";
    else cout<<f;
    return 0;
}

