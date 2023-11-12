#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 2e5+7;

int tree[N*4];

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
    
    tree[node] = max(tree[left],tree[right]); // change
}

void tree_update(int node, int ls, int rs, int idx, int value){
    if( idx<ls || rs<idx ) return;
    if( ls==rs && ls==idx ){
        tree[node] = max(tree[node],value);
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_update(left,ls,mid,idx,value);
    tree_update(right,mid+1,rs,idx,value);
    
    tree[node] = max(tree[left],tree[right]); //change
}


int tree_query(int node, int ls, int rs, int x, int y){
    if(ls>y || rs<x) return 0; //change
    if(ls>=x && rs<=y) return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    int res1 = tree_query(left,ls, mid, x, y);
    int res2 = tree_query(right, mid+1, rs, x, y);
    
    return max(res1,res2); //change
}

int n;
int arr[N],dp[N];

void solve(){
    cin>>n;

    set<int>st;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }

    int id=0;
    map<int,int>mp;
    for(auto x:st){
        mp[x] = ++id;
    }
    for(int i=1;i<=n;i++){
        arr[i] = mp[arr[i]];
    }
    
    tree_build(1,1,n);

    for(int i=1;i<=n;i++){
        int x = arr[i];

        dp[i]=1;
        if(x!=1){
            dp[i] = tree_query(1,1,n,1,x-1);
            dp[i]++;
        }
        tree_update(1,1,n,x,dp[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
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
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}