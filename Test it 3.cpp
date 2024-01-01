#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int mx = 1e6+7;

int tree[mx*4];
int arr[mx];

int merge(int left, int right){
    return left+right;
}

void tree_build(int node, int ls, int rs){
    if(ls==rs){
        tree[node] = 0;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);
    
    tree[node] = merge(tree[left],tree[right]); // change
}

void tree_update(int node, int ls, int rs, int idx){
    if( idx<ls || rs<idx ) return;
    if( ls==rs && ls==idx ){
        tree[node]++;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,idx);
    tree_update(right,mid+1,rs,idx);
    
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

void solve(){
    int n;
    cin>>n;

    vector<int>vec(n+1);
    set<int>st;
    for(int i=1;i<=n;i++){
        cin>>vec[i];
        st.insert(vec[i]);
    }
    int id=0;
    map<int,int>mp;

    for(auto x:st){
        mp[x] = ++id;
    }
    for(int i=1;i<=n;i++){
        vec[i] = mp[vec[i]];
    }

    tree_build(1,1,n);

    ll ans=0;
    for(int i=1;i<=n;i++){
        int x = vec[i];
        if(x<n) ans+= 1ll*tree_query(1,1,n,x+1,n);
        tree_update(1,1,n,x);
    }
    cout<<ans<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}