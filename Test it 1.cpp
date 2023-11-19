#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"


void solve(){
    int n;
    cin>>n;

    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    reverse(vec.begin(),vec.end());
    int mn=vec[0];

    //cout<<mn<<nn;
    int ans=0;
    for(int i=1;i<n;i++){
        int num = vec[i];
        if(num<mn){
            mn = num;
        }
        else if(num>mn){
            stack<int>q;
            q.push(num);
            map<int,int>mp;

            bool flag=0;
            while(!q.empty()){
                int x = q.top();
                q.pop();

                if(x>mn){
                    ans++;
                    int a = x/2;
                    int b = x-a;

                    if(!mp[a]){
                        q.push(a);
                        mp[a]=1;
                    }
                    q.push(b);

                }   
                else{
                    mn = min(mn, x);
                }
            }
        }
    }
    cout<<ans<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}