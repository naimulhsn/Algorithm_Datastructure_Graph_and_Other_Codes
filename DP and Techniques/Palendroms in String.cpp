#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a[s.size()+5]={0};
    for(int i=s.size()-1; i>=0; i--){
        int d=0;
        while(i+d<s.size() && i-d>=0 && s[i-d]==s[i+d]){
            a[i-d]=max(a[i-d],2*d+1);
            d++;
        }
    }
    for(int i=s.size()-1; i>0; i--){
        int d=0;
        while(i+d<s.size() && i-1-d>=0 && s[i-1-d]==s[i+d]){
            a[i-1-d]=max(a[i-1-d],2*(d+1));
            d++;
        }
    }
    // Print the size of palindrome starting at i
    for(int i=0; i<s.size(); i++)cout<<a[i];
    cout<<endl;

    //find the Maximum size palindrome
    int mx=-1,pos;
    for(int i=0; i<s.size(); i++){
        if(mx<a[i]){
            mx=a[i];
            pos=i;
        }
    }
    for(int i=pos; i<pos+a[pos]; i++)cout<<s[i];
}
