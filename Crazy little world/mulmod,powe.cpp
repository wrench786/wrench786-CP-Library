#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

ll mulmod(ll a, ll n, ll mod){
    if(n==0) return 0ll;

    ll p1 = mulmod(a,n/2,mod);
    if(n%2==0) return (p1 + p1) % mod;
    else return ((p1 + p1) % mod + a) % mod;
}

ll power(ll base, ll expo, ll mod=1e9+7){
    if(expo==0) return 1;

    ll p1 = power(base, expo / 2, mod);
    if(expo % 2 == 0) return  mulmod(p1,p1,mod);
    else return mulmod(mulmod(p1,p1,mod),base,mod);
}
ll inverse(ll n, ll mod){
    return power(n,mod-2,mod);
}


void solve(){
    ll a,b,mod;
    cin>>a>>b>>mod;

    cout<<power(a,b,mod)<<nn;
    cout<<mulmod(a,b,mod)<<nn;
    cout<<mulmod(a,inverse(b,mod),mod)<<nn;
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