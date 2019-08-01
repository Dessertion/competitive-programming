#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define eb_ emplace_back
#define mp_ make_pair
//#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;

const int MN = 1e5+5;
//
int N,K;
ll sum[MN], cnt[MN], ans;

priority_queue<int,vector<int>,std::less<int>> things[MN];

struct query{
    ll b,c,l,i;
};

query queries[MN];
int r;

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i ++){
        int b,c,l;
        cin>>b>>c>>l;
        queries[r++]={b,c,l,i};
        sum[i]+=c;
        cnt[i]++;
    }
    
    while(r>0){
        query cur = queries[--r];
        things[cur.i].push(cur.c);
        
        // cout<<cnt[cur.i]<<endl;
        
        while(!things[cur.i].empty()&&sum[cur.i]>K){
            sum[cur.i]-=things[cur.i].top();
            things[cur.i].pop();
            cnt[cur.i]--;
        }
        
        ans = max(ans,cur.l*cnt[cur.i]);
        if(things[cur.b].size()<things[cur.i].size())swap(things[cur.b],things[cur.i]);
        while(!things[cur.i].empty()){
            things[cur.b].push(things[cur.i].top());
            things[cur.i].pop();
        }
        sum[cur.b]+=sum[cur.i];
        cnt[cur.b]+=cnt[cur.i];
        
    }
    
    cout<<ans;
}
