#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

int power(ll base, ll expo, ll mod=1e9+7){
    if(expo==0) return 1;

    int res = power(base, expo / 2, mod);
    res = (1ll * res * res) % mod;
    if(expo % 2){
        res = ( 1ll * res * base) % mod;
    }
    return res;
}

// this one is done but not tested
int power(ll base, ll expo, ll mod=1e9+7){
    int res = 1;
    while(expo){
        if(expo%2==1) res = (1ll * res * base)%mod;
        base = (1ll * base * base)%mod;
        expo/=2;
    }
    return res;
}

void solve(){
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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