/*Given Array a[] of size N.
Find minimum numbers of the subArray of size M;
here n=6; m=3;
Input:
6 3
10 2 5 9 6 4
output:2 2 5 4

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,q,x,a[100005]={0};
    cin>>n>>m;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    deque<int> dq;
    vector<int> v;
    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.back()<=(i-m)){
            cout<<"popping dq.back()= "<<a[dq.back()]<<endl;
            dq.pop_back();
        }
        while(!dq.empty() && a[i] < a[dq.front()]){
            cout<<"popping a[dq.front()]= "<<a[dq.front()]<<endl;
            dq.pop_front();
        }
        dq.push_front(i);
        cout<<"dq.front() finally= "<<a[dq.front()]<<endl;
        if(i+1>=m)v.push_back(a[dq.back()]);
        cout<<"\n***********************\n";
    }
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    return 0;
}
