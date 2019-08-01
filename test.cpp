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


struct nd{
  int val;  
};

void ree(nd *a){
    a = 0;
}

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    nd *b = new nd{55};
    cout<<b<<endl;
    ree(b);
    cout<<b<<endl;
    nd a{55};
    nd *c = &a;
    cout<<&c<<endl;
    ree(c);
    cout<<&c<<endl;
}
