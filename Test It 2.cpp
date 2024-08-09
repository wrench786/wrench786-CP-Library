#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// const long max_rand = 1000000L;

// check int overflow
void solve(){
    srand(time(0));
    
    int n = (rand()%1000)+1;
    int m = (rand()%1000)+1;
    n = 1000;
    m = 1000;
    cout<<n<<" "<<m<<nn;

    string dhur = "";
    for(int i=1;i<=m;i++) dhur+='.';
    
    vector<string>vec;
    for(int i=1;i<=n;i++){
        vec.push_back(dhur);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool yo = rand()%2;
            if(yo){
                yo = rand()%2;
                if(yo){
                    yo = rand()%2;
                    if(yo)vec[i][j]='#';
                }
            }
        }
    }

    int x1=0,y1=0,x2=0,y2=0;
    while(x1==x2 && y1==y2){
        x1 = (rand()%n);
        y1 = (rand()%m);

        x2 = (rand()%n);
        y2 = (rand()%m);
    }

    vec[x1][y1] = 'H';
    vec[x2][y2] = 'V';

    for(auto x:vec) cout<<x<<nn;

    
    // unordered_map<int,double>mp;
    // while(mp.size()!=n){
    //     double lower_bound = 0;
    //     double upper_bound = 100;
    //     double random_double = lower_bound
    //                            + (upper_bound - lower_bound)
    //                                  * (random() % max_rand)
    //                                  / max_rand;
     
    //     int x = rand()%1000;
    //     mp[x]= random_double;
    // }
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