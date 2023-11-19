#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int p1 = 137, p2 = 269, mod1 = 999999989, mod2 = 987654319;
const int N = 1e5+7;

pair<int,int> pw[N];

void precal(){
    pw[0] = {1,1};
    for(int i=1;i<N;i++){
        pw[i].first = 1ll * pw[i-1].first * p1 % mod1;
        pw[i].second = 1ll * pw[i-1].second * p2 % mod2;
    }
}

pair<int,int> string_hash(string str){
    int n = str.size();
    pair<int,int>hs({0,0});
    
    for(int i=0;i<n;i++){
        hs.first += 1ll * str[i] * pw[i].first % mod1;
        hs.first %= mod1;
        
        hs.second += 1ll * str[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }

    return hs;
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