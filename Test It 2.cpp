#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    string str;
    cin>>str;

    int arr[26]={0};
    for(int i=0;i<(int)str.size()-1;i++){
        if(str[i]==str[i+1]){
            arr[str[i]-'a']++;
            if(i+2<(int)str.size()){
                arr[str[i+2]-'a']++;
            }
            for(int j=0;j<26;j++){
                if(!arr[j]){
                    str[i+1] = 'a'+j;
                    break;
                }
            }

            for(int j=0;j<26;j++){
                arr[j]=0;
            }
        }
    }
    cout<<str<<nn;
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