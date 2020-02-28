#include<bits/stdc++.h>
using namespace std;
void mx_heapify(int arr[],int len,int pos)
{
    int left=pos*2;
    int right=(pos*2)+1;
    int largest=pos;
    if(left<=len && arr[left]>arr[largest])
        largest=left;
    if(right<=len && arr[right]>arr[largest])
        largest=right;
    if(largest!=pos){
        swap(arr[pos],arr[largest]);
        mx_heapify(arr,len,largest);
    }
}
int main()
{
    int n,a[1000];
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    for(int i=n/2; i>=1; i--){
        mx_heapify(a,n,i);
    }
    cout<<"max Heap :  \n\n";
    for(int i=1; i<=n; i++)cout<<a[i]<<" ";
    cout<<"\n\n\n\n\n\n\n\n";
    int j=1;

    for(int i=1; i<=n; i+=i){

        for(int j=i ; j<i*2 && j<=n; j++)
        {
            for(int k=i; k<=n; k=k*2)cout<<"  ";
            cout<<a[j]<<" ";

        }
        cout<<"\n";
    }

    cout<<"\n\n";
    return 0;

}
/*
10
10 12 7 9 2 15 8 18 3 1
*/
