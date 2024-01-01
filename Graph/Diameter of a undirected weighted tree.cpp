#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
map<int,vector<pair<int,int>>>g;
int d[N];

void dfs(int u, int p, int cost){
    d[u] = d[p]+cost;

    for(auto [v,w]:g[u]){
        if(v!=p){
            dfs(v,u,w);
        }
    }
}

void solve(){
    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        u++;v++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        //cout<<u<<" "<<v<<nn;
    }
    int mx=0, s_node, e_node, ans;
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            mx = d[i];
            s_node = i;
        }
        d[i]=0;
    }
    dfs(s_node,0,0);
    mx=0;
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            mx = d[i];
            e_node = i;
        }
        d[i]=0;
    }
    cout<<mx<<nn;

    g.clear();
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    int cases=0;
    while(tc--){
        cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}