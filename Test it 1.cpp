#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

using namespace std;

// check int overflow4
void solve(){
    string str;
    cin>>str;

    int n = str.size();

    string a = string(n,'(') + string(n,')');
    string b ="";

    for(int i=1;i<=n;i++){
        b+='(';
        b+=')';
    }
    //hi

    if(str=="()") cout<<"NO"<<nn;
    else{
        cout<<"YES"<<nn;

        int flag=0;
        for(int i=0;i<n-1;i++){
            if(str[i]==str[i+1]) flag=1;
        }

        if(flag)cout<<b<<nn;
        else cout<<a<<nn;
    }
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