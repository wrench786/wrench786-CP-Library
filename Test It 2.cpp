#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e6+7;

int Trie[N][26];
int last[N];
int freq[N];
stack<int>unused;

int cnt=0;
void insert_string(string s){
    int node=0;
    //freq[0]++;
    for(auto ch:s){
        int x = ch-'a';

        if(Trie[node][x]==-1){
            if(!unused.empty()){
                Trie[node][x] = unused.top();
                unused.pop();
            }
            else Trie[node][x] = ++cnt;
        }
        node = Trie[node][x];
        // how many string has this node as
        // prefix
        freq[node]++;
    }
    // how many nodes last at node
    last[node]++;
}

// check means if s string has or not
// bool full_string_check(string s){
//     int node = 0;
//     for(auto ch:s){
//         int x = ch-'a';

//         if(Trie[node][x]==-1) return false;
//         else node = Trie[node][x];
//     }
//     if(last[node]) return true;
//     else return false;
// }

//how many s appear as a prfix in the trie
int prefix_cnt(string s){
    int node = 0;
    for(auto ch:s){
        int x = ch-'a';

        if(Trie[node][x]==-1) return 0;
        else node = Trie[node][x];
    }
    return freq[node];
}

// void delete_string(string s){
//     if(!full_string_check(s)) return;

//     int node=0;
//     freq[0]--;

//     for(auto ch:s){
//         int x = ch-'a';

//         int temp = Trie[node][x];
//         freq[temp]--;

//         if(freq[temp]==0){
//             unused.push(temp);
//             Trie[node][x]=-1;
//         }
//         node = temp;
//     }
//     if(last[node]) last[node]--;
// }


void solve(){
    memset(Trie,-1,sizeof Trie);
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        insert_string(s);
    }

    while(q--){
        string s;
        cin>>s;

        int ans = prefix_cnt(s);

        cout<<ans<<nn;
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
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}