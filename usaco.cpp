#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e4+7, K = 1e3+7;
int n,k;
int arr[N];
int dp[N];

int rec(int idx){
    if(idx>=n+1) return 0;

    int &ans = dp[idx];
    if(ans!=-1) return ans;
    ans = 0;
    int mx=0;
    for(int i=idx;i<=min(n,idx+k-1);i++){
        mx = max(mx, arr[i]);
        ans = max(ans, rec(i+1)+(mx*(i-idx+1)));
    }
    return ans;
}

void solve(){
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    // memset(dp,-1,sizeof dp);
    // cout<<rec(1)<<nn;

    for(int idx=n;idx>=1;idx--){
        int ans = 0, mx=0;
        for(int i=idx;i<=min(n,idx+k-1);i++){
            mx = max(mx, arr[i]);
            ans = max(ans, rec(i+1)+(mx*(i-idx+1)));
        }
        dp[idx] = ans;
    }
    cout<<dp[1]<<nn;
}   
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}