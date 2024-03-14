#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
int n,k;
int arr[N];
int dp[N][4][25];

int rec(int idx, int what, int change){
    if(idx==n+1) return 0;

    int &ans = dp[idx][what][change];
    if(ans!=-1) return ans;
    
    ans = 0;
    bool other=0;
    if(arr[idx]==1 && what==2) other=1;
    if(arr[idx]==2 && what==3) other=1;
    if(arr[idx]==3 && what==1) other=1;


    ans = max(ans, rec(idx+1,what,change));
    if(change){
        if(what==1){
            ans = max(ans, rec(idx+1,2,change-1));
            ans = max(ans, rec(idx+1,3,change-1));
        }
        if(what==2){
            ans = max(ans, rec(idx+1,1,change-1));
            ans = max(ans, rec(idx+1,3,change-1));
        }
        if(what==3){
            ans = max(ans, rec(idx+1,1,change-1));
            ans = max(ans, rec(idx+1,2,change-1));
        }
    }
    ans+=other;
    return ans;
}
    
// h = 1;
// p = 2;
// s = 3;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        if(x=='H') arr[i] = 1;
        if(x=='P') arr[i] = 2;
        if(x=='S') arr[i] = 3;
    }

    // memset(dp,-1,sizeof dp);
    // cout<<max(rec(1,1,k), max(rec(1,2,k),rec(1,3,k)))<<nn;

    memset(dp,0,sizeof dp);
    for(int idx=n;idx>=1;idx--){
        for(int change=0;change<=k;change++){
            for(int what=1;what<=3;what++){
                int ans = 0;
                bool other=0;
                if(arr[idx]==1 && what==2) other=1;
                if(arr[idx]==2 && what==3) other=1;
                if(arr[idx]==3 && what==1) other=1;

                ans = max(ans, dp[idx+1][what][change]);
                if(change){
                    if(what==1){
                        ans = max(ans, dp[idx+1][2][change-1]);
                        ans = max(ans, dp[idx+1][3][change-1]);
                    }
                    if(what==2){
                        ans = max(ans, dp[idx+1][1][change-1]);
                        ans = max(ans, dp[idx+1][3][change-1]);
                    }
                    if(what==3){
                        ans = max(ans, dp[idx+1][1][change-1]);
                        ans = max(ans, dp[idx+1][2][change-1]);
                    }
                }
                ans+=other;
                dp[idx][what][change] = ans;
            }
        }
    }
    cout<<max(dp[1][1][k],max(dp[1][2][k],dp[1][3][k]))<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}