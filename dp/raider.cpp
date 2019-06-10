#include <bits/stdc++.h>
#define pb_ push_back

using namespace std;

typedef pair<int,int> pii;

const int MN =5e5+5,MOD = 1e9+7;

int N,M,money[MN],dfn[MN],low[MN],scc,sccId[MN],provMoney[MN];
pii dp[MN][2];
unordered_map<int,int> mp;
bool inStack[MN];
vector<int> adj[MN],adj2[MN];

int idx = 1;    
    
void tarjans(int u, int p, stack<int> *st = new stack<int>()){
    dfn[u]=low[u]=idx++;
    (*st).push(u),inStack[u]=true;
    for(int v : adj[u]){
        if(!low[v]){
            tarjans(v,u,st);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
     if(dfn[u]==low[u]){
         scc++;// int x = 0;
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
    for(int i = 1; i<=scc; i++){
        unordered_set<int> s;
        for(int v: adj2[i])s.insert(v);
        adj2[i].assign(s.begin(),s.end());
    }
}

pii doDP(int u, bool lastPick){ //money, number
    if(u==sccId[N]){
        if(lastPick)return {0,1};
        return {provMoney[u]%MOD,1};
    }
    if(dp[u][!lastPick]!=pii{-1,-1}) return dp[u][!lastPick];
    
    pii ans{-99,0};
    for(int v : adj2[u]){
        if(!lastPick){
            pii temp = doDP(v,true);        
            temp.first = (temp.first+ provMoney[u])%MOD;
            if(temp.first>ans.first)ans=temp;
            else if(temp.first==ans.first)
                ans.second=(ans.second+temp.second)%MOD;
        }
        pii temp = doDP(v,false);
        if(temp.first>ans.first)ans=temp;
        else if(temp.first==ans.first)
            ans.second=(ans.second+temp.second)%MOD;
    }
    return dp[u][!lastPick] = ans;
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i = 1; i <= N ; i++){
        cin>>money[i];
        dp[i][0] = dp[i][1] = pii{-1,-1};
    } 
    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb_(b);
    }
    tarjans(1,-1);
    rebuild();
    cout<<doDP(sccId[1],false).first<<" "<<doDP(sccId[1],false).second<<endl;
    
}