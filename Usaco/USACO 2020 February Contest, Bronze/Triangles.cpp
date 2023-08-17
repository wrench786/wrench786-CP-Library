#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    int n;
    cin>>n;

    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(x[i]==x[j] && y[j]==y[k]) ans = max(ans, abs(y[i]-y[j])*abs(x[j]-x[k]));
                if(x[i]==x[k] && y[k]==y[j]) ans = max(ans, abs(y[i]-y[k])*abs(x[k]-x[j]));

                if(x[j]==x[i] && y[i]==y[k]) ans = max(ans, abs(y[j]-y[i])*abs(x[i]-x[k]));
                if(x[j]==x[k] && y[k]==y[i]) ans = max(ans, abs(y[j]-y[k])*abs(x[k]-x[i]));

                if(x[k]==x[i] && y[i]==y[j]) ans = max(ans, abs(y[k]-y[i])*abs(x[i]-x[j]));
                if(x[k]==x[j] && y[j]==y[i]) ans = max(ans, abs(y[k]-y[j])*abs(x[j]-x[i]));
            }
        }
    }
    cout<<ans<<nn;
}

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);
    while(tc--){
        solve();
    }
    return 0;
}