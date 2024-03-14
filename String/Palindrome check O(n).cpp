#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

// Check N and init precal in the main and build the sting
const int p1 = 137, p2 = 269, mod1 = 999999937, mod2 = 987654319;
const int N = 1e5+7;

pair<int,int> pw[N], ipw[N];

int power(ll base, ll expo, ll mod=1e9+7){
    if(expo==0) return 1;

    int p1 = power(base, expo / 2, mod);

    if(expo % 2 == 0) return 1ll * p1 * p1 % mod;
    else return (1ll * p1 * p1) % mod * base % mod;
}

void precal(){
    pw[0] = {1,1};
    for(int i=1;i<N;i++){
        pw[i].first = 1ll * pw[i-1].first * p1 % mod1;
        pw[i].second = 1ll * pw[i-1].second * p2 % mod2;
    }

    int ip1 = power(p1, mod1-2, mod1);
    int ip2 = power(p2, mod2-2, mod2);

    ipw[0] = {1,1};
    for(int i=1;i<N;i++){
        ipw[i].first = 1ll * ipw[i-1].first * ip1 % mod1;
        ipw[i].second = 1ll * ipw[i-1].second * ip2 % mod2;
    }
}

pair<int,int> forward_hash[N],backward_hash[N];

void build_string(string s){
    int n = s.size();

    for(int i=0;i<n;i++){
        forward_hash[i].first = 1ll * s[i] * pw[i].first % mod1;
        forward_hash[i].second = 1ll * s[i] * pw[i].second % mod2;
        if(i){
            forward_hash[i].first = ( forward_hash[i].first + forward_hash[i-1].first ) % mod1;
            forward_hash[i].second = ( forward_hash[i].second + forward_hash[i-1].second ) % mod2;
        }
    }
    for(int i=0;i<n;i++){
        backward_hash[i].first = 1ll * s[n-i-1] * pw[i].first % mod1;
        backward_hash[i].second = 1ll * s[n-i-1] * pw[i].second % mod2;
        if(i){
            backward_hash[i].first = ( backward_hash[i].first + backward_hash[i-1].first ) % mod1;
            backward_hash[i].second = ( backward_hash[i].second + backward_hash[i-1].second ) % mod2;
        }
    }

}

pair<int,int> forward_substring_hash(int i, int j){
    //assert(i<=j);
 
    pair<int,int>hs ({0,0});

    hs.first = forward_hash[j].first;
    hs.second = forward_hash[j].second;

    if(i){
        hs.first = (forward_hash[j].first - forward_hash[i-1].first + mod1) % mod1;
        hs.second = (forward_hash[j].second - forward_hash[i-1].second + mod2) % mod2;
    }
    hs.first = 1ll * hs.first * ipw[i].first % mod1;
    hs.second = 1ll * hs.second * ipw[i].second % mod2;
    return hs;
}

pair<int,int> backward_substring_hash(int i, int j){
    //assert(i<=j);
 
    pair<int,int>hs ({0,0});

    hs.first = backward_hash[j].first;
    hs.second = backward_hash[j].second;

    if(i){
        hs.first = (backward_hash[j].first - backward_hash[i-1].first + mod1) % mod1;
        hs.second = (backward_hash[j].second - backward_hash[i-1].second + mod2) % mod2;
    }
    hs.first = 1ll * hs.first * ipw[i].first % mod1;
    hs.second = 1ll * hs.second * ipw[i].second % mod2;
    return hs;
}

void solve(){
    string s;
    cin>>s;

    build_string(s);

    int n = s.size();
    int idx=n-1;
    for(int i=1;i<n;i++){
        if(forward_substring_hash(i,n-1)==backward_substring_hash(0,n-i-1)){
            idx = i-1;
            break;
        }
    }
    cout<<s;
    for(int i = idx;i>=0;i--){
        cout<<s[i];
    }
    cout<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precal();
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