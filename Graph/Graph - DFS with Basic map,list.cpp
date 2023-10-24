#include <bits/stdc++.h>
#define wrench786 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define PI (acos(-1.0))
#define LIMIT 1000000
#define eps 0.000000001
#define pb push_back
#define dot(x) fixed<<setprecision(x)
#define f first
#define s second
using namespace std;

bool visited[100];
unordered_map<int , list<int>>adj;

void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;

    for(auto x : adj[i]){
        dfs(x);
    }
}

int main(){
    wrench786

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int nodes,edges,x,y,i;
    cin>>nodes>>edges; 
    for(i=0;i<edges;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int co=0;
    for(i=1;i<=nodes;i++){
        if(visited[i]==false){
            dfs(i);
            co++;
        }
    }
    cout<<co<<endl;


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}