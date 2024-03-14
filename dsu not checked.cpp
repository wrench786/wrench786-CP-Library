#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
int par[N];

void dsu(){
    for(int i=1;i<N;i++){
        par[i] = i;
    }
}

int find_par(int n){
    if(par[n]!=n){
        par[n] = find_par(par[n]);
    }
    return par[n];
}

void add(int u, int v){
    int par_u = find_par(u);
    int par_v = find_par(v);

    par[v] = u;
}

void solve(){
    dsu();

    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;

        add(u,v);
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