#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
vector<int>g[N];
int par[N], color[N];
bool cycle;
vector<int>path;

void dfs(int u){
    color[u] = 1;
    for(auto v:g[u]){
        if(!color[v]){
            par[v] = u;
            dfs(v);
        }
        else if(color[v]==1 && !cycle){
            cycle = true;
            int yo = u;
            while(yo!=v){
                path.push_back(yo);
                yo = par[yo];
            }
            path.push_back(v);
            path.push_back(u);
            reverse(path.begin(),path.end());
        }
    }
    color[u]=2;
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    cycle = false;

    for(int i=1;i<=n;i++){
        if(!color[i])dfs(i);
    }

    if(cycle){
        cout<<path.size()<<nn;
        for(auto x:path){
            cout<<x<<" ";
        }
        cout<<nn;
    }
    else cout<<"IMPOSSIBLE"<<nn;
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