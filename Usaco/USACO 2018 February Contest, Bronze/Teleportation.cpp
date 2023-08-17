#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    // if(a>b) swap(a,b);
    // if(x>y) swap(x,y);

    int ans = abs(b-a);

    ans = min(ans, abs(x-a)+abs(y-b));
    ans = min(ans, abs(y-a)+abs(x-b));

    cout<<ans<<nn;
}

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);
    while(tc--){
        solve();
    }
    return 0;
}