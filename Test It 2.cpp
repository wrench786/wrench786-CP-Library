#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
    
#define mx 1000000

ll tree[mx*4];
int arr[mx];

void tree_build(int node, int ls, int rs){
    if(ls==rs){
        tree[node] = arr[ls];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);
    
    tree[node] = tree[left]+tree[right]; // change
}

void tree_update(int node, int ls, int rs, int idx, int value){
    if( idx<ls || rs<idx ) return;
    if( ls==rs && ls==idx ){
        tree[node] = value;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,idx,value);
    tree_update(right,mid+1,rs,idx,value);
    
    tree[node] = tree[left]+tree[right]; //change
}


ll tree_query(int node, int ls, int rs, int x, int y){
    if(ls>y || rs<x) return 0; //change
    if(ls>=x && rs<=y) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    ll res1 = tree_query(left,ls, mid, x, y);
    ll res2 = tree_query(right, mid+1, rs, x, y);
    
    return res1+res2; //change
}


// check int overflow
void solve(){
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    tree_build(1,1,n);

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int idx, value;
            cin>>idx>>value;

            tree_update(1,1,n,idx+1,value);
        }
        else{
            int l,r;
            cin>>l>>r;

            cout<<tree_query(1,1,n,l+1,r)<<nn;
        }
    }
}   

int main()
{

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}