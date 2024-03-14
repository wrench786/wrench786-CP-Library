#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e6+7;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> arr[k+10];

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        arr[x].push_back(i);
    }

    int ans = n;
    for(int i=1;i<=k;i++){
        int a=0,b=0,prev=0;

        if(!(int)arr[i].size())continue;
        for(int j=0;j<(int)arr[i].size();j++){
            int diff = arr[i][j]-prev-1;
            if(diff>=a){
                int tmp = a;
                a = diff;
                diff = tmp;
            }
            if(diff>=b) b = diff;
            prev = arr[i][j];
        }
        if(arr[i][(int)arr[i].size()-1]!=n){
            int diff = n-prev;
            if(diff>=a){
                int tmp = a;
                a = diff;
                diff = tmp;
            }
            if(diff>=b) b = diff;
        }        
        a/=2;
        ans = min(ans, max(a,b));
    }
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