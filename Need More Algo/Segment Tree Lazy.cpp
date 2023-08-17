#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

#define mx 1000000

vector<pair<int, int>>tree(mx*4);
vector<int>vec(mx);
int cases=0;

void tree_create(int node,int ss, int ee){
    tree[node].second=0;

    if(ss==ee){
        tree[node].first = vec[ss];
        return;
    }
    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    tree_create(left,ss,mid);
    tree_create(right,mid+1,ee);
    
    tree[node].first = tree[left].first +tree[right].first;
}

void tree_update(int node, int ss, int ee, int x, int y, int val){
    if(ss>y || ee<x) return;

    if(x<=ss && ee<=y){ 
        tree[node].second+= val;
        tree[node].first+= ((ee-ss+1)*val);
        return;
    }

    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    tree_update(left, ss, mid, x, y , val);
    tree_update(right, mid+1, ee, x, y , val);

    tree[node].first = tree[left].first + tree[right].first + (tree[node].second*(ee-ss+1));
}

int tree_query(int node, int ss, int ee, int x, int y, int carry){
    if(ss>y || ee<x) return 0;

    if(x<=ss && ee<=y){
        return tree[node].first+(ee-ss+1)*carry;
    }

    int left = node*2;
    int right = node*2+1;

    int mid = (ss+ee)/2;

    carry+= tree[node].second;

    int p1 = tree_query(left, ss, mid, x, y, carry);
    int p2 = tree_query(right, mid+1, ee, x, y, carry);

    return p1+p2;
}

// check int overflow
void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>vec[i];
    tree_create(1,1,n);
    tree_update(1,1,n,1,4,2);
    

    for(int i=1;i<100;i++){
        cout<<tree[i].first<<nn;
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