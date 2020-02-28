#include<bits/stdc++.h>
using namespace std;
struct NODE{
    NODE* next[26];
    bool isWord;
    int cnt;
    NODE(){
        cnt=0;
        isWord=false;
        for(int i=0; i<26; i++)next[i]=NULL;
    }
};

struct Trie{
    NODE* root;
    deque<int> d;
    Trie(){
        root=new NODE();
    }
    void Insert(char *s, int len){
        NODE* curr=root;
        for(int i=0; i<len; i++){
            int to=s[i]-'a';
            if(curr->next[to]==NULL)curr->next[to]=new NODE();
            curr=curr->next[to];
            curr->cnt++;
        }
        curr->isWord=true;
    }
    bool Find(char* s, int len){
         NODE* curr=root;
        for(int i=0; i<len; i++){
            int to=s[i]-'a';
            if(curr->next[to]==NULL)return false;
            curr=curr->next[to];
        }
        return curr->isWord;
    }
    int Count(char* s, int len){
         NODE* curr=root;
        for(int i=0; i<len; i++){
            int to=s[i]-'a';
            if(curr->next[to]==NULL)return 0;
            curr=curr->next[to];
        }
        return curr->cnt;
    }
    void DeleteAll(){
        cout<<"Deleting Full Trie:\n";
        Delete(root);
        root=new NODE();
        d.clear();
    }
    void Delete(NODE* curr){
        for(int i=0; i<26; i++){
            if(curr->next[i]!=NULL)Delete(curr->next[i]);
        }
        delete(curr);
    }
    void PrintAll(){
        cout<<"Printing All Words In This Trie:\n";
        Print(root);
        d.clear();
    }
    void Print(NODE* curr){
        if(curr->isWord){
            for(int i=0; i<d.size(); i++){
                printf("%c",d.at(i)+'a');
            }
            printf("\n");
        }
        for(int i=0; i<26; i++){
            if(curr->next[i]!=NULL){
                d.push_back(i);
                Print(curr->next[i]);
            }
        }
        if(!d.empty())d.pop_back();
    }
};


int main()
{
    int tc;
    cin>>tc;
    Trie t;
    char st[1000];
    while(tc--){

        scanf("%s",st);
        t.Insert(st,strlen(st));
    }
    for(int i=0; i<5; i++){
        scanf("%s",st);
        if(t.Find(st,strlen(st)))cout<<"Found!\n";
        else cout<<"Not found\n";
    }
    for(int i=0; i<5; i++){
        scanf("%s",st);
        cout<<"counted : "<<t.Count(st,strlen(st))<<endl;
    }
    t.PrintAll();
    t.DeleteAll();
    t.PrintAll();

}
