#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e6+7;
bool not_prime[N];
vector<int>primes;
void sieve(){
    not_prime[1]=1;

    for(int i=2;i*i<=N;i++){
        if(!not_prime[i]){
            for(int j=i+i;j<N;j+=i){
                not_prime[j]=1;
            }
        }
    }
    for(int i=1;i<N;i++){
        if(!not_prime[i]) primes.push_back(i);
    }
}

void solve(){
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}