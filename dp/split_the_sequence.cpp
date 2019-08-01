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


const int MN = 1e5+5;
ll N,M,psa[MN],dp[2][MN];
int reconstruct[205][MN],pre=0,now=1;

int dq[MN],f,r;

inline double slope(int p, int q){
    if(psa[p]==psa[q])return -0x3f3f3f3f;
    return 1.0*(double)(dp[pre][p]-dp[pre][q]+psa[N]*(psa[q]-psa[p]))/(double)(psa[q]-psa[p]);
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i = 1; i <= N; i++){
        cin>>psa[i];
        psa[i]+=psa[i-1];
    }
    
    for(int k = 1; k <= M ; k++){
        //memset(dp[now],-1,sizeof (dp[now]));
        f=r=0;
        for(int i = 1; i <= N; i++){
            while(f<r&&slope(dq[f],dq[f+1])<=psa[i])f++;
            dp[now][i] = dp[pre][dq[f]]+(psa[N]-psa[i])*(psa[i]-psa[dq[f]]);
            reconstruct[k][i]=dq[f];
            
            //for(int j = 0; j < dq.size(); j++)cout<<dq[j]<<" \n"[j==dq.size()-1];
            
            while(f<r&&slope(dq[r-1],dq[r])>=slope(dq[r],i))r--;
            dq[++r]=i;
        }
        pre^=1;now^=1;
    }
    ll ans = -0x3f3f3f;
    int pos = 0;
    for(int i = 1; i<= N; i++){
        if(dp[pre][i]>ans){
            ans = dp[pre][i];
            pos = i;
        }
    }
    cout<<ans<<endl;
    // cout<<pos<<" ";
    for(int k = M; k>=1; k--){
        cout<<pos<<" ";
        pos=reconstruct[k][pos];
    }
}
