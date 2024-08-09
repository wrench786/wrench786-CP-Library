#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const ll MX = 1e5 + 5, N = 15, Ran = 2e5 + 5;
ll n, m, d, k, A[N][MX], dp[N][MX], T[4 * Ran];
vector<ll> res;

void update(ll node, ll a, ll b, ll x, ll y) {
    if (a == b && a == x) {
        T[node] = y;
        return;
    }
    if (x > b || a > x) return;
    ll mid = (a + b) / 2, left = (node << 1), right = left + 1;
    update(left, a, mid, x, y);
    update(right, mid + 1, b, x, y);
    T[node] = max(T[left], T[right]);
}

ll query(ll node, ll a, ll b, ll x, ll y) {
    if (x > b || a > y) return 0LL;
    if (a >= x && y >= b) return T[node];
    ll mid = (a + b) / 2, left = (node << 1), right = left + 1;
    return max(query(left, a, mid, x, y), query(right, mid + 1, b, x, y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //judge input
    FILE *input;
    input = fopen("input.txt", "r");
    if (!input) {
        printf("1\n");
        return 0; // Exit with an error code
    }

    //participants output
    FILE *output;
    output = fopen("output.txt", "r");

    if (!output) {
        printf("1\n");
        return 0; // Exit with an error code
    }

    //judge's output
    FILE *answer;
    answer = fopen("answer.txt", "r");

    if (!answer) {
        printf("1\n");
        return 0; // Exit with an error code
    }

    // 0 means ac, else wa

    // input file

    n=0;
    m=0;
    k=0;
    d=0;
    ll number;
    int i=1,j=1;
    while (fscanf(input, "%lld", &number) == 1) {
        if(!n) n = number;
        else if(!m) m = number;
        else if(!k) k = number;
        else if(!d) d = number;
        else{
            A[i][j] = number;
            j++;
            if(j>m){
                i++;
                j=1;
            }
        }
    }
    // cout<<n<<" "<<m<<" "<<k<<" "<<d<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for (ll i = 1; i <= n; i++) {
        memset(T, 0, sizeof(T));
        ll cur = 0;
        for (ll j = 1; j <= m; j++) {
            ll left = max(1LL, A[i][j] - k), right = A[i][j] + k;
            dp[i][j] = query(1, 1, Ran, left, right) + A[i][j];
            update(1, 1, Ran, A[i][j], dp[i][j]);
            cur = max(cur, dp[i][j]);
        }
        res.push_back(cur);
    }
    ll sub = (1LL << n);
    bool ok = false;
    for (ll i = 1; i < sub; i++) {
        ll sm = 0;
        for (ll j = 0; j < n; j++) {
            if ((i >> j) & 1LL) {
                sm += res[j];
            }
        }
        if (sm == d) {
            ok = true;
            break;
        }
    }
    char str[10];
    if(fscanf(output, "%s", str)==1){
        // printf("%s\n", str);
    }

    if(str[0]=='Y' && !ok){
        printf("1\n");
        return 0;
    }
    if(str[0]=='N' && ok){
        printf("1\n");
        return 0;
    }
    if(ok){
        ll number;
        ll sum=0;
        while (fscanf(output, "%lld", &number) == 1) {
            sum+=res[number-1];
        }
        if(sum==d)printf("0\n");
        else printf("1\n");
        return 0;
    }
    printf("0\n");

    return 0;
}