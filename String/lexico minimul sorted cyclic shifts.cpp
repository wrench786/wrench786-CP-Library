#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

// Check N and init precal in the main and build the sting
const int p1 = 137, p2 = 269, mod1 = 999999937, mod2 = 987654319;
const int N = 2e5+7;

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

int get_lcp(int i,int j, int x, int y){

    int len1 = j-i+1;
    int len2 = y-x+1;

    int l=1, r = min(len1,len2), m, ans=0;

    while(l<=r){
        m = (r+l)/2;

        if(substring_hash(i,i+m-1)==substring_hash(x,x+m-1)){
            ans = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return ans;
}


string s;
// this compare will work for kinds of sting compare
int string_compare(int i,int j, int x, int y){
    int len1 = j-i+1;
    int len2 = y-x+1;

    // now as we know the hash of the main string
    // we dont have to check index by index, we can binary searh
    // to find the longest common prefix then check the lcp+1'th index

    int lcp = get_lcp(i,j,x,y);
    //string are equal
    if(lcp==len1 && len1==len2) return 0;
    //1st string is smaller
    else if(lcp==len1) return -1;
    //2nd string is smaller;
    else if(lcp==len2) return 1;
    // lcp+1 th character will decide who is smaller;
    else return s[i+lcp]-s[x+lcp];
}

int n;
bool cmp(int i, int j){
    int x = string_compare(i,i+n-1,j,j+n-1);

    if(x<0) return true;
    else return false;
}

void solve(){
    cin>>s;

    n = s.size();
    s+=s;
    build_string(s);

    // suppose this is our minimum n lenght string;

    vector<int>vec(n);
    for(int i=0;i<n;i++){
        vec[i]=i;
    }
    sort(vec.begin(),vec.end(),cmp);

    for(int i=0;i<n;i++){
        int start = vec[i];
        if(string_compare(start,start+n-1, 0,n-1)==0){
            cout<<i+1<<nn;
            return;
        }
    }
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