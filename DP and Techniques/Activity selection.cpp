#include<bits/stdc++.h>
using namespace std;
struct Event{
    int start,end;
};
bool compare(Event x,Event y){
    return x.end<y.end;
}
int main()
{
    int n,s,e;
    cin>>n;
    Event a[n+5];
    for(int i=0; i<n; i++){
        cin>>s>>e;
        a[i].start=s;
        a[i].end=e;
    }
    sort(a,a+n,compare);

    int ended=0,cnt=0;
    for(int i=0; i<n; i++){
        if(a[i].start>=ended){
            cnt++;
            ended=a[i].end;
        }
    }
    cout<<"Selected Activity : "<<cnt<<"\n";
    return 0;
}
