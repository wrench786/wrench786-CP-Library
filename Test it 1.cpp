#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

#define mx 1000000

struct number
{
    int zero,one,two;
};

number tree[mx*4];
int lazy[mx*4];

void push(int node, int ls, int rs){ // change
    // check for lazy[node] value???

    int dum=lazy[node];
    while(dum--){
        int temp = tree[node].two;
        tree[node].two = tree[node].one;
        tree[node].one = tree[node].zero;
        tree[node].zero = temp;
    }    

    if(ls!=rs){
        int left = node*2;
        int right = node*2+1;
        int mid = (ls+rs)/2;

        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[left]%=3;
        lazy[right]%=3;
    }
    lazy[node]=0;
}

number merge(number left, number right){
    number ans;

    ans.zero = left.zero+right.zero;
    ans.one = left.one+right.one;
    ans.two = left.two+right.two;

    return ans;
}

void tree_build(int node, int ls, int rs){
    // lazy[node] = blah... if we want to change all lazy nodes value
    lazy[node]=0;
    if(ls==rs){
        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=1;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);
        
    tree[node] = merge(tree[left],tree[right]); // change
}

void tree_update(int node, int ls, int rs, int l, int r, int value){
    push(node, ls, rs);

    if( r<ls || rs<l ) return;
    if(l<=ls && rs<=r){
        lazy[node]+= value;
        lazy[node]%=3;
        push(node, ls, rs);
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,l,r,value);
    tree_update(right,mid+1,rs,l,r,value);
        
    tree[node] = merge(tree[left],tree[right]); //change
}


number tree_query(int node, int ls, int rs, int l, int r){
    push(node,ls,rs);

    if(ls>r || rs<l) return {0,0,0}; //change
    if(l<=ls && rs<=r) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    number res1 = tree_query(left,ls, mid, l, r);
    number res2 = tree_query(right, mid+1, rs, l, r);
    
    return merge(res1,res2); //change
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

        if(type==0){
            int l,r;
            cin>>l>>r;

            tree_update(1,1,n,l+1,r+1,1);

            // for(int i=1;i<=n;i++){
            //     cout<<tree_query(1,1,n,i)<<" ";
            // }
            // cout<<nn;
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<tree_query(1,1,n,l+1,r+1).zero<<nn;
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
        cout<<"Case "<<++cases<<":"<<nn;
        solve();
    }
    return 0;
}