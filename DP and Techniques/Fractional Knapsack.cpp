#include<bits/stdc++.h>
using namespace std;
struct Item{
    int price,weight;
    double unit;
};
bool compare(Item x, Item y){
    return x.unit>y.unit;
}
int main()
{
    int n,p,w, W;
    cin>>W>>n;
    Item a[n+5];
    for(int i=0; i<n; i++){
        cin>>w>>p;
        a[i].weight=w;
        a[i].price=p;
        a[i].unit=(double)p/(double)w;
    }
    sort(a,a+n,compare);
    int money=0;
    for(int i=0; i<n; i++){
        if(W<=0)break;
        if(W>=a[i].weight){
            money+=a[i].price;
            W-=a[i].weight;
        }else{
            money+=W*a[i].unit;
            W=0;
        }
    }
    cout<<"Total money : "<< money<<"\n";
    return 0;
}

/*

15 5
3 6
2 65
6 8
5 4
8 20


*/
