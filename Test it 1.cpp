#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

#define mx 1000000

ll tree[mx*4];
ll prop[mx*4];

void push(int node, int ls, int rs){
    if(ls!=rs){
        int left = node*2;
        int right = node*2+1;
        int mid = (ls+rs)/2;

        prop[left] += prop[node];
        prop[right] += prop[node];

        tree[left] += prop[node]*(mid-ls+1);
        tree[right] += prop[node]*(rs-mid);

    }
    prop[node]=0;
}

void tree_build(int node, int ls, int rs){
    if(ls==rs){
        tree[node] = 0;
        prop[node] = 0;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);
        
    tree[node] = tree[left]+tree[right]; // change
}

void tree_update(int node, int ls, int rs, int l, int r, int value){
    push(node, ls, rs);

    if( r<ls || rs<l ) return;
    if(l<=ls && rs<=r){
        tree[node]+= (rs-ls+1)*value;
        prop[node]+= value;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,l,r,value);
    tree_update(right,mid+1,rs,l,r,value);
        
    tree[node] = tree[left]+tree[right]; //change
}


ll tree_query(int node, int ls, int rs, int l, int r){
    push(node,ls,rs);

    if(ls>r || rs<l) return 0ll; //change
    if(ls<=l && r<=rs) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    ll res1 = tree_query(left,ls, mid, l, r);
    ll res2 = tree_query(right, mid+1, rs, l, r);
    
    return max(res1,res2); //change
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

            tree_update(1,1,n,l,r,value);

            // for(int i=1;i<=n;i++){
            //     cout<<tree_query(1,1,n,i)<<" ";
            // }
            // cout<<nn;
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<tree_query(1,1,n,l,r)<<nn;
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