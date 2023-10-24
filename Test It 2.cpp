#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int N = 2e5+7;

int arr[N];

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int brr[n+1]={0};

    for(int i=1;i<=n-2;i++){
        if(arr[i]>=arr[i+1] && arr[i+1]>=arr[i+2]){
            brr[i]=1;
        }
    }

    int presum[n+1]={0};

    for(int i=1;i<=n;i++){
        presum[i] = presum[i-1]+brr[i];
    }

    while(m--){
        int l,r;
        cin>>l>>r;

        int ans = r-l+1;
        int cnt = presum[r]-presum[l-1];

        for(int i=r;i>=r-1 && i>=l;i--){
            if(brr[i]) cnt--;
        }
        
        cout<<ans-cnt<<nn;

    }
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