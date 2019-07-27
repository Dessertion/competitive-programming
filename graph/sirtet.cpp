#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define eb_ emplace_back
#define mp_ make_pair
//define endl \n
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;

const int ree = 1e6+5;

int N,M,inc,dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},dis[ree];
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> num;
vector<pii> blocks;

vector<pii> adj[ree];


struct comparePlease{
    bool operator()(pii a, pii b){return a.second<b.second;}
};
priority_queue<pii,vector<pii>,comparePlease> pq;

bool check(pii cur){
    if(cur.first >= N || cur.second >= M)return false;
    if(cur.first <0 || cur.second < 0)return false;
    return true;
}

void dfs(pii cur){
    num[cur.first][cur.second] = inc;
    vis[cur.first][cur.second] = true;
    for(auto d : dir){
        pii next{cur.first+d[0],cur.second+d[1]};
        if(!check(next))continue;
        if(grid[next.first][next.second]!='#')continue;
        if(vis[next.first][next.second])continue;
        vis[next.first][next.second]=true;
        dfs(next);
    }
}

pii getNext(pii start){
    for(int i = start.first+1; i<N; i++){
        if(grid[i][start.second]=='#')return pii{num[i][start.second],i-start.first-1};
    }
    return pii{0,N-start.first-1};
}


int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>M;
    grid.resize(N);
    for(int i = 0 ; i < N ; i++){
        grid[i].resize(M);
        for(int j = 0 ; j < M; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#'){
                blocks.eb_(i,j);
            }
        }
    }
    
    vis.resize(N);
    num.resize(N);
    for(int i = 0 ; i < N; i++){
        vis[i].resize(M);
        num[i].resize(M);
    }
    
    
    for(pii b : blocks){
        // cout<<b.first<<" "<<b.second<<endl;
        if(vis[b.first][b.second])continue;
        inc++;
        dfs(b);
    }
    
    //get closest block below it 
    for(pii b : blocks){
        pii close = getNext(b);
        if(num[b.first][b.second]==close.first)continue;
        int a = num[b.first][b.second];
        adj[a].eb_(close);
        adj[close.first].eb_(a,close.second);
    }
    
    //remove duplicates in adj
    for(int i = 0 ; i <= inc ;i++){
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    }
    
    //now do dijkstras :^)
    pq.push({0,0});
    fill(dis,dis+ree,0x3f3f3f);
    dis[0]=0;
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        for(pii v : adj[cur.first]){
            int alt = dis[cur.first]+v.second;
            if(alt<dis[v.first]){
                dis[v.first]=alt;
                pq.push(v);
            }
        }
    }
    
    // for(int i = N-1; i >= 0 ; i--){
    //     for(int j = 0 ; j < M ; j++){
    //         // if(grid[i][j]=='#')cout<<num[i][j]<<endl;
    //     }
    // }
    
    for(int i = blocks.size()-1; i >=0; i--){
        pii cur = blocks[i];
        //cout<<cur.first<<" "<<cur.second<<" "<<dis[num[cur.first][cur.second]]<<endl;
        int amt = dis[num[cur.first][cur.second]];
        grid[cur.first][cur.second]='.';
        grid[cur.first+amt][cur.second]='#';
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j< M ; j++)cout<<grid[i][j];
        cout<<endl;
    }
}
