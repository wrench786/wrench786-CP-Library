
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    assert(1<=N && N<=100000);
    int market_values[N];

    for (int i = 0; i < N;++i) {
        cin >> market_values[i];
        assert(0<=market_values[i] && market_values[i]<=10000);
    }
    

    int min_price = market_values[0];
    int max_profit = 0;

    for (int i = 1; i < N; ++i) {
        if (market_values[i] < min_price) {
            min_price = market_values[i];
        } else {
            max_profit = max(max_profit, market_values[i] - min_price);
        }
    }

    cout << max_profit << endl;

    return 0;
}