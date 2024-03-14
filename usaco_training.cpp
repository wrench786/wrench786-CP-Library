/*
ID: wrench71
TASK: milk2
LANG: C++14              
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e6+7;
int arr[N];

void solve(){
    int n,mn=N,mx=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        int s,e;
        cin>>s>>e;
        mn = min(mn,s);
        mx = max(mx,e);
        arr[s]++;
        arr[e]--;
    }
    int one=0,zero=0,sum=0,one_cnt=0,zero_cnt=0;

    for(int i=mn;i<=mx;i++){
        if(sum==0 && i!=mn){
            //cout<<i<<nn;
            zero_cnt++;
            zero = max(zero, zero_cnt);
            one_cnt=0;
        }
        sum+= arr[i];
        if(sum){
            one_cnt++;
            one = max(one, one_cnt);
            zero_cnt=0;
        }
        else{
            one_cnt=0;
        }
    }
    cout<<one<<" "<<zero<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}