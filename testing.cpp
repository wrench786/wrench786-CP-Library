#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
 
const int mx = 1e5 + 10;
int Ans[mx];
pair <int, int> dp[mx];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    int n; cin >> n;
    int arr[n + 1]; for (int i = 1; i <= n; i++) cin >> arr[i];

    int idx = 1;
    for (int i = 1; i <= n; i++){


        vector <int> div;
        for (int j = 1; j * j <= arr[i]; j++){
            if (arr[i] % j == 0){
                div.push_back(j);
                if (arr[i] / j != j)div.push_back(arr[i] / j);
            }
        }
        sort(div.rbegin(), div.rend());
        
        for (auto x: div){
            if (dp[x].f >= arr[i]) dp[x].f = arr[i];
            else dp[x].f = arr[i], dp[x].s++;
        }

        // for (int j = 1; j * j <= arr[i]; j++){
        //    if (arr[i] % j == 0){
                
        //         if (dp[idx][j].f >= arr[i])dp[idx ^ 1][j].f = arr[i];
                
        //         else dp[idx ^ 1][j].f = arr[i], dp[idx ^ 1][j].s = dp[idx][j].s + 1;
                
        //         int d = arr[i] / j;

        //         if (d != j){
                    
        //             if (dp[idx][d].f >= arr[i])dp[idx ^ 1][d].f = arr[i];

        //             else dp[idx ^ 1][d].f = arr[i], dp[idx ^ 1][d].s = dp[idx][d].s + 1;
        //         }
        //         // if (j == 6) cout << i << " " << dp[1][j].s << endl;
        //         // if (d == 6) cout << i << " " << dp[1][d].s << endl;
        //    }
        // }
        

    }


    for (int i = 1; i < mx; i++){
        Ans[dp[i].s] = max(Ans[dp[i].s], i);
    }
    for (int i = mx - 2; i >= 1; i--)Ans[i] = max(Ans[i], Ans[i + 1]);
    int q; cin >> q;
    while (q --){
        int x; cin >> x; cout << Ans[x] << '\n';
    }

    return 0;
}