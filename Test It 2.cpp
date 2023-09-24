#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353


vector<string>vec;

void rec(string str){
    vec.push_back(str);

    for(int i=str[str.size()-1]-'0'-1;i>=0;i--){
        rec(str+(char)(i+'0'));
    }
}

bool cmp(string a,string b){
    if(a.size()<b.size()) return true;
    else if(a.size()>b.size()) return false;
    else{
        if(a<b) return true;
        else return false;
    }
}

void precal(){

    for(int i=9;i>=1;i--){
        string str = "";
        str+=(char)(i+'0');
        rec(str);
    }
    
    sort(vec.begin(),vec.end(),cmp);

    // for(auto x:vec){
    //     cout<<x<<nn;
    // }

}

void solve(){
    int n;
    cin>>n;

    cout<<vec[n-1]<<nn;
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
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}