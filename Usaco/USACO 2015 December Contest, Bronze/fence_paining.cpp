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

    if(y<=a || b<=x) cout<<b-a+y-x<<nn;
    else cout<<max(b,y)-min(a,x)<<nn;
}

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ll tc=1;
    //scanf("%d",&tc);
    while(tc--){
        solve();
    }
}   