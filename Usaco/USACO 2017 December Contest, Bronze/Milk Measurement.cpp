#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

vector<string>cows{"Bessie", "Elsie", "Mildred"};
int milk[3],top[3];

void solve(){
    int n;
    cin>>n;

    vector<pair<int,pair<int,int>>>vec;

    for(int i=0;i<n;i++){
        int day, x;
        string s;
        char ch;
        cin>>day>>s>>ch>>x;
        if(ch=='-') x = -x;

        for(int j=0;j<3;j++){
            if(cows[j]==s){
                vec.push_back({day,{j,x}});
            }
        }
    }
    for(int i=0;i<3;i++){
        milk[i] = 7;
        top[i] = 1;
    }

    int ans=0;
    for(int i=1;i<=100;i++){
        for(int j=0;j<n;j++){
            if(i==vec[j].first){
                milk[vec[j].second.first]+= vec[j].second.second;

                int dum=0;
                for(int k=0;k<3;k++){
                    dum = max(dum,milk[k]);
                }
                bool flag=0;
                for(int k=0;k<3;k++){
                    if((milk[k]==dum && !top[k]) || (milk[k]!=dum && top[k])){
                        flag=1;
                    }
                    top[k] = milk[k]==dum;
                }
                if(flag) ans++;
                break;
            }
        }
    }
    cout<<ans<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}