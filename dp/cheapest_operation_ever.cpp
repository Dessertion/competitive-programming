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

const int MN =1e5+5;

ull N,H,crim[MN],last=1,dis,dp[MN];

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N>>H;
    for(int i = 1; i <= N ; i++){
        cin>>crim[i];
    }
    sort(crim,crim+N);
    
    dp[0]=0;
    dp[1]=H;    
    for(int i = 2; i <=N; i++){
        ull ans = 0x3f3f3f3f;
        for(int j = last; j<=i ;j++){
            if(H+dp[j-1]+(ull)pow(crim[i]-crim[j],2) <= ans){
                ans = H+dp[j-1]+(ull)pow(crim[i]-crim[j],2);
                last = j;
            }
        }
        dp[i]=ans;
    
    }    
    //for(int i = 0; i <= N; i++)cout<<dp[i]<<endl;
    cout<<dp[N]<<endl;
    
}
