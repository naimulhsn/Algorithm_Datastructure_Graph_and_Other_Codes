#include<bits/stdc++.h>
using namespace std;
int dist[1000][1000];
int pth[1000][1000];
int N;

void floyedWarshall()
{
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            //if(k==i)continue;
            for(int j=1; j<=N; j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pth[i][j]=pth[i][k];
                }
            }
        }
    }
}
void prntPath(int i, int j){
    cout<<i;
    while(pth[i][j]!=j){
        i=pth[i][j];
        cout<<" - "<<i;
    }
    cout<<" - "<<j<<"\n";
}
int main()
{
    int n,e,u,v,w;
    cin>>n>>e;
    N=n;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j)continue;
            dist[i][j]=100000000;
        }
    }
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        dist[u][v]=w;
        pth[u][v]=v;
    }
    cout<<"go floyed:\n";
    floyedWarshall();
    for(int i=0; i<5; i++){
        int a,b;
        cout<<"(a,b) : ";
        cin>>a>>b;
        printf("Dist : %d\n", dist[a][b]);
        cout<<"print path (a,b) : ";
        prntPath(a,b);
    }
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

