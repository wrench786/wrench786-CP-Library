#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

int extended_euclid(int a, int b, int &x, int &y){
    int xx = y = 0;
    int yy = x = 1;

    while(b){
        int q = a/b;
        int tmp = a%b; a = b; b = tmp;

        tmp = xx; xx = x - q*xx; x = tmp;
        tmp = yy; yy = y - q*yy; y = tmp;
    }
    return a;
}

void solve(){
    int x,y;
    cout<<extended_euclid(5,25,x,y)<<" "<<x<<" "<<y;
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