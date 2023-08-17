#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
void solve(){
    vector<string>vec{ "Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    
    int n;
    cin>>n;

    vector<pair<string, string>>dum;

    for(int i=0;i<n;i++){
        string a,b;
        cin>>a;
        for(int j=1;j<6;j++){
            cin>>b;
        }
        dum.push_back({a,b});
    }

    sort(vec.begin(),vec.end());

    do{
        bool flag=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<n;j++){
                string a,b;
                a = dum[j].first;
                b = dum[j].second;

                if(a==vec[i]){
                    bool flag2=0;
                    if( i+1<8 && vec[i+1]==b ) flag2=1;
                    if( i-1>=0 && vec[i-1]==b) flag2=1;
                    if(!flag2) flag=0;

                }
                if(b==vec[i]){
                    bool flag2=0;
                    if( i+1<8 && vec[i+1]==a ) flag2=1;
                    if( i-1>=0 && vec[i-1]==a) flag2=1;

                    if(!flag2) flag=0;

                }
            }

        }
        if(flag){
            for(int i=0;i<8;i++){
                cout<<vec[i]<<nn;
            }
            break;
        }
    }while(next_permutation(vec.begin(),vec.end()));

}

int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}