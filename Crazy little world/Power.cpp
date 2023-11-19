#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

int power(ll base, ll expo, ll mod=1e9+7){
    if(expo==0) return 1;

    int p1 = power(base, expo / 2, mod);
    if(expo % 2 == 0){
        return 1ll * p1 * p1 % mod;
    }
    else{
        return (1ll * p1 * p1) % mod * base % mod;
    }
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