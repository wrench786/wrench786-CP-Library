#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

#define mx 1000000

ll tree[mx*4];
ll lazy[mx*4];
int arr[mx];

void push(int node, int ls, int rs){ // change
    if(lazy[node]==0){
        return;
    }

    tree[node] = (lazy[node] * tree[node])%mod;

    if(ls!=rs){
        int left = node*2;
        int right = node*2+1;
        int mid = (ls+rs)/2;

        lazy[left] = (lazy[left] * lazy[node])%mod;
        lazy[right] = (lazy[right] * lazy[node])%mod;
    }
    lazy[node]=1;
}

void tree_build(int node, int ls, int rs){
    lazy[node]=1;
    
    if(ls==rs){
        tree[node] = 1;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);
        
    tree[node] = (tree[left]+tree[right])%mod; // change
}

void tree_update(int node, int ls, int rs, int l, int r, int value){
    push(node, ls, rs);

    if( r<ls || rs<l ) return;
    if(l<=ls && rs<=r){
        lazy[node]*=value;
        push(node, ls, rs);
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,l,r,value);
    tree_update(right,mid+1,rs,l,r,value);
        
    tree[node] = (tree[left]+tree[right])%mod; // change
}


ll tree_query(int node, int ls, int rs, int l, int r){
    push(node,ls,rs);

    if(ls>r || rs<l) return 0ll; //change
    if(l<=ls && rs<=r) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    ll res1 = tree_query(left,ls, mid, l,r);
    ll res2 = tree_query(right, mid+1, rs, l, r);
    
    return (res1+res2)%mod; //change
}

// check int overflow
void solve(){
    int n,q;
    cin>>n>>q;

    //for(int i=1;i<=n;i++) cin>>arr[i];

    tree_build(1,1,n);

    // for(int i=1;i<=n;i++){
    //     cout<<tree_query(1,1,n,i)<<" ";
    // }
    // cout<<nn;

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int l,r,value;
            cin>>l>>r>>value;

            tree_update(1,1,n,l+1,r,value);

            // for(int i=1;i<=n;i++){
            //     cout<<tree_query(1,1,n,i)<<" ";
            // }
            // cout<<nn;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}