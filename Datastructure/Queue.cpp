#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct Queue{
    int Start,Back;
    int a[100000];
    Queue(){
        Start=Back=0;
    }
    void Push(int n){
        if(Back>=100000){
            printf("Queue is full..\n");
            return;
        }
        a[Back]=n;
        Back++;
    }
    int Front(){
        return a[Start];
    }
    void Pop(){
        if(Start>=Back){
            printf("Invalid!!!Queue is empty..\n");
            return;
        }
        Start++;
    }
    bool IsEmpty(){
        if(Start>=Back)return true;
        return false;
    }
    int Size(){
        if(Start>=Back)return 0;
        return (Back-Start);
    }
};
int main()
{
    int n,x;
    Queue q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        q.Push(x);
    }
    cout<<"Printing full Queue :\n";
    for(int i=0; i<n; i++){
        cout<<q.Front()<<" - ";
        q.Pop();
    }
    return 0;
}
