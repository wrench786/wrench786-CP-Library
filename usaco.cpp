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

    vector<int>vec(n-1);

    for(int i=0;i<n-1;i++){
        cin>>vec[i];
    }

    for(int i=1;i<=n;i++){
        int dum = i, arr[n+1]={0}, flag=1;
        arr[dum]++;
        for(int j=0;j<n-1;j++){
            dum = vec[j]-dum;

            if(dum<1 || dum>n){
                flag=0;
                break;
            }

            arr[dum]++;
        }

        for(int j=1;j<=n;j++){
            if(arr[j]!=1) flag=0;
        }

        if(flag){
            int dum = i;
            cout<<dum;
            for(int j=0;j<n-1;j++){
                dum = vec[j]-dum;
                cout<<" "<<dum;
            }
            cout<<nn;
            break;
        }
    }
}

int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}