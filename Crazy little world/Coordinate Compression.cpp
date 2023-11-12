#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;

int arr[N];

void solve(){
    int n;
    cin>>n;

    set<int>st;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    int id=0;
    map<int,int>mp;

    for(auto x:st){
        mp[x] = ++id;
    }
    for(int i=1;i<=n;i++){
        arr[i] = mp[arr[i]];
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