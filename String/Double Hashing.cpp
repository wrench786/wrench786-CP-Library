#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int p1 = 137, p2 = 269, mod1 = 999999989, mod2 = 987654319;
const int N = 1e5+7;

int pw1[N], pw2[N];

void precal(){
    pw1[0]=1;
    for(int i=1;i<N;i++){
        pw1[i] = 1ll * pw1[i-1] * p1 % mod1;
    }
    pw2[0]=1;
    for(int i=1;i<N;i++){
        pw2[i] = 1ll * pw2[i-1] * p2 % mod2;
    }
}

pair<int,int> string_hash(string str){
    int n = str.size();
    int hs1 = 0, hs2 = 0;

    for(int i=0;i<n;i++){
        hs1 += 1ll * str[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }
    for(int i=0;i<n;i++){
        hs2 += 1ll * str[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }
    return {hs1,hs2};
}

void solve(){
    string a,b;
    cin>>a>>b;

    pair<int,int>aa = string_hash(a);
    pair<int,int>bb = string_hash(b);

    if(aa.first==bb.first && aa.second == bb.second) cout<<1<<nn;
    else cout<<0<<nn;

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precal();
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}