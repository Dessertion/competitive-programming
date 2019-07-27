#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define mp_ make_pair
//define endl \n
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;

constexpr int MN = 1e5+10;

ll N, p[MN];
vector<pii> adj[MN];

ll cnt,eid[MN],ein[MN],eout[MN],sz[MN],pref[MN],ans,off,val[MN];
unordered_map<ll,ll> ds;

void dfs1(int u, int pa){
    ein[u]=++cnt;
    eid[cnt]=u;
    sz[u]=1;
    pref[u]=-1;
    for(auto v : adj[u]){
        if(v.first == pa)continue;
        val[v.first]=val[u]+v.second;
        dfs1(v.first,u);
        sz[u]+=sz[v.first];
        if(pref[u]==-1 or sz[pref[u]] < sz[v.first])pref[u]=v.first;
    }
    eout[u]=cnt;
}

//sack trick
void dfs2(int u, int pa, bool isPref){
    //go to less preferred children
    for(auto v : adj[u]){
        if(v.first == pa or v.first == pref[u])continue;
        dfs2(v.first,u,false);
    }
    //go to preferred children
    if(pref[u]!=-1)dfs2(pref[u],u,true);
    
    //iterate through non-preferred children, sack 
    for(auto v : adj[u]){
        if(v.first == pa or v.first == pref[u])continue;
        for(int i = ein[v.first]; i <= eout[v.first]; i++){
            int nd = eid[i];
            int diff = val[nd]-val[u];
            ans += ds[-off + 1 - diff];
            ans += ds[-off - 1 - diff];
            ds[diff - off]++;
        }
    }
    //iterate cur too
    int diff = 0;
    ans += ds[-off + 1 - diff];
    ans += ds[-off - 1 - diff];
    ds[diff - off]++;
    
    //change off
    off += val[u] - val[pa];
    //wipe ds if not pref
    if(!isPref){
        ds.clear();
        off = 0;
    }
    
}


int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    for(int i = 0 ; i < N -1; i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        adj[a].pb_({b,c=='r'? 1 : -1});
        adj[b].pb_({a,c=='r'? 1 : -1});
    }
    
    dfs1(1,0);
    dfs2(1,0,true);
    cout<<ans-N+1;
}
