#include <bits/stdc++.h>
using namespace std;
#define pb_ push_back
#define eb_ emplace_back
#define mp_ make_pair
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long,long> pll;
typedef pair<int,int> pii;

ll T,N,K,table[34][34]; //eggs, drops

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>T;
    for(int i = 1; i <=32; i++){
       table[1][i]=i; 
    }
    for(int i = 2; i <=32; i++){
        for(int j = 1; j <=32; j++){
            table[i][j]=table[i][j-1]+table[i-1][j-1]+1;
        }
    }
    for(int i = 0 ; i < T; i++){
        cin>>N>>K;
        bool flag = false;
        for(int j = 1; j<=32; j++){
            if(table[K][j]>=N){
                cout<<j<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)cout<<"Impossible"<<endl;
    }

}
