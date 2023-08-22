#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

using namespace std;

// check int overflow4
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>vec(n+1),presum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];

        presum[i] = presum[i-1]+vec[i];
    }

    int sum = presum[k];

    priority_queue<pair<int, int>>pq;
    pq.push({vec[k],k});

    int cost=0;
    for(int i=k-1;i>=1;i--){
        while(presum[i]<sum && pq.size()){
            cost++;
            pair<int,int>a  = pq.top();
            pq.pop();

            sum-= 2*a.first;
            vec[a.second] = -a.first;
        }
    }
    for(int i=1;i<=n;i++){
        presum[i] = presum[i-1]+vec[i];
    }

    for(int i=k+1;i<=n;i++){
        while(presum[i]<sum && )
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