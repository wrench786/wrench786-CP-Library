#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    int n = 1e6;

    priority_queue<int>pq;
    pq.push(n);

    while(!pq.empty()){
        int x = pq.top();
        pq.pop();

        if(x>2){
            int a = x/2;
            int b = x-a;
            pq.push(a);
            pq.push(b);
        }
        else break;
    }
    cout<<pq.size()<<nn;
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