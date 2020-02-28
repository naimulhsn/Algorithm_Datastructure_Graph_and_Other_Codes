#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnt=0;
    cin>>n>>k;
    int a[n+5], b[n+5];
    for(int i=1; i<=n; i++ )cin>>a[i];
    b[0]=0;
    for(int i=1; i<=n; i++)b[i]=b[i-1]^a[i];
    for(int i=1; i<=n; i++)cout<<b[i]<<"  ";
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if((b[j]^b[i])>k)cnt++;
        }
    }
    cout<<endl<<endl<<cnt;
}
