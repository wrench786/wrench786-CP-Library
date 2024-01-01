#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
map<int,vector<pair<int,int>>>g;
int n;

int bfs(int u, vector<int>&d){
    //d.resize(n+1);
    vector<bool>vis(n+1,0);
    queue<int>q;
    q.push(u);
    d[u]=0;
    vis[u] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto [v,w]:g[u]){
            if(!vis[v]){
                vis[v]=1;
                d[v] = d[u]+w;
                q.push(v);
            }
        }
    }
    int node,mx=0;
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            mx = d[i];
            node = i;
        }
    }
    return node;

}

void solve(){
    cin>>n;

    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        u++;v++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        //cout<<u<<" "<<v<<nn;
    }

    vector<int>ds(n+1,0),de(n+1,0);
    int s = bfs(1,ds);
    int e = bfs(s,ds);
    bfs(e,de);

    for(int i=1;i<=n;i++){
        cout<<max(ds[i],de[i])<<nn;
    }

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
        cout<<"Case "<<++cases<<":\n";
        solve();
    }
    return 0;
}