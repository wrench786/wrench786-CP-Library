#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int inf = 1e9+7;
const int N = 1e5+7;

map<int,vector<int>>g;
int indeg[101];

void solve(){
    int n,m;
    while(cin>>n>>m && n+m){
        g.clear();
        memset(indeg,0,sizeof indeg);

        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;

            g[u].push_back(v);

            indeg[v]++;
        }

        queue<int>q;

        for(int i=1;i<=n;i++){
            if(!indeg[i]) q.push(i);
        }

        vector<int>ans;

        while(ans.size()!=n){
            if(q.empty()){
                cout<<"Mara"<<nn;
                return;
            }

            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(auto v:g[u]){
                indeg[v]--;
                if(!indeg[v])q.push(v);
            }
        }
        for(auto x:ans){
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
        //cout<<"Scenario #"<<++cases<<":"<<nn;
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}