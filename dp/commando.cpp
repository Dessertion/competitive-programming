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

const int MN = 1e6+5;

ll N,a,b,c,arr[MN],psa[MN],last=1;

ll dp[MN];

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    cin>>a>>b>>c;
    for(int i = 1; i <=N;i ++){
        cin>>arr[i];
        psa[i]=arr[i]+psa[i-1];
    }
    
    
    
    for(int i = 1; i <=N;i++){
        ll ans = -0x3f3f3f3f;
        for(int j = last; j<=i; j++){
            ll x = psa[i]-psa[j-1];
            ll temp = (a*x*x+b*x+c)+dp[j-1];
            if(ans<=temp){
                last=j;
                ans=temp;
            }
        }
        dp[i]=ans;
            
    }
    cout<<dp[N];
    
    return 0;
}
