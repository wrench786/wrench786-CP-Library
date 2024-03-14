/*
ID: wrench71
TASK: ride
LANG: C++14              
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int mod = 47;

void solve(){
	string a,b;
	cin>>a>>b;

	int aa=1,bb=1;
	for(auto ch:a){
		aa = aa * (ch-'A'+1) % mod;
	}
	for(auto ch:b){
		bb = bb * (ch-'A'+1) % mod;
	}
	if(aa!=bb) cout<<"STAY"<<nn;
	else cout<<"GO"<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}