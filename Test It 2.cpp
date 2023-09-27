#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

void solve(){   
    ll n;
    cin>>n;

    vector<int>x(n),y(n);
    int x_sum=0,y_sum=0;

    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i];

        x_sum+=x[i];
        y_sum+=y[i];
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int presum_x[n+1]={0};
    int presum_y[n+1]={0};

    for(int i=1;i<=n;i++){
        presum_x[i] = presum_x[i-1]+x[i-1];
    }
    for(int i=1;i<=n;i++){
        presum_y[i] = presum_y[i-1]+y[i-1];
    }

    int l = x[0],r = x[n-1],mid,ans=LLONG_MAX, xx;

    while(l<=r){
        mid = (l+r)/2;


    }



    cout<<x<<" "<<y<<nn;
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
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}