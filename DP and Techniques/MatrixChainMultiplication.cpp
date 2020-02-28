#include<bits/stdc++.h>
using namespace std;
int row[105],col[105];
int dp[105][105],vis[105][105];

int Cost(int l, int r){
    if(l>=r)return 0;
    if(vis[l][r])return dp[l][r];
    int ans=INT_MAX;
    for(int i=l; i<r; i++){
        int leftCost=Cost(l,i);
        int rightCost=Cost(i+1,r);
        int leftXrightCost=row[l]*col[i]*col[r];
        int total=leftCost+rightCost+leftXrightCost;
        ans=min(ans,total);
    }
    dp[l][r]=ans;
    vis[l][r]=1;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>row[i]>>col[i];
    }
    cout<<"Ans: "<<Cost(0,n-1)<<"\n";
    return 0;
}

/*

3
2 5
5 3
3 4

*/


/*

1
2 5

*/

/*

2
2 5
5 3

*/
