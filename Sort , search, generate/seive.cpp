#include<bits/stdc++.h>
using namespace std;
#define ll      long long
vector<int> prime;
int vis[1000005];
void seive(long long n)
{
    vis[0]=vis[1]=1;
    prime.push_back(2);
    for(long long i=4; i<=n; i+=2)vis[i]=1;
    for(long long i=3; i<=n; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(long long j=i*i; j<=n; j+=i*2)
                vis[j]=1;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    seive(n);
    cout<<prime.size();
    //for(int i=0; i<prime.size(); i++)cout<<prime[i]<<" ";
    return 0;
}
