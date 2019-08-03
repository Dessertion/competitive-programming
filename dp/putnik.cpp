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

const int MN = 1505;

int N,adj[MN][MN],dp[MN][MN];


int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    for(int i = 0 ; i <  N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>adj[i][j];
            dp[i][j]=0x3f3f3f3f;
        }
    }
    dp[0][0]=0;
    int ans = 0x3f3f3f3f;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j< N; j++){
            int cur = max(i,j)+1;
            dp[i][cur]=min(dp[i][cur],dp[i][j]+adj[j][cur]);
            dp[cur][j]=min(dp[cur][j],dp[i][j]+adj[i][cur]);
        }
    }
    for(int i = 0 ; i <  N; i++)ans = min(ans,dp[i][N-1]);
    cout<<ans;
}