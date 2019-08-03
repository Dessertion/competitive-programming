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


char thing[10][10];
bool vis[10][10];
int dis[10][10];
pii X;

int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool check(pii a){
    if(a.first>=10||a.first<0||a.second>=10||a.second<0)return false;
    if(vis[a.first][a.second])return false;
    if(thing[a.first][a.second]=='#')return false;
    return true;
}


int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    for (int t = 0; t < 5; t++){
        for(int i = 0 ; i < 10 ;i++){
            for(int j = 0 ; j < 10; j++){
                cin>>thing[i][j];
                if(thing[i][j]=='X')X={i,j};
            }
        }
        queue<pii> q;
        q.push(X);
        memset(vis,0,sizeof (vis));
        memset(dis,0,sizeof(dis));
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            // cout<<x<<" "<<y<<endl;
            //cout<<dis[x][y]<<endl;
            vis[x][y]=true;
            if(thing[x][y]=='X'&&dis[x][y]!=0){
                cout<<dis[x][y]<<endl;
                break;
            }
            for(auto d : dir){
                if(!check({x+d[0],y+d[1]}))continue;
                vis[x+d[0]][y+d[1]]=true;
                dis[x+d[0]][y+d[1]]=dis[x][y]+1;
                q.push({x+d[0],y+d[1]});
            }
        }
        string s;
        cin>>s;
    }
        
}
