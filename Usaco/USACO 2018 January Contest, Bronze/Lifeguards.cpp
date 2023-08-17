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
        int a,b;
        cin>>a>>b;
        vec[i] = {a,b};
    }

    sort(vec.begin(),vec.end());
    int ans=0;

    for(int i=0;i<n;i++){
        int a=0,b=0,cnt=0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(vec[j].first>b) {
                a = vec[j].first;
                b = vec[j].second;
                cnt+= b-a;
            }
            cnt+= vec[j].second-b;
            b = vec[j].second;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<nn;
}

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}