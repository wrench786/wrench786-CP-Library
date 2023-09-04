#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int N = 1e6+7;

using namespace std;

int spf[N];

void precal(){
    for(int i=1;i<N;i++) spf[i]=i;

    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            spf[j] = min(spf[j],i);
        }
    }
}

void solve(){
    precal();

    int n;
    while(cin>>n && n!=0){
        int dum = n;
        int cnt=0;

        while(n>1){
            int x = spf[n];
            cnt++;
            while(n%x==0){
                n/=x;
            }
        }
        cout<<dum<<" : "<<cnt<<nn;
    }
}


 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    // /cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}