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
    nd(int val):l(0),r(0),val(val),p(dist(mt)),sz(1){}
} *rt;

inline int sz(const nd *t){
    return t? t->sz:0;
}

void upd(nd *t){
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

void erase(int key, nd*& t = rt){
    if(!t)return;
    if(t->val==key){
        nd* tmp = t;
        merge(t,t->l,t->r);
        delete tmp;
    }
    else erase(key,t->val<key?t->r:t->l);
    upd(t);
}

int kth(int key, nd* t = rt, int idx = sz(rt->l)+1){
    if(idx==key)return t->val;
    if(idx<key)return kth(key,t->r,idx+sz(t->r->l)+1);
    return kth(key,t->l,idx-(sz(t->l->r)+1));
}

int find(int key,nd* t=rt,int idx=0){
    if(!t)return -1;
    if(t->val==key)return idx+sz(t->l)+1;
    if(t->val<key)return find(key,t->r,idx+sz(t->l)+1);
    return find(key,t->l,idx);
}

void print(nd* t=rt){
    if(!t)return;
    if(t->l)print(t->l);
    cout<<t->val<<" ";
    if(t->r)print(t->r);
}

int N,M;

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        int tmp;
        cin>>tmp;
        insert(new nd(tmp));
    }
    int ans = 0;
    for(int i = 0; i<M; i++){
        char c; int x;
        cin>>c>>x;
        x^=ans;
        switch(c){
            case 'I':
                insert(new nd(x));
                break;
            case 'R':
                erase(x);
                break;
            case 'S':
                ans = kth(x);
                cout<<ans<<endl;
                break;
            case 'L':
                ans = find(x);
                cout<<ans<<endl;
                break;
        }
    }
    
    print();
}
