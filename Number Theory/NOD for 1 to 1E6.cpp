#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e6+7;
int d[N];

void precal(){
    for(int i=1;i<N;i++) d[i]=0;

    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            d[j]++;
        }
    }
}

void solve(){
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