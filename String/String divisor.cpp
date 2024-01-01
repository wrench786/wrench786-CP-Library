#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int p1 = 137, p2 = 269, mod1 = 999999937, mod2 = 987654319;
const int N = 1e6+7;

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

pair<int,int> pref[N];

void build_string(string s){
    int n = s.size();

    for(int i=0;i<n;i++){
        pref[i].first = 1ll * s[i] * pw[i].first % mod1;
        pref[i].second = 1ll * s[i] * pw[i].second % mod2;

        if(i){
            pref[i].first = ( pref[i].first + pref[i-1].first ) % mod1;
            pref[i].second = ( pref[i].second + pref[i-1].second ) % mod2;
        }
    }
}

pair<int,int> substring_hash(int i, int j){
    //assert(i<=j);
 
    pair<int,int>hs ({0,0});

    hs.first = pref[j].first;
    hs.second = pref[j].second;

    if(i){
        hs.first = (pref[j].first - pref[i-1].first + mod1) % mod1;
        hs.second = (pref[j].second - pref[i-1].second + mod2) % mod2;
    }
    hs.first = 1ll * hs.first * ipw[i].first % mod1;
    hs.second = 1ll * hs.second * ipw[i].second % mod2;
    return hs;
}

vector<int> string_divisor(string s){
    vector<int>ans;
    int n = s.size();
    
    for(int len=1;len<=n;len++){
        bool flag=1;
        for(int i=0;i+len-1<n;i+=len){
            flag &= substring_hash(0,len-1)==substring_hash(i,i+len-1);
        }
        if(n%len){
            int r = n%len;

            flag &= substring_hash(0,r-1)==substring_hash(n-r,n-1);
        }
        if(flag) ans.push_back(len);
    }
    return ans;
}

void solve(){
    string s;
    cin>>s;

    precal();
    build_string(s);

    vector<int>divisors = string_divisor(s);

    for(auto x : divisors){
        cout<<x<<" ";
    }
    cout<<nn;
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
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}