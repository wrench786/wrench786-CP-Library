#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000007
using namespace std;

// check int overflow
void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>>vec;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        vec.push_back({a,b});
    }

    bool flag=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int m1 = (vec[j].second - vec[i].second)/(vec[j].first - vec[i].first);
                int m2 = (vec[k].second - vec[i].second)/(vec[k].first - vec[i].first);
                int m3 = (vec[k].second - vec[j].second)/(vec[k].first - vec[j].first);

                if(m1==m2 && m2==m3){
                    cout<<"Yes"<<nn;
                    return;
                }

            }
        }
    }
    cout<<"No"<<nn;
}

int main()
{
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}