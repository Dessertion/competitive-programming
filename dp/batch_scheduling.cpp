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

int N,S,tp[MN],fp[MN]; 

ll dp[MN];

deque<int> dq;

inline double slope(int j, int k){
    // if(tp[j]==tp[k])return 1.0e18;  
    return 1.0*(1.0*dp[j]-1.0*dp[k])/(1.0*tp[j]-1.0*tp[k]);
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>S;
    for(int i = 1; i<= N ; i++){
        cin>>tp[i]>>fp[i];
    }
    for(int i = N-1; i >= 1; i--){
        tp[i]+=tp[i+1];fp[i]+=fp[i+1];
    }
    
    dq.push_back(N+1);
    for(int i = N; i>= 1; i--){
        while(dq.size()>=2&&slope(dq[0],dq[1])<=fp[i])dq.pop_front();
        dp[i] = dp[dq[0]]+1LL*(S+tp[i]-tp[dq[0]])*fp[i];
        while(dq.size()>=2&&slope(dq[dq.size()-2],dq[dq.size()-1])>=slope(dq[dq.size()-1],i))dq.pop_back();
        dq.push_back(i);
    }
    
    cout<<dp[1]<<endl;
}
