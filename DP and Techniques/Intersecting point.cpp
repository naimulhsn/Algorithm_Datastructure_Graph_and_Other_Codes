#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a1,b1,c1,a2,b2,c2,p;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    p=a1*b2-b1*a2;
    cout<<"(" << (b1*c2-c1*b2)/p<<" , "<< (c1*a2-a1*c2)/p<<" ) \n";
}
