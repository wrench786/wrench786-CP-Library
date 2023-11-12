#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    string str;
    cin>>str;

    int n = str.size();

    stack<char>st;

    for(auto x:str){
        if(x=='C'){
            if(st.size()>=2){
                char b = st.top();
                st.pop();
                char a = st.top();
                st.pop();
                //cout<<a<<" "<<b<<nn;

                if(a=='A' && b=='B') continue;
                else{
                    st.push(a);
                    st.push(b);
                    st.push('C');
                }
            }
            else{
                st.push(x);
            }
        }
        else{
            st.push(x);
        }
    }
    vector<char>vec;

    while(!st.empty()){
        char x = st.top();
        vec.push_back(x);
        st.pop();
    }
    reverse(vec.begin(),vec.end());
    for(auto x:vec){
        cout<<x;
    }
    cout<<nn;
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