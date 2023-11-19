#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int inf = 1e9+7, N = 1e5+7;
map<int,vector<int>>g;
int d[N];

void solve(){
    int n,m;
    cin>>n>>m;

    g.clear();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        //cout<<u<<" "<<v<<nn;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    cin>>start;

    for(int i=1;i<=n;i++){
        d[i]= inf;
    }

    queue<int>q;
    q.push(start);
    d[start]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v:g[u]){
            if(d[u]+1<d[v]){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
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