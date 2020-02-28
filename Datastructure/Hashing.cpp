#include<bits/stdc++.h>
using namespace std;
#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define umap           unordered_map
#define pb             push_back
#define mp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define ff             first
#define ss             second
#define endl           '\n'

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
const ull p = 97;
ull p_pow[1000009];
ull h_val[1000009];
int p_gen(){
    p_pow[0]=1;
    for(int i = 0; i < 1000005; i++)
    {
        p_pow[i+1] = p_pow[i]*p;
    }
}
ull Hashval1(string s){
    int len = s.size();
    ull h=0;
    h_val[0]=0;
    for(int i = 0; i < len; i++)
    {
        h_val[i+1] = ((s[i]-'a'+1) * p_pow[i]);
    }
    return h;

}
ull Hashval2(string s)
{
    int len = s.size();
    ull h=0;
    for(int i = 0; i < len; i++)
    {
        h+= ((s[i]-'a'+1) * p_pow[i]);
    }
    return h;

}
int main()
{
    int tc,cs=0;
    cin>>tc;
    p_gen();
    while(cs<tc)
    {
        cs++;
        string a,b;
        cin>>a>>b;
        Hashval1(a);
        for(int i=1; i<=a.size(); i++)
        {
            h_val[i]+=h_val[i-1];
        }
        ull h= Hashval2(b);
        int lenb=b.size();
        int lena=a.size();
        ll ans=0;
        for(int i=0; i<=lena-lenb; i++)
        {
            if((h_val[i+lenb]-h_val[i])== (p_pow[i]*h))ans++;
        }
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }
    return 0;
}

