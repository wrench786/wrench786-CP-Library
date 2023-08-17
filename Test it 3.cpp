#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

using namespace std;

// check int overflow4
void solve(){
    int n;
    cin>>n;

    vector<int>vec(n+1,0);
    int ans[n+1]={0};

    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }

    int mn = INT_MAX;
    int mn2 = mn;
    bool flag=0;

    for(int i=1;i<=n;i++){
        if(vec[i]<mn){
            mn = vec[i];
            ans[i] = 0;
        }
        else if(vec[i]<mn2 && vec[i]>mn){
            mn2 = vec[i];
            ans[i]=1;
        }
        else{
            ans[i]=0;
        }
        
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+= ans[i];
    }
    cout<<cnt<<nn;
}
 
int main()
{
 
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}