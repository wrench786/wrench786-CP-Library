#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000007
using namespace std;

template<typename T>
class graph{
public:
    unordered_map<T, list<T>> adj;

    graph(){
    }

    void push_edge(T n1, T n2, bool bidirect = true){
        adj[n1].push_back(n2);
        if(bidirect){
            adj[n2].push_back(n1);
        }
    }

    void graph_print(){
        for(auto row: this->adj){
            cout<<row.first<<" -> ";
            for(auto x:row.second){
                cout<<x<<" ";
            }
            cout<<nn;
        }
    }
};


// check int overflow
void solve(){
    graph<int>gg;
    gg.push_edge(1,2);
    gg.push_edge(2,3);
    gg.push_edge(3,1);
    gg.push_edge(2,4);

    gg.graph_print();
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