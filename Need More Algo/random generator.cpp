#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check int overflow
void solve(){
    srand(time(0));
    
    int n = rand()%20;
    int m = rand()%20;
    cout<<n<<" "<<m<<nn;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<rand()%10000<<" ";
        }
        cout<<nn;
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