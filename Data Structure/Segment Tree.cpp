#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007

const int mx = 1e6;

int tree[mx*4];
int arr[mx];

int merge(int left, int right){
    return left+right;
}

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
    
    tree[node] = merge(tree[left],tree[right]); // change
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
    
    tree[node] = merge(tree[left],tree[right]); //change
}


int tree_query(int node, int ls, int rs, int x, int y){
    if(ls>y || rs<x) return 0; //change
    if(ls>=x && rs<=y) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    int res1 = tree_query(left,ls, mid, x, y);
    int res2 = tree_query(right, mid+1, rs, x, y);
    
    return merge(res1,res2); //change
}

// check int overflow
void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>arr[i];

    tree_build(1,1,n);
    //change 5 th number to 10;
    tree_update(1,1,n,5,10);


    int result = tree_query(1,1,n,3,4);
    cout<<result<<nn;
    // for(int i=1;i<16;i++){
    //     cout<<i << " " << tree[i]<<nn;
    // }
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