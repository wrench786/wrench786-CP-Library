#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
bool not_prime[N];
vector<int>primes;

void sieve(){
    for(int i=2;i*i<=N;i++){
        if(!not_prime[i]){
            for(int j=i+i;j<N;j+=i){
                not_prime[j]=1;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(!not_prime[i]) primes.push_back(i);
    }
}
void seg_sieve(int l, int r){
    bool is_prime[r-l+10];
    memset(is_prime,0,sizeof is_prime);

    if(l==1)l++;
    for(auto p:primes){ 
        if(p*p>r) break;
        
        int num = ((l+p-1)/p)*p;
        for(int i=num;i<=r;i+=p){
            is_prime[i-l] = 1;
        }
        if(num==p) is_prime[p-l] = 0;
    }
    for(int i=0;i<r-l+1;i++){
        if(!is_prime[i])cout<<(l+i)<<nn;
    }
    cout<<nn;
}


void solve(){
    int l,r;
    cin>>l>>r;
    
    seg_sieve(l,r);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
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