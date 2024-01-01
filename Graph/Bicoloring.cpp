#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

vector<int>g[205];
bool bicolorable;
int color[205];
int vis[205];

void dfs(int u){
    vis[u] = 1;

    for(auto v:g[u]){
        if(!vis[v]){
            color[v] = color[u] ^ 1;
            dfs(v);
        }
        else{
            if(color[u]==color[v]){
                bicolorable = false;
            }
        }
    }
}

void solve(){
    int n;
    while(cin>>n && n){
        int m;
        cin>>m;

        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }
        bicolorable = true;

        dfs(0);
        for(int i=0;i<205;i++){
            vis[i] = 0;
            color[i] = 0;
            g[i].clear();
        }

        if(bicolorable) cout<<"BICOLORABLE."<<nn;
        else cout<<"NOT BICOLORABLE."<<nn;


    }
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