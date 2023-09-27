#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

void solve(){
    double rt,rj,st,sj;
    cin>>rt>>rj>>st>>sj;    

    vector<double>vec;

    for(int i=1;i<=max(rt,rj);i++){
        vec.push_back((i-1)/st);
    }
    for(int i=1;i<=max(rt,rj);i++){
        vec.push_back((i-1)/sj);
    }
    sort(vec.begin(),vec.end());


    double t = (rt-1.0)/st;
    double j = (rj-1.0)/sj;

    for(auto x:vec){
        if(x==t){
            if(x==j){
                cout<<"SAME"<<nn;
                return;
            }
            else{
                cout<<"TAOYUAN"<<nn;
                return;
            }
        }
        else if(x==j){
            cout<<"JAKARTA"<<nn;
            return;
        }
    }

    // if(rt==1 && st!=1){
    //     cout<<"TAOYUAN"<<nn;
    //     return;
    // }
    // else if(st==1 && rt!=1){
    //     cout<<"JAKARTA"<<nn;
    //     return;
    // }

    // if(t<j) cout<<"TAOYUAN"<<nn;
    // else if(t>j) cout<<"JAKARTA"<<nn;
    // else cout<<"SAME"<<nn;
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
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}