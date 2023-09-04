#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int N = 1e6+7;

using namespace std;

int spf[N];

void solve(){
    for(int i=1;i<N;i++) spf[i]=i;

    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            spf[j] = min(spf[j],i);
        }
    }
}


 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    // /cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}