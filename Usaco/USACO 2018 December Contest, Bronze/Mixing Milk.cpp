#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    int box[3],milk[3];

    for(int i=0;i<3;i++){
        cin>>box[i]>>milk[i];
    }

    for(int i=0;i<100;i++){
        int empty = min(milk[i%3],box[(i+1)%3] - milk[(i+1)%3]);
        milk[i%3]-=empty;
        milk[(i+1)%3]+= empty;
    }
    for(int i=0;i<3;i++){
        cout<<milk[i]<<nn;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}