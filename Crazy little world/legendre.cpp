#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

int legendre(int n, int p){
    int ans=0;

    while(n){
        ans+= (n/p);
        n/=p;
    }
    return ans;
}

int again_legendre(int n, int p){
    int ans=0;

    for(int i=p;n/i>=1;i*=p){
        ans+= (n/i);
    }
    return ans;
}

void solve(){
    // how largest x so that given a prime p
    // n/(p^x)

    int x = legendre(n,p);
    x = again_legendre(n,p);
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