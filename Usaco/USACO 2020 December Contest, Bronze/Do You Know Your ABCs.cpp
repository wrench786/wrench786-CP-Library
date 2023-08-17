#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    int arr[7];
    for(int i=0;i<7;i++) cin>>arr[i];

    sort(arr,arr+7);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[6]-arr[0]-arr[1]<<nn;
}

int main()
{
    // freopen("teleport.in", "r", stdin);
    // freopen("teleport.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);
    while(tc--){
        solve();
    }
    return 0;
}