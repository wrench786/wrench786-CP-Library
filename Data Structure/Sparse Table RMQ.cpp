#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int MX = 1e6+7, LOG = 20;

int table[MX][LOG];
int arr[MX];

void table_build(int n){
    for(int i=1;i<=n;i++){
        table[i][0] = arr[i];
    }

    for(int j=1;j<=LOG;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int prev = (1<<(j-1));
            table[i][j] = min( table[i][j-1], table[i+prev][j-1]);
        }
    }
}

int table_query(int l, int r){
    int len=1,pw=0;
    while(len*2<=r-l+1){
        len*=2;
        pw++;
    }
    return min(table[l][pw],table[r-len+1][pw]);
}

void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    table_build(n);

    int m;
    cin>>m;

    while(m--){
        int l, r;
        cin>>l>>r;
        cout<<table_query(l+1,r+1)<<nn;
    }
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