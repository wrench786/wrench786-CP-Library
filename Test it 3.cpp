#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    int n,t;
    cin>>n>>t;

    int k;
    cin>>k;

    int l=1, r = n, m, ans;
    while(l<=r){
        m = (l+r)/2;
        cout<<"? 1 "<<m<<endl;

        int x;
        cin>>x;

        if(x==-1){
            return;
        }
        int zero = m-x;
        if(zero>k) r = m-1;
        else if(zero==k){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    cout<<"! "<<ans<<endl;
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