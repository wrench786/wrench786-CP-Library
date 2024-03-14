#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 105;

ll arr[N];

void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>arr[i];

    sort(arr+1,arr+n+1);

    bool ev=0,od=0;
    for(int i=1;i<=n;i++){
        if(arr[i]%2) od=1;
        else ev=1;
    }
    if(ev && od){
        cout<<2<<nn;
        return;
    }

    int gc = 0;
    for(int i=2;i<=n;i++){
        int x = arr[i]- arr[1];
        gc = __gcd(gc, x);
    }
    cout<<gc+arr[1]<<nn;
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