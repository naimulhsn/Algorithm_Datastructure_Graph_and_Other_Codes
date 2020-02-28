#include<bits/stdc++.h>
using namespace std;
struct trie
{
    int cnt;
    trie* node[26];
    trie()
    {
        for(int i=0; i<26; i++)
            node[i]=NULL;
        cnt=0;
        ///isEnd=true;
    }
};
trie* root=new trie();
void insertTrie(string s)
{
    int len=s.size();
    int c;
    trie* nod=root;
    for(int i=0; i<len; i++){
        c=s[i]-'a';
        if(nod->node[c]==NULL){
            nod->node[c]=new trie();
        }

        nod=nod->node[c];
        nod->cnt++;
    }
}

int cnt(string s)
{
     int len=s.size();
    int c;
    trie* nod=root;

    for(int i=0; i<len; i++){
        c=s[i]-'a';
        if(nod->node[c]==NULL){
            return 0;
        }
        nod=nod->node[c];
    }
    return nod->cnt;
}
void dlt(trie *nod)
{
    if(nod==NULL) return;
    for(int i=0;i<26;i++) dlt(nod->node[i]);
    delete(nod);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        insertTrie(s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<cnt(s)<<endl;
    }
    dlt(root);
}
