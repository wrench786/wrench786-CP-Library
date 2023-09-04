#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int N = 1e8+7;

using namespace std;

bitset<N>check;

// check int overflow
void solve(){
    int n = N-7;

    check[1]= true;

    vector<int>primes;

    for(int i=2;i*i<=n;i++){
        if(!check[i]){
            for(int j=i*i;j<=n;j+=i){
                check[j] = true;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            primes.push_back(i);
        }
    }
    //for(auto x:primes) cout<<x<<nn;
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