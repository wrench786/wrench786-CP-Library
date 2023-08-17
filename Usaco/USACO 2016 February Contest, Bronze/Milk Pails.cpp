#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    int x,y,m;
    cin>>x>>y>>m;

    int ans=0;
    for(int i=0;i<=m/x;i++){
        int dum = m - x*i;
        dum = (dum/y)*y;
        ans = max(ans, dum+x*i);
    }
    cout<<ans<<nn;
}

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}