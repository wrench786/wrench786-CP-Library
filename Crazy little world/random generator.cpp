#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

const long max_rand = 1000000L;

// check int overflow
void solve(){
    srand(time(0));
    
    int n = 3+(rand()%(10000-3));

    cout<<n<<nn;
    
    unordered_map<int,double>mp;
    while(mp.size()!=n){
        double lower_bound = 0;
        double upper_bound = 100;
        double random_double = lower_bound
                               + (upper_bound - lower_bound)
                                     * (random() % max_rand)
                                     / max_rand;
     
        int x = rand()%1000;
        mp[x]= random_double;
    }
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