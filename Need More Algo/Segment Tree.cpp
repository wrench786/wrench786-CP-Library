#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

#define mx 1000000

vector<int>tree(mx*4);
vector<int>vec(mx);

void tree_create(int node,int ss, int ee){
    if(ss==ee){
        tree[node] = vec[ss];
        return;
    }
    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    tree_create(left,ss,mid);
    tree_create(right,mid+1,ee);
    
    tree[node] = tree[left]+tree[right];
}

void tree_update(int node,int ss, int ee, int x, int val){
    if(x<ss || ee<x) return;
    if(ss==x){
        tree[node] = vec[val];
        return;
    }
    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    tree_update(left,ss,mid,x,val);
    tree_update(right,mid+1,ee,x,val);
    
    tree[node] = tree[left]+tree[right];
}


int tree_query(int node, int ss, int ee, int x, int y){
    if(ss>y || ee<x) return 0;
    if(ss>=x && ee<=y) return tree[node];
    
    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    int res1 = tree_query(left,ss, mid, x, y);
    int res2 = tree_query(right, mid+1, ee, x, y);
    
    return res1+res2;
}

// check int overflow
void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>vec[i];

    tree_create(1,1,n);
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