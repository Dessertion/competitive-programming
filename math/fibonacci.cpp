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

const int MOD = 1000000007;
ull N;
unordered_map<ull,int> dp;

void multiplyMatrices(ull fib[2][2], ull mul[2][2]){
    ull a = ((fib[0][0]*mul[0][0])%MOD+(fib[0][1]*mul[1][0])%MOD)%MOD;
    ull b = ((fib[0][0]*mul[0][1])%MOD+(fib[0][1]*mul[1][1])%MOD)%MOD;
    ull c = ((fib[1][0]*mul[0][0])%MOD+(fib[1][1]*mul[1][0])%MOD)%MOD;
    ull d = ((fib[1][0]*mul[0][1])%MOD+(fib[1][1]*mul[1][1])%MOD)%MOD;
    fib[0][0]=a,fib[0][1]=b,fib[1][0]=c,fib[1][1]=d;
}

void raiseToPower(ull fib[2][2],ull p){
    if(p==0||p==1)return;
    ull mul[2][2]={{1,1},{1,0}}; //fibonacci matrix
    raiseToPower(fib,p/2);
    multiplyMatrices(fib,fib);
    if(p%2==1)multiplyMatrices(fib,mul);
}

int getFib(ull n){
    ull fib[2][2] = {{1,1},{1,0}};
    raiseToPower(fib,n-1);
    return fib[0][0];
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    cout<<getFib(N);
    
    
}
