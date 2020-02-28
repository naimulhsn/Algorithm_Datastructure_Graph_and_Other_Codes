#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int vis[1000][1000];
struct Item{
    int weight, price;
};
Item a[1005];
int knapsack(int W, int i){
    if(W<=0|| i==0)return 0;
    if(vis[W][i])return dp[W][i];
    if(W<a[i].weight)return dp[W][i]=knapsack(W,i-1);

    vis[W][i]=1;
    return dp[W][i]=max(knapsack(W,i-1),a[i].price+knapsack(W-a[i].weight, i-1));
}
int main()
{
    int W,n;
    cin>>W>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].weight>>a[i].price;
    }
    cout<<"Total money : "<<knapsack(W,n);
}
