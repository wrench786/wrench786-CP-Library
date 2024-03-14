#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5;
int arr[N];

/// using double stack to make a queue  
void solve(){
    int m;
    cin>>m;

    int n=0,x;

    while(cin>>x && x!=-1){
        arr[++n] = x;
    }

    //using multiset
    // multiset<int, greater<int>>st;
    // for(int i=1;i<m;i++){
    //     st.insert(arr[i]);
    // }
    // for(int i=m;i<=n;i++){
    //     st.insert(arr[i]);
    //     int x = *(st.begin());
    //     cout<<x<<nn;
    //     st.erase(st.find(arr[i-m+1]));
    // }

    //using double stack to create a queue like structure
    stack<pair<int,int>>s1,s2;

    for(int i=1;i<m;i++){
        int num = arr[i];
        int mx = arr[i];

        if(s1.size()){
            mx = max(mx,s1.top().second);
        }
        s1.push({num,mx});
    }

    for(int i=m;i<=n;i++){
        // insert from array to stack
        int num = arr[i];
        int mx = arr[i];
        if(s1.size()){
            mx = max(mx,s1.top().second);
        }
        s1.push({num,mx});

        // output the max
        if(!(int)s1.size()){
            cout<<s2.top().second<<nn;
        }
        else if(!(int)s2.size()){
            cout<<s1.top().second<<nn;
        }
        else cout<<max(s1.top().second, s2.top().second)<<nn;

        // delete from the first element of m element
        if((int)s2.size()){
            s2.pop();
        }
        else{
            while(!s1.empty()){
                int num = s1.top().first;
                int mx = num;
                s1.pop();

                if(s2.size()){
                    mx = max(mx,s2.top().second);
                }
                s2.push({num,mx});               
            }
            s2.pop();
        }
    }
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