#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int inf = 1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;

    map<int,vector<int>>g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int start, end;
    cin>>start>>end;

    vector<int>d(n,inf);
    queue<int>q;
    d[start]=0;
    q.push(start);

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
    int ans=0,idx;
    for(int i=0;i<n;i++){
        if(i!=start && i!=end){
            idx = i;
            ans = max(ans, d[i]);
        }
        d[i]=inf;
    }
    
    d[idx]=0;
    q.push(idx);

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
    ans+= d[end];

    cout<<ans<<nn;   
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
        cout<<"Case "<<++cases<<":";
        solve();
    }
    return 0;
}