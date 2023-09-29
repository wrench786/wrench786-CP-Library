#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

const int N = 105+7;

int spf[N];
int arr[N];

void precal(){

    for(int i=1;i<N;i++) spf[i]=i;

    for(int i=2;i*i<=N;i++){
        for(int j = i+i;j<N;j+=i){
            spf[j] = min(i,spf[j]);
        }
    }
}

void solve(){
    int n;
    cin>>n;

    int ans=0;

    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int yo=1;
    set<int>gg;

    for(int i=0;i<n;i++){
        int x = vec[i];

        set<int>st;

        while(x>1){
            int p = spf[x];
            while(x%p==0){
                x/=p;
            }
            //cout<<p<<nn;
            st.insert(p);
        }
        int par=0;

        for(auto x:st){
            if(arr[x]){
                par = arr[x];
                break;
            }
        }
        if(par==0){
            par=yo++;
        }
        
        gg.insert(par);
    }
    cout<<gg.size()<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precal();
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}