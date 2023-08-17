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

    string str;
    cin>>str;

    map<string, int>mp;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            mp[str.substr(i,j-i+1)]++;
        }
    }

    int ans=1,len=0;
    for(auto it = mp.begin(); it!=mp.end();it++){
        string str = (*it).first;
        int cnt = (*it).second;

        if(cnt>1) ans = max(ans, (int)str.size()+1);
    }

    cout<<ans<<nn;

}

int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}