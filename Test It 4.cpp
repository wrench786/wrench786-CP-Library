#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

ll arr[100007]={0};
vector<ll>primes;

void sieve(){

    for(ll i=4;i<100007;i+=2) arr[i]=1;
    for(ll i=3;i*i<=100007;i+=2){
        if(!arr[i]){
            for(ll j=i*i;j<100007;j+=2*i){
                arr[j]=1;
            }
        }
    }

    for(ll i=2;i<100007;i++){
        if(!arr[i]) primes.push_back(i);
    }
}

// check int overflow
void solve(){
    int ans  =round(0.5);
    cout<<ans<<nn;
    
}

int main()
{
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}