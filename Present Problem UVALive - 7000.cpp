#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

// check ll overflow
int cases=0;

void solve() {
    int n,m,l;
    cin>>n>>m>>l;

    map<int, vector<int>>mp;
    map<pair<int, int> , int> direction;

    for(int i=0;i<m;i++){
        int col, row;
        cin>>col>>row;
        row--;

        mp[col].push_back(row);
        mp[col+1].push_back(row);

        direction[{row,col}]=1;
        direction[{row,col+1}]=-1;
    }
    for(auto it = mp.begin(); it!=mp.end(); it++){
        sort((*it).second.begin(), (*it).second.end());
    }

    for(int i=0;i<n;i++){
        int place = i,k=-1;
        while(1){
            if(mp[place].size() &&  upper_bound(mp[place].begin(),mp[place].end(),k)-mp[place].begin()<mp[place].size()){
                k = *upper_bound(mp[place].begin(), mp[place].end(),k);

                place+= direction[{k,place}];
            }
            else break;
        }
        cout<<place<<nn;
    }
}

int main()
{
    // freopen("teleport.in", "r", stdin);
    // freopen("teleport.out", "w", stdout);
    int tc = 1;
    cin >> tc;
    //scanf("%d",&tc);
    
    while (tc--) {
        //cout<<"Case "<<cases++<<": ";
        solve();
    }
    return 0;
}