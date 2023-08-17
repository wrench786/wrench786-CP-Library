#include <bits/stdc++.h>
#define wrench786 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define PI (acos(-1.0))
#define LIMIT 50000
#define pb push_back
#define dot(x) fixed<<setprecision(x)
using namespace std;

bool not_prime[LIMIT+1];
vector<ll int>primes;

void sieve(){
    ll int i,j;
    for(i=3;i*i<=LIMIT;i+=2){
        if(!not_prime[i]){
            for(j=i*i;j<=LIMIT;j+=2*i){
                not_prime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(i=3;i<=LIMIT;i+=2){
        if(!not_prime[i]) primes.pb(i);
    }
}

void seg_sieve(int l,int r){
    ll int i,j,x,current_prime,siz = r-l+1;
    bool arr[siz];
    for(i=0;i<siz;i++) arr[i] = false;
    if(l==1) arr[0] = true;
    for(i=0; primes[i]*primes[i]<=r ;i++){
        current_prime = primes[i];
        x = ((l + current_prime -1)/current_prime)*current_prime;
        if(x==current_prime) x+=current_prime;
        for(j=x;j<=r;j+=current_prime){
            arr[j-l] = true;
        }
    }
    vector<ll int>vec;
    for(i=0;i<siz;i++){
        if(!arr[i]) vec.pb(i+l);
    }
    ll int l1,l2,h1,h2,minim=0,maxim=0,prime1,prime2;
    for(i=0;i<vec.size()-1 && vec.size()>1;i++){
        prime1 = vec[i];
        prime2 = vec[i+1];
        if(!i){
            l1 = prime1;
            h1 = prime1;
            l2 = prime2;
            h2 = prime2;
            minim = prime2-prime1;
            maxim = minim;
        }
        else if(prime2-prime1<minim){
            minim = prime2-prime1;
            l1 = prime1;
            l2 = prime2;
        }
        else if(prime2-prime1>maxim){
            maxim = prime2-prime1;
            h1 = prime1;
            h2 = prime2;
        }
    }
    if(minim+maxim) cout<<l1<<","<<l2<<" are closest, "<<h1<<","<<h2<<" are most distant."<<endl;
    else cout<<"There are no adjacent primes."<<endl;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    sieve();
    ll int l,r;
    while(cin>>l>>r){
        seg_sieve(l,r);
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}