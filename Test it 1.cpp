#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

#define mx 1000000

int tree[mx*4];
int min_count[mx*4];
int arr[mx];

void tree_build(int node, int ls, int rs){
    if(ls==rs){
        tree[node] = arr[ls];
        min_count[node] = 1;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    tree_build(left,ls,mid);
    tree_build(right,mid+1,rs);

    tree[node] = min( tree[left], tree[right]); // change
    
    if(tree[left]<tree[right]){
        min_count[node] = min_count[left];
    }
    else if(tree[left]>tree[right]){
        min_count[node] = min_count[right];
    }
    else min_count[node] = min_count[left]+min_count[right];
    
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
    
    tree[node] = min( tree[left], tree[right]); // change

    if(tree[left]<tree[right]){
        min_count[node] = min_count[left];
    }
    else if(tree[left]>tree[right]){
        min_count[node] = min_count[right];
    }
    else min_count[node] = min_count[left]+min_count[right];
}


pair<int,int> tree_query(int node, int ls, int rs, int x, int y){
    if(ls>y || rs<x) return make_pair(INT_MAX,0); //change
    if(ls>=x && rs<=y) return make_pair(tree[node],min_count[node]);
    
    int left = node*2;
    int right = node*2+1;
    int mid = (ls+rs)/2;

    pair<int,int>res1 = tree_query(left,ls, mid, x, y);
    pair<int,int>res2 = tree_query(right, mid+1, rs, x, y);
    
    int mn = min(res1.first,res2.first);
    int cnt=0;

    if(mn==res1.first) cnt+= res1.second;
    if(mn==res2.first) cnt+= res2.second;

    return make_pair(mn,cnt);
}

// check int overflow
void solve(){
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>arr[i];

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

            pair<int,int>ans =  tree_query(1,1,n,l+1,r);

            cout<<ans.first<<" "<<ans.second<<nn;

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