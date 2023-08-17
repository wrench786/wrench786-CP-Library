#include <bits/stdc++.h>
#define wrench786 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define PI (acos(-1.0))
#define LIMIT 1000000007
using namespace std;

vector<int>dum(50000,0);
vector<int>prime;

void sieve(){
    int i,j;
    dum[0]=1;
    dum[1]=2;
    for(i=2;i*i<50000;i++){
        if(!dum[i]){
            for(j=i*i;j<50000;j+=i){
                dum[j]=1;
            }
        }
    }
    for(i=2;i<50000;i++){
        if(!dum[i]){
            prime.push_back(i);
        }
    }
}
void pf(int n){
    int i,sqr = sqrt(n);
    for(i=0;prime[i]<=sqr;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                if(n==1){
                    cout<<prime[i]<<"\n";
                }
                else{
                    cout<<prime[i]<<" x ";
                }
            }
        }
        sqr = sqrt(n);
    }
    if(n>1){
        cout<<n<<"\n";
    }
}

int main(){
    wrench786

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    sieve();
    int n;
    while(cin>>n){
        cout<<n<<" = ";
        int co;
        if(n<0){
            cout<<"-1 x ";
            pf(-n);
        }
        else pf(n);
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}