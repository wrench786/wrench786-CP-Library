#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

ll ans[1000007];

void solve(){
    ll n,p;
    cin>>n>>p;

    //cout<<n<<" "<<p<<nn;

    //cout<<n<<" "<<p<<nn;

    vector<pair<ll,ll>>vec(n);

    vector<ll>a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];

        vec[i] = {b[i],a[i]};
    }
    sort(vec.begin(),vec.end());

    for(ll i=0,j=1;i<n;i++){
        ll len = vec[i].second;
        ll cost = vec[i].first;

        if(j==n) break;
        while(len){
            ans[j++] = cost;
            len--;
            if(j==n) break;
        }
        if(j==n) break;
    }
    // for(ll i=0;i<n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<nn;

    //cout<<n<<" "<<p<<nn;

    // ll total = p;
    // for(int i=1;i<n;i++){
    //     total+= ans[i];
    // }


    // ll sum=0;
    // ll dum_total = total;
    // for(int i=n-1;i>=1;i--){
    //     sum+= ans[i];

    //     ll dum = dum_total - sum + (n-i)*p;
    //     total = min(total,dum);
    // }

    //cout<<total<<nn;
    

    ans[0] = p;
    ll res=p;
    for(ll i=1;i<n;i++){
        ans[i] = min(ans[i],(i+1)*p);
        res+= 1ll*ans[i];
    }
    cout<<res<<nn;

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