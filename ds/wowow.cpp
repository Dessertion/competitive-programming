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
uniform_int_distribution<int> dis(1,1e9);

const int MN= 1e6+5;

int N,friends[MN];

struct nd{
    nd* l, *r;
    int ra, prior, id,sz;
    nd(int rating, int identity):ra(rating),id(identity),prior(dis(mt)),sz(1){}
} *rt;

inline int sz(const nd *t){
    return t? t->sz:0;
}

void upd(nd *t){
    if(t)t->sz = sz(t->l)+sz(t->r)+1;
}

void split(nd* t, nd*& l, nd*& r, int key){
    if(!t)l=r=NULL;
    else if(t->ra<key)split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd(t);
}

void merge(nd*& t, nd* l, nd* r){
    if(!l||!r)t=l?l:r;
    else if(l->prior<r->prior)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    upd(t);
}

void insert(nd* in, nd*& t = rt){
    if(!t)t=in;
    else if(in->prior>t->prior)split(t,in->l,in->r,in->ra),t=in;
    else insert(in,t->ra<=in->ra?t->r:t->l);
    upd(t);
}

void erase(int key, nd*& t = rt){
    assert(t);
    if(!t)return;
    if(t->ra==key){
        nd* tmp = t;
        merge(t,t->l,t->r);
        delete tmp;
    }
    else erase(key,t->ra<key?t->r:t->l);
    upd(t);
}

nd* kth(int key, nd* t = rt, int idx = sz(rt->l)+1){
    assert(t);
    if(idx==key)return t;
    if(idx<key)return kth(key,t->r,idx+sz(t->r->l)+1);
    return kth(key,t->l,idx-(sz(t->l->r)+1));
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        char q; int a,b;
        cin>>q>>a;
        if(q=='N'){
            cin>>b;
            friends[a]=b;
            insert(new nd(b,a));
        }
        else if(q=='M'){
            cin>>b;
            erase(friends[a]);
            insert(new nd(b,a));
            friends[a]=b;
        }
        else{
            auto ree = kth(sz(rt)-a+1);
            cout<<ree->id<<endl;
        }
    }
    
}