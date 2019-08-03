#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define eb_ emplace_back
#define mp_ make_pair
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
mt19937 mt;
uniform_int_distribution<int> dist(1,1000000000);

struct nd{
    nd *l,*r;
    int val,p,sz;
    int depth;
    nd(int val, int d):l(0),r(0),val(val),p(dist(mt)),sz(1),depth(d){}
} *rt;

inline int sz(const nd *t){
    return t? t->sz:0;
}

inline void upd(nd *t){
    if(t)t->sz = sz(t->l)+sz(t->r)+1;
}

void split(nd* t, nd*& l, nd*& r, int key){
    if(!t)l=r=NULL;
    else if(t->val<key)split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd(t);
}

void merge(nd*& t, nd* l, nd* r){
    if(!l||!r)t=l?l:r;
    else if(l->p<r->p)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    upd(t);
}

void insert(nd* in, nd*& t = rt){
    if(!t)t=in;
    else if(in->p>t->p)split(t,in->l,in->r,in->val),t=in;
    else insert(in,t->val<=in->val?t->r:t->l);
    upd(t);
}

int kth(int key, nd* t = rt, int idx =0, int last = 0){
    if(!t)return last; 
    if(idx+sz(t->l)+1==key)return t->val;
    if(idx+sz(t->l)+1<key)return kth(key,t->r,idx+sz(t->l)+1,t->val);
    return kth(key,t->l,idx,t->val);
}

int find(int key,nd* t=rt,int idx=0){
    if(!t)return idx;
    if(t->val==key)return idx+sz(t->l)+1;
    if(t->val<key)return find(key,t->r,idx+sz(t->l)+1);
    return find(key,t->l,idx);
}

nd* findn(int key, nd* t= rt, nd* last = rt){
    if(!t)return last;
    if(t->val==key)return t;
    if(t->val<key)return findn(key,t->r,t);
    return findn(key,t->l,t);
}
ll N,C;

int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>N;
	int rtt;
	cin>>rtt;
    insert(new nd(rtt,0));
    cout<<"0"<<endl;
    for(int i = 0 ; i < N-1; i++){
        int tmp;
        cin>>tmp;
        int ree =find(tmp);
        int depth = max(findn(kth(ree))->depth,findn(kth(ree+1))->depth);
        insert(new nd(tmp,depth+1));
        C+=depth+1;
        cout<<C<<endl;
    }
}
