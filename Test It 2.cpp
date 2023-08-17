#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

using namespace std;

// check int overflow4
void solve(){
    ll m, k, a, b;
    cin>>m>>k>>a>>b;

    ll ss = min(m/k, b);
    b-=ss;

    ll ans = ss*k;
    ll rem = m - ans;

    ll cost=0;

    if(rem-a>0){
        if(rem<k)cost+= (rem-a);
        else{
            ll dum = (rem-a)/k;
            
            cost = dum;
            rem-=dum*k;

            if(rem>a){
                if(rem>k){
                    rem-=k;
                    rem-=a;
                    cost+=rem;
                }
                else{
                    rem-=a;
                    cost+=rem;
                }
            }
        }
    }
    cout<<cost<<nn;
}
 
int main()
{
 
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}