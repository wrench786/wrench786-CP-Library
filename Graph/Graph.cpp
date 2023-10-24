#include <bits/stdc++.h>
#define wrench786 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define PI (acos(-1.0))
#define LIMIT 1000000
#define eps 0.000000001
#define pb push_back
#define dot(x) fixed<<setprecision(x)
#define f first
#define s second
using namespace std;

template<typename T>
class Graph{
public:
     Graph(){
     }

     unordered_map<T, list<T>> adj;

     void add_edge(T n1, T n2, bool bi_direct = true){
        adj[n1].push_back(n2);
        if(bi_direct){
            adj[n2].push_back(n1);
        }
     }
     void print(){
        for(auto row : this->adj){
            cout<<"Current Node is "<<row.first<<"-->"<<endl;
            for(auto col : row.second){
                cout<<col<<", ";
            }
            cout<<endl;
        }
     }
};

int main(){
    wrench786

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}