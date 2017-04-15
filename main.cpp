



#include <iostream>
#include "optimization.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#define sqr(x) ((x)*(x))

//#define __int128 long long
using namespace std;

struct bor{
    int freq;
    string c;
    bor* left;
    bor *right;
};

bool operator<(const bor& a,const bor& b){
    if(a.freq!=b.freq)
        return a.freq<b.freq;
    return a.c<b.c;
}

map<string,bor> m;
map<string,string> code;
deque<bor> b;
deque<bor> d;

bor getmin(){
    bor t;
    if(d.empty()) {
        t=b.front();
        b.pop_front();
        return t;
    }
    if(b.empty()) {
        t=d.front();
        d.pop_front();
        return t;
    }
    if(d.front() < b.front()){
        t=d.front();
        d.pop_front();
        return t;
    }else{
        t=b.front();
        b.pop_front();
        return t;
    }

}

bor* huffman(){
    while(!b.empty()||d.size()>1){
        bor* t=new bor;
        bor* p=new bor;
        bor* top=new bor;
        *t=getmin();
        *p=getmin();
        top->freq=t->freq+p->freq;
        top->c="$";
        top->left=t;
        top->right=p;
        d.push_back(*top);
    }
    return &d.front();
}

void decypher(bor* leaf,string prefix){
    if(m.find(leaf->c)!=m.end()){
        code[leaf->c]=prefix;
        return;
    }
    decypher(leaf->left, prefix + '0');
    decypher(leaf->right, prefix + '1');
}

//#define home
int main() {
#ifdef home
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        string p="";
        p+=s[i];
        m[p].freq++;
        m[p].c=s[i];
    }
    int cnt=0;
    for(auto x:m){
        b.push_front(x.second);
        cnt++;
    }
    string ans="";
    sort(b.begin(),b.end());
    if(b.size()==1){
        for(int i=0;i<s.length();i++){
            ans+='0';
        }
        cout<<"1 "<<s.length()<<"\n";
        cout<<b.front().c<<": 0\n";
        cout<<ans;
        return 0;
    }
    decypher(huffman(),"");
    for(int i=0;i<s.length();i++){
        string p="";
        p+=s[i];
        ans+=code[p];
    }
    cout<<cnt<<" "<<ans.length()<<"\n";
    for(auto c:code){
        cout<<c.first<<": "<<c.second<<"\n";
    }
    cout<<ans;
    return 0;
}