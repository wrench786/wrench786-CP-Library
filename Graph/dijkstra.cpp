#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
const ll inf = 1e11+7;
vector<pair<int,int>> g[N];
int par[N];
int n,m;

vector<ll> dijkstra(int start){
    vector<ll>d(n+1,inf);
    vector<bool>vis(n+1,false);

    priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> >pq;
    pq.push({0,start});
    d[start] = 0;

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int u = x.second;
        if(vis[u]) continue;

        vis[u] = 1;
        for(auto x:g[u]){
            int v = x.first;
            int w = x.second;
            
            if(d[u]+w<d[v]){
                d[v] = d[u]+w;
                pq.push({d[v],v});
                par[v] = u;
            }
        }
    }

    return d;
}

void solve(){
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    auto d = dijkstra(1);

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<d[i]<<nn;
    // }

    if(d[n]==inf) cout<<-1<<nn;
    else{
        vector<int>path;

        int node = n;

        while(node){
            path.push_back(node);
            node = par[node];
        }
        reverse(path.begin(),path.end());
        for(auto x:path){
            cout<<x<<" ";
        }
        cout<<nn;
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