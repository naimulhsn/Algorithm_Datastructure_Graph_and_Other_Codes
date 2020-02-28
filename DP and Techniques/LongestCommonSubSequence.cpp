#include<bits/stdc++.h>
using namespace std;
vector<char> v;

int LCS(string s1,string s2, int len1, int len2)
{
    int dp[len1+5][len2+5];
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0){dp[i][j]=0; continue;}
            if(s1[i-1]==s2[j-1])dp[i][j]= 1+ dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=len1, j=len2;
    string subRev="";
    while(i>0&&j>0){
        if(s1[i]==s2[j]){
            subRev+=s1[i];
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else j--;
    }
    cout<<"\nThe Substring : ";
    for(int k=subRev.size()-1 ; k>=0; k--)cout<<subRev[k];
    cout<<"\n";

    return dp[len1][len2];
}

int LCSuff(string s1, string s2, int i, int j)
{
    if(i<0||j<0)return 0;
    if(s1[i]==s2[j])return LCSuff(s1,s2,i-1,j-1)+1;
    return 0;
}
int LS(string s1, string s2, int len1, int len2)
{
    int mx=0;
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            if(s1[i]==s2[j]){
                mx=max(mx,LCSuff(s1,s2,i,j));
            }
        }
    }
    return mx;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int len1, len2;
    len1=s1.size();
    len2=s2.size();
    cout<<"Longest common sub sequence : "<<LCS(s1,s2,len1,len2)<<"\n\n";
    cout<<"Longest common sequence : "<<LS(s1,s2,len1,len2)<<"\n";

    return 0;
}
/*
abcd
fcgde

abcd
abcadbc

abcdef
afef

bd
abcd

*/
