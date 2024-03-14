#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    string gg = s[0]+t;

    int ans = 1;

    for(int i=1;i<n;i++){
        if(gg[i]!=s[i]){
            if(s[i]=='1'){
                break;
            }
            else{
                gg[i] = s[i];
                ans=1;
            }
        }
        else{
            ans++;
        }
    }
    cout<<gg<<nn;
    cout<<ans<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}