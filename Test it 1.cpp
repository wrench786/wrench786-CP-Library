#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

void solve(){
    ll n,x;
    cin>>n>>x;

    vector<ll>vec(n);

    for(ll i=0;i<n;i++){
        cin>>vec[i];
    }

    ll l = 1;
    ll r = 1;

    while(1){
        ll sum=0;
        for(auto x:vec){
            if(r>x){
                sum+= r-x;
            }
        }
        if(sum>x) break;
        r*=2;
    }

    ll m;

    while(r-l>1ll){
        m = (r+l)/2;

        ll dum=x;
        for(ll i=0;i<n;i++){
            if(m>vec[i]){
                dum-= (m-vec[i]);
            }
        }
        if(dum>=0){
            l = m;
        }
        else r = m;
    }
    cout<<l<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}