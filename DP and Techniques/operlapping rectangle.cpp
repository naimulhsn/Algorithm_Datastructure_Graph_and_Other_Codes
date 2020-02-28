#include<bits/stdc++.h>
using namespace std;
int area(int a,int b, int c, int d){
    return (c-a) * (d-b);
}
int main()
{
    int a1,b1,c1,d1;
    int a2,b2,c2,d2;
    cin>>a1>>b1>>c1>>d1;
    cin>>a2>>b2>>c2>>d2;
    cout<<area(max(a1, a2), max(b1, b2), min(c1, c2), min(d1, d2));
}
