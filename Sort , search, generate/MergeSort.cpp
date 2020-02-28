#include<bits/stdc++.h>
using namespace std;
void MergeArray(int a[],int L[],int R[],int len, int lenL , int lenR){
    int i=0,j=0,k=0;
    while(j<lenL && k<lenR){
        if(L[j]<R[k]){
            a[i]=L[j];
            j++;
        }
        else{
            a[i]=R[k];
            k++;
        }
        i++;
    }
    while(j<lenL){
        a[i++]=L[j++];
    }
    while(k<lenR){
        a[i++]=R[k++];
    }
}
void MergeSort(int a[],int len){
    if(len<2)return ;
    int mid=len/2;
    int L[mid];
    int R[len-mid];
    for(int i=0; i<mid; i++)L[i]=a[i];

    for(int i=mid; i<len; i++)R[i-mid]=a[i];

    MergeSort(L,mid);
    MergeSort(R,len-mid);

    MergeArray(a,L,R,len,mid,len-mid);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
    MergeSort(a,n);
    cout<<"Sorted array:\n";
    for(int i=0; i<n; i++)cout<<a[i]<<" ";
}
