#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 3e3+7;

string a,b;
int n,m;
int dp[N][N];

int lcs(int i, int j){
    // returns the length of lcs from string [i-n) && [j-m)
    if(i==n || j==m) return 0;

    int &ans = dp[i][j];
    if(ans!=-1) return ans;

    ans=0;
    if(a[i]==b[j]){
        ans = 1 + lcs(i+1,j+1);
    }
    else{
        ans = lcs(i+1,j);
        ans = max(ans, lcs(i,j+1));
    }
    return ans;
}

void print_lcs(int i, int j){
    if(i==n || j==m) return;

    if(a[i]==b[j]){
        cout<<a[i];
        print_lcs(i+1,j+1);
    }
    else{
        int dum1 = lcs(i+1,j);
        int dum2 = lcs(i,j+1);

        if(dum1>=dum2) print_lcs(i+1,j);
        else print_lcs(i,j+1);
    }
}

void solve(){
    cin>>a>>b;

    n = a.size();
    m = b.size();

    // recursion
    //memset(dp,-1, sizeof dp);
    //cout<<lcs(0,0)<<nn;
    //print_lcs(0,0);

    //iterative
    memset(dp,0,sizeof dp);


    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j] = 1+ dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    //cout<<dp[0][0]<<nn;

    // printing??????????
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