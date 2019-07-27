#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define mp_ make_pair
//define endl \n
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;

const int MN = 1e5+5,MM = 1e5+5;

int parent[MN],rnk[MN];
int find(int x){
    while(parent[x]){
        parent[x]=parent[parent[x]],x=parent[x];
    }
    return x;
}
void uni(int u, int v){
    u = find(u),v=find(v);
    if(u==v)return;
    if(rnk[u]<rnk[v])std::swap(u,v);
    parent[v]=u;
    if(rnk[u]==rnk[v])rnk[u]++;
}

int N,M;
stack<pii> edges;
vector<int> adj[MN];

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        int a,b;
        cin>>a>>b;
        edges.push({a,b});
    }
    while(!edges.empty()){
        int a=edges.top().first,b=edges.top().second;edges.pop();
        if(find(a)!=find(b)){
            adj[a].pb_(b);
            adj[b].pb_(a);
        }
    }
}
