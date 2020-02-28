#include<bits/stdc++.h>
using namespace std;
#define ll             long long

ll BigMod(ll a, ll b, ll M)
{
    if(b==0)return 1%M;
    ll x=BigMod(a, b/2, M);
    x=(x*x)%M;
    if(b%2==1)x=(x*a)%M;
    return x;
}
int main()
{
    ll a,b,M;
    while(1){
        cin>>a>>b>>M;
        printf("BigMod of ( %d ^ %d )MOD %d  =  %d\n\n",a,b,M,BigMod(a,b,M));
    }
}
