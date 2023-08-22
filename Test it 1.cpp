#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

using namespace std;

// check int overflow4
void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll>vec(n+1);
    for(ll i=1;i<=n;i++){
        cin>>vec[i];
    }

    ll cost=0;
    priority_queue<ll>pq;

    ll sum=0;
    for(ll i=m;i>=2;i--){
        sum+=vec[i];

        if(vec[i]<=0) continue;

        pq.push(vec[i]);

        while(sum>0 && pq.size()){
            ll x = pq.top();
            pq.pop();

            sum-= (2*x);
            cost++;
        }
    }

    while(!pq.empty()) pq.pop();

    sum=0;
    for(ll i=m+1;i<=n;i++){
        sum+=vec[i];

        if(vec[i]>=0) continue;

        pq.push(-vec[i]);

        while(sum<0 && pq.size()){
            ll x = pq.top();
            pq.pop();

            sum+= (2*x);
            cost++;
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