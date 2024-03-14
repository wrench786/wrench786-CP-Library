#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7, K=100;

vector<int>g[N];
int n,k;

int dp[N][K];

// dp[i][j] means if i take i as a root of tree,
// how many different j sized subtree are there?

void dfs(int u, int p){

    dp[u][1] = 1;

    int dp_buffer[k+1]={0};
    dp_buffer[0] = 1;

    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u);

            int tmp[k+1] = {0};
            for(int i=0;i<=k;i++){
                for(int j=0;j<=k-i;j++){
                    tmp[i+j] += dp_buffer[i] * dp[v][j]; 
                }
            }
            for(int i=0;i<=k;i++){
                dp_buffer[i] = tmp[i];
            }
        }
    }
    for(int i=1;i<=k;i++){
        dp[u][i] = dp_buffer[i-1];
    }
    //dp[u][1] = 2;
}

void solve(){
    cin>>n>>k;

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,1);

    int total=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            total+=dp[i][j];
        }
    }
    cout<<total<<nn;

    for(int i=0;i<=k;i++){
        cout<<dp[2][i]<<" ";
    }
    cout<<nn;
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