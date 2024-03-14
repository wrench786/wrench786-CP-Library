#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

void solve(){
    int x,y;
    cin>>x>>y;

    int total=0;
    for(int i=0;;i++){
        int yo = (1<<i);

        if(x<y){
            if(i%2==0){
                if(x+yo>=y){
                    total+=(y-x);
                    break;
                }
                else total+=yo*2;
            }
            else{
                total+= 2*yo;
            }
            //cout<<total<<nn;
        }
        else{
            if(i%2==0){
                total+= 2*yo;
            }
            else{
                if(x-yo<=y){
                    total+= x-y;
                    break;
                }
                else total+=yo*2;
            }
        }
    }
    cout<<total<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}