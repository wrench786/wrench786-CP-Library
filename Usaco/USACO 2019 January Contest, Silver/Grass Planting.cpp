#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
int degree[N];

void solve(){
    int n;
    cin>>n;

    int mx=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }
    for(int i=1;i<=n;i++){
        mx = max(mx, degree[i]);
    }
    cout<<mx+1<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}