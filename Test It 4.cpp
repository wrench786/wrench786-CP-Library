#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5,inf = 1e5;

int segment[N], arr[N];
int n;

void precal(){
    int segment_size = sqrt(n);
    int segment_no=-1;

    for(int i=0;i<n;i++){
        if(i%segment_size==0) segment_no++;
        segment[segment_no] = max(segment[segment_no] , arr[i]);
    }
}

int query(int l, int r){
    int mx=0;
    int segment_size = sqrt(n);

    // left fraction
    while(l<=r && l%segment_size!=0){
        mx = max(mx,arr[l++]);
    }

    // full segment if needed
    while(l+segment_size-1<=r){
        mx = max(mx, segment[l/segment_size]);
        l+= segment_size;
    }
    // right fraction
    while(l<=r){
        mx = max(mx,arr[l++]);
    }
    return mx;
}

void solve(){
    int m;
    cin>>m;

    int x;
    n=-1;
    while(cin>>x && x!=-1){
        arr[++n] = x;
    }
    n++;

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<nn;

    precal();

    for(int i=0;i+m-1<n;i++){
        cout<<query(i,i+m-1)<<nn;
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
        //cout<<"Case "<<++cases<<":\n";
        solve();
    }
    return 0;
}