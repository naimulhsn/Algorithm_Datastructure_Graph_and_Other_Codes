#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
vector<int> sp[100005];

int query(int l, int r)
{
    int len=r-l+1;
    int j=log2(len);

    int num1=sp[l][j];
    int num2=sp[l+len-(1<<j)][j];
    return min(num1,num2);
    //return max(num1,num2);
}
long long querySum(int l, int r)
{
    long long sum=0;
    int len=0;
    while(l<=r){
        len=r-l+1;
        int j=log2(len);
        sum+=sp[l][j];
        l=l+(1<<j);
    }
    return sum;
}
void make_sparse_table()
{
    for(int i=0; i<n; i++)sp[i].push_back(a[i]);
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)-1<n; i++){
            //int val=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
            //int val=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
            int val=  sp[i][j-1]    +   sp[i+(1<<(j-1))][j-1];
            sp[i].push_back(val);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];

    make_sparse_table();
    cout<<"\n\nSparse Table:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<sp[i].size(); j++)cout<<sp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
    while(1){
        int l,r;
        cin>>l>>r;
        l--; r--;
        cout<<querySum(l,r)<<"\n\n";
    }

    return 0;
}


















