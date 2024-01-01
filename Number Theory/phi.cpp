#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

int phi(int n){

    int ans = n;
    for(int i = 2;i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)n /= i;
            ans -= (ans / i);
        }
    }
    if(n>1){
        ans -= (ans / n);
    }
    return ans;
}
const int N = 1e6+7;
int phi[N];
void phi_1_to_n(int n){
    for(int i=0;i<N;i++) phi[i]=i;

    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]-= (phi[j]/i);
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        int coprime = phi(num);
        cout<<coprime<<nn;
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