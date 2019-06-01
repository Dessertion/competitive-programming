#include <bits/stdc++.h>
#define pb_ push_back

using namespace std;

const int MN =5e5+5,MOD = 1e9+7;

int N,M,money[MN],dfn[MN],low[MN],scc,sccId[MN],provMoney[MN];
bool inStack[MN];
vector<int> adj[MN],adj2[MN];
    
void tarjans(int u, int p,int idx = 1, stack<int> *st = new stack<int>()){
    dfn[u]=low[u]=idx;
    (*st).push(u),inStack[u]=true;
    for(int v : adj[u]){
        if(low[v]){
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v]){
            tarjans(v,u,idx+1,st);
            low[u] = min(low[u],dfn[v]);
        }
    }
     if(dfn[u]==low[u]){
         scc++; int x = 0;
         while(true){
            int v = (*st).top(); (*st).pop();
            sccId[v] = scc;
            provMoney[scc]+=money[v];
            inStack[v]=false;
            if(u==v)break;
        } 
     }
}

void rebuild(){
    for(int u = 1; u <= N; u++){
        for(int v: adj[u]){
            if(sccId[u]!=sccId[v])adj2[sccId[u]].pb_(sccId[v]);
        }
    }
    for(int i = 1; i<= N; i++){
        unordered_set<int> s;
        for(int v: adj2[i])s.insert(v);
        adj2[i].assign(s.begin(),s.end());
    }
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i = 1; i <= N ; i++)cin>>money[i];
    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb_(b);
    }
    
    
}