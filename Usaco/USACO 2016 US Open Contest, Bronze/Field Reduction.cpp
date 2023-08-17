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

    vector<pair<int, int>>vec(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        vec[i]= {x,y};
    }

    int ans= INT_MAX;

    for(int i=0;i<n;i++){
        int mx_x=0,mx_y=0,mn_x=INT_MAX, mn_y=INT_MAX;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int x = vec[j].first;
            int y = vec[j].second;

            if(x<mn_x) mn_x = x;
            if(x>mx_x) mx_x = x;

            if(y<mn_y) mn_y = y;
            if(y>mx_y) mx_y = y;
        }

        int area = (mx_x-mn_x)*(mx_y-mn_y);
        ans = min(ans, area);
    }

    cout<<ans<<nn;
}

int main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}