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

const int MAX = 2e6+10;

int N,cnt=0;
set<int> se;
vector<int> v;
int check[MAX];

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>N;
    for(int i = 0 ; i < N; i++){
        int a;cin>>a;
        se.insert(a);
        check[a]++;
    }
    v.assign(se.begin(),se.end());
    for(int i = 0 ; i < v.size(); i++){
        if(check[v[i]]>1&&check[v[i]*2])cnt++;
        for(int j = 0; j<i; j++){
            if(check[v[i]+v[j]])cnt++;
        }
    }
    if(cnt)cout<<cnt;
    else cout<<"-1";
    return 0;
}
