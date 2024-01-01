#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;

int a[N];
int w[N];

void solve(){
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        // contribution Technique
        // LOJ = 1369
        w[i] = n+1-2*i;
        cin>>a[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+= 1ll*w[i]*a[i];
    }
    while(q--){
        int type;
        cin>>type;

        if(type==0){
            int idx, v;
            cin>>idx>>v;

            sum+= -1ll*w[idx+1]*a[idx+1];
            a[idx+1]=v;
            sum+= 1ll*w[idx+1]*a[idx+1];
        }
        else{
            cout<<sum<<nn;
        }
    }
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
        cout<<"Case "<<++cases<<":\n";
        solve();
    }
    return 0;
}