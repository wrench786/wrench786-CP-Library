#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

using namespace std;

ll n;
ll dp[101][100001];
vector<ll>x(101),y(101),z(101);
vector<ll>change,will_get;
ll len,need;

ll rec(ll idx, ll got){
    // min transfer to get need amount of voter

    if(idx==len){
        if(got<need) return INT_MAX;
        else return 0;
    }
    
    if(dp[idx][got]!=-1) return dp[idx][got];

    ll ans = rec(idx+1,got);

    ans = min(ans, rec(idx+1, got+will_get[idx])+change[idx]);

    return dp[idx][got] = ans;
}

// check ll overflow
void solve(){
    cin>>n;

    ll total=0;
    ll have=0;

    memset(dp,-1,sizeof dp);

    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i]>>z[i];
        total+=z[i];

        if(x[i]>y[i]) have+=z[i];
        else{
            ll dum = (x[i]+y[i]+1)/2 - x[i];

            change.push_back(dum);
            will_get.push_back(z[i]);
        }
    }

    // for(auto x:will_get) cout<<x<<" ";
    // cout<<nn;

    ll ans=0;

    //cout<<total<<" "<<have<<nn;

    if((total+1)/2>have){
        need = (total+1)/2 - have;
        len = (ll)change.size();
        
        ans = rec(0,0);
    }

    cout<<ans<<nn;
}

 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}