#include <bits/stdc++.h>
#define pb_ push_back
#pragma GCC optimize ("Ofast")

using namespace std;

const int MN = 5e3+5,MM = 1e5+5;

int N,M,fence[MM],ans,dp[MN];

int flowers[MN];

int doDP(int idx){
    if(dp[idx])return dp[idx];
    if(idx==N)return 0;
    int ret = 0x3f3f3f3f;
    for(int i = 1; i<= M; i++){
        auto itr = lower_bound(flowers,flowers+N,flowers[idx]+i)-flowers;
        ret = min(ret,doDP(itr)+fence[i]);
    }
    return dp[idx] = ret;
}

int main(){
    cin.tie(0),cout.tie(0),cout.sync_with_stdio(0);
    cin>>N>>M;
    for(int i = 0 ; i< N; i ++){
        int t;
        cin>>t;
        flowers[i]=t;
    }
    sort(flowers,flowers+N);
    
    for(int i = 1; i <=M; i++){
        cin>>fence[i];
    }
    
    for(int i = N-1; i>=0; i--){
        dp[i] = 0x3f3f3f3f;
        for(int j = 1; j<=M; j++){
            auto itr = lower_bound(flowers,flowers+N,flowers[i]+j)-flowers;
            dp[i]=min(dp[i],dp[itr]+fence[j]);
        }
    }
    cout<<dp[0];
    
    //cout<<doDP(0);
    
    return 0;
}