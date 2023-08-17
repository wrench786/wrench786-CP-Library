#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    int m,n;
    cin>>m>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        int dum[n+1]={0};

        for(int j=0;j<m;j++){
            bool flag=0;
            for(int k=0;k<n;k++){
                if(arr[j][k]==i) flag=1;
                else if(flag){
                    dum[arr[j][k]]++;
                    if(dum[arr[j][k]]==m) ans++;
                }
            }
        }
    }
    cout<<ans<<nn;
}

int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}