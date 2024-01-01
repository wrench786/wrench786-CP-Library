#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5;

int segment[N], arr[N];
int n;

void precal(){
    int segment_size = sqrt(n);
    int segment_no=-1;

    for(int i=0;i<n;i++){
        if(i%segment_size==0) segment_no++;
        segment[segment_no]+= arr[i];
    }
}

int query(int l, int r){
    int sum=0;
    int segment_size = sqrt(n);

    // left fraction
    while(l<=r && l%segment_size!=0){
        sum+= arr[l];
        l++;
    }

    // full segment if needed
    while(l+segment_size-1<=r){
        sum+= segment[l/segment_size];
        l+= segment_size;
    }
    // right fraction
    while(l<=r){
        sum+= arr[l++];
    }
    return sum;
}

void update(int idx, int value){
    int segment_size = sqrt(n);

    segment[idx/segment_size] -= arr[idx];
    arr[idx] = value;
    segment[idx/segment_size] += arr[idx];
}

void solve(){
    int q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        segment[i] = 0;
    }

    precal();

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int idx;
            cin>>idx;

            cout<<query(idx,idx)<<nn;
            update(idx,0);
        }
        else if(type==2){
            int idx,value;
            cin>>idx>>value;
            update(idx,arr[idx]+value);
        }
        else{
            int l,r;
            cin>>l>>r;

            cout<<query(l,r)<<nn;
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
    cin>>tc;
    
    int cases=0;
    while(tc--){
        cout<<"Case "<<++cases<<":\n";
        solve();
    }
    return 0;
}