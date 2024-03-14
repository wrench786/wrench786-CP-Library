#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 105;
vector<int> g[N];
int color[N];

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int u=1;u<=n;u++){
        vector<int>dum({1,1,1,1,1});
        for(auto v:g[u]){
            dum[color[v]]=0;
        }
        for(int c=1;c<=4;c++){
            if(dum[c]){
                color[u] = c;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i];
    }
    cout<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}